import java.util.Scanner;
public class Concurso6 {
    public static void main (String[]args){
        Scanner leer = new Scanner (System.in);
        String passkey = "Tj2024", key;
        do{
            System.out.println("Ingresa tu contraseña:");
            key = leer.nextLine();
            if (!passkey.equals(key)){System.out.println("Error en la contraseña.");}
        }while(!passkey.equals(key));
        leer.close();
    }
}