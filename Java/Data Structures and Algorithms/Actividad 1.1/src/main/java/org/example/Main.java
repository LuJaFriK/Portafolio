package org.example;
import java.util.Random;
import java.util.Scanner;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = array(100);
        remove(arr,1);
        for (int cas : arr) System.out.println(cas);


        sc.nextInt();

        System.out.println(search(arr, 3));
    }

    public static int[] array(int length){
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
        return index;
    }

    public static void remove(int[]arreglo, int numero){
        for (int i=0;(i < arreglo.length)&&(arreglo[i] != -1);i++){
            if (arreglo[i] == numero){
                arreglo[i] = -1;
                for(int x=0;i < arreglo.length;i++){
                    //aqui va el recorrido de las casillas
                }
                break;
            }
        }

    }
}