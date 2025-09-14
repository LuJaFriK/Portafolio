import java.util.Scanner;
public class Experimento3 {
    public static void main (String[]args){
        Scanner leer = new Scanner(System.in);
        int i=0,cambio;
        int[] arr = {500,100,50,20,10,5,1};
        System.out.println("¿Qué cantidad deseas retirar?");
        int cant=leer.nextInt();
        leer.close();
        for(i=0;i<4;i++){
            if(arr[i]<=cant){
                cambio=cant/arr[i];
                System.out.println(cambio+" billetes de " + arr[i]);
                cant=cant-cambio*arr[i];
            }else{
            System.out.println("0 billetes de " + arr[i]);
            }
        }
        for(i=4;i<7;i++){
            if(arr[i]<=cant){
                cambio=cant/arr[i];
                System.out.println(cambio+" monedas de " + arr[i]);
                cant=cant-cambio*arr[i];
            }else{
            System.out.println("0 monedas de " + arr[i]);
            }
            
        }
    }
}