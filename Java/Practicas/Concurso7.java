import java.util.ArrayList;
import java.util.Scanner;
public class Concurso7 {
    public static void main (String[]args){
        ArrayList<Integer> lista = new ArrayList<>();
        Scanner leer = new Scanner (System.in);
        int entero,i=0;
        System.out.println("Ingresa el numero entero:");
        entero = leer.nextInt();
        leer.close();
        for(i=1;i<=entero;i++){
            if(i%2==0){lista.add(i);}
                    lista.add(0);
        }

        System.out.println("Los numeros pares son: ");
        System.out.println(lista);
    }
}