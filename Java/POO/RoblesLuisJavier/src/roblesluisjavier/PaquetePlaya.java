/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package roblesluisjavier;

/**
 *
 * @author lujafrik
 */
public class PaquetePlaya extends Paquete {
    private boolean temporadaalta;
    private boolean bebidas;
    private boolean fiestanocturna;
    
    public PaquetePlaya(){
        super();
        temporadaalta = false;
        bebidas = false;
        fiestanocturna = false;
    }
    
    public PaquetePlaya(String destino,double preciobase,int duraciondias, boolean temporada, boolean bebidas, boolean fiesta){
        super(destino,preciobase,duraciondias);
        this.temporadaalta = temporada;
        this.bebidas = bebidas;
        this.fiestanocturna = fiesta;
    }
    
    public boolean TemporadaAlta(){
        return temporadaalta;
    }
    
    public void setTemporadaAlta(boolean temporada){
        this.temporadaalta = temporada;
    }
    
    public boolean getBebidasIncluidas(){
        return bebidas;
    }
    
    public void setBebidasIncluidas(boolean bebidas){
        this.bebidas = bebidas;
    }
    
    public boolean AccesoFiesta(){
        return fiestanocturna;
    }
    
    public void setAccesoFiesta(boolean fiesta){
        this.fiestanocturna = fiesta;
    }
    
    @Override
   public void venta(){
       double precionuevo = getPreciobase();
       if(temporadaalta){
           precionuevo *=1.25;
       }
       if(bebidas){
           precionuevo *=1.1;
       }
       if(fiestanocturna){
           precionuevo *=1.05;
       }
       if(getDuracion()<10){
           precionuevo *= 0.93;
       }
   }
}
