#!/usr/bin/env python3
"""
Simple Flask API Server for AI Boat System
"""

from flask import Flask, request, jsonify
from flask_cors import CORS
from datetime import datetime
import json
import os
import sys

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes

# Store latest data
latest_sensor_data = {
    "ph": 7.0,
    "temperature": 25.0,
    "tds": 250,
    "turbidity": 5.0,
    "distance": 1.0,
    "red": 100,
    "green": 100,
    "blue": 100,
    "clear": 100,
    "water_type": "Unknown",
    "timestamp": ""
}

latest_prediction = {
    "fish": "None",
    "confidence": 0,
    "water_type": "Unknown",
    "survivable": [],
    "sensitive": [],
    "ph": 7.0,
    "tds": 250,
    "timestamp": ""
}

current_mode = "normal"

# ============================================================
# ROUTES
# ============================================================

@app.route('/health', methods=['GET'])
def health_check():
    """Health check endpoint"""
    return jsonify({
        "status": "online",
        "timestamp": datetime.now().isoformat(),
        "mode": current_mode,
        "server": "Flask API v2.0"
    })

@app.route('/api/data', methods=['GET'])
def get_sensor_data():
    """Get latest sensor data"""
    return jsonify(latest_sensor_data)

@app.route('/api/data', methods=['POST'])
def post_sensor_data():
    """Receive sensor data from Pi"""
    global latest_sensor_data
    try:
        data = request.json
        latest_sensor_data.update(data)
        latest_sensor_data['timestamp'] = datetime.now().isoformat()
        print(f"[DATA] Received: pH={latest_sensor_data['ph']}, Temp={latest_sensor_data['temperature']}C")
        return jsonify({"status": "received", "timestamp": latest_sensor_data['timestamp']})
    except Exception as e:
        print(f"[ERROR] Failed to process data: {e}")
        return jsonify({"status": "error", "message": str(e)}), 500

@app.route('/api/prediction', methods=['GET'])
def get_prediction():
    """Get latest AI prediction"""
    return jsonify(latest_prediction)

@app.route('/api/prediction', methods=['POST'])
def post_prediction():
    """Receive AI prediction from Pi"""
    global latest_prediction
    try:
        data = request.json
        latest_prediction.update(data)
        latest_prediction['timestamp'] = datetime.now().isoformat()
        print(f"[PREDICTION] Fish: {latest_prediction['fish']}, Confidence: {latest_prediction['confidence']}%")
        return jsonify({"status": "received"})
    except Exception as e:
        print(f"[ERROR] Failed to process prediction: {e}")
        return jsonify({"status": "error", "message": str(e)}), 500

@app.route('/api/mode', methods=['GET'])
def get_mode():
    """Get current system mode"""
    return jsonify({"mode": current_mode})

@app.route('/api/mode', methods=['POST'])
def set_mode():
    """Set system mode"""
    global current_mode
    try:
        data = request.json
        current_mode = data.get('mode', 'normal')
        print(f"[MODE] Changed to: {current_mode}")
        return jsonify({"status": "changed", "mode": current_mode})
    except Exception as e:
        print(f"[ERROR] Failed to change mode: {e}")
        return jsonify({"status": "error", "message": str(e)}), 500

@app.route('/api/command', methods=['POST'])
def handle_command():
    """Handle commands from dashboard"""
    try:
        data = request.json
        command = data.get('command')
        print(f"[COMMAND] Received: {command}")
        return jsonify({"status": "command_received", "command": command})
    except Exception as e:
        print(f"[ERROR] Failed to handle command: {e}")
        return jsonify({"status": "error", "message": str(e)}), 500

# ============================================================
# MAIN
# ============================================================

if __name__ == '__main__':
    print("=" * 50)
    print("🚤 AI BOAT FLASK API SERVER")
    print("=" * 50)
    print(f"📍 Running on: http://0.0.0.0:5000")
    print(f"📡 Health check: http://0.0.0.0:5000/health")
    print(f"📊 Data endpoint: http://0.0.0.0:5000/api/data")
    print("=" * 50)
    
    # Run the server
    app.run(host='0.0.0.0', port=5000, debug=False, threaded=True)