#!/usr/bin/env python3
"""
Streamlit Dashboard for AI Boat System
Displays live data, AI predictions, and manages data collection
"""

import streamlit as st
import requests
import pandas as pd
import plotly.graph_objs as go
from plotly.subplots import make_subplots
from datetime import datetime
import time
import os
import base64

# ============================================================
# PAGE CONFIGURATION
# ============================================================

st.set_page_config(
    page_title="AI Boat Monitoring System",
    page_icon="🚤",
    layout="wide",
    initial_sidebar_state="expanded"
)

# ============================================================
# CONSTANTS
# ============================================================

API_URL = "http://localhost:5000"
REFRESH_INTERVAL = 3  # seconds

# Fish species list — kept in sync with FISH_TOLERANCE on the Pi
FISH_SPECIES_LIST = [
    "Tilapia", "Carp", "Pangasius", "Bata", "Rohu", "Prawn",
    "Singhara", "Wallago Catfish", "Silver Carp", "Grass Carp",
    "Mrigal", "Bighead Carp", "Kalbasu", "Catla", "Tengra"
]

# Default data collection duration (seconds) — kept in sync with
# DATASET_MODE_DURATION on the Pi
DEFAULT_COLLECTION_DURATION = 60

# Sensor validation ranges — kept in sync with SENSOR_LIMITS on the Pi.
# Keys map to the field names used in live_data / prediction payloads.
# Red/Green/Blue/Clear were removed since the color sensor is
# disabled on the Pi and no longer sends readings.
SENSOR_LIMITS = {
    "ph": {"label": "pH", "min": 6.0, "max": 8.5, "unit": ""},
    "temperature": {"label": "Temperature", "min": 20.0, "max": 38.0, "unit": "°C"},
    "turbidity": {"label": "Turbidity", "min": 0.5, "max": 14.0, "unit": "NTU"},
    "distance": {"label": "Distance", "min": 0.1, "max": 4.7, "unit": "m"},
    "tds": {"label": "TDS", "min": 50, "max": 900, "unit": "ppm"},
}

def find_out_of_range(data_dict):
    """
    Given a dict of sensor readings (e.g. live_data or a prediction payload),
    return a list of dicts describing any readings outside SENSOR_LIMITS:
        [{"sensor": "pH", "value": 9.1, "min": 6.0, "max": 8.5, "unit": ""}, ...]
    """
    violations = []
    for key, limits in SENSOR_LIMITS.items():
        value = data_dict.get(key)
        if value is None:
            continue
        try:
            value = float(value)
        except (TypeError, ValueError):
            continue
        if value < limits["min"] or value > limits["max"]:
            violations.append({
                "sensor": limits["label"],
                "value": value,
                "min": limits["min"],
                "max": limits["max"],
                "unit": limits["unit"]
            })
    return violations

# ============================================================
# SESSION STATE INITIALIZATION
# ============================================================

if 'data_history' not in st.session_state:
    st.session_state.data_history = pd.DataFrame()
if 'pi_online' not in st.session_state:
    st.session_state.pi_online = False
if 'current_mode' not in st.session_state:
    st.session_state.current_mode = "normal"
if 'last_update' not in st.session_state:
    st.session_state.last_update = None
if 'collection_data' not in st.session_state:
    st.session_state.collection_data = []
if 'auto_refresh' not in st.session_state:
    st.session_state.auto_refresh = True

# ============================================================
# HELPER FUNCTIONS
# ============================================================

@st.cache_data(ttl=2)
def check_pi_connection():
    """Check if Flask API is running"""
    try:
        response = requests.get(f"{API_URL}/health", timeout=2)
        if response.status_code == 200:
            data = response.json()
            st.session_state.pi_online = True
            st.session_state.current_mode = data.get('mode', 'normal')
            return True
    except:
        st.session_state.pi_online = False
    return False

@st.cache_data(ttl=2)
def fetch_live_data():
    """Fetch latest sensor data"""
    try:
        response = requests.get(f"{API_URL}/api/data", timeout=2)
        if response.status_code == 200:
            return response.json()
    except:
        pass
    return None

@st.cache_data(ttl=2)
def fetch_prediction():
    """Fetch AI prediction"""
    try:
        response = requests.get(f"{API_URL}/api/prediction", timeout=2)
        if response.status_code == 200:
            return response.json()
    except:
        pass
    return None

