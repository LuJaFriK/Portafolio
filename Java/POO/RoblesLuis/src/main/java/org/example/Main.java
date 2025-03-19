package org.example;
import java.util.Scanner;
/*
    Luis Javier Robles Topete 25460001
*/
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArticuloReparado articulo = new ArticuloReparado();
        int opc = 0;
        do{
            opc = 0;
            menu();
            opc = scanner.nextInt();
            scanner.nextLine();
            switch (opc){
                case 1:
                    registro(articulo);
                    break;
                case 2:
                    detalles(articulo);
                    break;
                case 3:
                    ticket(articulo);
                    break;
                case 4:
                    System.out.println("Saliendo...");
                    scanner.close();
                    break;
                default:
                    System.out.println("Error. Opcion no valida.");
                    break;
            }

        }while(opc!=4);
        scanner.close();
    }
    public static void menu(){
        System.out.println("1.- Registrar un articulo.");
        System.out.println("2.- Comprobar datos.");
        System.out.println("3.- Generar ticket.");
        System.out.println("4.- Salir");
    }
    public static void registro(ArticuloReparado articulo){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingresa el nombre del articulo: ");
        articulo.setNombre(scanner.nextLine());
        System.out.println("Ingresa el numero de serie para el articulo:");
        articulo.setNoserie(scanner.nextInt());
        scanner.nextLine();
        System.out.println("Ingresa la descripcion de la reparacion:");
        articulo.setDescripcion(scanner.nextLine());
        System.out.println("Ingresa el costo de la reparacion:");
        articulo.setCosto(scanner.nextDouble());
        System.out.println("Ingresa la clave del tecnico encargado:");
        articulo.setClavetecnico(scanner.nextInt());
    }
    public static void ticket(ArticuloReparado articulo){
        System.out.println("Mantenimiento de articulos elecronicos SA de CV");
        System.out.println("Detalles de la compra:");
        System.out.println("Nombre del producto: Reparacion de "+articulo.getNombre());
        System.out.println("Numero de serie del producto: "+articulo.getNoserie());
        System.out.println("Descripcion del producto: "+ articulo.getDescripcion());
        System.out.println("Subtotal: "+articulo.getCosto());
        System.out.println("Total(+IVA):"+(articulo.getCosto()*1.16));
        System.out.println("Atendio: "+articulo.getClavetecnico());
    }
    public static void detalles(ArticuloReparado articulo){
        System.out.println("=========================");
        articulo.info();
        System.out.println("Total: "+ articulo.getCosto()*1.16);
        System.out.println("=========================");
    }
}