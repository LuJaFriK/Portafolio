import java.util.Scanner;

public class proyecto4 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int n, i;
        System.out.println("Ingresa el numero para la tabla de multiplicar:");
        n = leer.nextInt();
        leer.close();
        for (i = 1; i < 11; i++) {
            System.out.println(n + "*" + i + "=" + (n * i));
        }
    }
}
