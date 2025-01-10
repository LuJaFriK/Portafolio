import java.util.Scanner;
public class Concurso3 {
    public static void main (String[]args){
        Scanner leer = new Scanner (System.in);
        int[] billetes = {500,100,50,20};
        int[] monedas = {10,5,1};
        System.out.println("Ingresa el monto a retirar");
        int monto = leer.nextInt();
        for (int i = 0; i<4; i++){
            int cos = monto/ billetes[i];
            System.out.println(cos+" billetes de "+billetes[i]);
            monto = monto - cos*billetes[i];
        }
        for (int i = 0; i<4; i++){
            int cos = monto/ monedas[i];
            System.out.println(cos+" monedas de "+monedas[i]);
            monto = monto - cos*monedas[i];
        }
        leer.close();
    }
}