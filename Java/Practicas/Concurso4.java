import java.util.Scanner;
public class Concurso4 {
    public static void main (String[]args){
        Scanner leer = new Scanner (System.in);
        int edad,precio=0;
        System.out.println("Ingrese su edad:");
        edad = leer.nextInt();
        if(edad<8){precio = 0;}
        else if (edad < 12 && edad > 7) {precio = 50;}
        else if (edad < 18 && edad > 11) {precio = 100;}
        else if (edad < 26 && edad > 17) {precio = 150;}
        else {precio = 200;}
        System.out.println("El costo de su entrada es: "+ precio+ " pesos.");
        leer.close();
    }
}