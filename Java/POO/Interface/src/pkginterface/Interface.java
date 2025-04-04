/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package pkginterface;

/**
 *
 * @author lujafrik
 */
public class Interface {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       Imprimible pdf1 = new PDF();
       Imprimible imp1 = new Impresora();
       pdf1.imprimir();
       imp1.imprimir();
    }
    
}
