import java.util.Scanner;

public class proyecto10 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int n;
        System.out.println("Ingresa el numero a verificar:");
        n = leer.nextInt();
        System.out.println("Pares:");
        lista(n, 0);
        System.out.println("Sumatoria de pares:");
        sumatoria(n, 0);
        System.out.println("Impares:");
        lista(n, 1);
        System.out.println("Sumatoria de impares:");
        sumatoria(n, 1);
        leer.close();
    }

    public static void lista(int n, int cos) {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == cos) {
                System.out.println(i);
            }
        }
    }

    public static void sumatoria(int n, int cos) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == cos) {
                sum += i;
            }
        }
        System.out.println(sum);
    }
}
