package org.example;

public class Pantalon {
    private int tipo;
    private String marca;
    private String talla;
    private boolean cinturaAjustable;
    private double precio;

    public Pantalon() {
        tipo = 0;
        marca = null;
        talla = null;
        cinturaAjustable = false;
        precio = 0; 
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getTalla() {
        return talla;
    }

    public void setTalla(String talla) {
        this.talla = talla;
    }

    public boolean getCinturaAjustable() {
        return cinturaAjustable;
    }

    public void setCinturaAjustable(String confirmacion) {
        if (confirmacion.equalsIgnoreCase("Si")){
            this.cinturaAjustable = true;
        }else if (confirmacion.equalsIgnoreCase("No")){
            this.cinturaAjustable = false;
        }else{
            System.out.println("Error. respuesta no valida. Se asume que no");
            this.cinturaAjustable = false;
        }
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        if (precio<0){precio*=-1;}
        if (cinturaAjustable){precio *=1.25;}
        if (tipo == 2){precio *=1.1;}
        this.precio = precio;
    }
    public int getTipo() {
        return tipo;
    }

    public void setTipo(int tipo) {
        if(tipo==1||tipo==2){
            this.tipo = tipo;
        }else{
            System.out.println("Error. tipo de pantalón no especificado. Se asigna casual.");
            this.tipo = 1;
        }
            
    }
    public void info(){
        String afi = "No.";
        if (cinturaAjustable){
            afi = "Si.";
        }
        System.out.println("Tipo: "+tipo);
        System.out.println("Marca: "+marca);
        System.out.println("Talla: "+talla);
        System.out.println("Cintura ajustable: "+afi);
        System.out.println("Precio: $"+precio);
    }
}
