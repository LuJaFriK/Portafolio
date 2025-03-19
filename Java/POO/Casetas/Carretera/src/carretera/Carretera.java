/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package carretera;
import java.util.Scanner;
/**
 *
 * @author 25460001 Luis Javier Robles Topete
 */
public class Carretera {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        CasetaPeaje caseta = new CasetaPeaje();
        Scanner leer = new Scanner (System.in);   
        int opc=0;
        Camion camion = new Camion();
        do{
        //caseta.CalcularPeaje(camion.getEjes(), camion.getPeso());
        System.out.println("Intgroduzca la acción a realizar:");
        System.out.println("1.- Llenar datos del camión.");
        System.out.println("2.- Mostrar Datos");
        System.out.println("3.- Cobrar y recaudar");
        System.out.println("4.- Revisar caseta");
        System.out.println("5.- Salir");
        opc=leer.nextInt();
        switch (opc){
            case 1:
                System.out.println("Ingresa el peso del camión:");
                camion.setPeso(leer.nextInt());
                System.out.println("Ingresa los ejes del camión:");
                camion.setEjes(leer.nextInt());
                break;
            case 2:
                System.out.println("Datos del camión:");
                System.out.println("Peso: "+camion.getPeso());
                System.out.println("Ejes: "+camion.getEjes());
                System.out.println("____________________________");
                break;
            case 3:
                double peaje = caseta.CalcularPeaje(camion);
                System.out.println("La cantidad a pagar es:"+ peaje);
                System.out.println("Cantidad recaudada con exito");
                break;
            case 4:
                System.out.println("Cantidad de camiones: "+ caseta.getCantCamiones());
                System.out.println("Total recaudado: $"+ caseta.getTotalRecaudado());
                break;
            case 5:
                System.out.println("Saliendo...");
                break;
            default:
                System.out.println("Error. Opción no válida.");
        }

        }while(opc!=5);
    }
    
}
