#!/bin/bash

# ==========================================
# AI BOAT SYSTEM - COMPLETE START SCRIPT
# Starts Flask API, Streamlit Dashboard, and Pi Main Code
# ==========================================

cd /home/salamat/fish_project
source venv/bin/activate

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Create logs directory if not exists
mkdir -p logs

# Kill existing processes
echo -e "${YELLOW}🛑 Stopping existing processes...${NC}"
pkill -f flask_server.py 2>/dev/null
pkill -f streamlit 2>/dev/null
pkill -f ai_boat_system.py 2>/dev/null
sleep 2

echo -e "${BLUE}🚤 Starting AI Boat System...${NC}"
echo "================================"

# Start Flask API
echo -e "${BLUE}📡 Starting Flask API...${NC}"
python3 dashboard/flask_server.py > logs/flask.log 2>&1 &
FLASK_PID=$!
echo -e "${GREEN}✅ Flask API started (PID: $FLASK_PID) on port 5000${NC}"

sleep 2

# Check if Flask API started successfully
if curl -s http://localhost:5000/health > /dev/null; then
    echo -e "${GREEN}✅ Flask API is responding${NC}"
else
    echo -e "${RED}⚠️ Flask API may not have started properly${NC}"
fi

# Start Streamlit Dashboard
echo -e "${BLUE}📊 Starting Streamlit Dashboard...${NC}"
streamlit run dashboard/dashboard_server.py \
    --server.port 8501 \
    --server.address 0.0.0.0 \
    --server.enableCORS true \
    --server.enableXsrfProtection false \
    > logs/streamlit.log 2>&1 &
STREAMLIT_PID=$!
echo -e "${GREEN}✅ Streamlit dashboard started (PID: $STREAMLIT_PID) on port 8501${NC}"

sleep 3

# Start Pi Main Code
echo -e "${BLUE}🤖 Starting Pi Main Code...${NC}"
python3 ai_boat_system.py > logs/pi_main.log 2>&1 &
PI_PID=$!
echo -e "${GREEN}✅ Pi main code started (PID: $PI_PID)${NC}"

# Save PIDs to file for later use
echo $FLASK_PID > logs/flask.pid
echo $STREAMLIT_PID > logs/streamlit.pid
echo $PI_PID > logs/pi.pid

# Get Pi IP address
PI_IP=$(hostname -I | awk '{print $1}')

echo "================================"
echo -e "${GREEN}✅ ALL SERVICES STARTED!${NC}"
echo "================================"
echo -e "${BLUE}📍 Dashboard URL:${NC} http://$PI_IP:8501"
echo -e "${BLUE}📡 API Endpoint:${NC} http://$PI_IP:5000"
echo -e "${BLUE}📁 Log files:${NC} logs/ directory"
echo "================================"
echo -e "${YELLOW}💡 Useful commands:${NC}"
echo "  View Flask logs:     tail -f logs/flask.log"
echo "  View Dashboard logs: tail -f logs/streamlit.log"
echo "  View Pi logs:        tail -f logs/pi_main.log"
echo "  Stop all services:   ./stop_boat_system.sh"
echo "  Check status:        ./status_boat_system.sh"
echo "================================"

# Optional: Show last few lines of Pi log
sleep 2
echo -e "${BLUE}📋 Last few lines from Pi main code:${NC}"
tail -5 logs/pi_main.log 2>/dev/null || echo "Waiting for logs..."