@st.cache_data(ttl=2)
def fetch_collection_status():
    """Fetch data collection status"""
    try:
        response = requests.get(f"{API_URL}/api/collection/data", timeout=2)
        if response.status_code == 200:
            return response.json()
    except:
        pass
    return None

def send_command(command, params=None):
    """Send command to Flask API"""
    try:
        payload = {"command": command}
        if params:
            payload.update(params)
        response = requests.post(f"{API_URL}/api/command", json=payload, timeout=2)
        return response.status_code == 200
    except:
        return False

def save_collection():
    """Save collected data to CSV"""
    try:
        response = requests.post(f"{API_URL}/api/collection/save", timeout=2)
        if response.status_code == 200:
            return response.json()
    except:
        pass
    return None

def create_gauge(value, title, min_val, max_val):
    """Create a gauge chart"""
    fig = go.Figure(go.Indicator(
        mode="gauge+number",
        value=value,
        title={"text": title},
        gauge={
            'axis': {'range': [min_val, max_val]},
            'bar': {'color': "#00ff00"},
            'steps': [
                {'range': [min_val, (min_val+max_val)/3], 'color': "lightgreen"},
                {'range': [(min_val+max_val)/3, 2*(min_val+max_val)/3], 'color': "yellow"},
                {'range': [2*(min_val+max_val)/3, max_val], 'color': "salmon"}
            ]
        }
    ))
    fig.update_layout(height=250, margin=dict(t=50, b=0, l=0, r=0))
    return fig

# ============================================================
# SIDEBAR
# ============================================================

with st.sidebar:
    st.image("https://emojis.slackmojis.com/emojis/2020-05-04/59890/boat.png", width=50)
    st.title("🚤 AI Boat System")
    st.markdown("---")
    
    # Connection Status
    st.subheader("📡 System Status")
    if check_pi_connection():
        st.success("🟢 PI ONLINE")
        st.info(f"Mode: **{st.session_state.current_mode.upper()}**")
    else:
        st.error("🔴 PI OFFLINE")
        st.caption("Check if Flask server is running")
    
    if st.session_state.last_update:
        st.caption(f"Last update: {st.session_state.last_update.strftime('%H:%M:%S')}")
    
    st.markdown("---")
    
    # Controls
    st.subheader("🎮 Dashboard Controls")
    
    auto_refresh = st.checkbox("Auto Refresh", value=st.session_state.auto_refresh)
    st.session_state.auto_refresh = auto_refresh
    
    if st.button("🔄 Manual Refresh", use_container_width=True):
        st.cache_data.clear()
        st.rerun()
    
    st.markdown("---")
    
    # Gamepad Controls Info
    st.subheader("🎮 Gamepad Controls")
    st.caption("""
    - **RB** → Start AI Mode
    - **LB** → Start Data Collection
    - **A** → Toggle Motor
    - **B/Y** → Steering
    - **START** → Reset
    - **D-pad** → Change OLED Page
    """)
    
    st.markdown("---")
    st.caption("Version 2.0 | AI Boat System")

# ============================================================
# MAIN CONTENT
# ============================================================

st.title("🤖 AI Boat Monitoring Dashboard")
st.markdown("*Real-time water quality monitoring and intelligent fish prediction system*")
st.markdown("---")

# Fetch data
live_data = fetch_live_data()
prediction = fetch_prediction()
collection_status = fetch_collection_status()

# Update data history
if live_data:
    live_data['timestamp'] = datetime.now()
    new_row = pd.DataFrame([live_data])
    st.session_state.data_history = pd.concat([st.session_state.data_history, new_row], ignore_index=True)
    if len(st.session_state.data_history) > 100:
        st.session_state.data_history = st.session_state.data_history.tail(100)
    st.session_state.last_update = datetime.now()

# Create tabs
tab1, tab2, tab3, tab4 = st.tabs(["📊 Live Monitoring", "🤖 AI Prediction", "💾 Data Collection", "📈 History & Analysis"])

# ============================================================
# TAB 1: LIVE MONITORING
# ============================================================

