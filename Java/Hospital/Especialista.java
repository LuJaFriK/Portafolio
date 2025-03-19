public class Especialista extends Medico{
    private String especialidad;
    public Especialista(){
        super();
        especialidad = null;
    }
    public Especialista(String nombre, int cedula, String Escuela, String especialidad){
        super(nombre, cedula, Escuela);
        this.especialidad = especialidad;
    }
    @Override
    public void info(){
        super.info();
        System.out.println("Especialidad: "+especialidad);
    }
}