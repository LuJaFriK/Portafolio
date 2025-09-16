package org.example;

import java.util.InputMismatchException;
import java.util.Scanner;

class Main{
    /* 
    public static void main(String[] args) {
        int index;
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


    Descomentar para su uso


    */
    public static void test(){

        //Paso 1: Crear lista
        Lista list = new Lista();

        //Paso 2: Crear 50000 nodos 
        list.randomLinkedList(50000);
        
        //Paso 3: imprimir lista
        System.out.println(list);
        
        //Paso 4: metodo de busqueda
        System.out.println(list.searchNode(6789));
        
        //Paso 5: Buscar valor
        int value = list.get(67);
        System.out.println(value);
        
        //Paso 6: Eliminar valor
        list.deleteNode(value);
        
        //Paso 7: Reimprimir lista
        System.out.println(list);

    }

    public static void main(String[] args) {
        Runtime runtime = Runtime.getRuntime();

        // Medir memoria inicial
        runtime.gc();
        long memoriaInicial = runtime.totalMemory() - runtime.freeMemory();

        // Medir tiempo inicial
        long inicio = System.nanoTime();

        // Código a medir
        test();

        // Medir tiempo final
        long fin = System.nanoTime();
        long tiempoEjecucion = fin - inicio;

        // Medir memoria final
        runtime.gc();
        long memoriaFinal = runtime.totalMemory() - runtime.freeMemory();

        // Resultados
        System.out.println("Tiempo de ejecución: " + tiempoEjecucion / 1_000_000.0 + " ms");
        // Para medir en Bytes, simplemente no dividas por 1024*1024.
        // La diferencia 'memoriaFinal - memoriaInicial' ya está en Bytes.
        System.out.println("Memoria usada: " + (memoriaFinal - memoriaInicial) + " Bytes");
    }

}