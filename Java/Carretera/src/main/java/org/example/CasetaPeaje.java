package org.example;

public class CasetaPeaje {
    private int cantcamiones;
    private double totalrecaudado;

    public CasetaPeaje(){
        cantcamiones=0;
        totalrecaudado=0;
    }
    public double getTotalRecaudado(){
        return totalrecaudado;

    }
    public int getCantCamiones(){
        return cantcamiones;
    }
    public double CalcularPeaje(Camion c){
        double peaje;
        int ejes=c.getEjes();
        int peso=c.getPeso();
        double costejes=ejes*5;
        double costpeso=peso/1000*10;
        peaje = costpeso+costejes;
        this.cantcamiones++;
        this.totalrecaudado+=peaje;
        return peaje;
    }
    public double recaudar(){
        return 0;
    }
    public void visualizarCaseta(){}
}

