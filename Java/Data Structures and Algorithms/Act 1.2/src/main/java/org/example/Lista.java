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
        Nodo current = this.head;
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
        Nodo current = this.head;
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
        Nodo current = this.head;
        for(int i=1;current!=null;i++){
            if(i==index) return current.getVal();
            current = current.getNext();
        }
        return -1;
    }
    public void printList(){
        Nodo current = this.head;
        for (int i=1;current!=null;i++){
            System.out.println(i+". "+current.getVal());
            current = current.getNext();
        }
    }
}


