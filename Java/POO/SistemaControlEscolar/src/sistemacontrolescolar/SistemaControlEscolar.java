/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package sistemacontrolescolar;

import java.nio.file.Path;
import java.util.Scanner;
/**
 *
 * @author lujafrik
 */
public class SistemaControlEscolar {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Estudiante[] estudiantes = new Estudiante[5];
        Scanner entrada=new Scanner(System.in);
        int opc=0;
        do{
            System.out.println("        Menú Sistema Control Escolar");
            System.out.println("1.- Registrar Estudiante.");
            System.out.println("2.- Calcular promedio");
            System.out.println("3.- Visualizar estudiante.");
            System.out.println("4.- Salir.");
            opc = entrada.nextInt();
            switch (opc){
                case 1:
                    registrar();
                break;
                case 2:
                break;
                case 3:
                break;
                case 4:
                break;
                default:
                break;
            }
        }while(opc!=4);
    }
    public void registrar(){
        int i;
        while (i < estudiantes.length-1 && estudaintes[i]!=null) {i++;}
        estudiantes[i]=new Estudiante();
        System.out.println("Ingresa el nombre del estudiante:");
        estudiantes[i].setNombre(entrada.nextLine());
        System.out.println("Ingresa el número de control del estudiante:");
        estudiantes[i].setNocontrol(entrada.nextLine());
        for(){
            System.out.println("Ingresa la evidencia número "+i+1);
            estudiantes[i].setNocontrol(entrada.nextLine());
        }
        
    }
    
}
