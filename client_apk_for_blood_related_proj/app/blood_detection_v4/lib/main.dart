import 'dart:async';
import 'dart:io';
import 'dart:ui' as ui;

import 'package:camera/camera.dart';
import 'package:flutter/material.dart';

import 'models/detection.dart';
import 'services/detector_service.dart';
import 'services/image_picker_service.dart';
import 'services/segmentation_service.dart';
import 'services/live_camera_service.dart';
import 'widgets/detection_painter.dart';
import 'widgets/heatmap_image_painter.dart';
import 'widgets/live_camera_view.dart';
import 'utils/heatmap_generator.dart';
import 'utils/constants.dart';  // for imageInputWidth/Height

late List<CameraDescription> cameras;

final GlobalKey<ScaffoldMessengerState> scaffoldMessengerKey = GlobalKey<ScaffoldMessengerState>();

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  cameras = await availableCameras();
  runApp(const MyApp());
}

enum AnalysisMode {
  detection,
  segmentation,
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  final ImagePickerService _picker = ImagePickerService();
  final DetectorService _detector = DetectorService();
  final SegmentationService _segmenter = SegmentationService();
  final ScrollController _scrollController = ScrollController();

  // Image
  File? selectedImage;
  List<Detection> detections = [];
  bool modelLoaded = false;
  bool isProcessing = false;
  bool showResult = false;
  bool isLoadingMedia = false;

  double imageWidth = 0;
  double imageHeight = 0;

  AnalysisMode mode = AnalysisMode.detection;
  List<List<double>> segmentationMask = [];
  ui.Image? heatmapImage;

  // Live Camera
  bool isLiveMode = false;
  LiveCameraService? _liveCameraService;
  List<Detection> liveDetections = [];
  ui.Image? liveFrameImage;
  double liveImageWidth = 0;
  double liveImageHeight = 0;

  @override
  void initState() {
    super.initState();
    loadModels();
  }

  @override
  void dispose() {
    _scrollController.dispose();
    heatmapImage?.dispose();
    liveFrameImage?.dispose();
    _liveCameraService?.dispose();
    _detector.close();
    _segmenter.close();
    super.dispose();
  }

  void _showSnackBar(String message, {Color? backgroundColor}) {
    scaffoldMessengerKey.currentState?.showSnackBar(
      SnackBar(
        content: Text(message),
        backgroundColor: backgroundColor ?? Colors.blue,
        duration: const Duration(seconds: 2),
      ),
    );
  }

  Future<void> loadModels() async {
    await _detector.loadModel();
    if (mode == AnalysisMode.segmentation) {
      await _segmenter.loadModel();
    }
    setState(() => modelLoaded = true);
  }

  void _clearMedia() {
    setState(() {
      selectedImage = null;
      detections.clear();
      segmentationMask.clear();
      heatmapImage?.dispose();
      heatmapImage = null;
      showResult = false;
      mode = AnalysisMode.detection;
      isLoadingMedia = false;
    });
    _showSnackBar("Media cleared", backgroundColor: Colors.blue);
  }

  // ==================== LIVE CAMERA METHODS ====================
  Future<void> _startLiveCamera() async {
    if (_liveCameraService == null) {
      _liveCameraService = LiveCameraService();
      await _liveCameraService!.initializeCamera((detections, frameImage, imageWidth, imageHeight) {
        setState(() {
          liveDetections = detections;
          liveFrameImage = frameImage;
          liveImageWidth = imageWidth;
          liveImageHeight = imageHeight;
        });
      });
    }

    if (cameras.isEmpty) {
      _showSnackBar("No camera available", backgroundColor: Colors.red);
      return;
    }

    final camera = cameras.firstWhere(
      (c) => c.lensDirection == CameraLensDirection.back,
      orElse: () => cameras.first,
    );

    await _liveCameraService!.startCamera(camera);
    setState(() {
      isLiveMode = true;
    });
    _showSnackBar("Live camera started", backgroundColor: Colors.green);
  }

