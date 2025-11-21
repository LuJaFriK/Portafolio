import streamlit as st
import streamlit.components.v1 as components
import pdfkit
import tempfile
from web_interface import generar_css, construir_html

st.set_page_config(page_title="Generador de CV Profesional", layout="wide")

def exportar_pdf(html_content):
    import pdfkit
    import tempfile

    # HTML completo con DOCTYPE + estilos inline + centrado
    html_final = f"""
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style>
    body {{
        background: #f0f0f0;
        display: flex;
        justify-content: center;
        align-items: center;
        padding: 40px;
        margin: 0;
    }}

    .cv-wrapper {{
        width: 800px;
        display: flex;
        justify-content: center;
    }}

    /* Tus estilos originales */
    {generar_css()}
</style>
</head>

<body>
    <div class="cv-wrapper">
        {html_content}
    </div>
</body>
</html>
"""

    # archivo temporal
    with tempfile.NamedTemporaryFile(delete=False, suffix=".pdf") as tmp_pdf:
        pdfkit.from_string(html_final, tmp_pdf.name)
        return tmp_pdf.name




def main():
    if "skills_list" not in st.session_state:
        st.session_state.skills_list = []

    st.sidebar.header("📝 Ingresa tus Datos")

    with st.sidebar.form("cv_form"):
        st.subheader("Datos Personales")
        nombre = st.text_input("Nombre Completo", "Juan Pérez")
        titulo = st.text_input("Título Profesional", "Ingeniero de Software")
        email = st.text_input("Email", "juan@ejemplo.com")
        telefono = st.text_input("Teléfono", "+52 55 1234 5678")
        linkedin = st.text_input("LinkedIn/Web", "linkedin.com/in/juanperez")

        st.subheader("Perfil")
        perfil = st.text_area("Resumen Profesional")

        st.subheader("Experiencia Laboral (Última)")
        cargo = st.text_input("Cargo")
        empresa = st.text_input("Empresa")
        fecha_exp = st.text_input("Fecha")
        desc_exp = st.text_area("Descripción de tareas")

        st.subheader("Educación")
        universidad = st.text_input("Institución")
        carrera = st.text_input("Carrera")
        fecha_edu = st.text_input("Año de Graduación")

        st.subheader("Nivel de Inglés")
        nivel_ingles = st.selectbox("Selecciona una opción", ["A1 Principiante", "A2 Básico", "B1 Intermedio", "B2 Intermedio", "C1 Avanzado", "C2 Nativo"])

        submitted = st.form_submit_button("Actualizar Vista Previa")

    st.sidebar.subheader("Habilidades (una por una)")

    if "skills_list" not in st.session_state:
        st.session_state.skills_list = []

    nueva_skill = st.sidebar.text_input("Nueva Skill")

    col1, col2 = st.sidebar.columns([1, 1])
    with col1:
        if st.button("➕ Agregar skill"):
            if nueva_skill.strip():
                st.session_state.skills_list.append(nueva_skill.strip())
                st.rerun()

    with col2:
        if st.button("🗑️ Borrar todas"):
            st.session_state.skills_list.clear()
            st.rerun()

    # CSS pequeño para ajustar la alineación y quitar viñetas
    st.sidebar.markdown(
        """
        <style>
        /* Evitar que aparezcan viñetas en markdown dentro del sidebar */
        .skill-text { list-style: none; padding: 8px 0; margin: 0; display: flex; align-items: center; }
        .skill-text p { margin: 0; padding-left: 6px; }
        /* Forzar un gap razonable entre texto y botón en dispositivos pequeños */
        .stButton button { min-width: 36px; height: 36px; }
        </style>
        """,
        unsafe_allow_html=True,
    )

    st.sidebar.write("### Skills agregadas:")

    # CSS para alinear y estilizar
    st.sidebar.markdown("""
    <style>
    .skill-row {
        display: flex;
        align-items: center;
        justify-content: space-between;
        padding: 6px 4px;
        background-color: rgba(255,255,255,0.05);
        border-radius: 6px;
        margin-bottom: 6px;
    }
    .skill-text {
        font-size: 15px;
        margin: 0;
    }
    .delete-btn > button {
        background: none !important;
        color: #ff4b4b !important;
        border: none !important;
        padding: 0 !important;
        font-size: 18px !important;
    }
    .delete-btn > button:hover {
        color: #ff7777 !important;
    }
    </style>
    """, unsafe_allow_html=True)

    for i, skill in enumerate(st.session_state.skills_list):

        # Crear columnas ultra compactas
        col_text, col_btn = st.sidebar.columns([6, 1])

        with col_text:
            st.markdown(f"<div class='skill-text'>{skill}</div>", unsafe_allow_html=True)

        with col_btn:
            # botón nativo de streamlit, estilizado como "X"
            if st.button("×", key=f"del_{i}", help="Eliminar", type="secondary"):
                st.session_state.skills_list.pop(i)
                st.rerun()







    html_content = construir_html(nombre, titulo, email, telefono, linkedin,
                                 perfil, cargo, empresa, fecha_exp, desc_exp,
                                 universidad, carrera, fecha_edu, st.session_state.skills_list, nivel_ingles)

    st.title("Vista Previa de tu CV")

    # Renderizamos el HTML (escoge un height suficientemente grande; el script ajustará)
    
    components.html(html_content, height=800, scrolling=True)

    if st.sidebar.button("📄 Exportar como PDF"):
        pdf_path = exportar_pdf(html_content)
        with open(pdf_path, "rb") as pdf:
            st.download_button(
                "⬇ Descargar PDF",
                data=pdf,
                file_name="CV.pdf",
            mime="application/pdf"
        )


if __name__ == "__main__":
    main()
