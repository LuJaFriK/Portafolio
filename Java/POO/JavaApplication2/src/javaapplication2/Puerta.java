/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaapplication2;

/**
 *
 * @author lujafrik
 */
public class Puerta{
    private String madera;
    //las medidas van en milimetros
    private int altura;
    private int anchura;
    private int grosor=45;
    private double precio;
    private String[] tiposmaderas={"Pino","Cedro","Roble"};
    
    public Puerta() {
        madera = this.tiposmaderas[0];
        altura = 2030;
        anchura = 825;
        precio = 2436.90;
    }

    public String getMadera() {
        return madera;
    }

    public void setMadera(int t) {
        this.madera = tiposmaderas[t];
    }

    public int getAltura() {
        return altura;
    }
    public void getTiposMaderas(){
        for(int i=1;i<4;i++){System.out.print(i+".- "+tiposmaderas[i-1]+"   ");}
        System.out.println("");
    }

    public void setAltura(int altura) {
        this.altura = altura;
    }

    public int getAnchura() {
        return anchura;
    }

    public void setAnchura(int anchura) {
        this.anchura = anchura;
    }
    public int getGrosor() {
        return grosor;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio() {
        if (this.altura!=2030||this.anchura!=825){this.precio=2436.90*1.15;}
        if(this.madera.equals(this.tiposmaderas[1])){this.precio=this.precio*1.18;}
        if(this.madera.equals(this.tiposmaderas[2])){this.precio=this.precio*1.32;}
    }
    
}
