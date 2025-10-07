import gi
import sys

# Requerimos la versión mínima de GTK 4.0
gi.require_version('Gtk', '4.0')
from gi.repository import Gtk, GLib

# NOTA: Hemos eliminado las referencias a Adwaita (Adw) para un diseño más libre.

class TabbedWindow(Gtk.ApplicationWindow):
    """
    Ventana principal de la aplicación que contiene el Gtk.Notebook.
    Ahora hereda de Gtk.ApplicationWindow.
    """
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        
        # 1. Configuración de la ventana
        self.set_title('Mi Aplicación con Pestañas GTK 4 (Diseño Personalizable)')
        self.set_default_size(600, 450)
        
        # 2. Creación del componente Notebook (Pestañas)
        self.notebook = Gtk.Notebook()
        self.notebook.set_vexpand(True) # Expande verticalmente para llenar la ventana
        self.notebook.set_hexpand(True) # Expande horizontalmente
        
        # 3. Creación y adición de pestañas
        self.create_tab1()
        self.create_tab2()
        self.create_tab3()
        
        # 4. Establecer el Notebook como el contenido principal de la ventana
        self.set_content(self.notebook)

    def create_tab1(self):
        """Crea el contenido para la Pestaña 1: Configuración."""
        
        # Contenedor principal de la pestaña (Gtk.Box vertical)
        content_box = Gtk.Box.new(Gtk.Orientation.VERTICAL, 12)
        content_box.set_margin_top(24)
        content_box.set_margin_bottom(24)
        content_box.set_margin_start(24)
        content_box.set_margin_end(24)
        
        # Título de la sección
        label = Gtk.Label.new("Panel de Configuración Principal")
        # Hemos eliminado las clases de estilo Adwaita para un diseño más simple
        label.set_halign(Gtk.Align.START)

        # Botones
        button_save = Gtk.Button.new_with_label("Guardar Cambios")
        button_save.set_tooltip_text("Haz clic para guardar las preferencias actuales.")
        button_save.connect("clicked", self.on_button_clicked, "Guardar Cambios")

        button_reset = Gtk.Button.new_with_label("Restablecer Valores")
        button_reset.connect("clicked", self.on_button_clicked, "Restablecer Valores")
        
        # Agrupar botones en una Gtk.Box horizontal
        button_box = Gtk.Box.new(Gtk.Orientation.HORIZONTAL, 12)
        button_box.set_halign(Gtk.Align.CENTER) # Centrar botones
        button_box.append(button_save)
        button_box.append(button_reset)
        
        # Ensamblar la pestaña
        content_box.append(label)
        content_box.append(Gtk.Separator.new(Gtk.Orientation.HORIZONTAL))
        content_box.append(button_box)

        # Añadir la pestaña al Notebook
        self.notebook.append_page(content_box, Gtk.Label.new("Configuración"))

    def create_tab2(self):
        """Crea el contenido para la Pestaña 2: Datos."""

        # Usamos Gtk.Box directamente, sin Adw.Clamp
        content_box = Gtk.Box.new(Gtk.Orientation.VERTICAL, 20)
        content_box.set_margin_all(30)
        content_box.set_halign(Gtk.Align.CENTER) # Centrar el contenido
        
        label = Gtk.Label.new("Visualización y Gestión de Datos")
        
        button_load = Gtk.Button.new_with_label("Cargar Datos")
        button_load.connect("clicked", self.on_button_clicked, "Cargar Datos")
        
        button_export = Gtk.Button.new_with_label("Exportar a CSV")
        button_export.connect("clicked", self.on_button_clicked, "Exportar a CSV")

        # Layout para los botones de datos (Gtk.Grid)
        grid = Gtk.Grid.new()
        grid.set_row_spacing(10)
        grid.set_column_spacing(10)
        grid.attach(button_load, 0, 0, 1, 1)
        grid.attach(button_export, 1, 0, 1, 1)
        grid.set_halign(Gtk.Align.CENTER)
        
        content_box.append(label)
        content_box.append(grid)
        
        # Añadir la pestaña
        self.notebook.append_page(content_box, Gtk.Label.new("Datos"))

    def create_tab3(self):
        """Crea el contenido para la Pestaña 3: Acerca de."""

        content_box = Gtk.Box.new(Gtk.Orientation.VERTICAL, 10)
        content_box.set_margin_all(20)
        content_box.set_halign(Gtk.Align.CENTER)
        
        label_info = Gtk.Label.new("Información de la Aplicación")
        
        # Botón para cerrar la aplicación
        button_close = Gtk.Button.new_with_label("Salir de la Aplicación")
        # Estilo predeterminado de GTK
        button_close.set_halign(Gtk.Align.CENTER)
        button_close.connect("clicked", self.on_close_application)
        
        content_box.append(label_info)
        content_box.append(Gtk.Label.new("Versión 1.0 - Desarrollado con Python y GTK 4"))
        content_box.append(button_close)
        
        # Añadir la pestaña
        self.notebook.append_page(content_box, Gtk.Label.new("Acerca de"))


    def on_button_clicked(self, button, action_name):
        """Función de callback para cuando se hace clic en un botón."""
        print(f"[{action_name}] Botón clickeado en la pestaña '{self.get_current_tab_title()}'")
        
        # Lógica de respuesta temporal: cambia la etiqueta
        button.set_label(f"¡{action_name} HECHO!")
        # Vuelve al texto original después de un breve retraso (2 segundos)
        GLib.timeout_add_seconds(2, self.reset_button_label, button, action_name)

    def reset_button_label(self, button, original_label):
        """Restablece el texto del botón a su etiqueta original."""
        button.set_label(original_label)
        return GLib.SOURCE_REMOVE # Detener el temporizador después de la primera ejecución


    def get_current_tab_title(self):
        """Obtiene el título de la pestaña actualmente visible."""
        current_page_num = self.notebook.get_current_page()
        page_widget = self.notebook.get_nth_page(current_page_num)
        tab_label_widget = self.notebook.get_tab_label(page_widget)
        if tab_label_widget and isinstance(tab_label_widget, Gtk.Label):
            return tab_label_widget.get_label()
        return "Desconocida"

    def on_close_application(self, button):
        """Cierra la aplicación al hacer clic en el botón 'Salir'."""
        print("Cerrando la aplicación...")
        self.get_application().quit()

class TabbedApp(Gtk.Application):
    """
    Clase principal de la aplicación GTK.
    Ahora hereda de Gtk.Application.
    """
    def __init__(self, **kwargs):
        super().__init__(application_id='com.ejemplo.TabbedAppLibre', **kwargs)
        self.connect('activate', self.on_activate)

    def on_activate(self, app):
        """Crea y muestra la ventana principal al activar la aplicación."""
        self.win = TabbedWindow(application=app)
        self.win.present()

if __name__ == '__main__':
    # Ejecución de la aplicación
    app = TabbedApp()
    exit_code = app.run(sys.argv)
    sys.exit(exit_code)