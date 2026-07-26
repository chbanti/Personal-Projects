#!/usr/bin/env python3
"""
AI BOAT SYSTEM — RASPBERRY PI
INTEGRATED WITH FLASK API & STREAMLIT DASHBOARD
WITH DYNAMIC IP DISPLAY ON OLED
============================================================
NOTE: The TCS230 color sensor cannot be trusted to reliably
auto-classify water type. Water type (Clear / Algae / Muddy /
Contaminated) is instead selected manually via the gamepad D-pad
(left navigator) at the start of AI Mode and Dataset Mode:
    D-pad UP    -> Clear
    D-pad DOWN  -> Contaminated
    D-pad LEFT  -> Algae
    D-pad RIGHT -> Muddy
The system waits up to 5 seconds for a D-pad press; if none is made,
it defaults to "Clear".
============================================================
"""

import os
import sys
import math
import time
import json
import threading
import requests
import socket
import subprocess
from datetime import datetime
from collections import deque

import pandas as pd
import numpy as np
import joblib

import RPi.GPIO as GPIO
import board
import busio

from gpiozero import PWMOutputDevice, OutputDevice, DistanceSensor
from inputs import get_gamepad

from PIL import Image, ImageDraw, ImageFont

# ============================================================
# OLED DISPLAY SETUP (IMPROVED)
# ============================================================

# Try to import OLED libraries
try:
    import adafruit_ssd1306
    OLED_AVAILABLE = True
    print("[INFO] OLED library available")
except ImportError:
    OLED_AVAILABLE = False
    print("[WARNING] OLED library not available")

# Try to import ADC sensors
try:
    import adafruit_ads1x15.ads1115 as ADS
    from adafruit_ads1x15.analog_in import AnalogIn
    ADC_AVAILABLE = True
    print("[INFO] ADC library available")
except ImportError:
    ADC_AVAILABLE = False
    print("[WARNING] ADC library not available")

# ============================================================
# CONFIGURATION
# ============================================================

# Flask API endpoint
FLASK_API_URL = "http://127.0.0.1:5000"

# Project paths
PROJECT_DIR = "/home/salamat/fish_project"
MODEL_PATH = f"{PROJECT_DIR}/lgbm_fish_model.pkl"
SCALER_PATH = f"{PROJECT_DIR}/scaler.pkl"
ENCODER_PATH = f"{PROJECT_DIR}/label_encoder_fish.pkl"

# Pond configuration
POND_ID = 1
FISH_SPECIES = "Tengra"

# Mode durations
AI_MODE_DURATION = 30
DATASET_MODE_DURATION = 30

# GPIO warnings off
GPIO.setwarnings(False)

# ============================================================
# IP ADDRESS FUNCTIONS
# ============================================================

def get_ip_address():
    """Get current Raspberry Pi IP address"""
    try:
        # Method 1: Get active network IP
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(("8.8.8.8", 80))
        ip = s.getsockname()[0]
        s.close()
        if ip and ip != "0.0.0.0":
            return ip
    except:
        pass
    
    try:
        # Method 2: Use hostname command
        result = subprocess.run(['hostname', '-I'], capture_output=True, text=True, timeout=2)
        output = result.stdout.strip()
        if output:
            ips = output.split()
            for ip in ips:
                if ip and not ip.startswith('127.'):
                    return ip
    except:
        pass
    
    return "No IP"

# Global IP variable with lock for thread-safe updates
current_ip = get_ip_address()
ip_lock = threading.Lock()

# ============================================================
# I2C & ADC SETUP
# ============================================================

i2c = None
ads = None
ph_channel = turbidity_channel = tds_channel = temp_channel = None
I2C_WORKING = False

try:
    i2c = busio.I2C(board.SCL, board.SDA)
    if ADC_AVAILABLE:
        ads = ADS.ADS1115(i2c)
        ph_channel = AnalogIn(ads, 0)
        turbidity_channel = AnalogIn(ads, 1)
        tds_channel = AnalogIn(ads, 2)
        temp_channel = AnalogIn(ads, 3)
        I2C_WORKING = True
        print("[I2C] ADS1115 initialized successfully")
    else:
        print("[I2C] ADC library not available, using simulation mode")
except Exception as e:
    print(f"[I2C ERROR] {e}")
    print("[I2C] Running in simulation mode")

# ============================================================
# OLED DISPLAY SETUP
# ============================================================

oled = None
oled_width = 128
oled_height = 64

if OLED_AVAILABLE and I2C_WORKING:
    try:
        oled = adafruit_ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)
        # Clear display
        oled.fill(0)
        oled.show()
        
        # Create image buffers
        display_image = Image.new("1", (oled_width, oled_height))
        display_draw = ImageDraw.Draw(display_image)
        
        # Try to load better fonts
        try:
            font_small = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 10)
            font_medium = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 12)
            font_large = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 20)
            print("[OLED] Fonts loaded successfully")
        except:
            font_small = font_medium = font_large = ImageFont.load_default()
            print("[OLED] Using default font")
        
        print("[OLED] Display initialized successfully")
    except Exception as e:
        print(f"[OLED ERROR] {e}")
        oled = None

# OLED display buffer
oled_lines = ["STARTING", "Loading sensors...", "Please wait", ""]
oled_lock = threading.Lock()
oled_update_counter = 0

def update_oled(lines):
    """Thread-safe OLED update"""
    global oled_lines
    with oled_lock:
        oled_lines = lines[:4]

