import java.util.Scanner;

public class problema3 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Solicitar la cantidad que el usuario desea retirar
        System.out.print("Ingrese el monto a retirar: ");
        int monto = scanner.nextInt();

        // Definir las denominaciones disponibles
        int[] billetes = { 500, 100, 50, 20 }; // Billetes
        int[] monedas = { 10, 5, 1 }; // Monedas

        // Imprimir la cantidad de billetes y monedas que se entregarán
        System.out.println("Salida:");

        // Contar billetes
        for (int billete : billetes) {
            int cantidadBilletes = monto / billete; // Calcular cuántos billetes de esta denominación
            if (cantidadBilletes > 0) {
                System.out.println(
                    cantidadBilletes + " billetes de " + billete
                );
            }
            monto %= billete; // Restar el valor de los billetes entregados al monto
        }

        // Contar monedas
        for (int moneda : monedas) {
            int cantidadMonedas = monto / moneda; // Calcular cuántas monedas de esta denominación
            if (cantidadMonedas > 0) {
                System.out.println(cantidadMonedas + " monedas de " + moneda);
            }
            monto %= moneda; // Restar el valor de las monedas entregadas al monto
        }

        // Si el monto no es 0, significa que no es posible entregar el monto exacto con las denominaciones disponibles
        if (monto != 0) {
            System.out.println(
                "El monto no puede ser entregado con las denominaciones disponibles."
            );
        }

        scanner.close();
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 999, 1000};

        System.out.println(invertirArreglo(arr));
    }

    public static int[] invertirArreglo(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - 1 - i];
            arr[n - 1 - i] = temp;
        }
        return arr;
    }
}