
import java.util.Scanner;
public class Experimento2{
/*
Experiment2 es un ejercicio de búsqueda binaria escrito en Java.
*/
    public static void main (String[]args){
        Scanner leer = new Scanner(System.in);
    //Arreglo de ejemplo
            int[] numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
            System.out.println("Ingresa el número a buscar:");
    //Valor a encontrar en el arreglo
            int find = leer.nextInt();
    //Imprime un mensaje de error    
           // if (binsrch(find, numeros)==-1){System.out.println("Error, número no encontrado.");}
    //Imprime la posición del número encontrado
            System.out.println(binsrch(find, numeros));
            leer.close();
    }
//Método para búsqueda binaria
    public static int binsrch (int find, int[]arr){
    //Variables que representa la posición más grande y más pequeña
        int max=arr.length-1, min=0;
    
    //Indice inicializado en -1 para regresar un mensaje de error en caso de no encotrar el valor solicitado.
        int index=-1;
        do{
    //variable search
           int srch = min+(max-min)/2;
           System.out.println("before method srch:"+ srch);
           System.out.println(arr[srch]);
           if (find==arr[srch]){return srch;}
           else if(find>arr[srch]){
           System.out.println(" find: "+find );
           System.out.println("search: " + srch);
           System.out.println(" arr[search]:"+ arr[srch]);
           System.out.println(" min: "+min);
           min++;
           }
           else if (find<arr[srch]){max--;
           System.out.println(" find: "+find );
           System.out.println(" arr[search]:"+ arr[srch]);
           System.out.println(" max: "+max);
           }
       }while (min<=max);
       System.out.println(index+ "this is the end");
       return index;
    }
}