with tab1:
    if st.session_state.current_mode == "ai":
        st.info("🤖 **AI Mode Active** - System is collecting data for analysis. Live data below.")
    elif st.session_state.current_mode == "collection":
        st.info("💾 **Data Collection Mode Active** - System is recording data for training dataset.")
    
    if live_data:
        # Key metrics row
        st.subheader("📊 Current Readings")
        col1, col2, col3 = st.columns(3)  # Changed from 4 to 3 columns
        
        with col1:
            st.metric("🌡️ Temperature", f"{live_data.get('temperature', 0):.1f}°C", 
                     delta=None if st.session_state.data_history.empty else f"{live_data.get('temperature', 0) - st.session_state.data_history.iloc[-2].get('temperature', 0):.1f}" if len(st.session_state.data_history) > 1 else None)
            st.metric("💧 pH Level", f"{live_data.get('ph', 0):.2f}")
        
        with col2:
            st.metric("💦 Total Dissolved Solids", f"{live_data.get('tds', 0):.0f} ppm")
            st.metric("🌊 Turbidity", f"{live_data.get('turbidity', 0):.1f} NTU")
        
        with col3:
            st.metric("📏 Distance", f"{live_data.get('distance', 0):.2f} m")
            st.metric("💧 Water Type", live_data.get('water_type', 'Unknown'))
        
        st.markdown("---")

        # Out-of-range sensor check (live readings)
        live_violations = find_out_of_range(live_data)
        st.subheader("🚨 Sensor Limit Check")
        if live_violations:
            st.error(f"⚠️ {len(live_violations)} sensor reading(s) are currently out of the acceptable range:")
            for v in live_violations:
                unit = f" {v['unit']}" if v['unit'] else ""
                st.warning(
                    f"**{v['sensor']}**: {v['value']:.2f}{unit}  "
                    f"(allowed range: {v['min']}–{v['max']}{unit})"
                )
        else:
            st.success("✅ All sensor readings are currently within acceptable limits.")
        
        st.markdown("---")
        
        # Gauge charts
        st.subheader("📊 Sensor Gauges")
        col1, col2 = st.columns(2)
        
        with col1:
            if live_data.get('ph'):
                st.plotly_chart(create_gauge(live_data['ph'], "pH Level", 0, 14), use_container_width=True)
        
        with col2:
            if live_data.get('temperature'):
                st.plotly_chart(create_gauge(live_data['temperature'], "Temperature (°C)", 0, 50), use_container_width=True)
        
        # Water type — the color sensor is disabled, so this is
        # whatever the user last selected manually on the gamepad D-pad
        st.subheader("💧 Water Type (Manual Entry)")
        st.info(
            f"Currently selected: **{live_data.get('water_type', 'Unknown')}**  \n"
            "Selected via the gamepad D-pad (Up=Clear, Down=Contaminated, "
            "Left=Algae, Right=Muddy) at the start of each AI/Dataset run."
        )
        
    else:
        st.warning("⚠️ No live data available. Waiting for Raspberry Pi to send data...")
        st.info("Make sure your Pi is running the main AI Boat script and sending data to the Flask API.")

# ============================================================
# TAB 2: AI PREDICTION
# ============================================================

