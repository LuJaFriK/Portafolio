package org.example;

public class Perro {
    //Atributos de la clase
    //Visisbilidad tipo nombre
    private String nombre;
    private String raza;
    private int edad;
    private double peso;

    //crear metodo constructor sin parametros(Crea objetos vacios)
    public Perro() {
        nombre = null;
        raza = null;
        edad = 0;
        peso = 0;
    }
   
    //crear metodo Getter get: obtener
    public String getNombre() {
        return nombre;
    }
    public String getRaza() {
        return raza;
    }
    public int getEdad(){
        return edad;
    }
    public double getPeso(){
        return peso;
    }

    //crear metodo Setter set: modificar
    public void setNombre(String nombre){
        this.nombre=nombre;
    }
    public void setPeso(double peso){
        if (peso>=0){
            this.peso=peso;
        }else{
            System.out.println("El peso no ha sido ingresado. \tPor favor, ingrese un dato válido.");
        }
    }
    public void setEdad(int edad){
        if (edad>=0){
            this.edad=edad;
        }else{
            System.out.println("La edad no ha sido ingresada. \tPor favor, ingrese un dato válido.");
        }
    }
    public void setRaza(String raza){
        this.raza=raza;
    }
    //Devolver todos los datos del perro
    public void infoPerro(){
        System.out.println("Nombre del perro: "+nombre);
        System.out.println("Raza del perro: "+raza);
        System.out.println("Edad del perro: "+edad);
        System.out.println("Peso del perro: "+peso);


    }
}