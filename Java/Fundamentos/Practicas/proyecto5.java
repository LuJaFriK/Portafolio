import java.util.Scanner;

public class proyecto5 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int n, i, f = 1;
        System.out.println("Ingresa el numero para el factorial:");
        n = leer.nextInt();
        leer.close();
        if (n >= 0) {
            for (i = 1; i < (n + 1); i++) {
                f *= i;
            }
            System.out.println(f);
        } else {
            System.out.println("No existe factorial para numeros negativos.");
        }
    }
}
