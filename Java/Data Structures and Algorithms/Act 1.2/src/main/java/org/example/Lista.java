package org.example;
public class Lista {
    private Nodo head;

    public Lista (){
        this.head = null;
    }

    public void randomLinkedList(int length){
        for (int i=0; i<length;i++) this.head = new Nodo((int)(Math.random()*10000)+1,this.head);
    }

    public int searchNode(int value){
        var current = this.head;
        for (int index=1;current!=null;index++){
            if (current.getVal()==value) return index;
            else current = current.getNext();
        }
        return -1;
    }


    public void deleteNode(int value){
        if (this.head.getVal()==value){
            this.head = this.head.getNext();
            return;
        }
        var current = this.head;
        while(current.getNext()!=null){
            if (current.getNext().getVal()==value){
                current.setNext(current.getNext().getNext());
                return;
            }
            current = current.getNext();
        }
        System.out.println("El valor no fue encontrado.");
    }

    public int searchIndex(int index){
        var current = this.head;
        for(int i=1;current!=null;i++){
            if(i==index) return current.getVal();
            current = current.getNext();
        }
        return -1;
    }

    @Override
    public String toString(){
        var lista = "";
        var current = this.head;
        for (int i=1;current != null;i++){
            lista = lista+i+". "+current;
            if (current.getNext()!=null) lista = lista+", ";
            current = current.getNext();
        }
        return "["+lista+"]";
    }

    /*
    *
    *
    * Clase Nodo encapsulada dentro de la clase lista porque no necesita ser utilizada en otro sitio
    *
    *
    * */

    private class Nodo {
        private int val;
        private Nodo next;

        private Nodo(int valor, Nodo next){
            this.val = valor;
            this.next = next;
        }

        private Nodo(){}

        private Nodo getNext() {
            return next;
        }

        private int getVal() {
            return val;
        }

        private void setNext(Nodo next) {
            this.next = next;
        }

        private void setVal(int val) {
            this.val = val;
        }

        @Override
        public String toString(){
            return ""+this.val;
        }
    }

}


