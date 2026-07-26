import 'dart:io';
import 'dart:typed_data';
import 'dart:ui' as ui;
import 'package:camera/camera.dart';
import 'package:flutter/material.dart';
import 'package:image/image.dart' as img;
import 'package:tflite_flutter/tflite_flutter.dart';

import '../models/detection.dart';
import '../models/image_info.dart';
import '../utils/yolo_decoder.dart';
import '../utils/constants.dart'; // for liveInputWidth/Height

class LiveCameraService {
  CameraController? _controller;
  bool _isStreaming = false;
  Interpreter? _interpreter;
  
  int _frameCounter = 0;
  int _skipFrames = 1;
  
  double _lastImageWidth = 640;
  double _lastImageHeight = 480;
  bool _isFrontCamera = false;
  
  // ---------- CONFIGURATION ----------
  // Set to true if boxes are horizontally mirrored (left ↔ right)
  bool _flipHorizontal = true;   // <-- CHANGE THIS IF NEEDED
  // ---------------------------------
  
  double _confidenceThreshold = 0.1;
  
  double _latestImageWidth = 0;
  double _latestImageHeight = 0;
  
  Function(List<Detection> detections, ui.Image? frameImage, double imageWidth, double imageHeight)? onDetection;

  bool get isStreaming => _isStreaming;
  CameraController? get controller => _controller;
  double get lastImageWidth => _lastImageWidth;
  double get lastImageHeight => _lastImageHeight;
  bool get isFrontCamera => _isFrontCamera;
  
  double get confidenceThreshold => _confidenceThreshold;
  set confidenceThreshold(double value) {
    _confidenceThreshold = value.clamp(0.0, 1.0);
    print("🔧 Confidence threshold set to: $_confidenceThreshold");
  }

  Future<void> initializeCamera(
    Function(List<Detection> detections, ui.Image? frameImage, double imageWidth, double imageHeight) callback
  ) async {
    onDetection = callback;
    
    if (_interpreter == null) {
      // Load the 224×224 live camera model
      _interpreter = await Interpreter.fromAsset('assets/models/detector_live.tflite');
      
      final inputShape = _interpreter!.getInputTensor(0).shape;
      print("✅ Live camera detector model loaded (224x224)");
      print("Input Shape: $inputShape");
    }
  }

  Future<void> startCamera(CameraDescription camera) async {
    if (_controller != null) {
      await _controller!.dispose();
    }

    _isFrontCamera = camera.lensDirection == CameraLensDirection.front;

    _controller = CameraController(
      camera,
      ResolutionPreset.medium,
      enableAudio: false,
      imageFormatGroup: ImageFormatGroup.yuv420,
    );

    await _controller!.initialize();
    
    final previewSize = _controller!.value.previewSize;
    if (previewSize != null) {
      _lastImageWidth = previewSize.width;
      _lastImageHeight = previewSize.height;
    }
    
    print("📹 Camera streaming started");
    print("📹 Preview size: ${_lastImageWidth}x${_lastImageHeight}");
    print("📹 Camera lens: ${_isFrontCamera ? 'Front' : 'Back'}");
    print("📹 Horizontal flip: $_flipHorizontal");
    print("📹 Confidence threshold: $_confidenceThreshold");

    await _controller!.startImageStream(_processCameraImage);
    _isStreaming = true;
  }

  void _processCameraImage(CameraImage cameraImage) {
    if (!_isStreaming || _interpreter == null) return;

    _frameCounter++;
    if (_frameCounter % _skipFrames != 0) return;

    try {
      // Get the actual camera image dimensions
      final int camWidth = cameraImage.width;
      final int camHeight = cameraImage.height;
      
      // Convert CameraImage to RGB Image
      final image = _convertCameraImageToImage(cameraImage);
      if (image == null) return;

      // Store the actual image dimensions
      _latestImageWidth = camWidth.toDouble();
      _latestImageHeight = camHeight.toDouble();

      // Preprocess image for detection (using live model size 224x224)
      final imageInfo = _preprocessImageForDetection(image);
      
      // Run inference
      final output = List.generate(
        1,
        (_) => List.generate(300, (_) => List.filled(6, 0.0)),
      );
      
      _interpreter!.run(imageInfo.inputTensor, output);
      
      // Decode detections (using live model size)
      List<Detection> detections = YoloDecoder.decode(
        output,
        imageInfo,
        inputWidth: liveInputWidth,
        inputHeight: liveInputHeight,
      );
      
      // ---------- APPLY HORIZONTAL FLIP IF NEEDED ----------
      if (_flipHorizontal) {
        detections = detections.map((det) {
          final double left = det.box.left;
          final double right = det.box.right;
          final double newLeft = _latestImageWidth - right;
          final double newRight = _latestImageWidth - left;
          return Detection(
            confidence: det.confidence,
            box: Rect.fromLTRB(newLeft, det.box.top, newRight, det.box.bottom),
          );
        }).toList();
      }
      // ------------------------------------------------------
      
      // Filter detections by confidence threshold
      final filteredDetections = detections
          .where((d) => d.confidence > _confidenceThreshold)
          .toList();
      
      // Create a UI image for display
      ui.Image? displayImage = _convertToUiImage(image);
      
      // Callback with results AND image dimensions
      onDetection?.call(
        filteredDetections, 
        displayImage,
        _latestImageWidth,
        _latestImageHeight
      );
      
    } catch (e) {
      // Silent error handling to avoid spam
    }
  }

