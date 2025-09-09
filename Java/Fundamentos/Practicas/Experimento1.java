public class Experimento1{
/*
Experiment1 es un ejercicio de invertir un arreglo estático escrito en Java.
*/
    public static void main (String[]args){
    //Arreglo de ejemplo
        int[] arr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    //Variables que representa la posición más grande y más pequeña
        int max = arr[(arr.length)-1], min = arr[0];
    //Variables para ir cambiando las posiciones
        int change1,change2;
    //Ciclo para ejecutar el cambio de posiciones
        do {
    /*La variable change1 obtiene el valor más pequeño dado
      La variable change2 obtiene el valor más bajo dado   */
            change1 = arr[min];
            change2 = arr[max];
    /*El valor más alto se convierte en el valor más bajo
      El valor más alto se convierte en el valor más alto*/
            arr[max] = change1;
            arr[min] = change2;
    /*Los ínidices máximo y mínimo descienden y ascienden 
      respectivamente para continuar con los siguientes valores*/
            min++;
            max--;
    //El ciclo se ejecuta mientras el minimo sea menor que el máximo
            }while (min<max); 
    //Este ciclo unicamente imprime el ciclo ya invertido como comprobación    
        for(int i=0; i<arr.length; i++){
            System.out.println(arr[i]);
        }
    }
}