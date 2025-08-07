package rpg;
import java.util.InputMismatchException;
import java.util.Scanner;



public class Inputs {
    // metodo para esperar un momento
    public static void wait(int milliseconds) {
        try {
            Thread.sleep(milliseconds);
        } catch (InterruptedException e) {
            System.out.println("La espera fue interrumpida.");
        }
    }   

    //metodos que optimizan el uso del scanner
    public static String InputString(String mensaje) {
        Scanner scanner = new Scanner(System.in);
        String scanned;
        while (true) {
            System.out.println(mensaje+ "(-1 para salir).");
            scanned = scanner.nextLine();
            if (!scanned.isEmpty()) break;
            System.out.println("Error, no se permite una entrada vacía. Intente nuevamente.");
            wait(2000);
        }
        if(scanned.equals("-1")){
            System.out.println("Cancelado...");
            return null;
        } 

        return scanned;
    }    

    
    public static int InputInt(String mensaje) {
       Scanner scanner = new Scanner(System.in);
        int scanned;
        while (true) {
            try {
                System.out.println(mensaje+ "(-1 para salir).");
                scanned = scanner.nextInt(); 
                break;
            } catch (InputMismatchException ex) {
                System.out.println("Error. Caracteres introducidos no válidos. Intente nuevamente.");
                scanner.nextLine();
                wait(2000);
            }
        }
        if(scanned == -1) System.out.println("Cancelado...");
        return scanned;
    }

    public static double InputDouble(String mensaje) {
        Scanner scanner = new Scanner(System.in);
        double scanned;
        while (true) {
            try {
                System.out.println(mensaje+ "(-1 para salir).");
                scanned = scanner.nextDouble(); 
                break;
            } catch (InputMismatchException ex) {
                System.out.println("Error. Caracteres introducidos no válidos. Intente nuevamente.");
                scanner.nextLine();
                wait(2000);
            }
        }
        if(scanned == -1) System.out.println("Cancelado...");
        return scanned;
    }

    //nuevo metodo input que tambien solo te permite ingresar un numero entre un rango determinado
    public static int InputIntRange(String mensaje, int min, int max) {
        Scanner scanner = new Scanner(System.in);
        int scanned;
        while (true) {
            try {
                System.out.println(mensaje);
                scanned = scanner.nextInt(); 
                if(scanned>=min&&scanned<=max){
                    break;
                }else{
                    System.out.println("Error. Opción no válida.");
                    wait(1500);
                }
            } catch (InputMismatchException ex) {
                System.out.println("Error. Caracteres introducidos no válidos. Intente nuevamente.");
                scanner.nextLine();
                wait(1500);
            }
        }
        return scanned;
    }
}