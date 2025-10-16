#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <string>


template<typename type>
class Linked_circular_list {
    private:
        
        struct Nodo {
            type value;
            Nodo* next;
            Nodo* prev;
            Nodo(type v, Nodo* next = nullptr,Nodo* prev = nullptr) : value(v), next(next),prev(prev) {}
        };

    protected:
        
        Nodo* head;
        Nodo* back;

        static void link(Nodo*back,Nodo*front){
            if(back) back->next = front;
            if(front) front->prev = back;
        }


    public:
        
        Linked_circular_list() : head(nullptr),back(nullptr){
            head->prev = back;
            back->next = head;
        }

        ~Linked_circular_list() {
            Nodo* current = head;
            while (current) {
                Nodo* next = current->next;
                delete current;
                current = next;
            }
        }

        bool empty() const { return (head == nullptr); }

        void add(type value) {
            if(empty()){
                head = new Nodo(value);
                back = head;
            }else{
                Nodo* nuevo = new Nodo(value);
                link(nuevo, head);
                head = nuevo;
            }
        }

        type pop(int index) {
            if (empty()) throw std::out_of_range("Lista vacía");
            if (index < 0) throw std::out_of_range("Índice inválido");

            Nodo* deleted_node = head;

            for(int i=0;i<index;i++){
                if (deleted_node->next == head && i !=0) throw std::out_of_range("Índice fuera de rango");
                deleted_node = deleted_node->next;
            }

            type deleted_value = deleted_node->value;
            remove(deleted_node);
            return deleted_value;
        }

        void remove(Nodo*& deleted_node) {
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

        int search(type val) const {
            Nodo* current = head;
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
            Nodo* current = head;
            for (int i = 0; i < index; i++) {
                if(current == nullptr)
                current = current->next; throw std::out_of_range("Índice inválido");
            }
            return current->value;
        }

        void print() const {
            Nodo* current = head;
            std::cout << "[";
            while (current) {
                std::cout << current->value; 
                if (current->next) std::cout << ", ";
                current = current->next;
            }
            std::cout << "]\n";
        }

        std::string toString() const {
            std::string lista = "";
            Nodo* current = head;

            if (current == nullptr) {
                return "[]";
            }

            lista += "[";
            while (current != nullptr) {
                // Usamos std::to_string, asumiendo que 'type' es convertible a string (e.g., int, float).
                // Si 'type' es un tipo complejo, se necesitará una forma de convertirlo a string.
                lista.append(std::to_string(current->value)); 

                if (current->next != nullptr) {
                    lista += ", ";
                }
                current = current->next;
            }

            lista += "]";
            return lista;
        }

};

#endif // LINKEDLIST_H