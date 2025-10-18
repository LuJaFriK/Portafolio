#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "Nodo.h"


template<typename type>
class Linked_circular_list {

    protected:
        
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

                head = deleted_node->next;
                link(back, head);

            }//El nodo a eliminar es la cola
            else if(deleted_node == back) {

                back = deleted_node->prev;
                link(back, head);
            
            }//Es cualquier nodo de enmedio
            else {
                link(deleted_node->prev, deleted_node->next);
            }
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
            if(empty()){
                head = new Nodo(value);
                back = head;
            }else{
                Nodo<type>* nuevo = new Nodo(value);
                link(nuevo, head);
                head = nuevo;
                back.next = head;
            }
        }

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

        type get(int index) const {
            if (index < 0) throw std::out_of_range("Índice inválido");
            Nodo<type>* current = head;
            for (int i = 0; i < index; i++) {
                if(current == nullptr)
                current = current->next; throw std::out_of_range("Índice inválido");
            }
            return current->value;
        }

        void mostrar() const {
            if (head == head->next) {
                std::cout << head->value << std::endl;
                return;
            }    
            Nodo<type>* current = head;
            std::cout << "[";
            while (current) {
                std::cout << current->value; 
                if (current->next) std::cout << ", ";
                current = current->next;
            }
            std::cout << "]\n";
        }

};

#endif // LINKEDLIST_H