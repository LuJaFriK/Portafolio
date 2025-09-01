package org.example;
import java.util.Scanner;
import java.util.InputMismatchException;
public class Lista {
    private Nodo head;

    public Lista (){
    }

    public Nodo randomLinkedList(int length){
        this.head = new Nodo((int)(Math.random()*10000)+1);
        Nodo current = this.head;
        for (int i=0;i<length-1;i++){
            current.setNext(new Nodo((int)(Math.random()*10000)+1));
            current = current.getNext();
        }
        return head;
    }

    public int searchNode(int value){
        Nodo current = this.head;
        for (int index=0;current!=null;index++){
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
        for(int i=0;current!=null;i++){
            if(i==index) return current.getVal();
            current = current.getNext();
        }
        return -1;
    }
    public void printList(){
        Nodo current = this.head;
        while(current != null){
            System.out.println(current.getVal());
            current = current.getNext();
        }
    }
}

class Main{
    public static void main(String[] args) {
        int index;
        boolean found;
        Lista list = new Lista();
        while(true){
            try{
                switch (input("""
                Ingresa una de las siguientes opciones:
                1.- Crear una lista enlazada con valores aleatorios
                2.- Imprimir la lista
                3.- Buscar un numero en la lista
                4.- Eliminar un numero de la lista
                5.- Consultar un espacio del arreglo
                0.- Salir""")){
                    case 1:
                        list.
                                randomLinkedList(input("Numero de nodos a crear:"));
                        break;
                    case 2:
                        list.printList();
                        break;
                    case 3:
                        index = list.searchNode(input("Ingrese el numero a buscar:"));
                        found = index!=-1;
                        System.out.println(found ? "El numero fue encontrado en el indice "+index : "El numero no fue encontrado.");//Altamente recomendado usar el operador ? para imprimir segun booleanos
                        break;
                    case 4:
                        list.deleteNode(input("Ingrese el numero a eliminar:"));
                        break;
                    case 5:
                        index = input("Ingresa el indice a mostrar:");
                        int value = list.searchIndex(index);
                        found = value != -1;
                        System.out.println(found ? "El valor de la lista en la posicion "+index+" es "+value:"El indice es mayor a la longitud de la lista.");

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
    public static int input(String mensaje) {
        /*
         * El metodo input es un reemplazo al scanner.nextInt
         * Elimina la redundancia, mejora la legibilidad del codigo
         * Y trabaja las Excepciones de tipado
         * NO REPLICAR EN SU COPIA DEL CODIGO
         * */
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
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    System.out.println("La espera fue interrumpida.");
                }
            }
        }
        return scanned;
    }
}


