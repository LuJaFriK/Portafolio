package org.example;
/*
    Luis Javier Robles Topete
    No. control: 25460001
*/
import java.util.Scanner;
public class Main{
    public static void main (String[]args){
        Scanner leer = new Scanner(System.in);
        int opc, i;
        do{
            System.out.println(".");
            System.out.println(".- :");
            System.out.println(".- :");
            System.out.println(".- :");
            System.out.println(".- :");
            opc = leer.nextInt();
            leer.nextInt();
            switch(opc){
                case 1:
                    i=0;
                    for (i=0; i<=10; i++){}
                    break;
                case 2:
                    i=0;
                    break;
                case 3:
                    i=0;
                    break;
                case 4:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Error. Opción no válida.");
                    break;
            }
        }while(opc!=4);
        leer.close();
    }

}

























    /*System.out.println("Ingresa el nombre del objeto:");
    String nombre = scanner.nextLine();
    for (int i = 0; i < objeto.length; i++) {
        if (estudiantes[i] != null && objeto[i].getNombre().equals(nombre)) {
            return i;
        }
    }
    System.out.println("El objeto no ha sido encontrado.");
    return -1;*/