  Future<void> _stopLiveCamera() async {
    await _liveCameraService?.stopCamera();
    setState(() {
      isLiveMode = false;
      liveDetections = [];
      liveFrameImage = null;
      liveImageWidth = 0;
      liveImageHeight = 0;
    });
    _showSnackBar("Live camera stopped", backgroundColor: Colors.orange);
  }

  void _toggleLiveMode() {
    if (isLiveMode) {
      _stopLiveCamera();
    } else {
      _startLiveCamera();
    }
  }

  // ==================== IMAGE METHODS ====================
  Future<void> _pickFromGallery() async {
    if (isLiveMode) {
      await _stopLiveCamera();
    }
    setState(() => isLoadingMedia = true);
    final img = await _picker.pickImageFromGallery();
    if (img == null) {
      setState(() => isLoadingMedia = false);
      return;
    }
    await _processSelectedImage(img);
    setState(() => isLoadingMedia = false);
  }

  Future<void> _takePhoto() async {
    if (isLiveMode) {
      await _stopLiveCamera();
    }
    setState(() => isLoadingMedia = true);
    final img = await _picker.takePhotoFromCamera();
    if (img == null) {
      setState(() => isLoadingMedia = false);
      return;
    }
    await _processSelectedImage(img);
    setState(() => isLoadingMedia = false);
  }

  Future<void> _processSelectedImage(File img) async {
    final decoded = await decodeImageFromList(await img.readAsBytes());
    setState(() {
      selectedImage = img;
      imageWidth = decoded.width.toDouble();
      imageHeight = decoded.height.toDouble();
      detections.clear();
      segmentationMask.clear();
      heatmapImage?.dispose();
      heatmapImage = null;
      showResult = false;
      mode = AnalysisMode.detection;
      isLoadingMedia = false;
    });
  }

  // ==================== RUN DETECTION ====================
  Future<void> runDetection() async {
    if (isProcessing) return;
    if (selectedImage == null) return;

    heatmapImage?.dispose();
    heatmapImage = null;
    segmentationMask = [];

    setState(() {
      isProcessing = true;
      showResult = false;
      detections = [];
    });

    try {
      final result = await computeAnalysis(selectedImage!, mode);
      setState(() {
        detections = result.detections;
        segmentationMask = result.mask;
        heatmapImage = result.heatmapImage;
        showResult = true;
      });
    } catch (e, stack) {
      print("=== CRITICAL ERROR ===");
      print(e);
      print(stack);
    } finally {
      setState(() => isProcessing = false);
    }
  }

  void _toggleMode(AnalysisMode newMode) {
    if (isLiveMode) return;
    setState(() {
      mode = newMode;
    });
    _reloadModelsForMode(newMode);
  }

  Future<void> _reloadModelsForMode(AnalysisMode newMode) async {
    if (!_detector.isLoaded) {
      await _detector.loadModel();
    }
    if (newMode == AnalysisMode.segmentation) {
      if (!_segmenter.isLoaded) {
        await _segmenter.loadModel();
      }
    } else {
      _segmenter.close();
    }
    setState(() => modelLoaded = true);
  }

