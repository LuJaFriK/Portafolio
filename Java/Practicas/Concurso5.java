import java.util.Scanner;
public class Concurso5{
    public static void main (String[]args){
        Scanner leer = new Scanner (System.in);
        System.out.println("Ingrese la cantidad a ahorrar mensualmente:");
        float cant = leer.nextFloat();
        System.out.println("Ingrese cuántos meses ahorrará:");
        int meses = leer.nextInt();
        int i = 1;
        do{
            System.out.println("Mes "+ i+": "+ (i*cant));
            i++;
        }while(i<=meses);
        leer.close();
    }
}