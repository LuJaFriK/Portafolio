/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package fragancia;
import java.util.Scanner;
/**
 *
 * @author lujafrik
 */
public class Fragancia{
    public static void main (String[]args){
        Perfume[] catalogo = new Perfume[30];
        Scanner leer = new Scanner(System.in);
        int opc, i;
        do{
            System.out.println("Perfumeria SA de CV.");
            System.out.println("1.- Ingresar un perfume nuevo:");
            System.out.println("2.- Buscar en el catalogo:");
            System.out.println("3.- Desplegar todo el catalogo:");
            System.out.println("4.- Comprar un perfume:");
            System.out.println("5.- Salir:");
            opc = leer.nextInt();
            leer.nextInt();
            switch(opc){
                case 1:
                    i=0;
                    
                    while (i<catalogo.length-1&&catalogo[i]!=null){i++;}
                    catalogo[i] = new Perfume();
                    System.out.println("Ingresa el nombre del perfume: ");
                    catalogo[i].setNombre(leer.nextLine());
                    System.out.println("Ingresa el precio del ferfume:");
                    catalogo[i].setPrecio(leer.nextDouble());
                    System.out.println("Ingresa la cantidad de perfumes disponibles:");
                    catalogo[i].setCantidad(leer.nextInt());
                    break;
                case 2:
                    System.out.println("Ingresa el nombre del perfume a buscar:");
                    int b = buscar(leer.nextLine(),catalogo);
                    if (b>=0){catalogo[b].imprimirInfo();}
                    break;
                case 3:
                    System.out.println("Catálogo de perfumes:");
                    for(i=0;i<catalogo.length;i++){
                        System.out.println("___________________");
                        catalogo[i].imprimirInfo();
                        System.out.println("___________________");
                    }
                    break;
                case 4:
                    System.out.println(" Ingresa el nombre del perfume a comprar");
                    b = buscar(leer.nextLine(),catalogo);
                    if (b>=0){
                        System.out.println("Cuántos desea comprar?");
                        int cantidad = leer.nextInt();
                        if(catalogo[b].getCantidad()<cantidad){
                            System.out.println("Lo sentimos, no hay suficientes productos.");
                        }else{catalogo[b].vender(cantidad);
                            System.out.println("Su total es de: $"+(catalogo[b].getPrecio()*cantidad)+"mxn");
                        generarTicket(perfume, cantidad);
                        }
                    }
                    break;
                case 5:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Error. Opción no válida.");
                    break;
            }
        }while(opc!=5);
        leer.close();
    }
    public static int buscar(String nombre, Perfume[] catalogo){
        int i;
        for (i=0; i<catalogo.length; i++){
            if(nombre.equals(catalogo[i].getNombre())){
                return i;
            }
        }
        System.out.println("No se encontraron coincidencias.");
        return -1;
    }
    public static void generarTicket(Perfume perfume, int cantidad) {
        double subtotal = perfume.getPrecio() * cantidad;
        double iva = subtotal * 0.16; // IVA del 16%
        double total = subtotal + iva;

        System.out.println("\n=== TICKET DE COMPRA ===");
        System.out.println("Perfumeria Fragancia SA de CV");
        System.out.println("-------------------");
        System.out.println("Producto: " + perfume.getNombre());
        System.out.println("Cantidad: " + cantidad);
        System.out.println("Precio unitario: $" + perfume.getPrecio());
        System.out.println("Subtotal: $" + subtotal);
        System.out.println("IVA (16%): $" + iva);
        System.out.println("Total con IVA: $" + total);
        System.out.println("-------------------");
        System.out.println("¡Gracias por su compra!");
        System.out.println("====================\n");
    }
}
    