  // ==================== BUILD ====================
  @override
  Widget build(BuildContext context) {
    final screenSize = MediaQuery.of(context).size;
    final isSmallScreen = screenSize.width < 380;
    final isLargeScreen = screenSize.width > 600;

    final double horizontalPadding = isSmallScreen ? 8 : 16;
    final double mediaHeight = isSmallScreen ? 250 : (isLargeScreen ? 400 : 320);
    final double fontSize = isSmallScreen ? 12 : 16;
    final double titleFontSize = isSmallScreen ? 18 : 22;

    return MaterialApp(
      debugShowCheckedModeBanner: false,
      scaffoldMessengerKey: scaffoldMessengerKey,
      home: Scaffold(
        appBar: AppBar(
          title: Text(
            isLiveMode ? "Live Detection" : "Blood Detection AI",
            style: TextStyle(fontSize: isSmallScreen ? 16 : 20),
          ),
          centerTitle: true,
          backgroundColor: isLiveMode ? Colors.red[700] : Colors.blue[800],
          foregroundColor: Colors.white,
        ),
        body: !modelLoaded
            ? const Center(child: CircularProgressIndicator())
            : Stack(
                children: [
                  SingleChildScrollView(
                    controller: _scrollController,
                    padding: EdgeInsets.all(horizontalPadding),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.stretch,
                      children: [
                        // ==================== ANALYSIS MODE ====================
                        Text(
                          "Analysis Mode",
                          style: TextStyle(
                            fontSize: titleFontSize,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                        const SizedBox(height: 12),

                        ToggleButtons(
                          borderRadius: BorderRadius.circular(12),
                          constraints: BoxConstraints(
                            minHeight: isSmallScreen ? 40 : 50,
                            minWidth: isSmallScreen ? 120 : 150,
                          ),
                          isSelected: [mode == AnalysisMode.detection, mode == AnalysisMode.segmentation],
                          onPressed: isLiveMode
                              ? null
                              : (index) {
                                  final newMode = index == 0 ? AnalysisMode.detection : AnalysisMode.segmentation;
                                  _toggleMode(newMode);
                                },
                          children: [
                            Padding(
                              padding: EdgeInsets.symmetric(horizontal: isSmallScreen ? 4 : 6),
                              child: Text(
                                "Detection Only",
                                textAlign: TextAlign.center,
                                style: TextStyle(
                                  fontSize: isSmallScreen ? 12 : fontSize,
                                  color: isLiveMode && mode == AnalysisMode.detection ? Colors.blue : null,
                                ),
                              ),
                            ),
                            Padding(
                              padding: EdgeInsets.symmetric(horizontal: isSmallScreen ? 4 : 6),
                              child: Text(
                                "Detection\n+ Segmentation",
                                textAlign: TextAlign.center,
                                style: TextStyle(
                                  fontSize: isSmallScreen ? 12 : fontSize,
                                  color: isLiveMode ? Colors.grey : null,
                                ),
                              ),
                            ),
                          ],
                        ),

                        if (isLiveMode)
                          Padding(
                            padding: const EdgeInsets.only(top: 8),
                            child: Text(
                              "⚠️ Segmentation disabled for live camera",
                              style: TextStyle(
                                fontSize: isSmallScreen ? 10 : 12,
                                color: Colors.orange,
                              ),
                            ),
                          ),

                        const SizedBox(height: 30),

                        // ==================== INPUT MEDIA HEADER ====================
                        if (!isLiveMode)
                          Row(
                            mainAxisAlignment: MainAxisAlignment.spaceBetween,
                            children: [
                              Text(
                                "Input Media",
                                style: TextStyle(
                                  fontSize: titleFontSize,
                                  fontWeight: FontWeight.bold,
                                ),
                              ),
                              if (selectedImage != null)
                                IconButton(
                                  onPressed: _clearMedia,
                                  icon: const Icon(Icons.clear, color: Colors.red),
                                  tooltip: "Clear Media",
                                  style: IconButton.styleFrom(
                                    backgroundColor: Colors.red.withOpacity(0.1),
                                    padding: isSmallScreen
                                        ? const EdgeInsets.all(6)
                                        : const EdgeInsets.all(8),
                                  ),
                                ),
                            ],
                          ),
                        if (!isLiveMode) const SizedBox(height: 12),

                        // ==================== MEDIA DISPLAY / LIVE CAMERA ====================
                        if (isLiveMode)
                          // Live Camera View
                          Card(
                            elevation: 4,
                            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(15)),
                            child: Container(
                              height: mediaHeight,
                              width: double.infinity,
                              decoration: BoxDecoration(
                                borderRadius: BorderRadius.circular(15),
                                color: Colors.black12,
                              ),
                              child: ClipRRect(
                                borderRadius: BorderRadius.circular(15),
                                child: LiveCameraView(
                                  cameraController: _liveCameraService?.controller,
                                  detections: liveDetections,
                                  frameImage: liveFrameImage,
                                  isStreaming: isLiveMode,
                                  imageWidth: liveImageWidth,
                                  imageHeight: liveImageHeight,
                                  isFrontCamera: _liveCameraService?.isFrontCamera ?? false,
                                ),
                              ),
                            ),
                          )
                        else
                          // Media Display (Image)
                          Card(
                            elevation: 4,
                            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(15)),
                            child: Container(
                              height: mediaHeight,
                              width: double.infinity,
                              decoration: BoxDecoration(
                                borderRadius: BorderRadius.circular(15),
                                color: Colors.black12,
                              ),
                              child: isLoadingMedia
                                  ? const Center(
                                      child: Column(
                                        mainAxisAlignment: MainAxisAlignment.center,
                                        children: [
                                          CircularProgressIndicator(),
                                          SizedBox(height: 16),
                                          Text(
                                            "Loading media...",
                                            style: TextStyle(fontSize: 16, color: Colors.grey),
                                          ),
                                        ],
                                      ),
                                    )
                                  : selectedImage == null
                                      ? const Center(
                                          child: Column(
                                            mainAxisAlignment: MainAxisAlignment.center,
                                            children: [
                                              Icon(Icons.image, size: 60, color: Colors.grey),
                                              SizedBox(height: 12),
                                              Text(
                                                "No Image Selected",
                                                style: TextStyle(fontSize: 18, color: Colors.grey),
                                              ),
                                              Text(
                                                "Select an image from below",
                                                style: TextStyle(fontSize: 12, color: Colors.grey),
                                              ),
                                            ],
                                          ),
                                        )
                                      : ClipRRect(
                                          borderRadius: BorderRadius.circular(15),
                                          child: Image.file(
                                            selectedImage!,
                                            fit: BoxFit.contain,
                                            width: double.infinity,
                                            height: double.infinity,
                                          ),
                                        ),
                            ),
                          ),

                        const SizedBox(height: 20),

                        // ==================== BUTTONS ====================
                        Column(
                          children: [
                            Row(
                              children: [
                                Expanded(
                                  child: ElevatedButton.icon(
                                    onPressed: (isProcessing || isLiveMode) ? null : _pickFromGallery,
                                    icon: Icon(Icons.photo_library, size: isSmallScreen ? 18 : 24),
                                    label: Text(
                                      "Gallery",
                                      style: TextStyle(fontSize: isSmallScreen ? 12 : fontSize),
                                    ),
                                    style: ElevatedButton.styleFrom(
                                      padding: EdgeInsets.symmetric(
                                        vertical: isSmallScreen ? 10 : 14,
                                      ),
                                    ),
                                  ),
                                ),
                                SizedBox(width: isSmallScreen ? 8 : 12),
                                Expanded(
                                  child: ElevatedButton.icon(
                                    onPressed: (isProcessing || isLiveMode) ? null : _takePhoto,
                                    icon: Icon(Icons.camera_alt, size: isSmallScreen ? 18 : 24),
                                    label: Text(
                                      "Camera",
                                      style: TextStyle(fontSize: isSmallScreen ? 12 : fontSize),
                                    ),
                                    style: ElevatedButton.styleFrom(
                                      padding: EdgeInsets.symmetric(
                                        vertical: isSmallScreen ? 10 : 14,
                                      ),
                                    ),
                                  ),
                                ),
                              ],
                            ),
                          ],
                        ),

                        SizedBox(height: isSmallScreen ? 8 : 12),

                        // ==================== LIVE CAMERA BUTTON ====================
                        if (selectedImage == null)
                          Padding(
                            padding: const EdgeInsets.only(bottom: 8),
                            child: ElevatedButton.icon(
                              onPressed: isProcessing ? null : _toggleLiveMode,
                              icon: Icon(
                                isLiveMode ? Icons.stop : Icons.videocam,
                                size: isSmallScreen ? 18 : 24,
                              ),
                              label: Text(
                                isLiveMode ? "Stop Live Camera" : "Start Live Camera",
                                style: TextStyle(fontSize: isSmallScreen ? 14 : fontSize),
                              ),
                              style: ElevatedButton.styleFrom(
                                padding: EdgeInsets.symmetric(
                                  vertical: isSmallScreen ? 12 : 14,
                                ),
                                backgroundColor: isLiveMode ? Colors.red : Colors.green,
                                foregroundColor: Colors.white,
                              ),
                            ),
                          ),

                        // ==================== START ANALYSIS BUTTON ====================
                        if (!isLiveMode)
                          ElevatedButton.icon(
                            onPressed: (selectedImage == null || isProcessing)
                                ? null
                                : runDetection,
                            icon: isProcessing
                                ? const SizedBox(width: 20, height: 20, child: CircularProgressIndicator(strokeWidth: 2, color: Colors.white))
                                : Icon(Icons.play_arrow, size: isSmallScreen ? 18 : 24),
                            label: Text(
                              isProcessing ? "Running Analysis..." : "Start Analysis",
                              style: TextStyle(fontSize: isSmallScreen ? 14 : fontSize),
                            ),
                            style: ElevatedButton.styleFrom(
                              padding: EdgeInsets.symmetric(
                                vertical: isSmallScreen ? 12 : 14,
                              ),
                              backgroundColor: Colors.blue[700],
                              foregroundColor: Colors.white,
                            ),
                          ),

                        // ==================== VIEW RESULT BUTTON ====================
                        if (showResult && !isLiveMode)
                          Padding(
                            padding: const EdgeInsets.only(top: 12),
                            child: ElevatedButton.icon(
                              onPressed: () {
                                _scrollController.animateTo(
                                  _scrollController.position.maxScrollExtent,
                                  duration: const Duration(milliseconds: 800),
                                  curve: Curves.easeInOut,
                                );
                              },
                              icon: const Icon(Icons.arrow_downward),
                              label: Text(
                                "View Result",
                                style: TextStyle(fontSize: isSmallScreen ? 14 : fontSize),
                              ),
                              style: ElevatedButton.styleFrom(
                                backgroundColor: Colors.green,
                                foregroundColor: Colors.white,
                                padding: EdgeInsets.symmetric(
                                  vertical: isSmallScreen ? 12 : 14,
                                ),
                              ),
                            ),
                          ),

                        const SizedBox(height: 30),

                        // ==================== IMAGE RESULT ====================
                        if (showResult && !isLiveMode) ...[
                          const Divider(thickness: 2, height: 40),
                          Text(
                            "Analysis Result",
                            style: TextStyle(
                              fontSize: titleFontSize,
                              fontWeight: FontWeight.bold,
                            ),
                          ),
                          const SizedBox(height: 15),

                          Card(
                            elevation: 5,
                            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(15)),
                            child: SizedBox(
                              height: mediaHeight,
                              child: Stack(
                                children: [
                                  Positioned.fill(
                                    child: ClipRRect(
                                      borderRadius: BorderRadius.circular(15),
                                      child: Image.file(
                                        selectedImage!,
                                        fit: BoxFit.contain,
                                      ),
                                    ),
                                  ),
                                  if (mode == AnalysisMode.segmentation && heatmapImage != null)
                                    Positioned.fill(
                                      child: ClipRRect(
                                        borderRadius: BorderRadius.circular(15),
                                        child: CustomPaint(
                                          painter: HeatmapImagePainter(heatmapImage!, imageWidth, imageHeight),
                                        ),
                                      ),
                                    ),
                                  if (detections.isNotEmpty)
                                    Positioned.fill(
                                      child: CustomPaint(
                                        painter: DetectionPainter(
                                          detections: detections,
                                          imageWidth: imageWidth,
                                          imageHeight: imageHeight,
                                        ),
                                      ),
                                    ),
                                ],
                              ),
                            ),
                          ),

                          const SizedBox(height: 20),

                          Card(
                            child: Padding(
                              padding: const EdgeInsets.all(16),
                              child: Column(
                                children: [
                                  Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, children: [const Text("Mode"), Text(mode == AnalysisMode.detection ? "Detection" : "Detection + Segmentation")]),
                                  const Divider(),
                                  Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, children: [const Text("Detections"), Text(detections.length.toString(), style: const TextStyle(fontWeight: FontWeight.bold, color: Colors.red))]),
                                  const Divider(),
                                  Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, children: [const Text("Image Size"), Text("${imageWidth.toInt()} × ${imageHeight.toInt()}")]),
                                  const Divider(),
                                  const Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, children: [Text("Status"), Text("Completed", style: TextStyle(color: Colors.green, fontWeight: FontWeight.bold))]),
                                ],
                              ),
                            ),
                          ),
                        ],

                        // ==================== LIVE CAMERA STATS ====================
                        if (isLiveMode && liveDetections.isNotEmpty) ...[
                          const Divider(thickness: 2, height: 40),
                          Text(
                            "Live Detection Stats",
                            style: TextStyle(
                              fontSize: titleFontSize,
                              fontWeight: FontWeight.bold,
                            ),
                          ),
                          const SizedBox(height: 15),

                          Card(
                            child: Padding(
                              padding: const EdgeInsets.all(16),
                              child: Column(
                                children: [
                                  Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, children: [const Text("Mode"), Text("Live Detection")]),
                                  const Divider(),
                                  Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, children: [const Text("Current Detections"), Text(liveDetections.length.toString(), style: const TextStyle(fontWeight: FontWeight.bold, color: Colors.red))]),
                                  const Divider(),
                                  const Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, children: [Text("Status"), Text("🟢 Live", style: TextStyle(color: Colors.green, fontWeight: FontWeight.bold))]),
                                ],
                              ),
                            ),
                          ),
                        ],
                      ],
                    ),
                  ),

                  if (isProcessing) const AnalysisLoadingOverlay(),
                ],
              ),
      ),
    );
  }
}

