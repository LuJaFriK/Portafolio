package org.example;

public class Nodo {
    private int val;
    private Nodo next;

    public Nodo(int valor, Nodo next){
        this.val = valor;
        this.next = next;
    }

    public Nodo(){}

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
