#!/bin/bash
cd /home/salamat/fish_project
mkdir -p logs

echo "[$(date '+%Y-%m-%d %H:%M:%S')] AI Boat System Starting..." >> logs/boot.log

# Kill old processes
pkill -f flask_server.py 2>/dev/null
pkill -f streamlit 2>/dev/null
pkill -f ai_boat_system.py 2>/dev/null
sleep 3

source venv/bin/activate 2>/dev/null || true

# Start services in background
python3 dashboard/flask_server.py > logs/flask.log 2>&1 &
echo $! > logs/flask.pid

streamlit run dashboard/dashboard_server.py \
  --server.port 8501 \
  --server.address 0.0.0.0 > logs/streamlit.log 2>&1 &
echo $! > logs/streamlit.pid

python3 ai_boat_system.py > logs/pi_main.log 2>&1 &
echo $! > logs/pi.pid

echo "[$(date '+%Y-%m-%d %H:%M:%S')] All services started successfully" >> logs/boot.log

# Keep the script running so systemd doesn't restart it
sleep infinity
