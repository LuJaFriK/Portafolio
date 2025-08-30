package org.example;
import java.util.Scanner;
import java.util.InputMismatchException;
public class Main {
    public static void main(String[] args) {
        int index;
        boolean found;
        Nodo list = null;
        Nodo iterationNode;
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
                        list = randomLinkedList(input("Numero de nodos a crear:"));
                        break;
                    case 2:
                        iterationNode = list;
                        while(iterationNode!=null){
                            System.out.println(iterationNode.getVal());
                            iterationNode = iterationNode.getNext();
                        }
                        break;
                    case 3:
                        index = searchNode(list,input("Ingrese el numero a buscar:"));
                        found = index!=-1;
                        System.out.println(found ? "El numero fue encontrado en el indice "+index : "El numero no fue encontrado.");//Altamente recomendado usar el operador ? para imprimir segun booleanos
                        break;
                    case 4:
                        deleteNode(list,input("Ingrese el numero a eliminar:"));
                        break;
                    case 5:
                        index = input("Ingresa el indice a mostrar:");
                        int value = searchIndex(list,index);
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
    public static Nodo randomLinkedList(int length){
        Nodo head = new Nodo((int)(Math.random()*10001));
        Nodo tempnode = head;
        for (int i=0;i<length-1;i++){
            tempnode.setNext(new Nodo((int)(Math.random()*10000)+1));
            tempnode = tempnode.getNext();
        }
        return head;
    }

    public static int searchNode(Nodo head,int value){
        Nodo current = head;
        for (int index=0;current!=null;index++){
            if (current.getVal()==value) return index;
            else current = current.getNext();
    }
        return -1;
    }

    public static void deleteNode(Nodo head,int value){
        if (head.getVal()==value){
            head = head.getNext();
            return;
        }
        Nodo current = head;
        while(current.getNext()!=null){
            if (current.getNext().getVal()==value){
                current.setNext(current.getNext().getNext());
                return;
            }
            current = current.getNext();
        }
        System.out.println("El valor no fue encontrado.");
    }

    public static int searchIndex(Nodo head, int index){
        Nodo current = head;
        for(int i=0;current!=null;i++){
            if(i==index) return current.getVal();
            current = current.getNext();
        }
        return -1;
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