def refresh_oled():
    """Refresh OLED hardware with current IP"""
    global oled_update_counter
    
    if oled is None:
        # Console fallback mode
        with oled_lock:
            lines = oled_lines.copy()
        oled_update_counter += 1
        if oled_update_counter % 10 == 0:
            print(f"[OLED] {lines[0]} | {lines[1]} | {lines[2]} | {lines[3]}")
        return
    
    try:
        with oled_lock:
            lines = oled_lines.copy()
        
        # Get current IP (thread-safe)
        with ip_lock:
            ip = current_ip
        
        # Clear image
        display_draw.rectangle((0, 0, oled_width-1, oled_height-1), outline=0, fill=0)
        
        # Draw IP address on first line (always)
        display_draw.text((0, 0), f"IP:{ip}", font=font_small, fill=255)
        
        # Draw separator line after IP
        display_draw.line((0, 10, oled_width-1, 10), fill=255, width=1)
        
        # Draw remaining lines (max 3 lines below IP)
        y_positions = [14, 30, 46]
        for i, line in enumerate(lines[:3]):
            if i < len(y_positions) and line:
                # Truncate long lines
                if len(line) > 21:
                    line = line[:18] + "..."
                display_draw.text((0, y_positions[i]), line, font=font_medium, fill=255)
        
        # Draw separator lines between sections
        for y in [28, 44]:
            display_draw.line((0, y, oled_width-1, y), fill=255, width=1)
        
        # Send to display
        oled.image(display_image)
        oled.show()
        
    except Exception as e:
        print(f"[OLED REFRESH ERROR] {e}")

def show_splash_screen():
    """Show splash screen on startup"""
    update_oled([
        "AI BOAT SYS",
        f"Started: {datetime.now().strftime('%H:%M:%S')}",
        "Initializing..."
    ])
    refresh_oled()
    time.sleep(2)

def show_ready_screen():
    """Show ready screen with controls"""
    update_oled([
        "SYSTEM READY",
        "RB=AI  LB=DATA",
        "A=MOTOR  B/Y=STEER",
        "START=RESET"
    ])
    refresh_oled()

def show_sensor_page():
    """Show sensor data page"""
    update_oled([
        "WATER QUALITY",
        f"pH: {sensor_data['ph']:.2f}",
        f"Temp: {sensor_data['temperature']:.1f}C",
        f"TDS: {sensor_data['tds']:.0f}ppm"
    ])
    refresh_oled()

def show_boat_status_page():
    """Show boat status page"""
    motor_status = "ON" if motor_running else "OFF"
    update_oled([
        "BOAT STATUS",
        f"Motor: {motor_status}",
        f"Water: {sensor_data['water_type']}",
        f"Dist: {sensor_data['distance']:.2f}m"
    ])
    refresh_oled()

