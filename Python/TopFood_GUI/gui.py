import tkinter as tk
from tkinter import ttk, messagebox
from __init__ import TopFoodLogic
from Mesero import Mesero

class TopFoodGUI(tk.Tk):
    def __init__(self, logic: TopFoodLogic):
        super().__init__()
        self.logic = logic
        self.title("TopFood")
        self.geometry("800x600")
        
        self.current_user: Mesero = None

        self.create_login_screen()

    def create_login_screen(self):
        self.clear_screen()
        
        self.login_frame = ttk.Frame(self)
        self.login_frame.pack(expand=True)

        ttk.Label(self.login_frame, text="Login", font=("Arial", 24)).pack(pady=20)

        ttk.Label(self.login_frame, text="ID de Mesero:").pack()
        self.mesero_id_entry = ttk.Entry(self.login_frame)
        self.mesero_id_entry.pack()

        ttk.Label(self.login_frame, text="Contraseña:").pack()
        self.password_entry = ttk.Entry(self.login_frame, show="*")
        self.password_entry.pack()

        ttk.Button(self.login_frame, text="Login", command=self.handle_login).pack(pady=10)
        ttk.Button(self.login_frame, text="Registrar Nuevo Mesero", command=self.create_register_screen).pack()

    def create_register_screen(self):
        self.clear_screen()

        self.register_frame = ttk.Frame(self)
        self.register_frame.pack(expand=True)

        ttk.Label(self.register_frame, text="Registrar Nuevo Mesero", font=("Arial", 24)).pack(pady=20)

        ttk.Label(self.register_frame, text="ID de Mesero:").pack()
        self.new_mesero_id_entry = ttk.Entry(self.register_frame)
        self.new_mesero_id_entry.pack()

        ttk.Label(self.register_frame, text="Nombre:").pack()
        self.new_nombre_entry = ttk.Entry(self.register_frame)
        self.new_nombre_entry.pack()

        ttk.Label(self.register_frame, text="Contraseña:").pack()
        self.new_password_entry = ttk.Entry(self.register_frame, show="*")
        self.new_password_entry.pack()

        ttk.Button(self.register_frame, text="Registrar", command=self.handle_register).pack(pady=10)
        ttk.Button(self.register_frame, text="Volver al Login", command=self.create_login_screen).pack()

    def handle_login(self):
        try:
            mesero_id = int(self.mesero_id_entry.get())
            password = int(self.password_entry.get())
            user = self.logic.login(mesero_id, password)
            if user:
                self.current_user = user
                self.create_main_menu()
            else:
                messagebox.showerror("Error de Login", "ID de mesero o contraseña incorrectos.")
        except ValueError:
            messagebox.showerror("Error de Input", "Por favor, ingrese un ID y contraseña numéricos.")

    def handle_register(self):
        try:
            mesero_id = int(self.new_mesero_id_entry.get())
            nombre = self.new_nombre_entry.get()
            password = int(self.new_password_entry.get())
            if self.logic.crear_mesero(mesero_id, nombre, password):
                messagebox.showinfo("Registro Exitoso", "Mesero registrado exitosamente.")
                self.create_login_screen()
            else:
                messagebox.showerror("Error de Registro", "El ID de mesero ya existe.")
        except ValueError:
            messagebox.showerror("Error de Input", "Por favor, ingrese un ID y contraseña numéricos.")

    def create_main_menu(self):
        self.clear_screen()

        self.main_menu_frame = ttk.Frame(self)
        self.main_menu_frame.pack(expand=True)

        ttk.Label(self.main_menu_frame, text=f"Bienvenido, {self.current_user.nombre}!", font=("Arial", 24)).pack(pady=20)

        ttk.Button(self.main_menu_frame, text="Ver Mis Mesas", command=self.create_mesas_screen).pack(pady=5)
        ttk.Button(self.main_menu_frame, text="Asignar Mesa", command=self.create_asignar_mesa_screen).pack(pady=5)
        ttk.Button(self.main_menu_frame, text="Hacer Pedido", command=self.create_hacer_pedido_screen).pack(pady=5)
        ttk.Button(self.main_menu_frame, text="Cerrar Cuenta", command=self.create_cerrar_cuenta_screen).pack(pady=5)
        ttk.Button(self.main_menu_frame, text="Logout", command=self.create_login_screen).pack(pady=20)

    def create_mesas_screen(self):
        self.clear_screen()

        self.mesas_frame = ttk.Frame(self)
        self.mesas_frame.pack(expand=True)

        ttk.Label(self.mesas_frame, text="Mis Mesas", font=("Arial", 24)).pack(pady=20)

        mesas = self.logic.get_mesas_by_mesero(self.current_user)
        if mesas:
            for numero, mesa in mesas.items():
                ttk.Label(self.mesas_frame, text=f"Mesa {numero}: {'Activa' if mesa.activo else 'Inactiva'} - Total: ${mesa.total:.2f}").pack()
        else:
            ttk.Label(self.mesas_frame, text="No tienes mesas asignadas.").pack()

        ttk.Button(self.mesas_frame, text="Volver al Menú Principal", command=self.create_main_menu).pack(pady=20)

    def create_asignar_mesa_screen(self):
        self.clear_screen()

        self.asignar_mesa_frame = ttk.Frame(self)
        self.asignar_mesa_frame.pack(expand=True)

        ttk.Label(self.asignar_mesa_frame, text="Asignar Mesa", font=("Arial", 24)).pack(pady=20)

        ttk.Label(self.asignar_mesa_frame, text="Número de Mesa:").pack()
        self.numero_mesa_entry = ttk.Entry(self.asignar_mesa_frame)
        self.numero_mesa_entry.pack()

        ttk.Button(self.asignar_mesa_frame, text="Asignar", command=self.handle_asignar_mesa).pack(pady=10)
        ttk.Button(self.asignar_mesa_frame, text="Volver al Menú Principal", command=self.create_main_menu).pack()

    def handle_asignar_mesa(self):
        try:
            numero_mesa = int(self.numero_mesa_entry.get())
            if self.logic.asignar_mesa(self.current_user, numero_mesa):
                messagebox.showinfo("Mesa Asignada", f"Mesa {numero_mesa} asignada exitosamente.")
                self.create_main_menu()
            else:
                messagebox.showerror("Error", "La mesa ya está asignada.")
        except ValueError:
            messagebox.showerror("Error de Input", "Por favor, ingrese un número de mesa válido.")

    def create_hacer_pedido_screen(self):
        self.clear_screen()

        self.hacer_pedido_frame = ttk.Frame(self)
        self.hacer_pedido_frame.pack(expand=True)

        ttk.Label(self.hacer_pedido_frame, text="Hacer Pedido", font=("Arial", 24)).pack(pady=20)

        # Mesa selection
        ttk.Label(self.hacer_pedido_frame, text="Seleccionar Mesa:").pack()
        mesas = self.logic.get_mesas_by_mesero(self.current_user)
        self.mesa_pedido_combobox = ttk.Combobox(self.hacer_pedido_frame, values=[num for num in mesas.keys()])
        self.mesa_pedido_combobox.pack()

        # Alimento selection
        ttk.Label(self.hacer_pedido_frame, text="Seleccionar Alimento:").pack()
        alimentos = self.logic.get_menu_items_by_type("Snack") + self.logic.get_menu_items_by_type("Cafe")
        self.alimento_pedido_combobox = ttk.Combobox(self.hacer_pedido_frame, values=[alimento.nombre for alimento in alimentos])
        self.alimento_pedido_combobox.pack()
        
        # Cantidad
        ttk.Label(self.hacer_pedido_frame, text="Cantidad:").pack()
        self.cantidad_entry = ttk.Entry(self.hacer_pedido_frame)
        self.cantidad_entry.pack()

        # Comentario
        ttk.Label(self.hacer_pedido_frame, text="Comentario:").pack()
        self.comentario_entry = ttk.Entry(self.hacer_pedido_frame)
        self.comentario_entry.pack()

        ttk.Button(self.hacer_pedido_frame, text="Hacer Pedido", command=self.handle_hacer_pedido).pack(pady=10)
        ttk.Button(self.hacer_pedido_frame, text="Volver al Menú Principal", command=self.create_main_menu).pack()

    def handle_hacer_pedido(self):
        try:
            numero_mesa = int(self.mesa_pedido_combobox.get())
            nombre_alimento = self.alimento_pedido_combobox.get()
            cantidad = int(self.cantidad_entry.get())
            comentario = self.comentario_entry.get()

            alimento = self.logic.menu.get(nombre_alimento)
            if not alimento:
                messagebox.showerror("Error", "Alimento no encontrado.")
                return

            if self.logic.hacer_pedido(numero_mesa, alimento, cantidad, comentario):
                messagebox.showinfo("Pedido Realizado", "Pedido realizado exitosamente.")
                self.create_main_menu()
            else:
                messagebox.showerror("Error", "No se pudo realizar el pedido. Verifique que la mesa esté activa.")
        except (ValueError, AttributeError):
            messagebox.showerror("Error de Input", "Por favor, complete todos los campos correctamente.")

    def create_cerrar_cuenta_screen(self):
        self.clear_screen()

        self.cerrar_cuenta_frame = ttk.Frame(self)
        self.cerrar_cuenta_frame.pack(expand=True)

        ttk.Label(self.cerrar_cuenta_frame, text="Cerrar Cuenta", font=("Arial", 24)).pack(pady=20)

        ttk.Label(self.cerrar_cuenta_frame, text="Seleccionar Mesa:").pack()
        mesas = self.logic.get_mesas_by_mesero(self.current_user)
        self.mesa_cerrar_combobox = ttk.Combobox(self.cerrar_cuenta_frame, values=[num for num in mesas.keys()])
        self.mesa_cerrar_combobox.pack()

        ttk.Button(self.cerrar_cuenta_frame, text="Cerrar Cuenta", command=self.handle_cerrar_cuenta).pack(pady=10)
        ttk.Button(self.cerrar_cuenta_frame, text="Volver al Menú Principal", command=self.create_main_menu).pack()

    def handle_cerrar_cuenta(self):
        try:
            numero_mesa = int(self.mesa_cerrar_combobox.get())
            ticket = self.logic.cerrar_cuenta(numero_mesa)
            if ticket:
                self.show_ticket(ticket)
            else:
                messagebox.showerror("Error", "No se pudo cerrar la cuenta. Verifique que la mesa esté activa.")
        except (ValueError, AttributeError):
            messagebox.showerror("Error de Input", "Por favor, seleccione una mesa.")

    def show_ticket(self, ticket_content):
        self.clear_screen()

        self.ticket_frame = ttk.Frame(self)
        self.ticket_frame.pack(expand=True)

        ttk.Label(self.ticket_frame, text="Ticket", font=("Arial", 24)).pack(pady=20)
        
        ticket_text = tk.Text(self.ticket_frame, height=20, width=50)
        ticket_text.insert(tk.END, ticket_content)
        ticket_text.config(state=tk.DISABLED)
        ticket_text.pack()

        ttk.Button(self.ticket_frame, text="Volver al Menú Principal", command=self.create_main_menu).pack(pady=20)

    def clear_screen(self):
        for widget in self.winfo_children():
            widget.destroy()

if __name__ == "__main__":
    logic = TopFoodLogic()
    app = TopFoodGUI(logic)
    app.mainloop()