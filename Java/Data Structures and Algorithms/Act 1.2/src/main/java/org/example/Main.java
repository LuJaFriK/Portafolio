package org.example;

import java.util.InputMismatchException;
import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        int index;
        short[] a = {1,2,3,4};
        int i = a.length;
        boolean found;
        var list = new Lista();
        while(true){
            try{
                switch (input("""
                Ingresa una de las siguientes opciones:
                1.- Crear una lista enlazada con valores aleatorios
                2.- Imprimir la lista
                3.- Buscar un numero en la lista
                4.- Eliminar un numero de la lista
                5.- Consultar un espacio del arreglo
                0.- Salir""")){
                    case 1:
                        list.randomLinkedList(
                                100
                                //input("Numero de nodos a crear:")
                        );
                        break;
                    case 2:
                        System.out.println(list);
                        break;
                    case 3:
                        index = list.searchNode(input("Ingrese el numero a buscar:"));
                        found = index!=-1;
                        System.out.println(found ? "El numero fue encontrado en el indice "+index : "El numero no fue encontrado.");//Altamente recomendado usar el operador ? para imprimir segun booleanos
                        break;
                    case 4:
                        list.deleteNode(input("Ingrese el numero a eliminar:"));
                        break;
                    case 5:
                        index = input("Ingresa el indice a mostrar:");
                        int value = list.searchIndex(index);
                        found = value != -1;
                        System.out.println(found ? "El valor de la lista en la posicion "+index+" es "+value:"El indice es mayor a la longitud de la lista.");
                        break;
                    case 0:
                        System.out.println("Saliendo...");
                        return;
                }
            }catch(NullPointerException ex){
                System.out.println("No existe ninguna lista creada.");
            }
        }
    }
    public static int input(String mensaje) {
        var sc = new Scanner(System.in);
        int value;
        while (true) {
            try {
                System.out.println(mensaje);
                value = sc.nextInt();
                break;
            } catch (InputMismatchException ex) {
                System.out.println("Error. Caracteres introducidos no válidos. Intente nuevamente.");
                sc.nextLine();
                try {
                    Thread.sleep(1500);
                } catch (InterruptedException e) {
                    System.out.println("La espera fue interrumpida.");
                }
            }
        }
        return value;
    }
}