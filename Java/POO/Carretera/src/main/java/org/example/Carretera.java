package org.example;

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

        System.out.println("Calcular peaje del camión:");
        int opc=0;
        do{
            //caseta.CalcularPeaje(camion.getEjes(), camion.getPeso());
            System.out.println("1.- Mostrar datos del camión.");
            System.out.println("2.- Estado de Caseta");
            System.out.println("3.- Recaudar");
            System.out.println("4.- Salir");
            switch (opc){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    System.out.println("Error. Opción no válida.");
            }
            

        }while(opc!=4);
    }

}