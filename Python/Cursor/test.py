import streamlit as st
import streamlit.components.v1 as components

st.set_page_config(layout="wide")

html_content = """
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<style>
body { background: #eee; font-family: Arial; }
.box {
    background: white;
    padding: 40px;
    margin: 20px auto;
    width: 600px;
    border-radius: 10px;
    box-shadow: 0 0 10px rgba(0,0,0,0.15);
}
</style>
</head>

<body>
<div class="box">
    <h1>Hola!</h1>
    <p>Si ves esto con estilo, tu Streamlit SÍ permite HTML.</p>
</div>
</body>
</html>
"""

components.html(html_content, height=800, scrolling=True)