  // Convert CameraImage to img.Image (RGB) - Universal YUV to RGB conversion
  img.Image? _convertCameraImageToImage(CameraImage cameraImage) {
    try {
      final int width = cameraImage.width;
      final int height = cameraImage.height;
      
      final img.Image image = img.Image(width: width, height: height);

      // Universal YUV420 to RGB conversion
      if (cameraImage.format.group == ImageFormatGroup.yuv420) {
        final Uint8List yPlane = cameraImage.planes[0].bytes;
        final Uint8List uPlane = cameraImage.planes[1].bytes;
        final Uint8List vPlane = cameraImage.planes[2].bytes;
        
        final int yRowStride = cameraImage.planes[0].bytesPerRow;
        final int uvRowStride = cameraImage.planes[1].bytesPerRow;
        final int uvPixelStride = cameraImage.planes[1].bytesPerPixel ?? 1;

        for (int y = 0; y < height; y++) {
          for (int x = 0; x < width; x++) {
            final int yIndex = y * yRowStride + x;
            final int uvIndex = (y ~/ 2) * uvRowStride + (x ~/ 2) * uvPixelStride;
            
            if (yIndex < yPlane.length && uvIndex < uPlane.length && uvIndex < vPlane.length) {
              final int yValue = yPlane[yIndex] & 0xFF;
              final int uValue = uPlane[uvIndex] & 0xFF;
              final int vValue = vPlane[uvIndex] & 0xFF;
              
              // Standard YUV to RGB conversion
              int r = (yValue + 1.402 * (vValue - 128)).round().clamp(0, 255);
              int g = (yValue - 0.344 * (uValue - 128) - 0.714 * (vValue - 128)).round().clamp(0, 255);
              int b = (yValue + 1.772 * (uValue - 128)).round().clamp(0, 255);
              
              image.setPixelRgb(x, y, r, g, b);
            }
          }
        }
        return image;
      }
      return null;
    } catch (e) {
      return null;
    }
  }

  // Preprocess image for detection model (using live model size 224x224)
  ImageInfoData _preprocessImageForDetection(img.Image image) {
    final int originalWidth = image.width;
    final int originalHeight = image.height;

    // Use live model input size
    const int inputWidth = liveInputWidth;
    const int inputHeight = liveInputHeight;

    final double scale = (inputWidth / originalWidth).clamp(0.0, double.infinity);
    final double scale2 = (inputHeight / originalHeight).clamp(0.0, double.infinity);
    final double ratio = scale < scale2 ? scale : scale2;

    final int resizedWidth = (originalWidth * ratio).round();
    final int resizedHeight = (originalHeight * ratio).round();

    final resized = img.copyResize(image, width: resizedWidth, height: resizedHeight);

    final canvas = img.Image(width: inputWidth, height: inputHeight);
    img.fill(canvas, color: img.ColorRgb8(114, 114, 114));

    final int padX = ((inputWidth - resizedWidth) / 2).round();
    final int padY = ((inputHeight - resizedHeight) / 2).round();

    img.compositeImage(canvas, resized, dstX: padX, dstY: padY);

    final input = List.generate(
      1,
      (_) => List.generate(
        inputHeight,
        (y) => List.generate(
          inputWidth,
          (x) {
            final pixel = canvas.getPixel(x, y);
            return [
              pixel.r / 255.0,
              pixel.g / 255.0,
              pixel.b / 255.0,
            ];
          },
        ),
      ),
    );

    return ImageInfoData(
      inputTensor: input,
      originalWidth: originalWidth,
      originalHeight: originalHeight,
      scale: ratio,
      padX: padX.toDouble(),
      padY: padY.toDouble(),
    );
  }

  // Convert img.Image to ui.Image for display
  ui.Image? _convertToUiImage(img.Image image) {
    try {
      final displayImage = img.copyResize(image, width: 320, height: 240);
      final bytes = img.encodePng(displayImage);
      return decodeImageFromList(bytes) as ui.Image?;
    } catch (e) {
      return null;
    }
  }

  Future<void> stopCamera() async {
    _isStreaming = false;
    if (_controller != null) {
      await _controller!.stopImageStream();
      await _controller!.dispose();
      _controller = null;
    }
    print("📹 Camera streaming stopped");
  }

  void dispose() {
    _isStreaming = false;
    _controller?.dispose();
    _interpreter?.close();
    _controller = null;
    _interpreter = null;
  }

  Future<void> switchCamera(CameraDescription camera) async {
    await stopCamera();
    await startCamera(camera);
  }
}