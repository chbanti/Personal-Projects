import dash
from dash import dcc, html
from dash.dependencies import Input, Output
import dash_bootstrap_components as dbc
import pandas as pd
import plotly.express as px
import plotly.graph_objects as go
import requests
import logging

# ==================================================
# CONFIGURATION
# ==================================================
FIREBASE_URL = "https://racr-ea0e0-default-rtdb.firebaseio.com/esp32/device1.json"
REFRESH_INTERVAL = 10_000
ENERGY_COST_PER_KWH = 0.15

# ==================================================
# SOFT LIGHT THEME COLORS
# ==================================================
BG = "#f2f4f8"
CARD_BG = "#ffffff"
PRIMARY = "#2563eb"
SECONDARY = "#16a34a"
DANGER = "#dc2626"
NEUTRAL = "#475569"
BORDER = "#e2e8f0"
TEXT = "#1e293b"

# ==================================================
logging.basicConfig(level=logging.INFO)

# ==================================================
# DATA FETCH
# ==================================================
def fetch_data() -> pd.DataFrame:
    try:
        r = requests.get(FIREBASE_URL, timeout=5)
        r.raise_for_status()
        data = r.json()

        if not data:
            return pd.DataFrame()

        df = pd.DataFrame.from_dict(data, orient="index")

        for col in [
            "timestamp", "ldr", "temp",
            "relay_state", "energyWh",
            "current", "stable_class"
        ]:
            if col not in df.columns:
                df[col] = None

        df["time"] = pd.to_datetime(df["timestamp"], unit="s")
        df = df.sort_values("time")
        return df

    except Exception as e:
        logging.error(e)
        return pd.DataFrame()

# ==================================================
# APP
# ==================================================
app = dash.Dash(
    __name__,
    external_stylesheets=[
        dbc.themes.BOOTSTRAP,
        "https://fonts.googleapis.com/css2?family=IBM+Plex+Sans:wght@300;400;500;600;700&display=swap"
    ]
)

# ==================================================
# METRIC CARD
# ==================================================
def metric_card(title, value_id, color):
    return dbc.Card(
        dbc.CardBody(
            [
                html.Div(title, style={"color": NEUTRAL, "fontSize": "0.95rem"}),
                html.Div(
                    id=value_id,
                    style={
                        "color": color,
                        "fontSize": "2rem",
                        "fontWeight": "600"
                    }
                )
            ]
        ),
        style={
            "background": CARD_BG,
            "border": f"1px solid {BORDER}",
            "borderRadius": "14px",
            "boxShadow": "0 6px 18px rgba(0,0,0,0.06)"
        }
    )

# ==================================================
# CONTENT
# ==================================================
content = dbc.Container(
    [
        html.H1(
            "Adaptive Street Lighting Dashboard",
            style={"fontWeight": "600", "marginBottom": "28px"}
        ),

        dbc.Row(
            [
                dbc.Col(metric_card("LDR Value", "ldr-value", PRIMARY), md=2),
                dbc.Col(metric_card("Temperature (°C)", "temp-value", DANGER), md=2),
                dbc.Col(metric_card("Relay State", "relay-value", NEUTRAL), md=2),
                dbc.Col(metric_card("Energy (Wh)", "energy-value", SECONDARY), md=3),
                dbc.Col(metric_card("Last Update", "update-value", NEUTRAL), md=3),
            ],
            className="g-4 mb-5"
        ),

        dbc.Row(
            [
                dbc.Col(dcc.Graph(id="ldr-chart"), md=6),
                dbc.Col(dcc.Graph(id="temp-chart"), md=6),
            ],
            className="mb-5"
        ),

        dbc.Row(
            [
                dbc.Col(dcc.Graph(id="pred-chart"), md=6),
                dbc.Col(dcc.Graph(id="relay-chart"), md=6),
            ],
            className="mb-5"
        ),

        # ✅ CURRENT GRAPH (REPLACED ENERGY GRAPH)
        dbc.Row(
            [
                dbc.Col(dcc.Graph(id="current-chart"), md=12),
            ],
            className="mb-5"
        ),

        dbc.Card(
            dbc.CardBody(
                [
                    html.H4("Daily Energy Consumption (Wh)", className="mb-2"),
                    html.Div(id="daily-table")
                ]
            ),
            style={
                "background": CARD_BG,
                "border": f"1px solid {BORDER}",
                "borderRadius": "14px",
                "boxShadow": "0 6px 18px rgba(0,0,0,0.06)"
            },
            className="mb-3"
        ),

        dbc.Row(
            [
                dbc.Col(metric_card("Monthly Energy Usage", "monthly-kwh", SECONDARY), md=3),
                dbc.Col(metric_card("Estimated Bill", "estimated-bill", PRIMARY), md=3),
            ],
            className="g-4 mb-5"
        ),

        dcc.Interval(id="interval", interval=REFRESH_INTERVAL, n_intervals=0)
    ],
    fluid=True,
    style={"padding": "40px"}
)

