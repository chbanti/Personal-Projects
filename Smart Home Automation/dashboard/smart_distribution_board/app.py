import streamlit as st
import pandas as pd
import numpy as np
import plotly.graph_objects as go
from datetime import datetime, timedelta, time as dt_time
import time
import json
import websocket

# ── Page config ────────────────────────────────────────────────────────────────
st.set_page_config(
    page_title="Smart Distribution Board",
    page_icon="⚡",
    layout="wide",
    initial_sidebar_state="expanded",
)

# ── Inject custom CSS ─────────────────────────────────────────────────────────
st.markdown("""
<style>
@import url('https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700&display=swap');

html, body, [class*="css"] {
    font-family: 'Inter', sans-serif;
}

#MainMenu, footer, header { visibility: hidden; }

[data-testid="stSidebar"] {
    background-color: #0f172a !important;
    color: white !important;
}
[data-testid="stSidebar"] .stRadio label,
[data-testid="stSidebar"] p,
[data-testid="stSidebar"] span {
    color: #cbd5e1 !important;
    font-size: 14px;
}
[data-testid="stSidebar"] .stRadio > div {
    gap: 4px;
}
[data-testid="stSidebar"] .stRadio label:hover {
    color: white !important;
}

.metric-card {
    background: white;
    border-radius: 12px;
    padding: 20px 24px;
    box-shadow: 0 1px 4px rgba(0,0,0,0.08);
    display: flex;
    align-items: center;
    gap: 16px;
    min-height: 100px;
}
.metric-icon {
    width: 52px;
    height: 52px;
    border-radius: 50%;
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 22px;
    flex-shrink: 0;
}
.metric-value { font-size: 28px; font-weight: 700; color: #1e293b; line-height: 1.1; }
.metric-label { font-size: 12px; color: #94a3b8; margin-top: 3px; }
.metric-title { font-size: 13px; font-weight: 600; margin-bottom: 2px; }

.section-card {
    background: white;
    border-radius: 12px;
    padding: 20px 22px;
    box-shadow: 0 1px 4px rgba(0,0,0,0.08);
    height: 100%;
}
.section-title { font-size: 15px; font-weight: 700; color: #1e293b; margin-bottom: 14px; }
.section-sub { font-size: 12px; color: #94a3b8; margin-bottom: 14px; margin-top: -10px; }

.pzem-row {
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding: 7px 0;
    border-bottom: 1px solid #f1f5f9;
    font-size: 13.5px;
}
.pzem-row:last-child { border-bottom: none; }
.pzem-row .label { color: #475569; display: flex; align-items: center; gap: 8px; }
.pzem-row .value { font-weight: 600; color: #1e293b; }

.appliance-row {
    background: #f8fafc;
    border-radius: 10px;
    padding: 12px 14px;
    display: flex;
    justify-content: space-between;
    align-items: center;
    margin-bottom: 10px;
}
.badge-on  { background:#22c55e; color:white; padding:2px 10px; border-radius:20px; font-size:12px; font-weight:600; }
.badge-off { background:#ef4444; color:white; padding:2px 10px; border-radius:20px; font-size:12px; font-weight:600; }
.badge-sched { background:#dbeafe; color:#2563eb; padding:2px 10px; border-radius:20px; font-size:11px; font-weight:600; }
.green { color: #22c55e; font-weight: 700; }
.ts { font-size: 11px; color: #94a3b8; margin-top: 4px; }

.source-row {
    background: #f8fafc;
    border-radius: 10px;
    padding: 12px 14px;
    margin-bottom: 10px;
}
.badge-avail { background:#dcfce7; color:#16a34a; padding:2px 10px; border-radius:20px; font-size:11px; font-weight:600; }
.source-metrics { font-size: 13px; color: #475569; margin-top: 6px; display:flex; justify-content:space-between; }
.info-banner {
    background: #eff6ff;
    border-radius: 8px;
    padding: 10px 14px;
    font-size: 13px;
    color: #2563eb;
    display: flex;
    align-items: center;
    gap: 6px;
    margin-top: 6px;
}
.warn-banner {
    background: #fff7ed;
    border-radius: 8px;
    padding: 10px 14px;
    font-size: 13px;
    color: #c2410c;
    display: flex;
    align-items: center;
    gap: 6px;
    margin-top: 6px;
}

.status-online {
    background: #064e3b;
    border-radius: 10px;
    padding: 12px 14px;
    color: white;
}
.dot-green { width:10px; height:10px; background:#22c55e; border-radius:50%; display:inline-block; margin-right:6px; }

.main .block-container { background: #f1f5f9; padding-top: 1.5rem; }

.topbar {
    background: white;
    border-radius: 12px;
    padding: 12px 22px;
    display: flex;
    justify-content: space-between;
    align-items: center;
    margin-bottom: 18px;
    box-shadow: 0 1px 4px rgba(0,0,0,0.06);
}
.topbar-title { font-size: 20px; font-weight: 700; color: #1e293b; }
.topbar-right  { font-size: 13px; color: #64748b; display: flex; gap: 20px; align-items:center; }

.audit-summary-card {
    background: white;
    border-radius: 12px;
    padding: 18px 20px;
    box-shadow: 0 1px 4px rgba(0,0,0,0.08);
    text-align: center;
}
.audit-summary-value { font-size: 24px; font-weight: 700; color: #1e293b; }
.audit-summary-label { font-size: 12px; color: #94a3b8; margin-top: 4px; }
.audit-summary-delta-up   { color: #ef4444; font-size: 12px; font-weight: 600; }
.audit-summary-delta-down { color: #22c55e; font-size: 12px; font-weight: 600; }

.schedule-item {
    background: #f8fafc;
    border-radius: 10px;
    padding: 14px 16px;
    margin-bottom: 10px;
    border-left: 4px solid #2563eb;
}
.schedule-item-disabled {
    background: #f8fafc;
    border-radius: 10px;
    padding: 14px 16px;
    margin-bottom: 10px;
    border-left: 4px solid #94a3b8;
    opacity: 0.6;
}
.schedule-time { font-size: 13px; color: #475569; font-weight: 600; }
.schedule-days { font-size: 11px; color: #94a3b8; margin-top: 3px; }
.schedule-active-now {
    background: #f0fdf4;
    border-radius: 8px;
    padding: 6px 12px;
    font-size: 12px;
    color: #16a34a;
    font-weight: 600;
    display: inline-block;
    margin-top: 6px;
}
.schedule-next-trigger {
    background: #eff6ff;
    border-radius: 8px;
    padding: 6px 12px;
    font-size: 12px;
    color: #2563eb;
    font-weight: 600;
    display: inline-block;
    margin-top: 6px;
}
</style>
""", unsafe_allow_html=True)

# ── WebSocket Configuration ─────────────────────────────────────────────────
ESP32_IP = "172.19.161.44"  # Your ESP32 IP
WEBSOCKET_PORT = 81

# ── Session state ────────────────────────────────────────────────────────────
if "bulb_on" not in st.session_state:
    st.session_state.bulb_on = False
if "fan_on" not in st.session_state:
    st.session_state.fan_on = False
if "page" not in st.session_state:
    st.session_state.page = "Dashboard"

# Schedules: only Bulb (Slave 1 LED) is controllable for now
if "schedules" not in st.session_state:
    st.session_state.schedules = [
        {
            "appliance": "Bulb",
            "on_time": "18:00",
            "off_time": "23:00",
            "days": "Mon–Sun",
            "enabled": True,
            "last_on_triggered": None,   # track last trigger to avoid repeated fires
            "last_off_triggered": None,
        },
    ]

# Schedule executor state
if "schedule_log" not in st.session_state:
    st.session_state.schedule_log = []   # list of dicts {time, action, appliance, source}

