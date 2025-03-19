package sistemacontrolescolar;

public class Estudiante{
    private String Nombre;
    private int nocontrol;
    private double[] calificaciones;
    
    public Estudiante() {
        this.Nombre = null;
        this.nocontrol = 0;
        this.calificaciones = new double[5];
    }

    public String getNombre() {
        return Nombre;
    }

    public void setNombre(String Nombre) {
        this.Nombre = Nombre;
    }

    public int getNocontrol() {
        return nocontrol;
    }

    public void setNocontrol(int nocontrol) {
        this.nocontrol = nocontrol;
    }

    public int[] getCalificaciones() {
        return calificaciones;
    }

    public void setCalificaciones(int[] calificaciones) {
        this.calificaciones = calificaciones;
    }

    public double calcularPromedio() {
        double suma = 0;
        for(int i=0;i<calificaciones.length;i++) {
            suma += calificaciones[i];
        }
        return suma / calificaciones.length;
    }
}