with tab2:
    st.header("🤖 AI Fish Species Prediction")
    
    if st.session_state.current_mode == "ai":
        st.info("🤖 **AI Mode Active** - Please wait 60 seconds while data is being collected and analyzed...")
        
        # Show progress
        if live_data:
            col1, col2, col3 = st.columns(3)
            with col1:
                st.metric("Current pH", f"{live_data.get('ph', 0):.2f}")
            with col2:
                st.metric("Current Temp", f"{live_data.get('temperature', 0):.1f}°C")
            with col3:
                st.metric("Turbidity", f"{live_data.get('turbidity', 0):.1f} NTU")
        
        st.progress(0.5, text="Collecting water quality data for AI analysis...")
        st.caption("AI mode runs for 60 seconds. The system will automatically show results when complete.")
        
    elif prediction and prediction.get('fish') not in ("None", None):
        st.success("✅ **AI Analysis Complete!**")
        
        # Main prediction result
        col1, col2 = st.columns(2)
        
        with col1:
            st.markdown("### 🐟 Predicted Fish Species")
            st.markdown(f"<h1 style='color: #00ff00;'>{prediction.get('fish', 'Unknown')}</h1>", unsafe_allow_html=True)
            st.metric("Confidence Score", f"{prediction.get('confidence', 0)}%")
            st.metric("Detected Water Type", prediction.get('water_type', 'Unknown'))
        
        with col2:
            st.markdown("### 📊 Water Parameters at Analysis")
            st.metric("pH Level", f"{prediction.get('ph', 0):.2f}")
            st.metric("TDS Level", f"{prediction.get('tds', 0):.0f} ppm")
            if live_data:
                st.metric("Temperature", f"{live_data.get('temperature', 0):.1f}°C")
        
        st.markdown("---")
        
        # Survivability analysis
        st.subheader("🎯 Fish Suitability Analysis")
        
        col1, col2 = st.columns(2)
        
        with col1:
            st.markdown("#### ✅ Survivable Fish Species")
            survivable = prediction.get('survivable', [])
            if survivable:
                for i, fish in enumerate(survivable[:10]):
                    st.success(f"{i+1}. {fish}")
            else:
                st.info("No survivable fish data available")
        
        with col2:
            st.markdown("#### ⚠️ Sensitive Fish Species")
            sensitive = prediction.get('sensitive', [])
            if sensitive:
                for i, fish in enumerate(sensitive[:10]):
                    st.warning(f"{i+1}. {fish}")
            else:
                st.info("No sensitive fish data available")
        
        st.markdown("---")
        
        # Recommendations
        st.subheader("💡 Recommendations")
        
        if prediction.get('water_type') == "Clear":
            st.success("✅ Water quality is clear and suitable for most fish species.")
        elif prediction.get('water_type') == "Algae":
            st.warning("⚠️ Algae detected. Consider reducing nutrient input or increasing aeration.")
        elif prediction.get('water_type') == "Muddy":
            st.warning("⚠️ High turbidity detected. Consider sedimentation or filtration.")
        elif prediction.get('water_type') == "Contaminated":
            st.error("❌ Contamination detected! Immediate action recommended.")
        
        if prediction.get('ph', 7) < 6.5:
            st.warning("📊 pH level is below optimal range (6.5-8.5). Consider adding pH buffer.")
        elif prediction.get('ph', 7) > 8.5:
            st.warning("📊 pH level is above optimal range (6.5-8.5). Consider adding pH reducer.")
        
        st.info(f"💡 Based on analysis, **{prediction.get('fish', 'Unknown')}** is recommended for current water conditions.")
        
        if st.button("🔄 Run New AI Analysis", use_container_width=True):
            send_command("start_ai")
            st.success("AI Mode requested! Please press RB button on the gamepad to start.")
            time.sleep(1)
            st.rerun()

    elif prediction and prediction.get('fish') == "None":
        st.error("🚫 **Pond is not suitable for any fish**")
        st.markdown(
            "One or more sensor readings fell outside the acceptable range during the "
            "last AI analysis, so no fish species could be recommended for this pond."
        )

        col1, col2 = st.columns(2)
        with col1:
            st.metric("pH at Analysis", f"{prediction.get('ph', 0):.2f}")
        with col2:
            st.metric("TDS at Analysis", f"{prediction.get('tds', 0):.0f} ppm")

        # Show exactly which sensor(s) triggered the "not suitable" result.
        # Prefer the out_of_range list sent by the Pi (based on the averaged
        # AI-mode readings); fall back to re-checking the payload directly.
        out_of_range = prediction.get('out_of_range') or find_out_of_range(prediction)

        st.markdown("---")
        st.subheader("🔍 Sensors Out of Range")
        if out_of_range:
            for v in out_of_range:
                sensor_name = v.get('sensor', 'Unknown')
                value = v.get('value', 0)
                low = v.get('min', v.get('low', '-'))
                high = v.get('max', v.get('high', '-'))
                unit = v.get('unit', '')
                unit_str = f" {unit}" if unit else ""
                st.warning(
                    f"**{sensor_name}**: {value}{unit_str}  "
                    f"(allowed range: {low}–{high}{unit_str})"
                )
        else:
            st.caption("Detailed sensor breakdown not available from the last analysis.")

        st.info("Adjust the water parameters and run a new AI analysis once conditions improve.")

        if st.button("🔄 Run New AI Analysis", use_container_width=True, key="rerun_ai_unsuitable"):
            send_command("start_ai")
            st.success("AI Mode requested! Please press RB button on the gamepad to start.")
            time.sleep(1)
            st.rerun()

    else:
        st.info("ℹ️ No AI prediction available yet.")
        st.markdown("""
        ### How to run AI Analysis:
        
        1. **From Gamepad:** Press the **RB button** on the connected controller
        2. **Wait 60 seconds** while the system collects water quality data
        3. **Results will appear here automatically**
        
        The AI model analyzes:
        - pH levels
        - Temperature
        - TDS (Total Dissolved Solids)
        - Turbidity
        - Water color (RGB values)
        - Ultrasonic distance
        
        Based on these parameters, it predicts the most suitable fish species for your pond.
        """)
        
        if st.button("🎮 Start AI Mode (Simulate)", use_container_width=True):
            send_command("start_ai")
            st.success("Command sent! Press RB button on the gamepad to start AI mode.")
            st.balloons()