def show_ai_progress(elapsed, total, samples):
    """Show AI mode progress"""
    percent = int((elapsed / total) * 100)
    remaining = total - elapsed
    mins = int(remaining // 60)
    secs = int(remaining % 60)
    
    # Create progress bar
    bar_length = 20
    filled = int(bar_length * percent / 100)
    bar = "[" + "#" * filled + "-" * (bar_length - filled) + "]"
    
    update_oled([
        "AI MODE ACTIVE",
        f"Time: {mins:02d}:{secs:02d}",
        f"Samples: {samples}",
        f"{bar} {percent}%"
    ])
    refresh_oled()

def show_dataset_progress(elapsed, total, samples):
    """Show dataset collection progress"""
    percent = int((elapsed / total) * 100)
    remaining = total - elapsed
    mins = int(remaining // 60)
    secs = int(remaining % 60)
    
    # Create progress bar
    bar_length = 20
    filled = int(bar_length * percent / 100)
    bar = "[" + "#" * filled + "-" * (bar_length - filled) + "]"
    
    update_oled([
        "DATASET MODE",
        f"Time: {mins:02d}:{secs:02d}",
        f"Samples: {samples}",
        f"{bar} {percent}%"
    ])
    refresh_oled()

def show_ai_result_screen():
    """Show AI prediction results with cycling"""
    global result_page, last_result_switch
    
    if time.time() - last_result_switch > 4:
        result_page = (result_page + 1) % 3
        last_result_switch = time.time()
    
    if result_page == 0:
        update_oled([
            "AI PREDICTION",
            f"Fish: {ai_result['fish']}",
            f"Conf: {ai_result['confidence']}%",
            f"Water: {ai_result['water_type']}"
        ])
    elif result_page == 1:
        fish_list = ", ".join(ai_result["survivable"][:1])
        update_oled([
            "SURVIVABLE",
            f"{fish_list[:18]}",
            f"pH: {ai_result['ph']:.1f}",
            "Good for pond"
        ])
    else:
        fish_list = ", ".join(ai_result["sensitive"][:1])
        update_oled([
            "SENSITIVE",
            f"{fish_list[:18]}",
            "NOT",
            "Recommended"
        ])
    refresh_oled()

def show_error_message(error):
    """Show error message on OLED"""
    update_oled([
        "ERROR",
        f"{error[:20]}",
        "Check logs",
        ""
    ])
    refresh_oled()
    time.sleep(2)

# ============================================================
# TCS230 RGB COLOR SENSOR — DISABLED (HARDWARE NOT WORKING)
# ============================================================
# The physical color sensor is not functioning reliably, so it is
# no longer initialized or read at all. Water type is entered
# manually by the user via the gamepad D-pad instead — see
# capture_water_type_selection(). No GPIO setup, no read attempts,
# and no sensor-error output happen for this sensor anywhere in the
# system or on the dashboard.

GPIO.setmode(GPIO.BCM)

COLOR_SENSOR_AVAILABLE = False

# ============================================================
# MOTOR & SERVO
# ============================================================

try:
    motor = OutputDevice(5)
    motor_running = False
    print("[MOTOR] Initialized")
except Exception as e:
    print(f"[MOTOR ERROR] {e}")
    class MockMotor:
        def on(self): pass
        def off(self): pass
    motor = MockMotor()
    motor_running = False

try:
    servo = PWMOutputDevice(13, frequency=50)
    SERVO_CENTER, SERVO_LEFT, SERVO_RIGHT = 8.5, 6.1, 10.9
    current_servo = SERVO_CENTER
    print("[SERVO] Initialized")
except Exception as e:
    print(f"[SERVO ERROR] {e}")
    class MockServo:
        def __init__(self): pass
        def on(self): pass
        def off(self): pass
    servo = MockServo()
    SERVO_CENTER, SERVO_LEFT, SERVO_RIGHT = 8.5, 6.1, 10.9
    current_servo = SERVO_CENTER

def set_servo(duty):
    global current_servo
    if current_servo == duty:
        return
    current_servo = duty
    try:
        servo.value = duty / 100.0
    except:
        pass
    time.sleep(0.15)

set_servo(SERVO_CENTER)

# ============================================================
# ULTRASONIC SENSOR
# ============================================================

try:
    ultrasonic = DistanceSensor(echo=24, trigger=23, max_distance=4, threshold_distance=0.3)
    print("[ULTRASONIC] Initialized")
except Exception as e:
    print(f"[ULTRASONIC ERROR] {e}")
    class MockUltrasonic:
        distance = 1.0
    ultrasonic = MockUltrasonic()

# ============================================================
# LOAD ML MODELS
# ============================================================

model = None
scaler = None
fish_encoder = None

def load_ml_models():
    """Load machine learning models"""
    global model, scaler, fish_encoder
    try:
        if os.path.exists(MODEL_PATH):
            model = joblib.load(MODEL_PATH)
            print(f"[ML] Model loaded")
        else:
            print(f"[ML] Model not found at {MODEL_PATH}")
        
        if os.path.exists(SCALER_PATH):
            scaler = joblib.load(SCALER_PATH)
            print(f"[ML] Scaler loaded")
        
        if os.path.exists(ENCODER_PATH):
            fish_encoder = joblib.load(ENCODER_PATH)
            print(f"[ML] Label encoder loaded")
    except Exception as e:
        print(f"[ML] Error loading models: {e}")

# ============================================================
# FISH TOLERANCE TABLE
# ============================================================

# FISH TOLERANCE TABLE (Updated from dataset image)
FISH_TOLERANCE = {
    "Tilapia": 5,
    "Carp": 4,
    "Pangasius": 5,
    "Bata": 4,
    "Rohu": 3,
    "Prawn": 3,
    "Singhara": 4,
    "Wallago Catfish": 2,
    "Silver Carp": 2,
    "Grass Carp": 4,
    "Mrigal": 4,
    "Bighead Carp": 4,
    "Kalbasu": 4,
    "Catla": 2,
    "Tengra": 4
}

# SENSOR VALIDATION LIMITS — used for pond suitability checking.
# Red/Green/Blue/Clear were removed since the color sensor is
# disabled and no longer produces real readings.
SENSOR_LIMITS = {
    "pH": (6.0, 8.5),
    "Temperature": (15.0, 38.0),
    "Turbidity": (0.5, 14.0),
    "Distance": (0.1, 5.5),
    "TDS": (50, 900)
}

WATER_ENCODING = {
    "Clear": 1, "Algae": 0, "Muddy": 3, "Contaminated": 2
}

def check_pond_suitability(avg_data):
    """
    Check whether averaged sensor readings fall within SENSOR_LIMITS.

    Returns (is_suitable, violations).
    - is_suitable: True only if every sensor reading is within range.
    - violations: a list of dicts, one per out-of-range sensor, e.g.
        {"sensor": "pH", "value": 9.2, "min": 6.0, "max": 8.5}
      Empty list when is_suitable is True.
    """
    checks = {
        "pH": avg_data.get("ph"),
        "Temperature": avg_data.get("temperature"),
        "Turbidity": avg_data.get("turbidity"),
        "Distance": avg_data.get("distance"),
        "TDS": avg_data.get("tds")
    }

    violations = []
    for key, value in checks.items():
        if value is None:
            continue
        low, high = SENSOR_LIMITS[key]
        if value < low or value > high:
            violations.append({
                "sensor": key,
                "value": round(float(value), 2),
                "min": low,
                "max": high
            })

    return (len(violations) == 0), violations

# ============================================================
# GLOBAL DATA STORAGE
# ============================================================

# Current sensor readings
sensor_data = {
    "ph": 0.0,
    "temperature": 0.0,
    "tds": 0.0,
    "turbidity": 0.0,
    "distance": 0.0,
    "water_type": "Unknown"  # entered manually via gamepad D-pad — see capture_water_type_selection()
}

# AI result storage
ai_result = {
    "fish": "None",
    "confidence": 0,
    "water_type": "Unknown",
    "survivable": [],
    "sensitive": [],
    "ph": 0.0,
    "tds": 0.0,
    "temperature": 0.0,
    "turbidity": 0.0,
    "distance": 0.0,
    "out_of_range": []  # list of {"sensor", "value", "min", "max"} when pond is unsuitable
}

# System state
current_mode = "normal"
ai_active = False
dataset_active = False
cancel_flag = False
display_page = 0
result_page = 0
last_page_switch = time.time()
last_result_switch = time.time()

# Data buffers
ai_data_buffer = []
dataset_data_buffer = []

# ------------------------------------------------------------
# MANUAL WATER TYPE SELECTION (via gamepad D-pad / left navigator)
# ------------------------------------------------------------
# The TCS230 color sensor cannot be trusted to reliably auto-classify
# water type, so classification is done manually by the user via the
# gamepad D-pad instead:
#   D-pad UP    -> Clear
#   D-pad DOWN  -> Contaminated
#   D-pad LEFT  -> Algae
#   D-pad RIGHT -> Muddy
# water_type_selection["value"] holds the most recent manual pick;
# water_type_selection["timestamp"] records when it was made so that
# capture_water_type_selection() can tell whether a pick happened
# *during* its 5-second waiting window.
water_type_selection = {"value": None, "timestamp": 0.0}
water_type_lock = threading.Lock()

# RGB smoothing


# ============================================================
# SENSOR CONVERSION FUNCTIONS
# ============================================================

def voltage_to_ph(voltage):
    """Convert ADC voltage to pH value (0-14) with proper calibration"""
    if not I2C_WORKING:
        # Simulation mode - generate realistic data around 7.0
        return round(6.8 + math.sin(time.time() / 30) * 0.5, 2)
    
    try:
        # pH sensor calibration formula
        # For most pH sensors: pH = 7 + (2.5 - voltage) * (pH_range / voltage_range)
        # Standard formula: pH = 7 - (voltage - 2.5) * (14 / 5)
        
        # Method 1: Standard formula (adjust multiplier as needed)
        ph = 7.0 - (voltage - 2.5) * 2.8
        
        # Method 2: If you have calibration points, use this:
        # ph = 7.0 + (voltage - 2.5) * 5.6  # Adjust multiplier based on your sensor
        
        # Clamp to valid range
        ph = max(0.0, min(14.0, ph)) + 1.6
        
        return round(ph, 2)
        
    except Exception as e:
        print(f"[PH ERROR] {e}")
        return 7.0  # Return neutral pH on error

def voltage_to_turbidity(voltage):
    """Convert voltage to turbidity (NTU)"""
    if not I2C_WORKING:
        return round(3.0 + math.sin(time.time() / 20) * 2, 2)
    try:
        turb = (1.5 - voltage) * 10
        return round(max(0.5, min(16.0, turb)), 2)
    except:
        return 5.0

def voltage_to_tds(voltage):
    """Convert voltage to TDS (ppm)"""
    if not I2C_WORKING:
        return round(250 + math.sin(time.time() / 25) * 50, 2)
    try:
        tds = voltage * 500
        return round(max(50.0, min(1000.0, tds)), 2)
    except:
        return 300.0

def voltage_to_temperature(voltage):
    """Convert NTC thermistor voltage to temperature (°C)"""
    if not I2C_WORKING:
        return round(25.0 + math.sin(time.time() / 15) * 3, 1)
    try:
        R_FIXED, VCC, BETA, R0, T0 = 4700, 3.3, 3950, 15000, 298.15
        r_ntc = R_FIXED * ((VCC / voltage) - 1)
        temp_k = 1.0 / ((1.0 / T0) + (1.0 / BETA) * math.log(r_ntc / R0))
        return round(temp_k - 273.15, 1)
    except:
        return 25.0

def detect_water_type(turbidity, r, g, b, c):
    """
    [DEPRECATED / UNRELIABLE]
    Auto-classify water type from turbidity + RGB color readings.

    NOTE: The TCS230 color sensor has proven unreliable for automatic
    classification, so this function is no longer called anywhere in
    the system. Water type is now selected manually by the user via
    the gamepad D-pad — see capture_water_type_selection() below.
    Kept here only for reference / possible future use once the
    sensor issue is resolved.
    """
    if turbidity <= 3 and c > 200:
        return "Clear"
    elif g > r and g > b:
        return "Algae"
    elif r > g and r > b:
        return "Muddy"
    else:
        return "Contaminated"

def capture_water_type_selection(timeout=5):
    """
    Determine the water type to use for this AI Mode / Dataset Mode
    session, based on the gamepad D-pad (left navigator):
        UP    -> Clear
        DOWN  -> Contaminated
        LEFT  -> Algae
        RIGHT -> Muddy

    IMPORTANT: this uses whatever selection is CURRENTLY live on the
    gamepad — the same value already shown on the OLED / dashboard —
    rather than requiring a brand new press at the exact moment the
    mode starts. That keeps the dashboard's live water type and the
    value actually used for prediction/data collection in sync.

    - If a selection has already been made at any point (even before
      this mode started), that value is used immediately.
    - Only if NO selection has ever been made does this function wait
      up to `timeout` seconds for a first D-pad press, defaulting to
      "Clear" if nothing arrives in that window.
    """
    with water_type_lock:
        current_value = water_type_selection["value"]

    if current_value is not None:
        print(f"[WATER TYPE] Using current gamepad D-pad selection: {current_value}")
        return current_value

    # No selection has ever been made yet — wait briefly for a first pick
    start_time = time.time()

    update_oled([
        "SELECT WATER",
        "Up=Clear Dn=Contam",
        "Lt=Algae Rt=Muddy",
        f"Waiting {timeout}s..."
    ])
    refresh_oled()

    while time.time() - start_time < timeout:
        with water_type_lock:
            sel_value = water_type_selection["value"]

        if sel_value is not None:
            print(f"[WATER TYPE] Selected via gamepad D-pad: {sel_value}")
            return sel_value

        time.sleep(0.1)

    print("[WATER TYPE] No gamepad input received within "
          f"{timeout}s, defaulting to 'Clear'")
    return "Clear"

# ============================================================
# COLOR SENSOR FUNCTIONS — REMOVED
# ============================================================
# The color sensor read/convert/smoothing functions that used to
# live here (read_frequency, read_red/green/blue, frequency_to_rgb,
# smooth_rgb_values) have been removed entirely. The sensor is not
# working, so nothing in this system attempts to read it anymore.
# Water type is entered manually — see capture_water_type_selection().

# ============================================================
# FLASK API COMMUNICATION
# ============================================================

def send_to_flask(endpoint, data):
    """Send data to Flask API (non-blocking)"""
    try:
        response = requests.post(f"{FLASK_API_URL}{endpoint}", json=data, timeout=1)
        return response.status_code == 200
    except:
        return False

def send_sensor_data():
    """Send current sensor readings to Flask API"""
    data = {
        "ph": sensor_data["ph"],
        "temperature": sensor_data["temperature"],
        "tds": sensor_data["tds"],
        "turbidity": sensor_data["turbidity"],
        "distance": sensor_data["distance"],
        "water_type": sensor_data["water_type"],
        "timestamp": datetime.now().isoformat()
    }
    return send_to_flask("/api/data", data)

def send_prediction():
    """Send AI prediction to Flask API"""
    return send_to_flask("/api/prediction", ai_result)

def send_mode():
    """Send current mode to Flask API"""
    return send_to_flask("/api/mode", {"mode": current_mode})

# ============================================================
# THREAD 1: SENSOR READING THREAD
# ============================================================

def sensor_reading_thread():
    """Read all sensors continuously"""
    while True:
        try:
            if I2C_WORKING and ADC_AVAILABLE:
                ph_voltage = ph_channel.voltage
                turb_voltage = turbidity_channel.voltage
                tds_voltage = tds_channel.voltage
                temp_voltage = temp_channel.voltage
                
                sensor_data["ph"] = voltage_to_ph(ph_voltage)
                sensor_data["temperature"] = voltage_to_temperature(temp_voltage)
                sensor_data["tds"] = voltage_to_tds(tds_voltage)
                sensor_data["turbidity"] = voltage_to_turbidity(turb_voltage)
            else:
                sensor_data["ph"] = voltage_to_ph(0)
                sensor_data["temperature"] = voltage_to_temperature(0)
                sensor_data["tds"] = voltage_to_tds(0)
                sensor_data["turbidity"] = voltage_to_turbidity(0)
            
            try:
                sensor_data["distance"] = round(ultrasonic.distance, 2)
            except:
                sensor_data["distance"] = 1.0 + math.sin(time.time()) * 0.5
            
            # Water type is no longer auto-detected from the color
            # sensor (unreliable) — it reflects whatever the user last
            # selected on the gamepad D-pad, defaulting to "Clear".
            with water_type_lock:
                current_selection = water_type_selection["value"]
            sensor_data["water_type"] = current_selection if current_selection else "Clear"
            
        except Exception as e:
            print(f"[SENSOR ERROR] {e}")
        
        time.sleep(0.5)

# ============================================================
# THREAD 2: IP MONITOR THREAD
# ============================================================
# (The color sensor polling thread has been removed entirely — the
# sensor is disabled and never read. Water type is
# selected manually via the gamepad D-pad instead.)

def ip_monitor_thread():
    """Monitor IP address changes and update display"""
    global current_ip
    last_ip = current_ip
    
    while True:
        time.sleep(5)  # Check every 5 seconds
        new_ip = get_ip_address()
        
        if new_ip != last_ip:
            print(f"[IP MONITOR] IP changed from {last_ip} to {new_ip}")
            last_ip = new_ip
            with ip_lock:
                current_ip = new_ip
            
            # Force OLED refresh to show new IP
            if oled:
                refresh_oled()

# ============================================================
# THREAD 4: OLED DISPLAY THREAD
# ============================================================

def oled_display_thread():
    """Update OLED display - IP always shown on first line"""
    global display_page, last_page_switch, ai_active, dataset_active
    global ai_start_time, ds_start_time
    
    ai_start_time = 0
    ds_start_time = 0
    
    while True:
        try:
            if oled is None:
                time.sleep(1)
                continue
            
            if ai_active:
                if ai_start_time == 0:
                    ai_start_time = time.time()
                elapsed = time.time() - ai_start_time
                percent = int((elapsed / AI_MODE_DURATION) * 100)
                remaining = AI_MODE_DURATION - elapsed
                mins = int(remaining // 60)
                secs = int(remaining % 60)
                
                bar_length = 20
                filled = int(bar_length * percent / 100)
                bar = "[" + "#" * filled + "-" * (bar_length - filled) + "]"
                
                update_oled([
                    f"AI MODE",
                    f"Time: {mins:02d}:{secs:02d}",
                    f"Samples: {len(ai_data_buffer)}",
                    f"{bar} {percent}%"
                ])
            
            elif dataset_active:
                if ds_start_time == 0:
                    ds_start_time = time.time()
                elapsed = time.time() - ds_start_time
                percent = int((elapsed / DATASET_MODE_DURATION) * 100)
                remaining = DATASET_MODE_DURATION - elapsed
                mins = int(remaining // 60)
                secs = int(remaining % 60)
                
                bar_length = 20
                filled = int(bar_length * percent / 100)
                bar = "[" + "#" * filled + "-" * (bar_length - filled) + "]"
                
                update_oled([
                    f"DATASET",
                    f"Time: {mins:02d}:{secs:02d}",
                    f"Samples: {len(dataset_data_buffer)}",
                    f"{bar} {percent}%"
                ])
            
            elif ai_result["fish"] != "None" and not ai_active:
                if time.time() - last_result_switch > 5:
                    result_page = (result_page + 1) % 3
                    last_result_switch = time.time()
                
                if result_page == 0:
                    update_oled([
                        f"RESULT",
                        f"Fish: {ai_result['fish']}",
                        f"Conf: {ai_result['confidence']}%",
                        f"Water: {ai_result['water_type']}"
                    ])
                elif result_page == 1:
                    fish_list = ", ".join(ai_result["survivable"][:1])
                    update_oled([
                        f"SURVIVABLE",
                        f"{fish_list[:18]}",
                        f"pH: {ai_result['ph']:.1f}",
                        "Good for pond"
                    ])
                else:
                    fish_list = ", ".join(ai_result["sensitive"][:1])
                    update_oled([
                        f"SENSITIVE",
                        f"{fish_list[:18]}",
                        "NOT",
                        "Recommended"
                    ])
            
            else:
                if time.time() - last_page_switch > 8:
                    display_page = (display_page + 1) % 2
                    last_page_switch = time.time()
                
                if display_page == 0:
                    update_oled([
                        f"WATER",
                        f"pH: {sensor_data['ph']:.2f}",
                        f"Temp: {sensor_data['temperature']:.1f}C",
                        f"TDS: {sensor_data['tds']:.0f}ppm"
                    ])
                else:
                    motor_status = "ON" if motor_running else "OFF"
                    update_oled([
                        f"BOAT",
                        f"Motor: {motor_status}",
                        f"Water: {sensor_data['water_type']}",
                        f"Dist: {sensor_data['distance']:.2f}m"
                    ])
            
            refresh_oled()
            
        except Exception as e:
            print(f"[OLED ERROR] {e}")
        
        time.sleep(0.25)

# ============================================================
# THREAD 5: FLASK SENDER THREAD
# ============================================================

def flask_sender_thread():
    """Send data to Flask API periodically"""
    last_mode = ""
    
    while True:
        try:
            send_sensor_data()
            
            if current_mode != last_mode:
                send_mode()
                last_mode = current_mode
            
        except Exception as e:
            print(f"[FLASK ERROR] {e}")
        
        time.sleep(2)

# ============================================================
# THREAD 6: AI MODE THREAD
# ============================================================

def ai_mode_thread():
    """Collect data and run AI prediction"""
    global ai_active, cancel_flag, ai_result, current_mode, ai_data_buffer
    
    while True:
        while not ai_active:
            time.sleep(0.1)
        
        print("[AI MODE] Started")
        current_mode = "ai"
        send_mode()
        
        # Water type can no longer be trusted from the color sensor,
        # so ask the user to pick it manually on the gamepad D-pad.
        # Waits up to 5s, defaults to "Clear" if nothing is pressed.
        selected_water_type = capture_water_type_selection(timeout=5)
        sensor_data["water_type"] = selected_water_type
        
        ai_data_buffer = []
        start_time = time.time()
        
        while time.time() - start_time < AI_MODE_DURATION:
            if cancel_flag:
                print("[AI MODE] Cancelled")
                cancel_flag = False
                break
            
            data_point = {
                "ph": sensor_data["ph"],
                "temperature": sensor_data["temperature"],
                "tds": sensor_data["tds"],
                "turbidity": sensor_data["turbidity"],
                "distance": sensor_data["distance"]
            }
            ai_data_buffer.append(data_point)
            time.sleep(1)
        
        if not cancel_flag and len(ai_data_buffer) > 0:
            print(f"[AI MODE] Analyzing {len(ai_data_buffer)} samples...")
            
            df = pd.DataFrame(ai_data_buffer)
            avg = df.mean()
            
            # Water type for this session was chosen manually above —
            # no longer derived from the (unreliable) color sensor.
            water_type = selected_water_type

            # --------------------------------------------------
            # POND SUITABILITY CHECK
            # If any averaged sensor reading falls outside the
            # acceptable SENSOR_LIMITS range, the pond is marked
            # unsuitable for any fish and prediction is skipped.
            # --------------------------------------------------
            is_suitable, violations = check_pond_suitability(avg)

            if not is_suitable:
                violation_summary = ", ".join(
                    f"{v['sensor']}={v['value']} (allowed {v['min']}-{v['max']})"
                    for v in violations
                )
                print(f"[AI MODE] Pond is not suitable for any fish - {violation_summary}")

                ai_result = {
                    "fish": "None",
                    "confidence": 0,
                    "water_type": water_type,
                    "survivable": [],
                    "sensitive": [],
                    "ph": round(avg["ph"], 2),
                    "tds": round(avg["tds"], 2),
                    "temperature": round(avg["temperature"], 2),
                    "turbidity": round(avg["turbidity"], 2),
                    "distance": round(avg["distance"], 2),
                    "out_of_range": violations
                }
                send_prediction()

                # Show the pond is unsuitable plus which sensor triggered it first
                first_violation = violations[0]
                update_oled([
                    "WARNING",
                    "Not suitable",
                    f"{first_violation['sensor']}: {first_violation['value']}",
                    f"({len(violations)} sensor(s) OOR)"
                ])
                refresh_oled()
                time.sleep(3)

            elif model and scaler and fish_encoder:
                try:
                    water_encoded = WATER_ENCODING.get(water_type, 2)

                    # The pretrained model/scaler still expect
                    # Red/Green/Blue/Clear columns. Since the color
                    # sensor is disabled and never read, fixed neutral
                    # placeholder values are sent here ONLY so the
                    # existing model doesn't break — they are not
                    # measured, not displayed, and not used for any
                    # suitability checks. Retrain the model without
                    # these columns to remove this placeholder.
                    input_df = pd.DataFrame([{
                        "pH": avg["ph"],
                        "Temperature": avg["temperature"],
                        "Turbidity": avg["turbidity"],
                        "Ultrasonic": avg["distance"],
                        "TDS": avg["tds"],
                        "Red": 0,
                        "Green": 0,
                        "Blue": 0,
                        "Clear": 0,
                        "water_encoded": water_encoded,
                        "Pond_ID": POND_ID
                    }])
                    
                    scaled = scaler.transform(input_df)
                    prediction = model.predict(scaled)[0]
                    fish_name = fish_encoder.inverse_transform([prediction])[0]
                    
                    confidence = 85 + int(abs(avg["ph"] - 7.0) * 5)
                    confidence = min(98, max(70, confidence))
                    
                    pred_level = FISH_TOLERANCE.get(fish_name, 3)
                    survivable = [f for f, lvl in FISH_TOLERANCE.items() if lvl >= pred_level]
                    sensitive = [f for f, lvl in FISH_TOLERANCE.items() if lvl < pred_level]
                    
                    ai_result = {
                        "fish": fish_name,
                        "confidence": confidence,
                        "water_type": water_type,
                        "survivable": survivable[:10],
                        "sensitive": sensitive[:10],
                        "ph": round(avg["ph"], 2),
                        "tds": round(avg["tds"], 2),
                        "temperature": round(avg["temperature"], 2),
                        "turbidity": round(avg["turbidity"], 2),
                        "distance": round(avg["distance"], 2),
                        "out_of_range": []
                    }
                    
                    send_prediction()
                    print(f"[AI MODE] Result: {fish_name} ({confidence}%)")
                    
                except Exception as e:
                    print(f"[AI MODE ERROR] {e}")
                    ai_result = {
                        "fish": "Error",
                        "confidence": 50,
                        "water_type": water_type,
                        "survivable": [],
                        "sensitive": [],
                        "ph": round(avg["ph"], 2),
                        "tds": round(avg["tds"], 2),
                        "temperature": round(avg["temperature"], 2),
                        "turbidity": round(avg["turbidity"], 2),
                        "distance": round(avg["distance"], 2),
                        "out_of_range": []
                    }
            else:
                import random
                fish_list = list(FISH_TOLERANCE.keys())
                fish_name = random.choice(fish_list[:10])

                # Use the same deterministic tolerance-level partition
                # as the real model branch so a fish can never land in
                # both lists. Two independent random.sample() calls
                # (the old approach) could pick the same fish for both
                # "survivable" and "sensitive" — that was the bug.
                pred_level = FISH_TOLERANCE.get(fish_name, 3)
                survivable = [f for f, lvl in FISH_TOLERANCE.items() if lvl >= pred_level]
                sensitive = [f for f, lvl in FISH_TOLERANCE.items() if lvl < pred_level]

                ai_result = {
                    "fish": fish_name,
                    "confidence": random.randint(75, 95),
                    "water_type": water_type,
                    "survivable": survivable[:10],
                    "sensitive": sensitive[:10],
                    "ph": round(avg["ph"], 2),
                    "tds": round(avg["tds"], 2),
                    "temperature": round(avg["temperature"], 2),
                    "turbidity": round(avg["turbidity"], 2),
                    "distance": round(avg["distance"], 2),
                    "out_of_range": []
                }
                send_prediction()
                print(f"[AI MODE DEMO] Result: {fish_name}")
        
        ai_active = False
        cancel_flag = False
        current_mode = "normal"
        send_mode()
        print("[AI MODE] Finished")

# ============================================================
# THREAD 7: DATASET COLLECTION THREAD
# ============================================================

def dataset_collection_thread():
    """Collect data for training dataset"""
    global dataset_active, cancel_flag, current_mode, dataset_data_buffer
    
    while True:
        while not dataset_active:
            time.sleep(0.1)
        
        print("[DATASET MODE] Started")
        current_mode = "collection"
        send_mode()
        
        # Ask the user to manually classify the water type on the
        # gamepad D-pad before logging starts (color sensor is
        # unreliable). Waits up to 5s, defaults to "Clear".
        selected_water_type = capture_water_type_selection(timeout=5)
        sensor_data["water_type"] = selected_water_type
        
        dataset_data_buffer = []
        start_time = time.time()
        
        while time.time() - start_time < DATASET_MODE_DURATION:
            if cancel_flag:
                print("[DATASET MODE] Cancelled")
                cancel_flag = False
                break
            
            data_point = {
                "timestamp": datetime.now().isoformat(),
                "Pond_ID": POND_ID,
                "Fish_Species": FISH_SPECIES,
                "pH": sensor_data["ph"],
                "Temperature": sensor_data["temperature"],
                "TDS": sensor_data["tds"],
                "Turbidity": sensor_data["turbidity"],
                "Distance": sensor_data["distance"],
                "Water_Type": selected_water_type
            }
            dataset_data_buffer.append(data_point)
            time.sleep(1)
        
        if not cancel_flag and len(dataset_data_buffer) > 0:
            os.makedirs(f"{PROJECT_DIR}/datasets", exist_ok=True)
            timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
            filename = f"{PROJECT_DIR}/datasets/pond_{POND_ID}_{timestamp}.csv"
            
            df = pd.DataFrame(dataset_data_buffer)
            df.to_csv(filename, index=False)
            
            print(f"[DATASET MODE] Saved {len(dataset_data_buffer)} rows to {filename}")
            update_oled(["DATASET", "SAVED", f"Rows: {len(dataset_data_buffer)}", ""])
            refresh_oled()
            time.sleep(3)
        
        dataset_active = False
        cancel_flag = False
        current_mode = "normal"
        send_mode()
        print("[DATASET MODE] Finished")

# ============================================================
# THREAD 8: GAMEPAD CONTROLLER THREAD
# ============================================================

def gamepad_controller_thread():
    """Handle USB gamepad input"""
    global motor_running, ai_active, dataset_active, cancel_flag
    global current_mode, ai_result
    
    print("[GAMEPAD] Waiting for controller...")
    
    while True:
        try:
            events = get_gamepad()
            
            for event in events:
                if event.code == "BTN_TR" and event.state == 1:
                    if not ai_active and not dataset_active:
                        print("[GAMEPAD] Starting AI Mode")
                        ai_active = True
                        cancel_flag = False
                        ai_result["fish"] = "None"
                
                elif event.code == "BTN_TL" and event.state == 1:
                    if not ai_active and not dataset_active:
                        print("[GAMEPAD] Starting Dataset Mode")
                        dataset_active = True
                        cancel_flag = False
                
                elif event.code == "BTN_SOUTH" and event.state == 1:
                    motor_running = not motor_running
                    if motor_running:
                        try:
                            motor.on()
                        except:
                            pass
                        print("[GAMEPAD] Motor ON")
                    else:
                        try:
                            motor.off()
                        except:
                            pass
                        print("[GAMEPAD] Motor OFF")
                
                elif event.code == "BTN_EAST":
                    if event.state == 1:
                        set_servo(SERVO_RIGHT)
                        print("[GAMEPAD] Steering RIGHT")
                    else:
                        set_servo(SERVO_CENTER)
                
                elif event.code == "BTN_NORTH":
                    if event.state == 1:
                        set_servo(SERVO_LEFT)
                        print("[GAMEPAD] Steering LEFT")
                    else:
                        set_servo(SERVO_CENTER)
                
                # --------------------------------------------------
                # D-PAD (LEFT NAVIGATOR) = MANUAL WATER TYPE SELECT
                # The color sensor can't be trusted to auto-classify,
                # so each D-pad direction picks one of the 4 water
                # classes. This just records the pick + timestamp;
                # capture_water_type_selection() does the actual
                # 5-second wait/consume at the start of each mode.
                # --------------------------------------------------
                elif event.code == "ABS_HAT0Y" and event.state == -1:
                    with water_type_lock:
                        water_type_selection["value"] = "Clear"
                        water_type_selection["timestamp"] = time.time()
                    print("[GAMEPAD] Water type -> Clear (D-pad Up)")
                
                elif event.code == "ABS_HAT0Y" and event.state == 1:
                    with water_type_lock:
                        water_type_selection["value"] = "Contaminated"
                        water_type_selection["timestamp"] = time.time()
                    print("[GAMEPAD] Water type -> Contaminated (D-pad Down)")
                
                elif event.code == "ABS_HAT0X" and event.state == -1:
                    with water_type_lock:
                        water_type_selection["value"] = "Algae"
                        water_type_selection["timestamp"] = time.time()
                    print("[GAMEPAD] Water type -> Algae (D-pad Left)")
                
                elif event.code == "ABS_HAT0X" and event.state == 1:
                    with water_type_lock:
                        water_type_selection["value"] = "Muddy"
                        water_type_selection["timestamp"] = time.time()
                    print("[GAMEPAD] Water type -> Muddy (D-pad Right)")
                
                elif event.code == "BTN_START" and event.state == 1:
                    print("[GAMEPAD] Cancel/Reset")
                    cancel_flag = True
                    ai_active = False
                    dataset_active = False
                    motor_running = False
                    try:
                        motor.off()
                    except:
                        pass
                    set_servo(SERVO_CENTER)
                    current_mode = "normal"
                    send_mode()
                    
                    update_oled([
                        "RESET",
                        "Ready",
                        "RB=AI  LB=DATA",
                        "A=MOTOR  B/Y=STEER"
                    ])
                    refresh_oled()
                    time.sleep(2)
                
                elif event.code == "BTN_SELECT" and event.state == 1:
                    print("[GAMEPAD] Status requested")
                    update_oled([
                        "STATUS",
                        f"Mode: {current_mode.upper()}",
                        f"Motor: {'ON' if motor_running else 'OFF'}",
                        f"Pond: {POND_ID}"
                    ])
                    refresh_oled()
                    time.sleep(2)
                
        except Exception as e:
            time.sleep(0.5)

# ============================================================
# MAIN FUNCTION
# ============================================================

def main():
    """Main entry point"""
    print("=" * 50)
    print("🚤 AI BOAT SYSTEM - RASPBERRY PI")
    print("=" * 50)
    
    # Print current IP address
    print(f"\n📡 Current IP Address: {current_ip}")
    print(f"   SSH: pi@{current_ip}")
    print(f"   VNC: {current_ip}:5900")
    print(f"   Web: http://{current_ip}:8501")
    print("=" * 50)
    
    # Show startup on OLED
    update_oled([
        "STARTING",
        "Loading sensors...",
        "Please wait",
        ""
    ])
    refresh_oled()
    
    # Load ML models (color sensor calibration no longer applies —
    # sensor is disabled)
    load_ml_models()
    
    # Start all threads
    threads = [
        ("SENSOR", sensor_reading_thread),
        ("IP_MONITOR", ip_monitor_thread),
        ("OLED", oled_display_thread),
        ("FLASK", flask_sender_thread),
        ("AI_MODE", ai_mode_thread),
        ("DATASET", dataset_collection_thread),
        ("GAMEPAD", gamepad_controller_thread)
    ]
    
    for name, target in threads:
        thread = threading.Thread(target=target, daemon=True, name=name)
        thread.start()
        print(f"[THREAD] Started: {name}")
    
    # Show ready screen
    show_ready_screen()
    
    print("=" * 50)
    print("✅ System Ready!")
    print(f"📍 Dashboard: http://{current_ip}:8501")
    print("🎮 Gamepad connected")
    print("💡 IP will auto-update on WiFi change")
    print("=" * 50)
    print("Press Ctrl+C to exit")
    print("=" * 50)
    
    # Keep main thread alive
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print("\n[SYSTEM] Shutting down...")
        try:
            motor.off()
            servo.off()
            GPIO.cleanup()
            if oled:
                oled.fill(0)
                oled.show()
        except:
            pass
        print("[SYSTEM] Goodbye!")
        sys.exit(0)

# ============================================================
# RUN MAIN
# ============================================================

if __name__ == "__main__":
    main()