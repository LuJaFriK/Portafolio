import java.util.Scanner;

public class problema8 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i = 0, longitud;
        System.out.print("Ingresa la longitud del arreglo: ");
        longitud = scanner.nextInt();
        int arr[] = new int[longitud];
        while (i < longitud) {
            System.out.println("Ingresa el valor " + (i + 1));
            arr[i] = scanner.nextInt();
            i++;
        }
        scanner.close();
        int max = arr[0], min = arr[0];
        for (i = 0; i < longitud; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        for (i = 0; i < longitud; i++) {
            if (min > arr[i]) {
                min = arr[i];
            }
        }
        System.out.println("maximo: " + max);
        System.out.println("minimo: " + min);
    }
}
