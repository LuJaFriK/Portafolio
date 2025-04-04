/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package hospital;

/**
 *
 * @author lujafrik
 */
public class Medico {
    private String nombre;
    private int cedula;
    private String escuela;
    
    public Medico(){
        nombre = null;
        cedula = 0;
        escuela = null;
    }
    
    public Medico(String nombre,int cedula,String escuela){
        this.nombre = nombre;
        this.cedula = cedula;
        this.escuela = escuela;
    }
    
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getCedula() {
        return cedula;
    }

    public void setCedula(int cedula) {
        this.cedula = cedula;
    }

    public String getEscuela() {
        return escuela;
    }

    public void setEscuela(String escuela) {
        this.escuela = escuela;
    }
    
    public void atenderPaciente(){
        
    }
    
    public void info(){
        System.out.println("Nombre del médico: " + nombre);
        System.out.println("Cédula del médico: " + cedula);
        System.out.println("Escuela del médico: " + escuela);
    }
}