# WebSocket session state
if "ws_data" not in st.session_state:
    st.session_state.ws_data = {
        "voltage": 0, "current": 0, "active_power": 0,
        "apparent_power": 0, "power_factor": 0, "frequency": 0,
        "energy_total": 0, "energy_today": 0,
        "bulb_current": 0, "bulb_power": 0,
        "fan_current": 0, "fan_power": 0,
        "src1_voltage": 0, "src1_freq": 0,
        "src2_voltage": 0, "src2_freq": 0,
        "temperature": 0, "humidity": 0, "ldr": 0,
        "bulb_on": False, "fan_on": False,
        "connected": False,
    }

if "ws_conn" not in st.session_state:
    st.session_state.ws_conn = None

# ── WebSocket Functions ─────────────────────────────────────────────────────
def get_ws_connection():
    try:
        ws = websocket.create_connection(
            f"ws://{ESP32_IP}:{WEBSOCKET_PORT}", timeout=5)
        return ws
    except Exception:
        return None

def fetch_esp32_data():
    try:
        if st.session_state.ws_conn is None:
            st.session_state.ws_conn = get_ws_connection()
        ws = st.session_state.ws_conn
        if ws is None:
            st.session_state.ws_data["connected"] = False
            return False
        ws.send(json.dumps({"command": "get_status"}))
        ws.settimeout(3)
        response = ws.recv()
        if response:
            data = json.loads(response)
            st.session_state.ws_data.update(data)
            st.session_state.ws_data["connected"] = True
            esp32_current = 0.24
            sensor_current = 0.05
            total_current = (data.get("bulb_current", 0) + data.get("fan_current", 0)
                             + esp32_current + sensor_current)
            st.session_state.ws_data["current"] = round(total_current, 2)
            if "bulb_on" in data:
                st.session_state.bulb_on = data["bulb_on"]
            if "fan_on" in data:
                st.session_state.fan_on = data["fan_on"]
            return True
    except websocket.WebSocketTimeoutException:
        st.session_state.ws_data["connected"] = False
    except Exception:
        if st.session_state.ws_conn:
            try:
                st.session_state.ws_conn.close()
            except Exception:
                pass
        st.session_state.ws_conn = None
        st.session_state.ws_data["connected"] = False
    return False

def send_esp32_command(command, **kwargs):
    try:
        if st.session_state.ws_conn is None:
            st.session_state.ws_conn = get_ws_connection()
        ws = st.session_state.ws_conn
        if ws is None:
            return False
        data = {"command": command}
        data.update(kwargs)
        ws.send(json.dumps(data))
        ws.settimeout(2)
        response = ws.recv()
        return True if response else False
    except Exception:
        if st.session_state.ws_conn:
            try:
                st.session_state.ws_conn.close()
            except Exception:
                pass
        st.session_state.ws_conn = None
        return False

# ── Schedule Executor ────────────────────────────────────────────────────────
DAY_MAP = {
    "Mon–Sun": list(range(7)),         # 0=Mon … 6=Sun
    "Mon–Fri": list(range(5)),
    "Sat–Sun": [5, 6],
    "Custom":  list(range(7)),         # treat Custom as every day
}

def _today_in_days(days_str: str) -> bool:
    """Return True if today's weekday is included in the schedule's day range."""
    allowed = DAY_MAP.get(days_str, list(range(7)))
    return datetime.now().weekday() in allowed

def _time_matches(hhmm: str) -> bool:
    """Return True if the current HH:MM matches the given 'HH:MM' string."""
    now = datetime.now()
    try:
        h, m = map(int, hhmm.split(":"))
        return now.hour == h and now.minute == m
    except Exception:
        return False

def _date_key() -> str:
    """Return YYYY-MM-DD for today — used to stamp last-triggered date."""
    return datetime.now().strftime("%Y-%m-%d")

def run_schedule_engine():
    """
    Called once per page render (every ~2 s on Dashboard).
    Checks every enabled schedule and fires set_bulb / set_fan
    if the current time matches ON or OFF time, once per minute.
    Only Bulb (Slave 1 LED) is wired through — fan command still sent
    but Slave 1 only has a bulb relay per the user's note.
    """
    now_key = datetime.now().strftime("%Y-%m-%d %H:%M")  # minute-resolution key

    for idx, sched in enumerate(st.session_state.schedules):
        if not sched.get("enabled", True):
            continue
        if not _today_in_days(sched["days"]):
            continue

        appliance = sched["appliance"]  # "Bulb" or "Fan"
        command   = "set_bulb" if appliance == "Bulb" else "set_fan"

        # ── ON trigger ──────────────────────────────────────────────────────
        if _time_matches(sched["on_time"]):
            last_on = sched.get("last_on_triggered", "")
            if last_on != now_key:                        # fire only once per minute
                success = send_esp32_command(command, state=True)
                st.session_state.schedules[idx]["last_on_triggered"] = now_key
                if appliance == "Bulb":
                    st.session_state.bulb_on = True
                else:
                    st.session_state.fan_on = True
                # Log the event
                st.session_state.schedule_log.insert(0, {
                    "timestamp": datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
                    "action":    f"{appliance} → ON",
                    "source":    "Schedule" + (" ✓" if success else " ✗ (no conn)"),
                })
                # Keep log to 50 entries
                st.session_state.schedule_log = st.session_state.schedule_log[:50]

        # ── OFF trigger ─────────────────────────────────────────────────────
        if _time_matches(sched["off_time"]):
            last_off = sched.get("last_off_triggered", "")
            if last_off != now_key:
                success = send_esp32_command(command, state=False)
                st.session_state.schedules[idx]["last_off_triggered"] = now_key
                if appliance == "Bulb":
                    st.session_state.bulb_on = False
                else:
                    st.session_state.fan_on = False
                st.session_state.schedule_log.insert(0, {
                    "timestamp": datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
                    "action":    f"{appliance} → OFF",
                    "source":    "Schedule" + (" ✓" if success else " ✗ (no conn)"),
                })
                st.session_state.schedule_log = st.session_state.schedule_log[:50]


def _schedule_is_active_now(sched: dict) -> bool:
    """Return True if the schedule's window is currently active today."""
    if not sched.get("enabled", True):
        return False
    if not _today_in_days(sched["days"]):
        return False
    try:
        now_t = datetime.now().time().replace(second=0, microsecond=0)
        on_h,  on_m  = map(int, sched["on_time"].split(":"))
        off_h, off_m = map(int, sched["off_time"].split(":"))
        on_t  = dt_time(on_h,  on_m)
        off_t = dt_time(off_h, off_m)
        if on_t <= off_t:
            return on_t <= now_t <= off_t
        else:  # overnight window e.g. 22:00 → 06:00
            return now_t >= on_t or now_t <= off_t
    except Exception:
        return False


