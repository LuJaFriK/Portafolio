    package org.example;

import java.util.Scanner;

public class Veterinaria {
    public static void main(String[] args) {
    Scanner leer = new Scanner(System.in);
    int opc,i;
    //Declarar objetos
    Perro[] Perros = new Perro[3];
    //inicio menu
    do{
        opc=0;
        System.out.println("=======================================");
        System.out.println("        Menú Veterinaria.");
        System.out.println("1.- Registrar un perro.");
        System.out.println("2.- Visualizar los perros registrados.");
        System.out.println("3.- Buscar un perro.");
        System.out.println("4.- Salir");
        System.out.print("Ingresa la opción a continuar: ");
        opc=leer.nextInt();
  
        switch (opc) {
            case 1:
                leer.nextLine();
                i=0;
                //ciclo para entrar en la posicion correcta
                while (i < Perros.length-1 && Perros[i]!=null) {i++;}
                if(Perros[i]==null){
                    Perros[i]=new Perro();
                    System.out.println("Ingresa el nombre del perro:");
                    Perros[i].setNombre(leer.nextLine());
                    System.out.println("Ingresa la raza del perro:");
                    Perros[i].setRaza(leer.nextLine());
                    System.out.println("Ingresa la edad del perro:");
                    Perros[i].setEdad(leer.nextInt());
                    System.out.println("Ingresa el peso del perro:");
                    Perros[i].setPeso(leer.nextDouble());
                }else {
                    System.out.println("No se pueden ingresar más perros.");
                }
                break;
            case 2:
                i=0;
                System.out.println("Perros registrados:");
                while(i < Perros.length-1 && Perros[i]!=null){
                    System.out.println("===========================");
                    System.out.println("Perro "+(i+1)+".- ");
                    Perros[i].infoPerro();
                    i++;
                }
                break;
            case 3:
                leer.nextLine();
                i=0;
                System.out.print("Ingresa el nombre del perro a buscar:");
                String nompe = leer.nextLine();
                while(i < Perros.length-1 &&!Perros[i].getNombre().equals(nompe)){
                    i++;
                }if(Perros[i].getNombre().equals(nompe)){Perros[i].infoPerro();
                }else{
                System.out.println("El perro no ha sido encontrado.");
            }

                break;
            case 4:
                System.out.println("Saliendo...");
                break;
            default:
                System.out.println("Error. Opción no válida.");
                break;
        }
    }while(opc!=4);
    //fin del menu
    }
}
