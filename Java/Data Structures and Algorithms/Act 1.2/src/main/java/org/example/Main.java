package org.example;
import java.util.Scanner;
import java.util.InputMismatchException;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Nodo head = null;
        while(true){
            try{
                switch (input("""
                Ingresa una de las siguientes opciones:
                1.- Crear una lista enlazada de 100 espacios con valores aleatorios
                2.- Imprimir la lista
                3.- Buscar un numero en el arreglo
                4.- Eliminar un numero del arreglo
                5.- Consultar un espacio del arreglo
                0.- Salir""")){
                    case 1:

                        break;
                    case 2:
                        Nodo iterationNode = head;
                        while(iterationNode!=null){
                            System.out.println();
                        }
                        break;
                    case 3:

                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 0:
                        System.out.println("Saliendo...");
                        return;
                }
            }catch(NullPointerException ex){
                System.out.println("No existe ninguna lista creada.");
            }
        }
    }
    public static void randomLinkedList(Nodo head,int length){
        Nodo tempnode = head;
        for (int i=0;i<100;i++){
            tempnode.setNext(new Nodo((int)(Math.random()*10000)+1));
        }

    }

    public static Nodo deleteNode(Nodo head, int value) {
        Nodo tempNode = head;
        if(head.getVal() == value){
            return head.getNext();}else {
            while (tempNode.getNext() != null) {
                if (tempNode.getNext().getVal() == value) {
                    tempNode.setNext(tempNode.getNext().getNext());
                    break;
                } else {
                    tempNode = tempNode.getNext();

                }
            }
        }

        return head;
    }
    public static Nodo addNode(Nodo head, int value){
        Nodo tempNode = head;
        while (tempNode.getNext() != null) {
            tempNode = tempNode.getNext();
        }
        tempNode.setNext(new Nodo (value));
        return head;
    }
    public static Nodo preNode(Nodo head, int value){
        Nodo newhead = new Nodo(value);
        newhead.setNext(head);
        return newhead;
    }

    public static Nodo setNode(Nodo head, int pos, int value) {
        Nodo tempNode = head;
        for(int i = 0; i < pos - 1 && tempNode != null; i++) {
            tempNode = tempNode.getNext();
        }

        if(tempNode != null && tempNode.getNext() != null) {
            tempNode.getNext().setVal(value);
        }

        return head;
    }
    public static int input(String mensaje) {
        Scanner scanner = new Scanner(System.in);
        int scanned;
        while (true) {
            try {
                System.out.println(mensaje);
                scanned = scanner.nextInt();
                break;
            } catch (InputMismatchException ex) {
                System.out.println("Error. Caracteres introducidos no válidos. Intente nuevamente.");
                scanner.nextLine();
                wait(2000);
            }
        }
        return scanned;
    }

    public static void wait(int milliseconds) {
        try {
            Thread.sleep(milliseconds);
        } catch (InterruptedException e) {
            System.out.println("La espera fue interrumpida.");
        }
    }
}