// ====================== ANALYSIS ======================
class AnalysisResult {
  final List<Detection> detections;
  final List<List<double>> mask;
  final ui.Image? heatmapImage;

  AnalysisResult({required this.detections, required this.mask, this.heatmapImage});
}

Future<AnalysisResult> computeAnalysis(File imageFile, AnalysisMode mode) async {
  // Use image model (640×640)
  final detector = DetectorService(
    modelPath: 'assets/models/detector_image.tflite',
    inputWidth: imageInputWidth,
    inputHeight: imageInputHeight,
  );
  final segmenter = SegmentationService();

  try {
    await detector.loadModel();
    if (mode == AnalysisMode.segmentation) {
      await segmenter.loadModel();
    }

    final bytes = await imageFile.readAsBytes();
    final decoded = await decodeImageFromList(bytes);
    final originalWidth = decoded.width.toDouble();
    final originalHeight = decoded.height.toDouble();

    final detections = await detector.detect(imageFile);

    List<List<double>> mask = [];
    ui.Image? heatmapImage;
    if (mode == AnalysisMode.segmentation) {
      mask = await segmenter.segment(imageFile);
      if (mask.isNotEmpty) {
        heatmapImage = await HeatmapGenerator.generateHeatmap(mask, originalWidth, originalHeight);
      }
    }

    return AnalysisResult(detections: detections, mask: mask, heatmapImage: heatmapImage);
  } finally {
    detector.close();
    if (mode == AnalysisMode.segmentation) segmenter.close();
  }
}

// ====================== LOADING OVERLAY ======================
class AnalysisLoadingOverlay extends StatelessWidget {
  const AnalysisLoadingOverlay({super.key});

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: () {},
      behavior: HitTestBehavior.opaque,
      child: Container(
        color: Colors.black.withOpacity(0.9),
        child: const Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              SizedBox(width: 70, height: 70, child: CircularProgressIndicator(color: Colors.white, strokeWidth: 7)),
              SizedBox(height: 30),
              Text("Analyzing", style: TextStyle(color: Colors.white, fontSize: 24, fontWeight: FontWeight.bold)),
              SizedBox(height: 12),
              Text("Please wait...", style: TextStyle(color: Colors.white70, fontSize: 17)),
              SizedBox(height: 40),
              Text("Do not touch the screen", style: TextStyle(color: Colors.white54, fontSize: 15)),
            ],
          ),
        ),
      ),
    );
  }
}