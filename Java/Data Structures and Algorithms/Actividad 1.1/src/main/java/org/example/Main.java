package org.example;
import java.util.Random;
import java.util.Scanner;
import java.util.InputMismatchException;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        int[] arr = null;
        while (true){
            try{
                switch (input("""
                Ingresa una de las siguientes opciones:
                1.- Crear un arreglo de 100 espacios con valores aleatorios
                2.- Imprimir el arreglo
                3.- Buscar un numero en el arreglo
                4.- Eliminar un numero del arreglo
                5.- Salir
                """)){
                    case 1:
                        arr = randarray(100);
                        break;
                    case 2:
                        for(int i=0;i<arr.length;i++){
                            if(i!=arr.length-1) System.out.print(arr[i]+" ");
                            else System.out.print(arr[i]+"\n");
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
                        System.out.println("Saliendo...");
                        return;
                }
            }catch(NullPointerException ex){
                System.out.println("Debes crear el arreglo primero");
            }
        }
    }

    public static int[] randarray(int length){
        Random random = new Random();
        int[] arr = new int[length];
        for(int i = 0;i<length;i++) {
            arr[i] = random.nextInt(10001);
        }
        return arr;
    }

    public static int search(int[]arreglo,int busqueda){
        int index = -1;
        for(int i=0; (i < arreglo.length)&&(arreglo[i]!=-1);i++){
            if(arreglo[i] == busqueda){
                index = i;
                break;
            }
        }
        if (index == -1) System.out.println("Número no encontrado");
        return index;
    }

    public static void remove(int[]arreglo, int numero){
        int index = search(arreglo,numero);
        if(index!=-1){
            for(int i=index;i<arreglo.length-1;i++){
                arreglo[i] = arreglo[i+1];
            }
            arreglo[arreglo.length-1] = -1;
        }
    }

    public static int input(String mensaje) {
        Scanner scanner = new Scanner(System.in);
        int scanned;
        while (true) {
            try {
                System.out.print(mensaje);
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