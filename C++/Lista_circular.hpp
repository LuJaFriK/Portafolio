#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Data_structure.hpp"
#include <stdexcept>
#include <string>

template<typename T>
class Linked_circular_list : public data_structure<T> {
    protected:
        Nodo_doble<T>* head;
        Nodo_doble<T>* back; 
        
        void remove(Nodo_doble<T>*& deleted_node) {
            //Solo un nodo
            if (deleted_node == head && deleted_node == back) {
                head = nullptr;
                back = nullptr;
            }
            //El nodo a eliminar es la cabeza
            else if(deleted_node == head){

                head = deleted_node->getNext(); 
                this->link(back, head); // Enlaza la cola con la nueva cabeza

            }
            //El nodo a eliminar es la cola
            else if(deleted_node == back) {

                back = deleted_node->getPrev(); 
                this->link(back, head); // Enlaza la nueva cola con la cabeza
            }
            //Es cualquier nodo de enmedio
            else {

                this->link(deleted_node->getPrev(), deleted_node->getNext());
            }
            //Esta linea exacta es la que deja al siguiente como jugador principal
            head = deleted_node->getNext();
            delete deleted_node;
            
        }

        T pull()const{
            if (empty()) throw std::out_of_range("Lista vacía");
            return head->getValue();
        }


    public:
        Linked_circular_list() : head(nullptr), back(nullptr) { }

        virtual ~Linked_circular_list() override {
            if (empty()) return;
            
            back->setNext(nullptr); 

            Nodo_doble<T>* current = head;
            while (current) {
                Nodo_doble<T>* next = current->getNext(); 
                delete current;
                current = next;
            }
        }

        bool empty() const override { return (head == nullptr); }

        void add(const T& value) {
            
            Nodo_doble<T>* nuevo = new Nodo_doble<T>(value);
            
            if(empty()){
                head = nuevo;
                back = nuevo;
                this->link(head, head);
            }else{
                this->link(nuevo, head); 
                
                this->link(back, nuevo);

                head = nuevo;
            }
        }

        virtual T pop(const int& index) {
            if (empty()) throw std::out_of_range("Lista vacía");
            if (index < 0) throw std::out_of_range("Índice inválido");

            Nodo_doble<T>* deleted_node = head;
            for(int i=0; i < index; i++){
                deleted_node = deleted_node->getNext(); 
            }

            T deleted_value = deleted_node->getValue(); 
            remove(deleted_node);
            return deleted_value;
        }

        int search(const T& val) const {
            if(empty()) return -1;
            
            Nodo_doble<T>* current = head;
            int index = 0;

            do {
                if (current->getValue() == val) return index;
                current = current->getNext();
                index++;
            } while (current != head);
            
            return -1;
        }

        T get(const int& index) const {
            if (empty()) throw std::out_of_range("Lista vacía");
            if (index < 0) throw std::out_of_range("Índice inválido");

            Nodo_doble<T>* current = head;
            
            for (int i = 0; i < index; i++) {
                current = current->getNext(); 
                if (current == head)
                    throw std::out_of_range("Índice fuera de rango");
            }
            return current->getValue(); 
        }

        std::string mostrar() const override { return this->to_string(head); }

};

#endif // LINKEDLIST_H