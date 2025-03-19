package org.example;

public class Estudiante {
    private String nombre;
    private double[] calificaciones;
    private int nocontrol;
    private double promedio;
    public Estudiante(){
        nombre = null;
        int nocontrol=0;
        calificaciones  = new double[6];
        for(int i=0;i<6;i++){
            calificaciones[i]=0;
        }
    }
    
    public String getNombre() {
        return nombre;
    }
    
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    
    public double[] getCalificaciones() {
        return calificaciones;
    }
    
    public void setCalificaciones(int i, double calificacion) {
        this.calificaciones[i] = calificacion;
    }
    
    public int getNocontrol() {
        return nocontrol;
    }
    
    public void setNocontrol(int nocontrol) {
        this.nocontrol = nocontrol;
    }
    public void setPromedio(double[] calificaciones) {
        double suma = 0.0;
        for (int i = 0; i < calificaciones.length; i++) {
            suma += calificaciones[i];
        }
        this.promedio = suma / calificaciones.length;
    }
    public double getPromedio(){
        return promedio;
    }
    public void infoEstudiante(){
        System.out.println("Nombre del estudiante: "+ nombre);
        System.out.println("Número de control: "+nocontrol);
        System.out.println("Datos de las calificaciones:");
        for(int i=0;i<6;i++){
            System.out.println("Calificacion "+(i+1)+": "+calificaciones[i]);
        }
        System.out.println("Promedio del estudiante: "+ promedio);
    }
}