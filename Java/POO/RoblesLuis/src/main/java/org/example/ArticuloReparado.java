package org.example;

public class ArticuloReparado {
    private String nombre;
    private int noserie;
    private String descripcion;
    private double costo;
    private int clavetecnico;
    ArticuloReparado(){
        nombre = null;
        noserie = 0;
        descripcion = null;
        costo = 0;
        clavetecnico = 0;
    }
    ArticuloReparado(String nombre, int noserie,String descripcion,double costo, int clavetecnico){
        this.nombre = nombre;
        this.noserie = noserie;
        this.descripcion = descripcion;
        this.costo=costo;
        this.clavetecnico = clavetecnico;
    }

    public String getNombre() {
        return nombre;
    }
    public void setNombre(String nombre){
        this.nombre=nombre;
    }

    public int getNoserie() {
        return noserie;
    }

    public void setNoserie(int noserie) {
        this.noserie = noserie;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public double getCosto() {
        return costo;
    }

    public void setCosto(double costo) {
        this.costo = costo;
    }

    public int getClavetecnico() {
        return clavetecnico;
    }

    public void setClavetecnico(int clavetecnico) {
        this.clavetecnico = clavetecnico;
    }
    public void info(){
        System.out.printf("Nombre del articulo: "+nombre);
        System.out.printf("Numero de serie"+ noserie);
        System.out.printf("Descripcion de la reparacion: "+ descripcion);
        System.out.printf("Costo: "+ costo);
        System.out.printf("Clave del tecnico: "+ clavetecnico);
    }
}
