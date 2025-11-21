def generar_css():
    return """
    <style>
    @import url('https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;700&display=swap');

    html, body {
        margin: 0;
        padding: 0;
        background: #f0f2f6;
        font-family: 'Roboto', sans-serif;
    }

    .cv-container {
        color: #333;
        max-width: 850px;
        margin: 30px auto;
        background: white;
        box-shadow: 0 0 15px rgba(0,0,0,0.15);
        padding: 40px;
        border-radius: 10px;
    }

    .header { 
        text-align: center; 
        border-bottom: 2px solid #2c3e50;
        padding-bottom: 20px; 
        margin-bottom: 30px;
    }

    .header h1 { 
        margin: 0; 
        color: #2c3e50; 
        text-transform: uppercase;
        letter-spacing: 2px;
        font-size: 2rem;
    }

    .header h2 {
        margin-top: 5px;
        color: #444;
        font-size: 1.1rem;
        font-weight: 400;
    }

    .section-title {
        color: #2c3e50;
        border-left: 5px solid #3498db;
        padding-left: 10px;
        margin-top: 25px;
        margin-bottom: 10px;
        text-transform: uppercase;
        font-weight: bold;
        font-size: 1.05rem;
    }

    .skills-list {
        display: flex;
        flex-wrap: wrap;
        gap: 10px;
        margin-top: 10px;
    }

    .skill-tag {
        background: #ecf0f1;
        color: #2c3e50;
        padding: 5px 12px;
        border-radius: 4px;
        font-size: 0.9rem;
        font-weight: 600;
    }

    @media print {
        @page { margin: 0; }
        body, html {
            background: white !important;
        }
        .cv-container {
            box-shadow: none !important;
            width: 100% !important;
            padding: 20px !important;
            margin: 0 !important;
            border-radius: 0 !important;
        }
    }

    @media print {
        body {
            background: white !important;
        }   

        .cv-container {
            box-shadow: 0 0 10px rgba(0,0,0,0.1); /* mantener recuadro */
            margin: auto !important;
            transform: scale(1);
        }
    }

    </style>
    """
    
def construir_html(nombre, titulo, email, telefono, linkedin, perfil,
                    cargo, empresa, fecha_exp, desc_exp,
                    universidad, carrera, fecha_edu, skills_input, nivel_ingles):

    css = generar_css()

    # Generar la lista de skills como HTML
    skills_html = "".join([f"<span class='skill-tag'>{s}</span>" for s in skills_input])

    body_html = f"""
    <div class="cv-container" id="cv-root">
        <div class="header">
            <h1>{nombre}</h1>
            <h2>{titulo}</h2>
            <p>{email} | {telefono} | {linkedin}</p>
        </div>

        <div class="section">
            <div class="section-title">Perfil Profesional</div>
            <p>{perfil}</p>
        </div>

        <div class="section">
            <div class="section-title">Experiencia Laboral</div>
            <p><strong>{cargo}</strong> — {empresa}</p>
            <p><i>{fecha_exp}</i></p>
            <p>{desc_exp}</p>
        </div>

        <div class="section">
            <div class="section-title">Educación</div>
            <p><strong>{carrera}</strong></p>
            <p>{universidad}</p>
            <p><i>{fecha_edu}</i></p>
        </div>

        <div class="section">
            <div class="section-title">Habilidades</div>
            <div class="skills-list">
                {skills_html}
            </div>
        </div>

        <div class="section">
            <div class="section-title">Idiomas</div>
            <p><strong>Inglés:</strong> {nivel_ingles}</p>
        </div>
    </div>
    """

    # Wrapper completo con script para ajustar la altura del iframe
    full_html = f"""<!doctype html>
    <html>
      <head>
        <meta charset="utf-8"/>
        <meta name="viewport" content="width=device-width, initial-scale=1"/>
        {css}
      </head>
      <body>
        {body_html}

        <script>
          function sendHeight() {{
            const height = document.documentElement.scrollHeight || document.body.scrollHeight;
            // Enviar mensaje al iframe padre (Streamlit) para ajustar altura
            window.parent.postMessage({{ "type": "setHeight", "height": height }}, "*");
          }}

          // Enviar altura inicial y cuando cambie el contenido
          window.addEventListener("load", function() {{
            sendHeight();
            // Observador para cambios dinámicos
            const ro = new ResizeObserver(sendHeight);
            ro.observe(document.body);
          }});
          // También reenviamos altura cada 300ms los primeros segundos por si hay fuentes que cargan tarde
          let tries = 0;
          const interval = setInterval(function() {{
            sendHeight();
            tries++;
            if (tries > 20) clearInterval(interval);
          }}, 300);
        </script>
      </body>
    </html>
    """
    return full_html