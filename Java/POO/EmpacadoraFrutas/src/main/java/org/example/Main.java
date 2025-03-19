package org.example;
import java.util.Scanner;
//Luis Javier Robles Topete 25460001
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Empleado[] empleados = new Empleado[5];
        Gerente gerente = new Gerente();
        gerente.info();
        int opc= 0, i;
        
        do {
            System.out.println("Ingresa la opcion para continuar:");
            System.out.println("1.- Ingresar datos del trabajador.");
            System.out.println("2.- Consultar datos de un trabajador.");
            System.out.println("3.- Salir.");
            opc = scanner.nextInt();
            scanner.nextLine();
            switch (opc) {
                case 1:
                    i = 0;
                    while (i < empleados.length-1 && empleados[i]!=null) {i++;}
                    if(empleados[i]==null) {
                        empleados[i] = new Empleado();
                        System.out.println("Ingresa el nombre del empleado:");
                        empleados[i].setNombre(scanner.nextLine());
                        System.out.println("Ingresa el salario del empleado:");
                        empleados[i].setSalario(scanner.nextInt());
                        System.out.println("Ingresa los días que trabajó el empleado:");
                        empleados[i].setPeriodo(scanner.nextInt());
                        double monto = calcularpago(empleados[i]);
                        empleados[i].setMontoTotal(monto);
                    }
                    break;
                case 2:
                    i = 0;
                    int b = buscarEmpleado(empleados);
                        empleados[b].infoEmpleado();
                    break;
                case 3:
                    System.out.println("Saliendo...");
                    break;
            }
        } while (opc!=3);
    }

    public static int buscarEmpleado(Empleado[] empleados) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingresa el nombre del empleado:");
        String nombre = scanner.nextLine();
        for (int i = 0; i < empleados.length; i++) {
            if (empleados[i] != null && empleados[i].getNombre().equalsIgnoreCase(nombre)) {
                return i;
            }
        }
        System.out.println("El empleado no ha sido encontrado.");
        return -1;
    }
    public static double calcularpago(Empleado empleado){
        double pago = empleado.getSalario()*empleado.getPeriodo();
        return pago;
    }
}