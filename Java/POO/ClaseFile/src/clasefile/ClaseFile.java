/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package clasefile;

import java.io.File;
import java.io.IO;
import java.io.IOException;
import java.util.logging.Logger;

/**
 *
 * @author lujafrik
 */
public class ClaseFile {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        File archivo = new File("File.txt");
        //crear archivio
        try {
            System.out.println(archivo.createNewFile()?"Pendejo":"Pendejo de todas formas");
        } catch (IOException ex) {
            ex.printStackTrace();
        }    
    }
    
}
