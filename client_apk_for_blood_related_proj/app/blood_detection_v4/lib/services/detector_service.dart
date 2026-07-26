import 'dart:io';
import 'package:camera/camera.dart';
import 'package:tflite_flutter/tflite_flutter.dart';

import '../models/detection.dart';
import '../utils/image_preprocessor.dart';
import '../utils/yolo_decoder.dart';
import '../utils/constants.dart';

class DetectorService {
  final String modelPath;
  final int inputWidth;
  final int inputHeight;
  Interpreter? _interpreter;

  DetectorService({
    this.modelPath = 'assets/models/detector_image.tflite',
    this.inputWidth = imageInputWidth,
    this.inputHeight = imageInputHeight,
  });

  bool get isLoaded => _interpreter != null;

  Future<void> loadModel() async {
    if (_interpreter != null) return;
    _interpreter = await Interpreter.fromAsset(modelPath);
    print("✅ Detector model loaded: ${modelPath.split('/').last} (${inputWidth}x${inputHeight})");
    print("Input Shape : ${_interpreter!.getInputTensor(0).shape}");
    print("Output Shape: ${_interpreter!.getOutputTensor(0).shape}");
  }

  Future<List<Detection>> detect(File imageFile) async {
    if (_interpreter == null) throw Exception("Detector model not loaded.");
    final imageInfo = await ImagePreprocessor.preprocess(
      imageFile,
      inputWidth: inputWidth,
      inputHeight: inputHeight,
    );
    final output = List.generate(1, (_) => List.generate(300, (_) => List.filled(6, 0.0)));
    _interpreter!.run(imageInfo.inputTensor, output);
    return YoloDecoder.decode(
      output,
      imageInfo,
      inputWidth: inputWidth,
      inputHeight: inputHeight,
    );
  }

  Future<List<Detection>> detectFromCameraImage(CameraImage cameraImage) async {
    if (_interpreter == null) throw Exception("Detector model not loaded.");
    final imageInfo = await ImagePreprocessor.preprocessCameraImage(
      cameraImage,
      inputWidth: inputWidth,
      inputHeight: inputHeight,
    );
    final output = List.generate(1, (_) => List.generate(300, (_) => List.filled(6, 0.0)));
    _interpreter!.run(imageInfo.inputTensor, output);
    return YoloDecoder.decode(
      output,
      imageInfo,
      inputWidth: inputWidth,
      inputHeight: inputHeight,
    );
  }

  void close() {
    _interpreter?.close();
    _interpreter = null;
  }
}