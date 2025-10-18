#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <string>
#include <sstream>
#include "Nodo.hpp"


template<typename type>
class Linked_circular_list {

    private:
        
        Nodo<type>* head;
        Nodo<type>* back;

        static void link(Nodo<type>*back,Nodo<type>*front){
            //Si back es un nodo valido, lo enlaza con front
            if(back) back->next = front;
            //Si front es un nodo valido, lo enlaza con back
            if(front) front->prev = back;
        }

        void remove(Nodo<type>*& deleted_node) {
            //Solo un nodo
            if (deleted_node == head && deleted_node == back) {
                head = nullptr;
                back = nullptr;
            }//El nodo a eliminar es la cabeza
            else if(deleted_node == head){
                //Desenlace
                head = deleted_node->next;
                link(back, head);

            }//El nodo a eliminar es la cola
            else if(deleted_node == back) {
                //Desenlace
                back = deleted_node->prev;
                link(back, head);
            
            }//Es cualquier nodo de enmedio
            else {
                link(deleted_node->prev, deleted_node->next);
            }
            //Eliminar el nodo al final
            delete deleted_node;
        }


    public:
        
        Linked_circular_list() : head(nullptr),back(nullptr){
        }

        ~Linked_circular_list() {
            if (head) {
                Nodo<type>* current = head;
                back->next = nullptr; // Break the circle
                while (current) {
                    Nodo<type>* next = current->next;
                    delete current;
                    current = next;
                }
                head = nullptr;
                back = nullptr;
            }
        }

        bool empty() const { return (head == nullptr); }

        void add(type value) {
            //Crea el nodo nuevo
            Nodo<type>* nuevo = new Nodo(value);
            //Si es vacia asigna el nodo nuevo a los apuntadores y los enlaza
            if(empty()){
                head = back = nuevo;
                link(head,back);
            //Si no es vacia enlaza el nodo antes de la cabecera, despues de la cola y reasigna la cabeza
            }else{
                link(nuevo,head);
                link(back,nuevo);
                head = nuevo;
            }
        }

        //Extrae el valor de la cabeza sin modificar nada
        type pull()const{ return head->value; }

        type pop(int index) {
            //Validar vacios
            if (empty()) throw std::out_of_range("Lista vacía");
            if (index < 0) throw std::out_of_range("Índice inválido");

            Nodo<type>* deleted_node = head;
            //Encontrar el nodo 
            for(int i=0; i < index; i++){
                deleted_node = deleted_node->next;
            }

            type deleted_value = deleted_node->value;
            //Eliminar el puntero correctamente
            remove(deleted_node);
            return deleted_value;
        }

        //Busca el indice de un valor supuestamente indexado
        int search(type val) const {
            Nodo<type>* current = head;
            int index = 0;
            while (current) {
                if (current->value == val) return index;
                current = current->next;
                index++;
            }
            return -1;
        }

        //Retorna el valor de un indice
        type get(int index) const {
            if (index < 0) throw std::out_of_range("Índice inválido");
            Nodo<type>* current = head;
            for (int i = 0; i < index; i++) {
                if(current == nullptr)
                current = current->next; throw std::out_of_range("Índice inválido");
            }
            return current->value;
        }

        std::string mostrar() const {
            if (!head) {
                return "[]";
            }
            
            // Usaremos un stringstream para construir la cadena de manera eficiente
            std::stringstream ss;
            ss << "[";
            
            // Caso de un solo nodo: head == head->next
            if (head == head->next) {
                // Asumiendo que 'type' puede ser insertado en un stream (std::cout o std::stringstream)
                ss << head->value;
                ss << "]";
                return ss.str();
            }
            
            Nodo<type>* current = head;
            
            // Recorremos la lista circular hasta que current vuelva a ser head
            do {
                // 1. Agregar el valor actual
                ss << current->value;
                
                // 2. Moverse al siguiente nodo
                current = current->next;
                
                // 3. Agregar la coma y el espacio si NO hemos llegado al final del ciclo (head)
                if (current != head) {
                    ss << ", ";
                }
            } while (current != head);
            
            ss << "]";
            return ss.str();
    }

};

#endif // LINKEDLIST_H