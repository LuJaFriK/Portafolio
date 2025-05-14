/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package roblesluisjavier;

/**
 *
 * @author lujafrik
 */
public class PaqueteMontaña extends Paquete{
   boolean invierno;
   boolean guia;
   boolean equipoincluido;
   
   public PaqueteMontaña (){
    super();
    invierno = false;
    guia = false;
    equipoincluido = false;
   }
   
   public PaqueteMontaña (String destino,double preciobase,int duraciondias, boolean invierno, boolean guia, boolean equipoincluido){
    super(destino, preciobase, duraciondias);
    this.invierno = invierno;
    this.guia = guia;
    this.equipoincluido = equipoincluido;
   }
   
   public boolean Invierno(){
       return invierno;
   }
   
   public void setInvierno(boolean invierno){
       this.invierno = invierno;
   }
   
   public boolean Guia(){
       return guia;
   }
   
   public void setGuia(boolean guia){
       this.guia = guia;
   }
   
   public boolean incluyeEquipo(){
       return equipoincluido;
   }
    
   
   public void incluirEquipo(boolean equipo){
       this.equipoincluido = equipo;
   }
   
   @Override
   public void venta(){
       double precionuevo = getPreciobase();
       if(invierno){
           precionuevo *=1.15;
       }
       if(guia){
           precionuevo *=1.1;
       }
       if(getDuracion()<10){
           precionuevo *= 0.93;
       }
   }
   
}

