package org.example;

public class Gerente extends Empleado {
    private String departamento;
    private String asistente;
    private double bono;

    public Gerente() {
        super();
        departamento = null;
        asistente = null;
        bono = 0;
    }

    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    public String getDepartamento() {
        return departamento;
    }

    public void setAsistente(String Asistente) {
        this.asistente = Asistente;
    }

    public String getAsistente() {
        return asistente;
    }

    public void setBono(double bono) {
        this.bono = bono;
    }

    public double getBono() {
        return bono;
    }

    @Override
    public void setMontoTotal(double montoTotal) {
        super.setMontoTotal(montoTotal + bono);
    }
    @Override
    public void infoEmpleado(){
        super.infoEmpleado();
    }
    
}
