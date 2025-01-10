import java.util.Scanner;

public class proyecto9 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int cant;
        System.out.println("Ingresa la cantidad de balones a comprar:");
        cant = leer.nextInt();
        leer.close();
        System.out.println("El total a pagar sera de: " + precio(cant));
    }

    public static double precio(int cant) {
        double costo = 0;
        if (cant >= 10) {
            costo = cant * 150.50;
        } else {
            costo = cant * 190;
        }
        return costo;
    }
}