# ============================================================
# TAB 3: DATA COLLECTION
# ============================================================

with tab3:
    st.header("💾 Dataset Collection for Training")
    
    # Collection form
    with st.form("collection_form"):
        st.subheader("📝 Collection Parameters")
        
        col1, col2 = st.columns(2)
        with col1:
            pond_id = st.number_input("Pond ID", min_value=1, max_value=100, value=1, step=1,
                                     help="Unique identifier for your pond")
        with col2:
            fish_name = st.selectbox(
                "Fish Species",
                FISH_SPECIES_LIST,
                help="Select the fish species in your pond"
            )
        
        st.markdown("---")
        
        col1, col2 = st.columns(2)
        with col1:
            duration_options = [60, 120, 180, 240, 300]
            default_index = duration_options.index(DEFAULT_COLLECTION_DURATION)
            duration = st.selectbox("Collection Duration", duration_options, index=default_index,
                                   help="How long to collect data (seconds)")
        with col2:
            auto_save = st.checkbox("Auto-save after collection", value=True)
        
        submitted = st.form_submit_button("🎯 Start Data Collection", use_container_width=True)
        
        if submitted:
            if send_command("start_collection", {"pond_id": pond_id, "fish_name": fish_name}):
                st.success(f"✅ Data collection started for Pond {pond_id} - {fish_name}")
                st.info(f"⏱️ Collection will run for {duration} seconds. The system will automatically save the data.")
                st.session_state.collection_active = True
            else:
                st.error("Failed to start collection. Make sure the Pi is connected.")
    
    st.markdown("---")
    
    # Collection status
    if collection_status and collection_status.get('active'):
        st.subheader("📊 Live Collection Status")
        
        col1, col2, col3 = st.columns(3)
        with col1:
            st.metric("Samples Collected", collection_status.get('samples', 0))
        with col2:
            st.metric("Pond ID", collection_status.get('pond_id', '-'))
        with col3:
            st.metric("Fish Species", collection_status.get('fish_name', '-'))
        
        # Show latest collected data
        if collection_status.get('data'):
            st.subheader("Latest Samples")
            df_collect = pd.DataFrame(collection_status['data'])
            st.dataframe(df_collect.tail(10), use_container_width=True)
        
        # Stop button
        if st.button("⏹️ Stop Collection & Save", use_container_width=True):
            result = save_collection()
            if result:
                st.success(f"✅ Data saved! {result.get('rows', 0)} rows saved to {result.get('filename', 'file')}")
                st.session_state.collection_active = False
                time.sleep(1)
                st.rerun()
            else:
                st.error("Failed to save collection data")
    
    # Saved datasets
    st.subheader("📁 Saved Datasets")
    
    try:
        datasets_dir = "/home/salamat/fish_project/datasets"
        if os.path.exists(datasets_dir):
            datasets = [f for f in os.listdir(datasets_dir) if f.endswith('.csv')]
            if datasets:
                selected_dataset = st.selectbox("Select a dataset to view", datasets)
                if selected_dataset:
                    df = pd.read_csv(f"{datasets_dir}/{selected_dataset}")
                    st.dataframe(df, use_container_width=True)
                    
                    # Download button
                    csv = df.to_csv(index=False)
                    b64 = base64.b64encode(csv.encode()).decode()
                    href = f'<a href="data:file/csv;base64,{b64}" download="{selected_dataset}">📥 Download {selected_dataset}</a>'
                    st.markdown(href, unsafe_allow_html=True)
            else:
                st.info("No datasets found. Start data collection to create training datasets.")
        else:
            st.info("Datasets directory not yet created. Datasets will appear here after collection.")
    except Exception as e:
        st.error(f"Error loading datasets: {e}")

