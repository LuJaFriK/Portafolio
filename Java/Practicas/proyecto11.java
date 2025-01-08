import java.util.Scanner;

public class proyecto11 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        String palabra;
        System.out.println("Ingresa la palabra a desglozar: ");
        palabra = leer.nextLine().toUpperCase();
        System.out.println("Cantidad de vocales: " + cant(palabra, true));
        System.out.println("Cantidad de consonantes: " + cant(palabra, false));
        leer.close();
    }

    public static int cant(String palabra, boolean opc) {
        int i;
        int cov = 0;
        char letra;
        for (i = 0; i < palabra.length(); i++) {
            letra = palabra.charAt(i);
            if (
                letra == 'A' ||
                letra == 'E' ||
                letra == 'I' ||
                letra == 'O' ||
                letra == 'U'
            ) {
                cov++;
            }
        }
        if (opc == true) {
            return cov;
        } else {
            int coc;
            coc = palabra.length() - cov;
            return coc;
        }
    }
}
