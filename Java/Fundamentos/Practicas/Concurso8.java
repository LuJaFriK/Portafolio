import java.util.Scanner;
public class Concurso8 {
    public static void main (String[]args){
        Scanner leer = new Scanner (System.in);
        System.out.println("Ingresa el largo del arreglo:");
        int index = leer.nextInt();
        int[] arr = new int[index];
        for (int i=0;i<index;i++ ){
            System.out.println("Valor "+(i+1)+":");
            arr[i]=leer.nextInt();
        }
        int min = arr[1];
        int max = arr[1];
        for (int i=0;i<index;i++){
            if(min>arr[i]){min=arr[i];}
            if(max<arr[i]){max=arr[i];}
        }
        System.out.println("El valor minimo es: "+min);
        System.out.println("El valor maximo es: "+max);
        
        leer.close();
    }
}