#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Nodo.hpp"
#include <iostream>
#include <stdexcept>
#include <string>



template<typename type>
class Linked_double_list {
    private:
        Nodo_doble<type>* head;
        Nodo_doble<type>* back;
        
        void remove(Nodo_doble<type>*& deleted_node) {
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
        
        Linked_double_list() : head(nullptr),back(nullptr){
            head->prev = back;
            back->next = head;
        }

        virtual ~Linked_double_list() {
            Nodo_doble<type>* current = head;
            while (current) {
                Nodo_doble<type>* next = current->next;
                delete current;
                current = next;
            }
        }

        bool empty() const { return (head == nullptr); }

        virtual void add(const type& value) {
            if(empty()){
                head = new Nodo_doble<type>(value);
                back = head;
            }else{
                Nodo_doble<type>* nuevo = new Nodo_doble<type>(value);
                link(nuevo, head);
                head = nuevo;
            }
        }

        virtual type pop(const int& index) {
            //Validar vacios
            if (empty()) throw std::out_of_range("Lista vacía");
            if (index < 0) throw std::out_of_range("Índice inválido");

            Nodo_doble<type>* deleted_node = head;
            //Encontrar el nodo 
            for(int i=0;i<index;i++){
                if (deleted_node->next == head && i !=0) throw std::out_of_range("Índice fuera de rango");
                deleted_node = deleted_node->next;
            }

            type deleted_value = deleted_node->value;
            //Eliminar el puntero correctamente
            remove(deleted_node);
            return deleted_value;
        }

        int search(const type& val) const {
            Nodo_doble<type>* current = head;
            int index = 0;
            while (current) {
                if (current->value == val) return index;
                current = current->next;
                index++;
            }
            return -1;
        }

        type get(const int& index) const {
            if (index < 0) throw std::out_of_range("Índice inválido");
            Nodo_doble<type>* current = head;
            for (int i = 0; i < index; i++) {
                if(current == nullptr)
                current = current->next; throw std::out_of_range("Índice inválido");
            }
            return current->value;
        }

        void print() const {
            Nodo_doble<type>* current = head;
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