# ============================================================
# TAB 4: HISTORY & ANALYSIS
# ============================================================

with tab4:
    st.header("📈 Historical Data Analysis")
    
    if not st.session_state.data_history.empty:
        # Time range selection
        st.subheader("📅 Time Range")
        col1, col2 = st.columns(2)
        with col1:
            time_range = st.selectbox("Select time range", ["Last 10 records", "Last 50 records", "All records"])
        
        with col2:
            if st.button("Export to CSV", use_container_width=True):
                csv = st.session_state.data_history.to_csv(index=False)
                b64 = base64.b64encode(csv.encode()).decode()
                href = f'<a href="data:file/csv;base64,{b64}" download="boat_data_export.csv">📥 Download CSV</a>'
                st.markdown(href, unsafe_allow_html=True)
        
        # Filter data
        if time_range == "Last 10 records":
            plot_df = st.session_state.data_history.tail(10)
        elif time_range == "Last 50 records":
            plot_df = st.session_state.data_history.tail(50)
        else:
            plot_df = st.session_state.data_history
        
        # Create comprehensive chart
        st.subheader("📊 Sensor Trends Over Time")
        
        fig = make_subplots(
            rows=3, cols=2,
            subplot_titles=("Temperature (°C)", "pH Level", "TDS (ppm)", "Turbidity (NTU)", "Distance (m)"),
            vertical_spacing=0.12
        )
        
        # Temperature
        fig.add_trace(go.Scatter(x=plot_df['timestamp'], y=plot_df['temperature'], 
                                mode='lines+markers', name='Temp', line=dict(color='red')), row=1, col=1)
        
        # pH
        fig.add_trace(go.Scatter(x=plot_df['timestamp'], y=plot_df['ph'], 
                                mode='lines+markers', name='pH', line=dict(color='blue')), row=1, col=2)
        
        # TDS
        fig.add_trace(go.Scatter(x=plot_df['timestamp'], y=plot_df['tds'], 
                                mode='lines+markers', name='TDS', line=dict(color='green')), row=2, col=1)
        
        # Turbidity
        fig.add_trace(go.Scatter(x=plot_df['timestamp'], y=plot_df['turbidity'], 
                                mode='lines+markers', name='Turbidity', line=dict(color='orange')), row=2, col=2)
        
        # Distance
        if 'distance' in plot_df.columns:
            fig.add_trace(go.Scatter(x=plot_df['timestamp'], y=plot_df['distance'], 
                                    mode='lines+markers', name='Distance', line=dict(color='purple')), row=3, col=1)
        
        fig.update_layout(height=800, showlegend=True)
        fig.update_xaxes(title_text="Time", row=3, col=1)
        fig.update_xaxes(title_text="Time", row=3, col=2)
        
        st.plotly_chart(fig, use_container_width=True)
        
        # Statistical summary
        st.subheader("📊 Statistical Summary")
        
        col1, col2 = st.columns(2)
        
        with col1:
            st.markdown("#### 📈 Temperature Statistics")
            temp_stats = plot_df['temperature'].describe()
            st.write(f"Mean: {temp_stats['mean']:.1f}°C")
            st.write(f"Min: {temp_stats['min']:.1f}°C")
            st.write(f"Max: {temp_stats['max']:.1f}°C")
            st.write(f"Std Dev: {temp_stats['std']:.1f}°C")
        
        with col2:
            st.markdown("#### 📈 pH Statistics")
            ph_stats = plot_df['ph'].describe()
            st.write(f"Mean: {ph_stats['mean']:.2f}")
            st.write(f"Min: {ph_stats['min']:.2f}")
            st.write(f"Max: {ph_stats['max']:.2f}")
            st.write(f"Std Dev: {ph_stats['std']:.2f}")
        
        # Data table
        st.subheader("📋 Raw Data")
        st.dataframe(plot_df, use_container_width=True)
        
    else:
        st.info("No historical data available yet. Waiting for data from Raspberry Pi...")

# ============================================================
# AUTO REFRESH
# ============================================================

if st.session_state.auto_refresh:
    time.sleep(REFRESH_INTERVAL)
    st.rerun()