# ==================================================
# LAYOUT
# ==================================================
app.layout = html.Div(
    content,
    style={
        "backgroundColor": BG,
        "minHeight": "100vh",
        "fontFamily": "IBM Plex Sans",
        "color": TEXT
    }
)

# ==================================================
# CALLBACK
# ==================================================
@app.callback(
    [
        Output("ldr-value", "children"),
        Output("temp-value", "children"),
        Output("relay-value", "children"),
        Output("energy-value", "children"),
        Output("update-value", "children"),
        Output("ldr-chart", "figure"),
        Output("temp-chart", "figure"),
        Output("pred-chart", "figure"),
        Output("relay-chart", "figure"),
        Output("current-chart", "figure"),
        Output("daily-table", "children"),
        Output("monthly-kwh", "children"),
        Output("estimated-bill", "children"),
    ],
    Input("interval", "n_intervals")
)
def update_dashboard(_):
    df = fetch_data()
    if df.empty:
        raise dash.exceptions.PreventUpdate

    last = df.iloc[-1]
    template = "plotly_white"

    fig_ldr = px.line(df, x="time", y="ldr", template=template)
    fig_ldr.update_traces(line_color=PRIMARY)

    fig_temp = px.line(df, x="time", y="temp", template=template)
    fig_temp.update_traces(line_color=DANGER)

    fig_pred = px.scatter(df, x="time", y="stable_class", template=template)
    fig_pred.update_traces(marker_color=NEUTRAL)

    df["relay_num"] = df["relay_state"].map({"OFF": 0, "ON": 1})
    fig_relay = go.Figure(go.Scatter(
        x=df["time"],
        y=df["relay_num"],
        mode="lines",
        line_shape="hv",
        line=dict(color=NEUTRAL)
    ))
    fig_relay.update_layout(
        template=template,
        yaxis=dict(tickvals=[0, 1], ticktext=["OFF", "ON"])
    )

    # ✅ CURRENT GRAPH
    fig_current = px.line(df, x="time", y="current", template=template)
    fig_current.update_traces(line_color=PRIMARY)
    fig_current.update_layout(yaxis_title="Current (A)")

    # ENERGY CALCULATION (UNCHANGED)
    df["date"] = df["time"].dt.date
    daily = df.groupby("date")["energyWh"].max().reset_index()

    table = dbc.Table(
        [
            html.Thead(html.Tr([html.Th("Date"), html.Th("Energy (Wh)")])),

            html.Tbody(
                [
                    html.Tr([html.Td(d), html.Td(f"{e:.4f}")])
                    for d, e in zip(daily["date"], daily["energyWh"])
                ]
            ),
        ],
        bordered=True,
        hover=True
    )

    monthly_kwh = daily["energyWh"].sum() / 1000
    bill = monthly_kwh * ENERGY_COST_PER_KWH

    return (
        last["ldr"],
        f"{last['temp']:.2f}",
        last["relay_state"],
        f"{last['energyWh']:.4f}",
        last["time"].strftime("%Y-%m-%d %H:%M:%S"),
        fig_ldr,
        fig_temp,
        fig_pred,
        fig_relay,
        fig_current,
        table,
        f"{monthly_kwh:.3f} kWh",
        f"PKR {bill:.2f}"
    )

# ==================================================
if __name__ == "__main__":
    app.run(debug=True)
