import 'dart:ui';
import '../models/detection.dart';
import '../models/image_info.dart';

class YoloDecoder {
  static List<Detection> decode(
    List output,
    ImageInfoData imageInfo, {
    required int inputWidth,
    required int inputHeight,
  }) {
    final detections = <Detection>[];
    final data = output[0];
    if (data == null || data.length == 0) return detections;

    double maxConf = 0.0;
    int detectionsFound = 0;

    for (int i = 0; i < data.length; i++) {
      if (data[i] == null || data[i].length < 5) continue;
      final confidence = data[i][4].toDouble();
      if (confidence > maxConf) maxConf = confidence;
      if (confidence < 0.05) continue;
      detectionsFound++;

      double x1 = data[i][0].toDouble();
      double y1 = data[i][1].toDouble();
      double x2 = data[i][2].toDouble();
      double y2 = data[i][3].toDouble();
      x1 = x1.clamp(0.0, 1.0);
      y1 = y1.clamp(0.0, 1.0);
      x2 = x2.clamp(0.0, 1.0);
      y2 = y2.clamp(0.0, 1.0);

      // Map from model input space (inputWidth x inputHeight) to original image
      double left = (x1 * inputWidth - imageInfo.padX) / imageInfo.scale;
      double top = (y1 * inputHeight - imageInfo.padY) / imageInfo.scale;
      double right = (x2 * inputWidth - imageInfo.padX) / imageInfo.scale;
      double bottom = (y2 * inputHeight - imageInfo.padY) / imageInfo.scale;

      left = left.clamp(0.0, imageInfo.originalWidth.toDouble());
      top = top.clamp(0.0, imageInfo.originalHeight.toDouble());
      right = right.clamp(0.0, imageInfo.originalWidth.toDouble());
      bottom = bottom.clamp(0.0, imageInfo.originalHeight.toDouble());

      if (right > left + 5 && bottom > top + 5) {
        detections.add(Detection(
          confidence: confidence,
          box: Rect.fromLTRB(left, top, right, bottom),
        ));
      }
    }

    if (maxConf > 0 || detectionsFound > 0) {
      print("=== YOLO DEBUG ===");
      print("Max confidence: $maxConf");
      print("Detections above threshold: $detectionsFound");
      print("Final detections: ${detections.length}");
      print("==================");
    }
    return detections;
  }
}