package org.example;
import java.util.Random;
import java.util.Scanner;
import java.util.InputMismatchException;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    /* 
    public static void main(String[] args) {
        int[] arr = new int[100];
        while (true){
            try{
                switch (input("""
                Ingresa una de las siguientes opciones:
                1.- Crear un arreglo de 100 espacios con valores aleatorios
                2.- Imprimir el arreglo
                3.- Buscar un numero en el arreglo
                4.- Eliminar un numero del arreglo
                5.- Consultar un espacio del arreglo
                0.- Salir""")){
                    case 1:
                        randarray(arr);
                        break;
                    case 2:
                        for(int i=0;i<arr.length;i++){
                            if(arr[i]==-1)break;
                            System.out.print(arr[i]+" ");
                        }
                        break;
                    case 3:
                        int index = search(arr,input("Ingresa el numero a buscar:"));
                        if(index != -1){
                            System.out.println("El indice del numero es: "+index);
                        }
                        break;
                    case 4:
                        remove(arr,input("Ingresa el numero a buscar:"));
                        break;
                    case 5:
                        int posicion = input("Ingresa la posicion a consultar:");
                        System.out.println("La posicion "+posicion+" contiene el valor "+arr[posicion]);
                        break;
                    case 0:
                        System.out.println("Saliendo...");
                        return;
                }
            }catch(NullPointerException ex){
                System.out.println("Debes crear el arreglo primero");
            }
        }
    }

    Descomentar para usar

    */

    public static void test(){

        //Paso 1: Crear el arreglo
        int[] arreglo;
        //Paso 2: Crear 50000 espacios
        arreglo = randarray(50000);
        //Paso 3: Imprimir el arreglo
        printarray(arreglo);
        //Paso 4: metodo de busqueda
        System.out.println(search(arreglo, 6789));    
        //Paso 5: Buscar valor
        int val = arreglo[67];
        System.out.println(val);
        
        //Paso 6: Eliminar valor
        remove(arreglo, val);
        
        //Paso 7: Reimprimir lista
        printarray(arreglo);


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

    public static void printarray(int[]arr){
        System.out.print('[');
        for (int i=0;i<arr.length;i++){
            System.out.print(arr[i]);
            if(arr[i]+1 != 0) System.out.print(',');
        }
        System.out.println(']');
    }


    public static int[] randarray(int length){
        Random random = new Random();
        int[] arr = new int[length];
        for(int i = 0;i<length;i++) arr[i] = random.nextInt(10001);
        return arr;
    }

    public static void randarray(int[] arr){
        for(int i = 0;i<arr.length;i++) arr[i] = (int) (Math.random()*10001);
    }

    public static int search(int[]arreglo,int busqueda) {
        for (int i = 0; (i < arreglo.length) && (arreglo[i] != -1); i++) {
            if (arreglo[i] == busqueda) return i;
            else if (arreglo[i] == -1) {
                System.out.println("Número no encontrado");
                break;
            }

        }
        return -1;
    }

    public static void remove(int[]arreglo, int numero){
        int index = search(arreglo,numero);
        if(index!=-1){
            int i =0;
            for(i=index;(i<arreglo.length-1)&&(arreglo[i]!=-1);i++){
                arreglo[i] = arreglo[i+1];
            }
            arreglo[i] = -1;
        }
    }

    public static int input(String mensaje) {
        Scanner scanner = new Scanner(System.in);
        int scanned;
        while (true) {
            try {
                System.out.println(mensaje);
                scanned = scanner.nextInt();
                break;
            } catch (InputMismatchException ex) {
                System.out.println("Error. Caracteres introducidos no válidos. Intente nuevamente.");
                scanner.nextLine();
                wait(2000);
            }
        }
        return scanned;
    }

    public static void wait(int milliseconds) {
        try {
            Thread.sleep(milliseconds);
        } catch (InterruptedException e) {
            System.out.println("La espera fue interrumpida.");
        }
    }


}