/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package hospital;

/**
 *
 * @author lujafrik
 */
public class Cardiologo extends Medico{
    private String subespecialidad;
    public Cardiologo(){
        super();
        subespecialidad = null;
    }
    public Cardiologo(String nombre, int cedula, String Escuela, String subespecialidad){
        super(nombre, cedula, Escuela);
        this.subespecialidad = subespecialidad;
    }
        public void realizarECG(){
        
    }
    public String getSubespecialidad(){
        return subespecialidad;
    }
    public void setSubespecialidad(String subespecialidad){
        this.subespecialidad = subespecialidad;
    }
}
