import java.util.Scanner;

public class proyecto7 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        float[] lista;
        int index, i;
        float prom, sum = 0;
        System.out.println("Cuantos numeros ingresaras?");
        index = leer.nextInt();
        lista = new float[index];
        for (i = 0; i < index; i++) {
            System.out.println("Ingresa el valor numero " + (i + 1));
            lista[i] = leer.nextFloat();
            sum += lista[i];
        }
        leer.nextLine();
        leer.close();
        prom = sum / index;
        System.out.println("El promedio es:" + prom);
    }
}
