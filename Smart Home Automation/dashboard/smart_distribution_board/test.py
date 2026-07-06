# test_websocket.py
import websocket
import json

ESP32_IP = "172.19.161.44"

try:
    print(f"Connecting to ws://{ESP32_IP}:81...")
    ws = websocket.create_connection(f"ws://{ESP32_IP}:81", timeout=5)
    print("✅ Connected!")
    
    # Send status request
    ws.send(json.dumps({"command": "get_status"}))
    print("📤 Sent: get_status")
    
    # Receive response
    ws.settimeout(3)
    response = ws.recv()
    print(f"📥 Received: {response}")
    
    data = json.loads(response)
    print(f"✅ Voltage: {data.get('voltage', 'N/A')} V")
    print(f"✅ Current: {data.get('current', 'N/A')} A")
    
    ws.close()
    
except websocket.WebSocketTimeoutException:
    print("❌ Timeout - No response from ESP32")
except ConnectionRefusedError:
    print("❌ Connection refused - WebSocket server not running on ESP32")
except Exception as e:
    print(f"❌ Error: {e}")