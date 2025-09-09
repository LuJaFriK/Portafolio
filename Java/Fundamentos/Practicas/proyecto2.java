import java.util.Scanner;

public class proyecto2 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        double n1, n2, resultado;
        System.out.println("Ingresa el primer numero para la suma:");
        n1 = leer.nextDouble();
        System.out.println("Ingresa el segundo numero para la suma");
        n2 = leer.nextDouble();
        resultado = n1 + n2;
        System.out.println(resultado);
        leer.close();
    }
}
