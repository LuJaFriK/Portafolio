import java.util.Scanner;

public class proyecto6 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int n;
        System.out.println(
            "Ingresa un numero para empezar la cuenta regresiva:"
        );
        n = leer.nextInt();
        leer.close();
        while (n != 0) {
            System.out.println(n);
            n--;
        }
    }
}
