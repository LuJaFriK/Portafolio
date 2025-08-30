package org.example;

public class Nodo {
    private int val; //Refiere al valor que almacena el nodo, por ejemplo arreglo[3] = 6;
    private Nodo next; //Almacena literalmente al nodo siguiente

    //Metodos irrelevantes

    public Nodo(int valor){
        this.val = valor;
        this.next = null;
    }
    public Nodo getNext() {
        return next;
    }

    public int getVal() {
        return val;
    }

    public void setNext(Nodo next) {
        this.next = next;
    }

    public void setVal(int val) {
        this.val = val;
    }
}
