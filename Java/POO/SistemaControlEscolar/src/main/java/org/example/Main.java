package org.example;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Estudiante[] Estudiantes = new Estudiante[30];
        Scanner scanner = new Scanner (System.in);
        int op = 0, i=0, b;
        do {
            System.out.println("1.- Ingresar un estudiante:");
            System.out.println("2.- Modificar las calificaciones de un estudiante:");
            System.out.println("3.- Desplegar datos de un estudiante:");
            System.out.println("4.- Desplegar la lista de estudiantes:");
            System.out.println("5.- Salir:");
            op = scanner.nextInt();
                    switch (op) {
                        case 1:
                            scanner.nextLine();
                            i=0;

                            while (i < Estudiantes.length-1 && Estudiantes[i]!=null) {i++;}
                            if(Estudiantes[i]==null) {
                                Estudiantes[i] = new Estudiante();
                                System.out.println("Ingresa el nombre del estudiante:");
                                Estudiantes[i].setNombre(scanner.nextLine());
                                System.out.println("Ingresa el numero de control del alumno:");
                                Estudiantes[i].setNocontrol(scanner.nextInt());
                            }
                            int opt = 0;
                            System.out.println("Ingresar calificaciones?");
                            System.out.println("1.- Si         2.-No");
                            opt = scanner.nextInt();
                            if (opt==1){
                                for(int ii=0;ii<6;ii++){
                                    System.out.println("Ingresa la calificación "+(ii+1)+":");
                                    Estudiantes[i].setCalificaciones(ii, scanner.nextInt());
                                }
                                System.out.println("Calificaciones ingresadas con éxito.");
                                Estudiantes[i].setPromedio(Estudiantes[i].getCalificaciones());
                            }
                            break;
                        case 2:
                            b = buscarEstudiante(Estudiantes);
                            if (b==-1){break;}
                            for(i=0;i<6;i++){
                                System.out.println("Ingresa la calificación "+(i+1)+":");
                                Estudiantes[b].setCalificaciones(i, scanner.nextInt());
                            }
                            System.out.println("Calificaciones ingresadas con éxito.");
                            Estudiantes[b].setPromedio(Estudiantes[b].getCalificaciones());
                            break;
                        case 3:
                            b = buscarEstudiante(Estudiantes);
                            if (b==-1){break;}
                            Estudiantes[b].infoEstudiante();
                            break;
                        case 4:
                            i=0;
                            while (i < Estudiantes.length-1 && Estudiantes[i]!=null) {
                                System.out.println("__________________________");
                                System.out.println("No. de lista: "+(i+1));
                                Estudiantes[i].infoEstudiante();
                                System.out.println("__________________________");
                                i++;
                            }
                            break;
                        case 5:
                            System.out.println("Saliendo...");
                            break;
                        default:
                            System.out.println("Error. Opción no válida.");
                            break;
                    }
                } while (op!=5);
    }
    public static int buscarEstudiante(Estudiante[] estudiantes) {
        Scanner scanner = new Scanner(System.in);
        int op = 0;

        System.out.println("1.- Buscar estudiante por nombre.");
        System.out.println("2.- Buscar estudiante por número de control.");
        System.out.println("3.- Buscar estudiante por número de lista.");
        op = scanner.nextInt();
        scanner.nextLine();

        switch (op) {
            case 1:
                System.out.println("Ingresa el nombre del estudiante:");
                String nombre = scanner.nextLine();
                for (int i = 0; i < estudiantes.length; i++) {
                    if (estudiantes[i] != null && estudiantes[i].getNombre().equalsIgnoreCase(nombre)) {
                        return i;
                    }
                }
                System.out.println("El estudiante no ha sido encontrado.");
                break;

            case 2:
                System.out.println("Ingresa el número de control del estudiante:");
                int noControl = scanner.nextInt();
                for (int i = 0; i < estudiantes.length; i++) {
                    if (estudiantes[i] != null && estudiantes[i].getNocontrol() == noControl) {
                        return i;
                    }
                }
                System.out.println("El estudiante no ha sido encontrado.");
                break;

            case 3:
                System.out.println("Ingresa el número de lista del estudiante:");
                int lista = scanner.nextInt();
                if (lista > 0 && lista <= estudiantes.length && estudiantes[lista - 1] != null) {
                    return lista - 1;
                } else {
                    System.out.println("El estudiante no ha sido encontrado.");
                }
                break;

            default:
                System.out.println("Opción no válida.");
                break;
        }

        return -1;
    }

}
