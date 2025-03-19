/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package javaapplication2;

import java.util.Scanner;

/**
 *
 * @author lujafrik
 */
public class JavaApplication2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner leer = new Scanner (System.in);
        System.out.println("Ingresa una puerta nueva:");
        Puerta puerta = new Puerta();
        int opc=0;
        do{
            System.out.println("1. Revisar datos actuales de la puerta.");
            System.out.println("2. Ingresar medidas nuevas.");
            System.out.println("3. Cambiar el tipo de madera.");
            System.out.println("4. Remover cambios.");
            System.out.println("5. Comprar y generar ticket.");
            System.out.println("6. Salir.");
            opc=leer.nextInt();
            leer.nextLine();
            switch(opc){
                case 1:
                    infoPuerta(puerta);
                break;
                case 2:
                    System.out.println("Ingresar altura nueva de la puerta (0 para altura predeterminada): ");
                    int altura = leer.nextInt();
                    if(altura!=0){
                        puerta.setAltura(altura);
                    }
                    System.out.println("Ingresar anchura nueva de la puerta (0 para altura predeterminada): ");
                    int anchura = leer.nextInt();
                    if(anchura!=0){
                        puerta.setAnchura(anchura);
                    }
                break;
                case 3:
                    System.out.println("Ingresa una madera de las siguientes:");
                    puerta.getTiposMaderas();
                    puerta.setMadera(leer.nextInt()-1);
                break;
                case 4:
                    puerta = new Puerta();
                    System.out.println("Se han eliminado todos los cambios.");
                break;
                case 5:
                    ticketPuerta(puerta);
                    System.out.println("\nUsted ha comprado exitosamente. ¿Desea continuar comprando?");
                    System.out.println("0: No.    1: Si.");
                    int op = leer.nextInt();
                    puerta=new Puerta();
                    if(op==0){opc=6;}
                break;
                case 6:
                    System.out.println("Saliendo...");
                break;
                default:
                    System.out.println("Opcion no válida, por favor, ingresa la opción correcta.");
                    break;
            }
            puerta.setPrecio();
        }while(opc!=6);
        
    }
    public static void infoPuerta(Puerta puerta){
        System.out.println("Datos de la puerta:");
        System.out.println("Madera: "+puerta.getMadera());
        System.out.println("Dimensiones:"+puerta.getAltura()+"mm x "+puerta.getAnchura()+"mm x "+puerta.getGrosor()+"mm");
        System.out.println("Subtotal: $"+puerta.getPrecio());
    }
    public static void ticketPuerta(Puerta puerta){
        double iva = puerta.getPrecio() * 0.16;
        System.out.println("===============================");
        System.out.println("        TICKET DE VENTA       ");
        System.out.println("===============================");
        System.out.println("Producto: Puerta de madera");
        System.out.println("Tipo de madera: " + puerta.getMadera());
        System.out.println("Dimensiones: ");
        System.out.println("  Alto: " + puerta.getAltura() + "mm");
        System.out.println("  Ancho: " + puerta.getAnchura() + "mm"); 
        System.out.println("  Grosor: " + puerta.getGrosor() + "mm");
        System.out.println("-------------------------------");
        System.out.println("Subtotal: $" + puerta.getPrecio());
        System.out.println("IVA (16%): $" + String.format("%.2f", iva));
        System.out.println("Total: $" + String.format("%.2f", (puerta.getPrecio() + iva)));
        System.out.println("===============================");
        System.out.println("    ¡Gracias por su compra!   ");
        System.out.println("===============================");
    }
}
