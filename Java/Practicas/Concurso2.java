import java.util.Scanner;
public class Concurso2 {
    public static void main (String[]args){
        Scanner leer = new Scanner (System.in);
        System.out.println("Ingresa la altura:");
        float altura = leer.nextFloat();
        System.out.println("Ingresa la base:");
        float base = leer.nextFloat();
        System.out.println("Ingresa el ancho:");
        float ancho = leer.nextFloat();
        float V = base*altura*ancho;
        leer.close();
        System.out.println("El volumen de prisma rectangular es: "+ V+" metros cúbicos");
    }
}