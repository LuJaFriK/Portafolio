/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package roblesluisjavier;

/**
 *
 * @author lujafrik
 */
public abstract class Paquete {
    private String destino;
    private double preciobase;
    private int duraciondias;
    
    public Paquete(){
        destino = null;
        preciobase = 0;
        duraciondias = 0;
    }
    
    public Paquete(String destino,double preciobase,int duraciondias){
        this.destino = destino;
        this.preciobase = preciobase;
        this.duraciondias = duraciondias;
    }
    
    public String getDestino(){
        return destino;
    }
    
    public void setDestino(String destino){
        this.destino = destino;
    }
    
    public double getPreciobase(){
        return preciobase;
    }
    
    public void setPreciobase(double preciobase){
        this.preciobase = preciobase;
    }
    
    public int getDuracion(){
        return duraciondias;
    }
    
    public void setDuracion(int duracion){
        this.duraciondias = duracion;
    }
    
    public abstract void venta();
    
    
    
}
