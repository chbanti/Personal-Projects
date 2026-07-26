import 'dart:ui' as ui;
import 'package:flutter/material.dart';
import 'package:camera/camera.dart';
import '../models/detection.dart';

class LiveCameraView extends StatefulWidget {
  final CameraController? cameraController;
  final List<Detection> detections;
  final ui.Image? frameImage;
  final bool isStreaming;
  final double imageWidth;
  final double imageHeight;
  final bool isFrontCamera;

  const LiveCameraView({
    super.key,
    this.cameraController,
    this.detections = const [],
    this.frameImage,
    this.isStreaming = false,
    this.imageWidth = 0,
    this.imageHeight = 0,
    this.isFrontCamera = false,
  });

  @override
  State<LiveCameraView> createState() => _LiveCameraViewState();
}

class _LiveCameraViewState extends State<LiveCameraView> {
  @override
  Widget build(BuildContext context) {
    if (!widget.isStreaming || widget.cameraController == null) {
      return const Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Icon(Icons.videocam_off, size: 60, color: Colors.grey),
            SizedBox(height: 16),
            Text(
              "Camera not started",
              style: TextStyle(fontSize: 18, color: Colors.grey),
            ),
            Text(
              "Tap 'Start Live Camera' to begin",
              style: TextStyle(fontSize: 14, color: Colors.grey),
            ),
          ],
        ),
      );
    }

    return LayoutBuilder(
      builder: (context, constraints) {
        // Use a fixed aspect ratio that works on all devices (4:3)
        // This is the most compatible aspect ratio for cameras
        final double previewAspectRatio = 4.0 / 3.0;
        
        final double containerWidth = constraints.maxWidth;
        final double containerHeight = constraints.maxHeight;
        
        // Calculate display size to contain the preview
        double displayWidth = containerWidth;
        double displayHeight = containerHeight;
        final double containerAspectRatio = containerWidth / containerHeight;
        
        if (containerAspectRatio > previewAspectRatio) {
          displayWidth = containerHeight * previewAspectRatio;
          displayHeight = containerHeight;
        } else {
          displayWidth = containerWidth;
          displayHeight = containerWidth / previewAspectRatio;
        }
        
        final double offsetX = (containerWidth - displayWidth) / 2;
        final double offsetY = (containerHeight - displayHeight) / 2;

        // Use fixed image dimensions (most cameras are 640x480 or similar)
        final double imageW = 640.0;
        final double imageH = 480.0;
        
        // Calculate the scale factor from image to display
        final double scaleX = displayWidth / imageW;
        final double scaleY = displayHeight / imageH;
        final double scale = scaleX < scaleY ? scaleX : scaleY;
        
        // Calculate the image offset within the display
        final double imageOffsetX = (displayWidth - (imageW * scale)) / 2;
        final double imageOffsetY = (displayHeight - (imageH * scale)) / 2;

        return Container(
          color: Colors.black,
          child: Center(
            child: Stack(
              fit: StackFit.loose,
              children: [
                // Camera preview with fixed aspect ratio
                Container(
                  width: displayWidth,
                  height: displayHeight,
                  decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(15),
                  ),
                  child: ClipRRect(
                    borderRadius: BorderRadius.circular(15),
                    child: CameraPreview(widget.cameraController!),
                  ),
                ),
                
                // Detection overlay
                if (widget.detections.isNotEmpty)
                  Positioned(
                    left: offsetX,
                    top: offsetY,
                    width: displayWidth,
                    height: displayHeight,
                    child: ClipRRect(
                      borderRadius: BorderRadius.circular(15),
                      child: CustomPaint(
                        painter: LiveDetectionPainter(
                          detections: widget.detections,
                          imageWidth: imageW,
                          imageHeight: imageH,
                          displayWidth: displayWidth,
                          displayHeight: displayHeight,
                          offsetX: imageOffsetX,
                          offsetY: imageOffsetY,
                          scale: scale,
                          isFrontCamera: widget.isFrontCamera,
                        ),
                        size: Size(displayWidth, displayHeight),
                      ),
                    ),
                  ),
                
                // Detection count
                Positioned(
                  bottom: 8,
                  right: 8,
                  child: Container(
                    padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 6),
                    decoration: BoxDecoration(
                      color: Colors.black.withOpacity(0.7),
                      borderRadius: BorderRadius.circular(8),
                    ),
                    child: Text(
                      "Detections: ${widget.detections.length}",
                      style: const TextStyle(
                        color: Colors.white, 
                        fontSize: 14,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                ),
                
                // Live indicator
                Positioned(
                  top: 8,
                  right: 8,
                  child: Container(
                    padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 4),
                    decoration: BoxDecoration(
                      color: Colors.red.withOpacity(0.8),
                      borderRadius: BorderRadius.circular(12),
                    ),
                    child: const Row(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        SizedBox(
                          width: 8,
                          height: 8,
                          child: DecoratedBox(
                            decoration: BoxDecoration(
                              color: Colors.white,
                              shape: BoxShape.circle,
                            ),
                          ),
                        ),
                        SizedBox(width: 6),
                        Text(
                          "LIVE",
                          style: TextStyle(
                            color: Colors.white, 
                            fontSize: 10, 
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
              ],
            ),
          ),
        );
      },
    );
  }
}

class LiveDetectionPainter extends CustomPainter {
  final List<Detection> detections;
  final double imageWidth;
  final double imageHeight;
  final double displayWidth;
  final double displayHeight;
  final double offsetX;
  final double offsetY;
  final double scale;
  final bool isFrontCamera;

  LiveDetectionPainter({
    required this.detections,
    required this.imageWidth,
    required this.imageHeight,
    required this.displayWidth,
    required this.displayHeight,
    required this.offsetX,
    required this.offsetY,
    required this.scale,
    this.isFrontCamera = false,
  });

  @override
  void paint(Canvas canvas, Size size) {
    if (detections.isEmpty) return;

    final paint = Paint()
      ..color = Colors.green
      ..strokeWidth = 3
      ..style = PaintingStyle.stroke;

    for (final d in detections) {
      // Use fixed coordinate mapping
      double left = d.box.left;
      double right = d.box.right;
      double top = d.box.top;
      double bottom = d.box.bottom;
      
      // For front camera, flip horizontally
      if (isFrontCamera) {
        final tempLeft = left;
        left = imageWidth - right;
        right = imageWidth - tempLeft;
      }
      
      // Map to display coordinates
      final rect = Rect.fromLTRB(
        offsetX + (left * scale),
        offsetY + (top * scale),
        offsetX + (right * scale),
        offsetY + (bottom * scale),
      );
      
      canvas.drawRect(rect, paint);

      // Draw confidence text
      final tp = TextPainter(
        text: TextSpan(
          text: "${(d.confidence * 100).toStringAsFixed(1)}%",
          style: const TextStyle(
            color: Colors.red,
            fontSize: 14,
            fontWeight: FontWeight.bold,
            shadows: [
              Shadow(
                color: Colors.black,
                blurRadius: 4,
                offset: Offset(1, 1),
              ),
            ],
          ),
        ),
        textDirection: TextDirection.ltr,
      );

      tp.layout();
      
      final textRect = Rect.fromLTWH(
        rect.left,
        rect.top - 20,
        tp.width + 8,
        tp.height + 4,
      );
      
      final bgPaint = Paint()
        ..color = Colors.black.withOpacity(0.5)
        ..style = PaintingStyle.fill;
      
      canvas.drawRRect(
        RRect.fromRectAndRadius(textRect, const Radius.circular(4)),
        bgPaint,
      );
      
      tp.paint(
        canvas,
        Offset(rect.left + 4, rect.top - 18),
      );
    }
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) {
    return true;
  }
}