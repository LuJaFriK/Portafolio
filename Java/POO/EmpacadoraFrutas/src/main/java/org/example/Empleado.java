package org.example;

public class Empleado {
    private String nombre;
    private double salario;
    private int periodo;
    private double montototal;

    public Empleado() {
        nombre = null;
        salario = 0;
        periodo = 0;
        montototal = 0;
    }
    public void setNombre(String nombre){this.nombre=nombre;}
    public String getNombre(){return nombre;}

    public double getSalario(){return salario;}
    public void setSalario(double salario){this.salario=salario;}

    public int getPeriodo(){return periodo;}
    public void setPeriodo(int periodo){this.periodo=periodo;}

    public void setMontoTotal(double montoTotal){this.montototal = montoTotal;}
    public double getMontoTotal(){
        return montototal;
    }

    public void infoEmpleado(){
        System.out.println("Nombre del trabajador: "+ nombre);
        System.out.println("Periodo trabajado: "+ periodo);
        System.out.println("Salario diario base: "+ salario);
        System.out.println("Monto a pagar por esta quincena: "+ montototal);
    }
}