def _next_trigger_str(sched: dict) -> str:
    """Return a human-readable string for the next ON or OFF trigger."""
    try:
        now = datetime.now()
        on_h,  on_m  = map(int, sched["on_time"].split(":"))
        off_h, off_m = map(int, sched["off_time"].split(":"))
        on_dt  = now.replace(hour=on_h,  minute=on_m,  second=0, microsecond=0)
        off_dt = now.replace(hour=off_h, minute=off_m, second=0, microsecond=0)
        candidates = []
        for dt_cand, label in [(on_dt, "ON"), (off_dt, "OFF")]:
            if dt_cand <= now:
                dt_cand += timedelta(days=1)
            candidates.append((dt_cand, label))
        candidates.sort(key=lambda x: x[0])
        nxt_dt, nxt_label = candidates[0]
        delta = nxt_dt - now
        hours_left = int(delta.total_seconds() // 3600)
        mins_left  = int((delta.total_seconds() % 3600) // 60)
        return f"Next {nxt_label} at {nxt_dt.strftime('%H:%M')} (in {hours_left}h {mins_left}m)"
    except Exception:
        return ""


# ── Fetch data from ESP32 + run schedule ───────────────────────────────────
fetch_esp32_data()
run_schedule_engine()

# ── Data function ───────────────────────────────────────────────────────────
def get_live_data():
    ws_data = st.session_state.ws_data
    if ws_data.get("connected", False):
        return ws_data
    return {
        "voltage": 229.6, "current": 2.35,
        "active_power": 482.7, "apparent_power": 540.3,
        "power_factor": 0.89, "frequency": 50.02,
        "energy_total": 125.36, "energy_today": 2.48,
        "bulb_current": 0.58, "bulb_power": 61.3,
        "fan_current": 1.77, "fan_power": 187.6,
        "src1_voltage": 229.8, "src1_freq": 50.01,
        "src2_voltage": 230.1, "src2_freq": 50.02,
        "temperature": 0, "humidity": 0, "ldr": 0,
    }

@st.cache_data
def power_trend_data():
    hours = np.linspace(0, 24, 100)
    base  = 300
    trend = (base + 200 * np.sin(np.pi * hours / 12) + np.random.normal(0, 30, 100))
    trend = np.clip(trend, 150, 800)
    return hours, trend

@st.cache_data
def voltage_current_trend():
    hours = np.linspace(0, 24, 100)
    voltage = 230 + 3 * np.sin(np.pi * hours / 24) + np.random.normal(0, 0.8, 100)
    current = 2.3 + 1.0 * np.sin(np.pi * hours / 12 - 0.5) + np.random.normal(0, 0.15, 100)
    current = np.clip(current, 0.5, 4.5)
    return hours, voltage, current

@st.cache_data
def daily_energy_data(days=90):
    end = datetime.now().date()
    dates = [end - timedelta(days=i) for i in range(days - 1, -1, -1)]
    base = 5.5
    weekday_factor = np.array([1.05 if d.weekday() < 5 else 0.85 for d in dates])
    seasonal = 1 + 0.15 * np.sin(np.linspace(0, 4 * np.pi, days))
    noise = np.random.normal(0, 0.4, days)
    kwh = np.clip(base * weekday_factor * seasonal + noise, 2.0, 10.0)
    df = pd.DataFrame({"date": dates, "kwh": kwh})
    df["cost"] = df["kwh"] * 30
    return df

# ═══════════════════════════════════════════════════════════════════════════════
# SIDEBAR
# ═══════════════════════════════════════════════════════════════════════════════
with st.sidebar:
    st.markdown("""
    <div style="display:flex;align-items:center;gap:12px;padding:10px 0 24px 0;">
      <div style="background:#f59e0b;border-radius:10px;width:42px;height:42px;
                  display:flex;align-items:center;justify-content:center;font-size:20px;">⚡</div>
      <div>
        <div style="color:white;font-weight:700;font-size:15px;line-height:1.2;">Smart Distribution</div>
        <div style="color:#94a3b8;font-size:12px;">Board</div>
      </div>
    </div>
    """, unsafe_allow_html=True)

    nav_items = {
        "Dashboard":      "🏠",
        "Energy Monitor": "📈",
        "Energy Audit":   "📊",
        "Appliances":     "🔌",
        "Scheduling":     "📅",
        "Power Sources":  "🗼",
        "Logs":           "📋",
        "Settings":       "⚙️",
    }

    for label, icon in nav_items.items():
        active = st.session_state.page == label
        if st.button(f"{icon}  {label}", key=f"nav_{label}",
                     use_container_width=True,
                     type="primary" if active else "secondary"):
            st.session_state.page = label
            st.rerun()

    st.markdown("<div style='height:30px'></div>", unsafe_allow_html=True)
    now_str = datetime.now().strftime("%I:%M:%S %p")

    if st.session_state.ws_data.get("connected", False):
        st.markdown(f"""
        <div class="status-online">
          <div style="font-size:12px;color:#86efac;margin-bottom:4px;">
            <span class="dot-green"></span>ESP32 Connected
          </div>
          <div style="font-size:18px;font-weight:700;color:#22c55e;">Live Data</div>
          <div style="font-size:11px;color:#6ee7b7;margin-top:4px;">IP: {ESP32_IP}</div>
        </div>
        """, unsafe_allow_html=True)
    else:
        st.markdown(f"""
        <div class="status-online" style="background:#450a0a;">
          <div style="font-size:12px;color:#fca5a5;margin-bottom:4px;">
            <span style="width:10px;height:10px;background:#ef4444;border-radius:50%;display:inline-block;margin-right:6px;"></span>ESP32 Disconnected
          </div>
          <div style="font-size:18px;font-weight:700;color:#ef4444;">Simulated Data</div>
          <div style="font-size:11px;color:#fca5a5;margin-top:4px;">Check {ESP32_IP}</div>
        </div>
        """, unsafe_allow_html=True)

    # Show active schedule count in sidebar
    active_scheds = sum(1 for s in st.session_state.schedules if s.get("enabled"))
    st.markdown(f"""
    <div style="margin-top:12px;background:#1e293b;border-radius:8px;padding:10px 12px;">
      <div style="color:#94a3b8;font-size:11px;">SCHEDULES ACTIVE</div>
      <div style="color:#f59e0b;font-size:20px;font-weight:700;">{active_scheds}</div>
    </div>
    """, unsafe_allow_html=True)

    st.markdown("<div style='height:16px'></div>", unsafe_allow_html=True)
    st.markdown("""
    <div style="display:flex;align-items:center;gap:10px;padding:8px 0;">
      <div style="background:#334155;border-radius:50%;width:36px;height:36px;
                  display:flex;align-items:center;justify-content:center;font-size:16px;">👤</div>
      <div>
        <div style="color:white;font-size:13px;font-weight:600;">User</div>
        <div style="color:#94a3b8;font-size:11px;">Admin</div>
      </div>
    </div>
    """, unsafe_allow_html=True)

# ═══════════════════════════════════════════════════════════════════════════════
# DASHBOARD PAGE
# ═══════════════════════════════════════════════════════════════════════════════
if st.session_state.page == "Dashboard":
    fetch_esp32_data()
    data = get_live_data()
    now_str = datetime.now().strftime("%I:%M:%S %p")

    st.markdown(f"""
    <div class="topbar">
      <div class="topbar-title">Dashboard</div>
      <div class="topbar-right">
        <span>📶 Wi-Fi Connected</span>
        <span>🕐 {now_str}</span>
        <span>🔔</span>
      </div>
    </div>
    """, unsafe_allow_html=True)

    time.sleep(2)
    st.rerun()

    c1, c2, c3, c4 = st.columns(4)
    metrics = [
        (c1, "#eff6ff", "#2563eb", "⚡", "Voltage",      f"{data['voltage']} V",     "AC Voltage",       "#2563eb"),
        (c2, "#f0fdf4", "#22c55e", "📈", "Total Current", f"{data['current']} A",     "Bulb+Fan+ESP32",   "#22c55e"),
        (c3, "#fff7ed", "#f97316", "⏱️", "Active Power", f"{data['active_power']} W", "Power",            "#f97316"),
        (c4, "#f5f3ff", "#7c3aed", "📊", "Temperature",  f"{data['temperature']}°C", "DHT11 Sensor",     "#7c3aed"),
    ]
    for col, bg, accent, icon, title, value, sublabel, color in metrics:
        with col:
            st.markdown(f"""
            <div class="metric-card">
              <div class="metric-icon" style="background:{bg};">
                <span style="font-size:22px;">{icon}</span>
              </div>
              <div>
                <div class="metric-title" style="color:{color};">{title}</div>
                <div class="metric-value">{value}</div>
                <div class="metric-label">{sublabel}</div>
              </div>
            </div>
            """, unsafe_allow_html=True)

    st.markdown("<div style='height:14px'></div>", unsafe_allow_html=True)

    col_pzem, col_app, col_src = st.columns([1.2, 1.1, 1.1])

    with col_pzem:
        pzem_rows = [
            ("⚡", "Voltage",        f"{data['voltage']} V"),
            ("〰️", "Total Current",  f"{data['current']} A"),
            ("⏱",  "Active Power",   f"{data['active_power']} W"),
            ("VA",  "Apparent Power", f"{data['apparent_power']} VA"),
            ("Φ",  "Power Factor",   f"{data['power_factor']}"),
            ("〜",  "Frequency",      f"{data['frequency']} Hz"),
            ("🔢",  "Energy Total",   f"{data['energy_total']} kWh"),
        ]
        rows_html = "".join([
            f'<div class="pzem-row"><span class="label"><span>{icon}</span>{label}</span>'
            f'<span class="value">{val}</span></div>'
            for icon, label, val in pzem_rows
        ])
        st.markdown(f"""
        <div class="section-card">
          <div class="section-title">Energy Monitoring (PZEM-004T)</div>
          {rows_html}
          <div style="font-size:10px;color:#94a3b8;margin-top:8px;">Current = Bulb + Fan + ESP32(0.24A) + Sensors(0.05A)</div>
        </div>
        """, unsafe_allow_html=True)

    with col_app:
        b_badge = '<span class="badge-on">ON</span>'  if st.session_state.bulb_on else '<span class="badge-off">OFF</span>'
        f_badge = '<span class="badge-on">ON</span>'  if st.session_state.fan_on  else '<span class="badge-off">OFF</span>'
        # Show schedule badge if a bulb schedule is active now
        bulb_sched_active = any(_schedule_is_active_now(s) for s in st.session_state.schedules if s["appliance"] == "Bulb")
        sched_badge = '<span class="badge-sched">⏰ SCHEDULED</span>' if bulb_sched_active else ""
        st.markdown(f"""
        <div class="section-card">
          <div class="section-title">Appliance Status</div>

          <div class="appliance-row">
            <div style="display:flex;align-items:center;gap:12px;">
              <span style="font-size:32px;">💡</span>
              <div>
                <div style="font-weight:700;font-size:15px;">Bulb (Slave 1)</div>
                {b_badge} {sched_badge}
              </div>
            </div>
            <div style="text-align:right;">
              <div style="font-size:12px;color:#94a3b8;">Current</div>
              <div class="green">{data['bulb_current']} A</div>
              <div style="font-size:12px;color:#94a3b8;">Power</div>
              <div class="green">{data['bulb_power']} W</div>
            </div>
          </div>
          <div class="ts">Last Update: {now_str}</div>

          <div style="height:8px"></div>

          <div class="appliance-row">
            <div style="display:flex;align-items:center;gap:12px;">
              <span style="font-size:32px;">🌀</span>
              <div>
                <div style="font-weight:700;font-size:15px;">Fan</div>
                {f_badge}
              </div>
            </div>
            <div style="text-align:right;">
              <div style="font-size:12px;color:#94a3b8;">Current</div>
              <div class="green">{data['fan_current']} A</div>
              <div style="font-size:12px;color:#94a3b8;">Power</div>
              <div class="green">{data['fan_power']} W</div>
            </div>
          </div>
          <div class="ts">Last Update: {now_str}</div>
        </div>
        """, unsafe_allow_html=True)

    with col_src:
        st.markdown(f"""
        <div class="section-card">
          <div class="section-title">Power Source Status</div>

          <div class="source-row">
            <div style="display:flex;justify-content:space-between;align-items:center;">
              <div style="display:flex;align-items:center;gap:10px;">
                <span style="font-size:26px;color:#22c55e;">🗼</span>
                <span style="font-weight:700;font-size:14px;">Source 1 (Main)</span>
              </div>
              <span class="badge-avail">AVAILABLE</span>
            </div>
            <div class="source-metrics">
              <span>{data['src1_voltage']} V</span>
              <span>{data['src1_freq']} Hz</span>
            </div>
          </div>

          <div class="source-row">
            <div style="display:flex;justify-content:space-between;align-items:center;">
              <div style="display:flex;align-items:center;gap:10px;">
                <span style="font-size:26px;color:#f59e0b;">🗼</span>
                <span style="font-weight:700;font-size:14px;">Source 2 (Backup)</span>
              </div>
              <span class="badge-avail">AVAILABLE</span>
            </div>
            <div class="source-metrics">
              <span>{data['src2_voltage']} V</span>
              <span>{data['src2_freq']} Hz</span>
            </div>
          </div>

          <div class="info-banner">
            ℹ️ Temperature: {data['temperature']}°C | Humidity: {data['humidity']}% | LDR: {data['ldr']}
          </div>
        </div>
        """, unsafe_allow_html=True)

    st.markdown("<div style='height:14px'></div>", unsafe_allow_html=True)

    col_chart, col_ctrl = st.columns([1.8, 1])

    with col_chart:
        hours, power = power_trend_data()
        fig = go.Figure()
        fig.add_trace(go.Scatter(
            x=hours, y=power, mode="lines+markers",
            line=dict(color="#2563eb", width=2.5),
            marker=dict(size=4, color="#2563eb"),
            name="Active Power (W)",
            fill="tozeroy", fillcolor="rgba(37,99,235,0.07)",
        ))
        fig.update_layout(
            title=dict(text="Power Trend (Today)", font=dict(size=14, color="#1e293b"), x=0),
            xaxis=dict(tickvals=[0,4,8,12,16,20,24],
                       ticktext=["00:00","04:00","08:00","12:00","16:00","20:00","24:00"],
                       showgrid=True, gridcolor="#f1f5f9", linecolor="#e2e8f0",
                       title="", tickfont=dict(size=11)),
            yaxis=dict(range=[0, 850], showgrid=True, gridcolor="#f1f5f9",
                       title="Power (W)", tickfont=dict(size=11)),
            plot_bgcolor="white", paper_bgcolor="white",
            margin=dict(l=40, r=20, t=40, b=40),
            legend=dict(orientation="h", y=-0.15, x=0.35, font=dict(size=11), bgcolor="white"),
            height=300,
        )
        st.markdown('<div class="section-card" style="padding-bottom:4px;">', unsafe_allow_html=True)
        st.plotly_chart(fig, use_container_width=True, config={"displayModeBar": False})
        st.markdown('</div>', unsafe_allow_html=True)

    with col_ctrl:
        st.markdown('<div class="section-card">', unsafe_allow_html=True)
        st.markdown('<div class="section-title">Quick Control</div>', unsafe_allow_html=True)

        if st.session_state.ws_data.get("connected", False):
            st.success("🟢 Connected to ESP32")
        else:
            st.error("🔴 Not connected")
            if st.button("🔄 Reconnect", use_container_width=True):
                if st.session_state.ws_conn:
                    try:
                        st.session_state.ws_conn.close()
                    except Exception:
                        pass
                st.session_state.ws_conn = None
                st.rerun()

        qc1, qc2 = st.columns(2)
        with qc1:
            st.markdown("💡 **Bulb**")
            b1, b2 = st.columns(2)
            with b1:
                if st.button("ON", key="bulb_on_btn",
                             type="primary" if st.session_state.bulb_on else "secondary"):
                    send_esp32_command("set_bulb", state=True)
                    st.session_state.bulb_on = True
                    st.rerun()
            with b2:
                if st.button("OFF", key="bulb_off_btn",
                             type="secondary" if st.session_state.bulb_on else "primary"):
                    send_esp32_command("set_bulb", state=False)
                    st.session_state.bulb_on = False
                    st.rerun()

        with qc2:
            st.markdown("🌀 **Fan**")
            f1, f2 = st.columns(2)
            with f1:
                if st.button("ON", key="fan_on_btn",
                             type="primary" if st.session_state.fan_on else "secondary"):
                    send_esp32_command("set_fan", state=True)
                    st.session_state.fan_on = True
                    st.rerun()
            with f2:
                if st.button("OFF", key="fan_off_btn",
                             type="secondary" if st.session_state.fan_on else "primary"):
                    send_esp32_command("set_fan", state=False)
                    st.session_state.fan_on = False
                    st.rerun()

        st.markdown("<div style='height:12px'></div>", unsafe_allow_html=True)
        if st.button("📅  Go to Scheduling", use_container_width=True, type="primary"):
            st.session_state.page = "Scheduling"
            st.rerun()

        st.markdown('</div>', unsafe_allow_html=True)

# ═══════════════════════════════════════════════════════════════════════════════
# ENERGY MONITOR PAGE
# ═══════════════════════════════════════════════════════════════════════════════
elif st.session_state.page == "Energy Monitor":
    data = get_live_data()
    now_str = datetime.now().strftime("%I:%M:%S %p")

    st.markdown(f"""
    <div class="topbar">
      <div class="topbar-title">Energy Monitor</div>
      <div class="topbar-right">
        <span>📶 Wi-Fi Connected</span>
        <span>🕐 {now_str}</span>
        <span>🔔</span>
      </div>
    </div>
    """, unsafe_allow_html=True)

    c1, c2, c3, c4 = st.columns(4)
    metrics = [
        (c1, "#eff6ff", "⚡", "Voltage",      f"{data['voltage']} V",    "#2563eb"),
        (c2, "#f0fdf4", "〰️","Total Current", f"{data['current']} A",    "#22c55e"),
        (c3, "#fff7ed", "Φ", "Power Factor",  f"{data['power_factor']}", "#f97316"),
        (c4, "#f5f3ff", "〜","Frequency",      f"{data['frequency']} Hz", "#7c3aed"),
    ]
    for col, bg, icon, title, value, color in metrics:
        with col:
            st.markdown(f"""
            <div class="metric-card">
              <div class="metric-icon" style="background:{bg};">
                <span style="font-size:22px;">{icon}</span>
              </div>
              <div>
                <div class="metric-title" style="color:{color};">{title}</div>
                <div class="metric-value">{value}</div>
              </div>
            </div>
            """, unsafe_allow_html=True)

    st.markdown("<div style='height:14px'></div>", unsafe_allow_html=True)

    hours, voltage, current = voltage_current_trend()
    _, power = power_trend_data()

    fig_v = go.Figure()
    fig_v.add_trace(go.Scatter(x=hours, y=voltage, mode="lines",
                                line=dict(color="#2563eb", width=2.5),
                                fill="tozeroy", fillcolor="rgba(37,99,235,0.06)"))
    fig_v.update_layout(
        title=dict(text="Voltage Trend (Today)", font=dict(size=14, color="#1e293b"), x=0),
        xaxis=dict(tickvals=[0,4,8,12,16,20,24],
                   ticktext=["00:00","04:00","08:00","12:00","16:00","20:00","24:00"],
                   showgrid=True, gridcolor="#f1f5f9", tickfont=dict(size=11)),
        yaxis=dict(range=[215,245], showgrid=True, gridcolor="#f1f5f9", title="Voltage (V)", tickfont=dict(size=11)),
        plot_bgcolor="white", paper_bgcolor="white",
        margin=dict(l=40, r=20, t=40, b=40), height=300, showlegend=False,
    )

    fig_c = go.Figure()
    fig_c.add_trace(go.Scatter(x=hours, y=current, mode="lines",
                                line=dict(color="#22c55e", width=2.5),
                                fill="tozeroy", fillcolor="rgba(34,197,94,0.08)"))
    fig_c.update_layout(
        title=dict(text="Current Trend (Today)", font=dict(size=14, color="#1e293b"), x=0),
        xaxis=dict(tickvals=[0,4,8,12,16,20,24],
                   ticktext=["00:00","04:00","08:00","12:00","16:00","20:00","24:00"],
                   showgrid=True, gridcolor="#f1f5f9", tickfont=dict(size=11)),
        yaxis=dict(range=[0,5], showgrid=True, gridcolor="#f1f5f9", title="Current (A)", tickfont=dict(size=11)),
        plot_bgcolor="white", paper_bgcolor="white",
        margin=dict(l=40, r=20, t=40, b=40), height=300, showlegend=False,
    )

    cv, cc = st.columns(2)
    with cv:
        st.markdown('<div class="section-card" style="padding-bottom:4px;">', unsafe_allow_html=True)
        st.plotly_chart(fig_v, use_container_width=True, config={"displayModeBar": False})
        st.markdown('</div>', unsafe_allow_html=True)
    with cc:
        st.markdown('<div class="section-card" style="padding-bottom:4px;">', unsafe_allow_html=True)
        st.plotly_chart(fig_c, use_container_width=True, config={"displayModeBar": False})
        st.markdown('</div>', unsafe_allow_html=True)

    st.markdown("<div style='height:14px'></div>", unsafe_allow_html=True)
    apparent = power / 0.89
    fig_p = go.Figure()
    fig_p.add_trace(go.Scatter(x=hours, y=power, mode="lines", name="Active Power (W)",
                                line=dict(color="#f97316", width=2.5)))
    fig_p.add_trace(go.Scatter(x=hours, y=apparent, mode="lines", name="Apparent Power (VA)",
                                line=dict(color="#94a3b8", width=2, dash="dash")))
    fig_p.update_layout(
        title=dict(text="Active vs Apparent Power (Today)", font=dict(size=14, color="#1e293b"), x=0),
        xaxis=dict(tickvals=[0,4,8,12,16,20,24],
                   ticktext=["00:00","04:00","08:00","12:00","16:00","20:00","24:00"],
                   showgrid=True, gridcolor="#f1f5f9", tickfont=dict(size=11)),
        yaxis=dict(showgrid=True, gridcolor="#f1f5f9", title="Power (W / VA)", tickfont=dict(size=11)),
        plot_bgcolor="white", paper_bgcolor="white",
        margin=dict(l=40, r=20, t=40, b=40), height=320,
        legend=dict(orientation="h", y=-0.18, x=0.3, font=dict(size=11)),
    )
    st.markdown('<div class="section-card" style="padding-bottom:4px;">', unsafe_allow_html=True)
    st.plotly_chart(fig_p, use_container_width=True, config={"displayModeBar": False})
    st.markdown('</div>', unsafe_allow_html=True)

    st.markdown("<div style='height:14px'></div>", unsafe_allow_html=True)
    energy_cum = np.cumsum(power) * (24 / len(hours)) / 1000
    fig_e = go.Figure()
    fig_e.add_trace(go.Scatter(x=hours, y=energy_cum, mode="lines",
                                line=dict(color="#7c3aed", width=2.5),
                                fill="tozeroy", fillcolor="rgba(124,58,237,0.08)"))
    fig_e.update_layout(
        title=dict(text="Cumulative Energy Consumption (Today)", font=dict(size=14, color="#1e293b"), x=0),
        xaxis=dict(tickvals=[0,4,8,12,16,20,24],
                   ticktext=["00:00","04:00","08:00","12:00","16:00","20:00","24:00"],
                   showgrid=True, gridcolor="#f1f5f9", tickfont=dict(size=11)),
        yaxis=dict(showgrid=True, gridcolor="#f1f5f9", title="Energy (kWh)", tickfont=dict(size=11)),
        plot_bgcolor="white", paper_bgcolor="white",
        margin=dict(l=40, r=20, t=40, b=40), height=300, showlegend=False,
    )
    st.markdown('<div class="section-card" style="padding-bottom:4px;">', unsafe_allow_html=True)
    st.plotly_chart(fig_e, use_container_width=True, config={"displayModeBar": False})
    st.markdown('</div>', unsafe_allow_html=True)

# ═══════════════════════════════════════════════════════════════════════════════
# ENERGY AUDIT PAGE
# ═══════════════════════════════════════════════════════════════════════════════
elif st.session_state.page == "Energy Audit":
    now_str = datetime.now().strftime("%I:%M:%S %p")
    st.markdown(f"""
    <div class="topbar">
      <div class="topbar-title">Energy Audit Report</div>
      <div class="topbar-right">
        <span>📶 Wi-Fi Connected</span>
        <span>🕐 {now_str}</span>
      </div>
    </div>
    """, unsafe_allow_html=True)

    df = daily_energy_data(90)
    today = df.iloc[-1]; yesterday = df.iloc[-2]
    week_df = df.tail(7); prev_week_df = df.tail(14).head(7)
    month_df = df.tail(30); prev_month_df = df.tail(60).head(30)

    def pct_change(curr, prev):
        return 0 if prev == 0 else (curr - prev) / prev * 100

    today_kwh = today["kwh"]; week_kwh = week_df["kwh"].sum()
    month_kwh = month_df["kwh"].sum(); three_month_kwh = df["kwh"].sum()
    day_change   = pct_change(today_kwh, yesterday["kwh"])
    week_change  = pct_change(week_kwh,  prev_week_df["kwh"].sum())
    month_change = pct_change(month_kwh, prev_month_df["kwh"].sum())

    s1, s2, s3, s4 = st.columns(4)
    for col, value, label, change in [
        (s1, f"{today_kwh:.2f} kWh", "Today's Consumption", day_change),
        (s2, f"{week_kwh:.2f} kWh",  "This Week (7 days)",  week_change),
        (s3, f"{month_kwh:.2f} kWh", "This Month (30 days)",month_change),
        (s4, f"{three_month_kwh:.2f} kWh","Last 3 Months",  None),
    ]:
        with col:
            delta_html = ""
            if change is not None:
                cls = "audit-summary-delta-up" if change >= 0 else "audit-summary-delta-down"
                arrow = "▲" if change >= 0 else "▼"
                delta_html = f'<div class="{cls}">{arrow} {abs(change):.1f}% vs previous</div>'
            st.markdown(f"""
            <div class="audit-summary-card">
              <div class="audit-summary-value">{value}</div>
              <div class="audit-summary-label">{label}</div>
              {delta_html}
            </div>
            """, unsafe_allow_html=True)

    st.markdown("<div style='height:16px'></div>", unsafe_allow_html=True)
    rate = 30
    cost1, cost2 = st.columns(2)
    with cost1:
        st.markdown(f'<div class="info-banner">💰 Estimated cost (last 30 days) at PKR {rate}/unit: <b>PKR {month_kwh*rate:,.0f}</b></div>', unsafe_allow_html=True)
    with cost2:
        st.markdown(f'<div class="info-banner">💰 Estimated cost (last 90 days) at PKR {rate}/unit: <b>PKR {three_month_kwh*rate:,.0f}</b></div>', unsafe_allow_html=True)

    st.markdown("<div style='height:8px'></div>", unsafe_allow_html=True)
    tab_daily, tab_weekly, tab_monthly = st.tabs(["📅 Daily (Last 30 Days)", "📆 Weekly (Last 12 Weeks)", "🗓️ Monthly (Last 3 Months)"])

    with tab_daily:
        daily30 = df.tail(30).copy()
        daily30["label"] = daily30["date"].apply(lambda d: d.strftime("%d %b"))
        fig_d = go.Figure()
        fig_d.add_trace(go.Bar(x=daily30["label"], y=daily30["kwh"], marker_color="#2563eb"))
        fig_d.update_layout(title=dict(text="Daily Unit Consumption", font=dict(size=14,color="#1e293b"),x=0),
                            xaxis=dict(tickangle=-45,tickfont=dict(size=10)),
                            yaxis=dict(title="kWh",showgrid=True,gridcolor="#f1f5f9"),
                            plot_bgcolor="white",paper_bgcolor="white",
                            margin=dict(l=40,r=20,t=40,b=70),height=350,showlegend=False)
        st.markdown('<div class="section-card" style="padding-bottom:4px;">', unsafe_allow_html=True)
        st.plotly_chart(fig_d, use_container_width=True, config={"displayModeBar": False})
        st.markdown('</div>', unsafe_allow_html=True)

    with tab_weekly:
        weekly = df.copy()
        weekly["week"] = weekly["date"].apply(lambda d: (d - timedelta(days=d.weekday())))
        weekly_grp = weekly.groupby("week").agg(kwh=("kwh","sum"),cost=("cost","sum")).reset_index().tail(12)
        weekly_grp["label"] = weekly_grp["week"].apply(lambda d: d.strftime("%d %b"))
        fig_w = go.Figure()
        fig_w.add_trace(go.Bar(x=weekly_grp["label"],y=weekly_grp["kwh"],marker_color="#22c55e"))
        fig_w.update_layout(title=dict(text="Weekly Unit Consumption",font=dict(size=14,color="#1e293b"),x=0),
                            xaxis=dict(tickangle=-45,tickfont=dict(size=10)),
                            yaxis=dict(title="kWh",showgrid=True,gridcolor="#f1f5f9"),
                            plot_bgcolor="white",paper_bgcolor="white",
                            margin=dict(l=40,r=20,t=40,b=70),height=350,showlegend=False)
        st.markdown('<div class="section-card" style="padding-bottom:4px;">', unsafe_allow_html=True)
        st.plotly_chart(fig_w, use_container_width=True, config={"displayModeBar": False})
        st.markdown('</div>', unsafe_allow_html=True)

    with tab_monthly:
        monthly = df.copy()
        monthly["month"] = monthly["date"].apply(lambda d: d.strftime("%Y-%m"))
        monthly_grp = monthly.groupby("month").agg(kwh=("kwh","sum"),cost=("cost","sum")).reset_index()
        monthly_grp["label"] = monthly_grp["month"].apply(lambda m: datetime.strptime(m,"%Y-%m").strftime("%b %Y"))
        fig_m = go.Figure()
        fig_m.add_trace(go.Bar(x=monthly_grp["label"],y=monthly_grp["kwh"],marker_color="#7c3aed"))
        fig_m.update_layout(title=dict(text="Monthly Unit Consumption",font=dict(size=14,color="#1e293b"),x=0),
                            xaxis=dict(tickfont=dict(size=11)),
                            yaxis=dict(title="kWh",showgrid=True,gridcolor="#f1f5f9"),
                            plot_bgcolor="white",paper_bgcolor="white",
                            margin=dict(l=40,r=20,t=40,b=40),height=350,showlegend=False)
        st.markdown('<div class="section-card" style="padding-bottom:4px;">', unsafe_allow_html=True)
        st.plotly_chart(fig_m, use_container_width=True, config={"displayModeBar": False})
        st.markdown('</div>', unsafe_allow_html=True)

    st.markdown("<div style='height:14px'></div>", unsafe_allow_html=True)
    csv = df.to_csv(index=False).encode("utf-8")
    st.download_button("⬇️ Download Full Audit Data (CSV)", csv, "energy_audit_report.csv", "text/csv")

# ═══════════════════════════════════════════════════════════════════════════════
# APPLIANCES PAGE
# ═══════════════════════════════════════════════════════════════════════════════
elif st.session_state.page == "Appliances":
    data = get_live_data()
    now_str = datetime.now().strftime("%I:%M:%S %p")

    st.markdown(f"""
    <div class="topbar">
      <div class="topbar-title">Appliances</div>
      <div class="topbar-right">
        <span>📶 Wi-Fi Connected</span>
        <span>🕐 {now_str}</span>
      </div>
    </div>
    """, unsafe_allow_html=True)

    a1, a2 = st.columns(2)
    with a1:
        b_badge = '<span class="badge-on">ON</span>' if st.session_state.bulb_on else '<span class="badge-off">OFF</span>'
        bulb_sched_active = any(_schedule_is_active_now(s) for s in st.session_state.schedules if s["appliance"] == "Bulb")
        sched_badge = '<span class="badge-sched">⏰ SCHEDULED</span>' if bulb_sched_active else ""
        st.markdown('<div class="section-card">', unsafe_allow_html=True)
        st.markdown('<div class="section-title">💡 Bulb — Slave 1</div>', unsafe_allow_html=True)
        st.markdown(f"""
          <div class="appliance-row">
            <div style="display:flex;align-items:center;gap:12px;">
              <span style="font-size:32px;">💡</span>
              <div>
                <div style="font-weight:700;font-size:15px;">Slave 1 Light</div>
                {b_badge} {sched_badge}
              </div>
            </div>
            <div style="text-align:right;">
              <div style="font-size:12px;color:#94a3b8;">Current</div>
              <div class="green">{data['bulb_current']} A</div>
              <div style="font-size:12px;color:#94a3b8;">Power</div>
              <div class="green">{data['bulb_power']} W</div>
            </div>
          </div>
        """, unsafe_allow_html=True)
        bb1, bb2 = st.columns(2)
        with bb1:
            if st.button("Turn ON", key="bulb_on_appl", use_container_width=True,
                         type="primary" if st.session_state.bulb_on else "secondary"):
                send_esp32_command("set_bulb", state=True)
                st.session_state.bulb_on = True
                st.rerun()
        with bb2:
            if st.button("Turn OFF", key="bulb_off_appl", use_container_width=True,
                         type="secondary" if st.session_state.bulb_on else "primary"):
                send_esp32_command("set_bulb", state=False)
                st.session_state.bulb_on = False
                st.rerun()
        st.markdown('</div>', unsafe_allow_html=True)

    with a2:
        f_badge = '<span class="badge-on">ON</span>' if st.session_state.fan_on else '<span class="badge-off">OFF</span>'
        st.markdown('<div class="section-card">', unsafe_allow_html=True)
        st.markdown('<div class="section-title">🌀 Fan</div>', unsafe_allow_html=True)
        st.markdown(f"""
          <div class="appliance-row">
            <div style="display:flex;align-items:center;gap:12px;">
              <span style="font-size:32px;">🌀</span>
              <div>
                <div style="font-weight:700;font-size:15px;">Ceiling Fan</div>
                {f_badge}
              </div>
            </div>
            <div style="text-align:right;">
              <div style="font-size:12px;color:#94a3b8;">Current</div>
              <div class="green">{data['fan_current']} A</div>
              <div style="font-size:12px;color:#94a3b8;">Power</div>
              <div class="green">{data['fan_power']} W</div>
            </div>
          </div>
        """, unsafe_allow_html=True)
        ff1, ff2 = st.columns(2)
        with ff1:
            if st.button("Turn ON", key="fan_on_appl", use_container_width=True,
                         type="primary" if st.session_state.fan_on else "secondary"):
                send_esp32_command("set_fan", state=True)
                st.session_state.fan_on = True
                st.rerun()
        with ff2:
            if st.button("Turn OFF", key="fan_off_appl", use_container_width=True,
                         type="secondary" if st.session_state.fan_on else "primary"):
                send_esp32_command("set_fan", state=False)
                st.session_state.fan_on = False
                st.rerun()
        st.markdown('</div>', unsafe_allow_html=True)

    st.markdown("<div style='height:14px'></div>", unsafe_allow_html=True)
    st.info("➕ To add more appliances, connect additional PZEM sensors and extend this page.")

# ═══════════════════════════════════════════════════════════════════════════════
# SCHEDULING PAGE  ← fully functional now
# ═══════════════════════════════════════════════════════════════════════════════
elif st.session_state.page == "Scheduling":
    now_str = datetime.now().strftime("%I:%M:%S %p")

    st.markdown(f"""
    <div class="topbar">
      <div class="topbar-title">Scheduling — Slave 1 Light Control</div>
      <div class="topbar-right">
        <span>📶 Wi-Fi Connected</span>
        <span>🕐 {now_str}</span>
      </div>
    </div>
    """, unsafe_allow_html=True)

    # ── How it works banner ──────────────────────────────────────────────────
    st.markdown("""
    <div class="info-banner" style="margin-bottom:14px;">
      ℹ️ <b>How scheduling works:</b> The dashboard checks schedules on every page refresh (~2 s on Dashboard, manual on this page).
      When the current time matches a schedule's ON or OFF time, a <code>set_bulb</code> / <code>set_fan</code> WebSocket command
      is sent to the ESP32, which controls Slave 1's LED via the existing relay logic.
      Keep the Dashboard tab open for automatic execution.
    </div>
    """, unsafe_allow_html=True)

    col_list, col_add = st.columns([1.4, 1])

    with col_list:
        st.markdown('<div class="section-card">', unsafe_allow_html=True)
        st.markdown('<div class="section-title">Active Schedules</div>', unsafe_allow_html=True)

        if not st.session_state.schedules:
            st.markdown('<div class="section-sub">No schedules configured yet.</div>', unsafe_allow_html=True)
        else:
            for idx, sched in enumerate(st.session_state.schedules):
                icon = "💡" if sched["appliance"] == "Bulb" else "🌀"
                is_active = _schedule_is_active_now(sched)
                next_str  = _next_trigger_str(sched) if sched.get("enabled") else ""
                status_badge = '<span class="badge-on">ENABLED</span>' if sched["enabled"] else '<span class="badge-off">DISABLED</span>'
                active_html  = f'<div class="schedule-active-now">🟢 Active window now</div>' if is_active else ""
                next_html    = f'<div class="schedule-next-trigger">⏰ {next_str}</div>' if next_str and not is_active else ""

                card_class = "schedule-item" if sched["enabled"] else "schedule-item-disabled"

                row_l, row_r = st.columns([4, 1])
                with row_l:
                    st.markdown(f"""
                    <div class="{card_class}">
                      <div style="display:flex;justify-content:space-between;align-items:center;">
                        <div>
                          <div style="font-weight:700;font-size:14px;">{icon} {sched['appliance']}</div>
                          <div class="schedule-time">ON: {sched['on_time']} → OFF: {sched['off_time']}</div>
                          <div class="schedule-days">📅 {sched['days']}</div>
                        </div>
                        {status_badge}
                      </div>
                      {active_html}
                      {next_html}
                    </div>
                    """, unsafe_allow_html=True)
                with row_r:
                    toggle_label = "Disable" if sched["enabled"] else "Enable"
                    if st.button(toggle_label, key=f"toggle_sched_{idx}", use_container_width=True):
                        st.session_state.schedules[idx]["enabled"] = not sched["enabled"]
                        st.rerun()
                    if st.button("🗑️ Delete", key=f"del_sched_{idx}", use_container_width=True):
                        st.session_state.schedules.pop(idx)
                        st.rerun()

        st.markdown('</div>', unsafe_allow_html=True)

        # ── Manual trigger for testing ───────────────────────────────────────
        st.markdown("<div style='height:12px'></div>", unsafe_allow_html=True)
        st.markdown('<div class="section-card">', unsafe_allow_html=True)
        st.markdown('<div class="section-title">🧪 Manual Test — Slave 1 Light</div>', unsafe_allow_html=True)
        st.markdown('<div class="section-sub">Send an immediate command to test the connection without waiting for a schedule.</div>', unsafe_allow_html=True)
        mt1, mt2 = st.columns(2)
        with mt1:
            if st.button("💡 Force Bulb ON", use_container_width=True, type="primary"):
                ok = send_esp32_command("set_bulb", state=True)
                st.session_state.bulb_on = True
                st.session_state.schedule_log.insert(0, {
                    "timestamp": datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
                    "action": "Bulb → ON",
                    "source": "Manual test" + (" ✓" if ok else " ✗ (no conn)"),
                })
                st.rerun()
        with mt2:
            if st.button("💡 Force Bulb OFF", use_container_width=True):
                ok = send_esp32_command("set_bulb", state=False)
                st.session_state.bulb_on = False
                st.session_state.schedule_log.insert(0, {
                    "timestamp": datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
                    "action": "Bulb → OFF",
                    "source": "Manual test" + (" ✓" if ok else " ✗ (no conn)"),
                })
                st.rerun()
        st.markdown('</div>', unsafe_allow_html=True)

        # ── Schedule event log ───────────────────────────────────────────────
        if st.session_state.schedule_log:
            st.markdown("<div style='height:12px'></div>", unsafe_allow_html=True)
            st.markdown('<div class="section-card">', unsafe_allow_html=True)
            st.markdown('<div class="section-title">📋 Schedule Execution Log</div>', unsafe_allow_html=True)
            log_df = pd.DataFrame(st.session_state.schedule_log)
            st.dataframe(log_df, use_container_width=True, hide_index=True, height=220)
            if st.button("🗑️ Clear Log"):
                st.session_state.schedule_log = []
                st.rerun()
            st.markdown('</div>', unsafe_allow_html=True)

    with col_add:
        st.markdown('<div class="section-card">', unsafe_allow_html=True)
        st.markdown('<div class="section-title">➕ Add New Schedule</div>', unsafe_allow_html=True)

        # Only Bulb (Slave 1 LED) is supported right now per the project scope
        appliance = st.selectbox("Appliance", ["Bulb"], help="Only Slave 1 Bulb is controllable currently.")
        on_time   = st.time_input("Turn ON time",  value=datetime.strptime("18:00", "%H:%M").time())
        off_time  = st.time_input("Turn OFF time", value=datetime.strptime("23:00", "%H:%M").time())
        days_option = st.selectbox("Repeat", ["Mon–Sun", "Mon–Fri", "Sat–Sun", "Custom"])

        if on_time == off_time:
            st.markdown('<div class="warn-banner">⚠️ ON and OFF times are the same — schedule will do nothing useful.</div>', unsafe_allow_html=True)

        if st.button("📅  Add Schedule", use_container_width=True, type="primary"):
            st.session_state.schedules.append({
                "appliance":          appliance,
                "on_time":            on_time.strftime("%H:%M"),
                "off_time":           off_time.strftime("%H:%M"),
                "days":               days_option,
                "enabled":            True,
                "last_on_triggered":  None,
                "last_off_triggered": None,
            })
            st.rerun()

        st.markdown("<div style='height:10px'></div>", unsafe_allow_html=True)
        st.markdown("""
        <div class="info-banner" style="margin-top:0;flex-direction:column;align-items:flex-start;gap:4px;">
          <b>ℹ️ Tips</b>
          <span>• Keep the Dashboard page open for auto-execution every ~2 s.</span>
          <span>• Schedules fire once per minute at the exact HH:MM.</span>
          <span>• Manual override (Quick Control) always works and overrides schedules.</span>
          <span>• "Active window now" badge appears when inside the ON→OFF window.</span>
        </div>
        """, unsafe_allow_html=True)
        st.markdown('</div>', unsafe_allow_html=True)

# ═══════════════════════════════════════════════════════════════════════════════
# POWER SOURCES PAGE
# ═══════════════════════════════════════════════════════════════════════════════
elif st.session_state.page == "Power Sources":
    data = get_live_data()
    now_str = datetime.now().strftime("%I:%M:%S %p")
    st.markdown(f"""
    <div class="topbar">
      <div class="topbar-title">Power Sources</div>
      <div class="topbar-right">
        <span>📶 Wi-Fi Connected</span>
        <span>🕐 {now_str}</span>
      </div>
    </div>
    """, unsafe_allow_html=True)

    p1, p2 = st.columns(2)
    with p1:
        st.markdown(f"""
        <div class="section-card">
          <div class="section-title">🗼 Source 1 (Main / WAPDA)</div>
          <div class="source-row">
            <div style="display:flex;justify-content:space-between;align-items:center;">
              <span style="font-weight:700;font-size:14px;">Status</span>
              <span class="badge-avail">AVAILABLE — ACTIVE</span>
            </div>
            <div class="source-metrics">
              <span>Voltage: {data['src1_voltage']} V</span>
              <span>Frequency: {data['src1_freq']} Hz</span>
            </div>
          </div>
          <div class="info-banner">ℹ️ This source is currently powering the load.</div>
        </div>
        """, unsafe_allow_html=True)
    with p2:
        st.markdown(f"""
        <div class="section-card">
          <div class="section-title">🗼 Source 2 (Backup / Generator)</div>
          <div class="source-row">
            <div style="display:flex;justify-content:space-between;align-items:center;">
              <span style="font-weight:700;font-size:14px;">Status</span>
              <span class="badge-avail">AVAILABLE — STANDBY</span>
            </div>
            <div class="source-metrics">
              <span>Voltage: {data['src2_voltage']} V</span>
              <span>Frequency: {data['src2_freq']} Hz</span>
            </div>
          </div>
          <div class="info-banner">ℹ️ Automatic transfer switch engages if Source 1 fails.</div>
        </div>
        """, unsafe_allow_html=True)

# ═══════════════════════════════════════════════════════════════════════════════
# LOGS PAGE
# ═══════════════════════════════════════════════════════════════════════════════
elif st.session_state.page == "Logs":
    now_str = datetime.now().strftime("%I:%M:%S %p")
    st.markdown(f"""
    <div class="topbar">
      <div class="topbar-title">Logs</div>
      <div class="topbar-right">
        <span>📶 Wi-Fi Connected</span>
        <span>🕐 {now_str}</span>
      </div>
    </div>
    """, unsafe_allow_html=True)

    # Merge schedule log with sample system logs
    combined_logs = []
    for entry in st.session_state.schedule_log:
        combined_logs.append({
            "Timestamp": entry["timestamp"],
            "Event":     entry["action"],
            "Type":      entry["source"],
        })

    sample_logs = pd.DataFrame({
        "Timestamp": pd.date_range(end=datetime.now(), periods=10, freq="H").strftime("%Y-%m-%d %H:%M"),
        "Event": ["Bulb turned ON", "Fan turned OFF", "Source switched to Main",
                  "Voltage spike detected", "Bulb turned OFF", "Fan turned ON",
                  "System restarted", "Schedule: Fan OFF", "Schedule: Bulb ON",
                  "Energy reading logged"],
        "Type":  ["Control","Control","Power Source","Alert","Control",
                  "Control","System","Schedule","Schedule","Data"],
    })

    if combined_logs:
        sched_df = pd.DataFrame(combined_logs)
        log_data = pd.concat([sched_df, sample_logs], ignore_index=True)
    else:
        log_data = sample_logs

    st.markdown('<div class="section-card">', unsafe_allow_html=True)
    st.markdown('<div class="section-title">Recent Event Logs</div>', unsafe_allow_html=True)
    st.dataframe(log_data, use_container_width=True, hide_index=True, height=400)
    st.markdown('</div>', unsafe_allow_html=True)

# ═══════════════════════════════════════════════════════════════════════════════
# SETTINGS PAGE
# ═══════════════════════════════════════════════════════════════════════════════
elif st.session_state.page == "Settings":
    now_str = datetime.now().strftime("%I:%M:%S %p")
    st.markdown(f"""
    <div class="topbar">
      <div class="topbar-title">Settings</div>
      <div class="topbar-right">
        <span>📶 Wi-Fi Connected</span>
        <span>🕐 {now_str}</span>
      </div>
    </div>
    """, unsafe_allow_html=True)

    st.markdown('<div class="section-card">', unsafe_allow_html=True)
    st.markdown('<div class="section-title">⚙️ Thresholds & Alerts</div>', unsafe_allow_html=True)
    st.slider("Over-voltage alert threshold (V)",  220, 260, 245)
    st.slider("Under-voltage alert threshold (V)", 180, 220, 200)
    st.slider("Overcurrent alert threshold (A)",     1,  20,  10)
    st.markdown('</div>', unsafe_allow_html=True)

    st.markdown("<div style='height:14px'></div>", unsafe_allow_html=True)

    st.markdown('<div class="section-card">', unsafe_allow_html=True)
    st.markdown('<div class="section-title">💰 Billing / Audit Settings</div>', unsafe_allow_html=True)
    st.number_input("Electricity rate (PKR per unit / kWh)", min_value=1, max_value=100, value=30)
    st.markdown('</div>', unsafe_allow_html=True)