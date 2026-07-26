#!/bin/bash

# ==========================================
# AI BOAT SYSTEM - STOP SCRIPT
# Stops all services gracefully
# ==========================================

echo "========================================="
echo "🛑 Stopping AI Boat System..."
echo "========================================="

cd /home/salamat/fish_project

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

# Stop Pi main code
if [ -f logs/pi.pid ]; then
    PID=$(cat logs/pi.pid)
    if kill -0 $PID 2>/dev/null; then
        echo -e "${YELLOW}🛑 Stopping Pi main code (PID: $PID)...${NC}"
        kill $PID 2>/dev/null
        sleep 2
        kill -9 $PID 2>/dev/null
        echo -e "${GREEN}✅ Pi main code stopped${NC}"
    fi
    rm -f logs/pi.pid
fi

# Stop Streamlit
if [ -f logs/streamlit.pid ]; then
    PID=$(cat logs/streamlit.pid)
    if kill -0 $PID 2>/dev/null; then
        echo -e "${YELLOW}🛑 Stopping Streamlit dashboard (PID: $PID)...${NC}"
        kill $PID 2>/dev/null
        sleep 2
        kill -9 $PID 2>/dev/null
        echo -e "${GREEN}✅ Streamlit dashboard stopped${NC}"
    fi
    rm -f logs/streamlit.pid
fi

# Stop Flask API
if [ -f logs/flask.pid ]; then
    PID=$(cat logs/flask.pid)
    if kill -0 $PID 2>/dev/null; then
        echo -e "${YELLOW}🛑 Stopping Flask API (PID: $PID)...${NC}"
        kill $PID 2>/dev/null
        sleep 2
        kill -9 $PID 2>/dev/null
        echo -e "${GREEN}✅ Flask API stopped${NC}"
    fi
    rm -f logs/flask.pid
fi

# Force kill any remaining processes
echo -e "${YELLOW}🧹 Cleaning up...${NC}"
pkill -f flask_server.py 2>/dev/null
pkill -f streamlit 2>/dev/null
pkill -f ai_boat_system.py 2>/dev/null

echo "========================================="
echo -e "${GREEN}✅ ALL SERVICES STOPPED${NC}"
echo "========================================="