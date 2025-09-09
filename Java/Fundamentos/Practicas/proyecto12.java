import java.util.Scanner;

public class proyecto12 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        Datos[] liga;
        int index, i, ii;
        System.out.println("Ingresa la cantidad de equipos que participan");
        index = leer.nextInt();
        liga = new Datos[index];
        for (i = 0; i < index; i++) {
            leer.nextLine();
            liga[i] = new Datos();
            System.out.println("Ingresa el nombre del equipo " + i + ":");
            liga[i].nombre = leer.nextLine();
            for (ii = 0; ii < 10; ii++) {
                System.out.println(
                    "Ingresa los puntos del partido " + (ii + 1) + ":"
                );
                liga[i].puntos[ii] = leer.nextInt();
                liga[i].total += liga[i].puntos[ii];
            }
        }
        for (i = 0; i < index; i++) {
            System.out.println(liga[i].nombre + ":");
            for (ii = 0; ii < 10; ii++) {
                System.out.println(
                    "Puntos del partido " + (ii + 1) + ":" + liga[i].puntos[ii]
                );
            }
            System.out.println("Total de puntos: " + liga[i].total);
        }
        leer.close();
    }
}
