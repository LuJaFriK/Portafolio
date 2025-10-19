#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Asumo que tu archivo de nodos se llama "Nodo.hpp" como indicaste
#include "Nodo.hpp" 
#include <stdexcept>
#include <string>

template<typename type>
class Linked_circular_list {
    private:
        Nodo_doble<type>* head;
        Nodo_doble<type>* back; 
        
        void remove(Nodo_doble<type>*& deleted_node) {
            //Solo un nodo
            if (deleted_node == head && deleted_node == back) {
                head = nullptr;
                back = nullptr;
            }
            //El nodo a eliminar es la cabeza
            else if(deleted_node == head){

                head = deleted_node->getNext(); 
                link(back, head); // Enlaza la cola con la nueva cabeza

            }
            //El nodo a eliminar es la cola
            else if(deleted_node == back) {

                back = deleted_node->getPrev(); 
                link(back, head); // Enlaza la nueva cola con la cabeza
            }
            //Es cualquier nodo de enmedio
            else {

                link(deleted_node->getPrev(), deleted_node->getNext());
            }
            delete deleted_node;
        }


    public:
        Linked_circular_list() : head(nullptr), back(nullptr) { }

        virtual ~Linked_circular_list() {
            if (empty()) return;
            
            back->setNext(nullptr); 

            Nodo_doble<type>* current = head;
            while (current) {
                // FIX: Usar getter
                Nodo_doble<type>* next = current->getNext(); 
                delete current;
                current = next;
            }
        }

        bool empty() const { return (head == nullptr); }

        virtual void add(const type& value) {
            
            Nodo_doble<type>* nuevo = new Nodo_doble<type>(value);
            
            if(empty()){
                head = nuevo;
                back = nuevo;
                link(head, head);
            }else{
                link(nuevo, head); 
                
                link(back, nuevo);

                head = nuevo;
            }
        }
        
        type pull()const{
            if (empty()) throw std::out_of_range("Lista vacía");
            return head->getValue();
        }

        virtual type pop(const int& index) {
            if (empty()) throw std::out_of_range("Lista vacía");
            if (index < 0) throw std::out_of_range("Índice inválido");

            Nodo_doble<type>* deleted_node = head;
            for(int i=0; i < index; i++){
                deleted_node = deleted_node->getNext(); ;
            }

            type deleted_value = deleted_node->getValue(); 
            remove(deleted_node);
            return deleted_value;
        }

        int search(const type& val) const {
            if(empty()) return -1;
            
            Nodo_doble<type>* current = head;
            int index = 0;

            do {
                if (current->getValue() == val) return index;
                current = current->getNext();
                index++;
            } while (current != head);
            
            return -1;
        }

        type get(const int& index) const {
            if (empty()) throw std::out_of_range("Lista vacía");
            if (index < 0) throw std::out_of_range("Índice inválido");

            Nodo_doble<type>* current = head;
            
            for (int i = 0; i < index; i++) {
                current = current->getNext(); 
                if (current == head)
                    throw std::out_of_range("Índice fuera de rango");
            }
            return current->getValue(); 
        }

        std::string mostrar() const { return to_string(head); }

};

#endif // LINKEDLIST_H