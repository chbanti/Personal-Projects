#!/bin/bash
cd /home/salamat/fish_project
source venv/bin/activate 2>/dev/null || echo "Warning: venv not found"

mkdir -p logs

echo "[$(date)] Starting AI Boat System..." >> logs/boot.log

# Start Flask
python3 dashboard/flask_server.py > logs/flask.log 2>&1 &
echo $! > logs/flask.pid

# Start Streamlit
streamlit run dashboard/dashboard_server.py \
  --server.port 8501 \
  --server.address 0.0.0.0 \
  --server.enableCORS true \
  > logs/streamlit.log 2>&1 &
echo $! > logs/streamlit.pid

# Start Main Pi Code
python3 ai_boat_system.py > logs/pi_main.log 2>&1 &
echo $! > logs/pi.pid

echo "[$(date)] All services started" >> logs/boot.log
