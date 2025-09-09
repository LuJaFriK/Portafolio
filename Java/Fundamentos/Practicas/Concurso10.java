import java.util.Scanner;
public class Concurso10 {
    public static void main (String[]args){
        Scanner leer = new Scanner (System.in);
        System.out.println("Ingrese los minutos:");
        int min = leer.nextInt();
        leer.close();
        horas(min);        
    }
    public static void horas (int min){
        int horas = min/60;
        int res = min-horas*60;
        System.out.println(min+" minutos es igual a "+horas+" horas y "+res+" minutos.");
    }
}