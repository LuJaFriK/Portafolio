import java.util.Scanner;

public class proyecto3 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int n;
        System.out.println("Ingresa el numero a verificar");
        n = leer.nextInt();
        leer.close();
        if (n % 2 == 0) {
            System.out.println(n + " es un numero par");
        } else {
            System.out.println(n + " es un numero impar");
        }
    }
}
