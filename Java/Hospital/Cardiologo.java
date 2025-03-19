public class Cardiologo extends Especialista{
    private String subespecialidad;
    public Cardiologo(){
        super();
        subespecialidad = null;
    }
    public Cardiologo(String nombre, int cedula, String Escuela, String subespecialidad){
        super(nombre, cedula, Escuela, "Cardiologia");
        this.subespecialidad = subespecialidad;
    }
    public void aplicarTerapia(){
        
    }
    public String getSubespecialidad(){
        return subespecialidad;
    }
    public void setSubespecialidad(String subespecialidad){
        this.subespecialidad = subespecialidad;
    }
}