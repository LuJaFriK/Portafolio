import java.util.Scanner;
public class Concurso1 {
    public static void main (String[]args){
        Scanner leer = new Scanner (System.in);
        float celsius;
        System.out.println("Ingresa la cantidad en grados celsius");
        celsius = leer.nextFloat();
        float fahrenheit = celsius*9/5+32;
        leer.close();
        System.out.println(celsius+" grados Celsius es igual a "+ fahrenheit+ " grados Fahrenheit.");
    }
}