import gi; gi.require_version('Gtk','4.0'); from gi.repository import Gtk

class DemoAppWindow(Gtk.ApplicationWindow):
    def __init_(self,**kwargs):
        super().__init__(**kwargs)
        self.set_title('Buenos dias papu')

        self.contador = 0

        self.button = Gtk.Button()
        self.button.set_label('Hola')
        self.set_child(self.button)
        self.button.connect('clicked',self.on_click)

    def on_click(self,_data):
        self.contador +=1
        self.button.set_label(f'Pulsaste el boton {self.contador} veces')

class DemoApp(Gtk.Application):
    def __init_(self,**kwargs):
        super().__init__(**kwargs,application_id='Hola')
    
    def do_activate(self):
        win = DemoAppWindow(application = self)
        win.present()

app = DemoApp()

app.run()