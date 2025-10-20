#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Nodo.hpp"
#include <stdexcept>
#include <string>



template<typename T>
class Linked_list {
    private:
        Nodo_simple<T>* head;
    public:
        
        Linked_list() : head(nullptr){}

        virtual ~Linked_list() {
            Nodo_simple<T>* current = head;
            while (current) {
                Nodo_simple<T>* next = current->next;
                delete current;
                current = next;
            }
        }
        
        Linked_list(const Linked_list& other) : head(nullptr) {
            Nodo_simple<T>* current = other.head;
            while (current) {
                add(current->value);
                current = current->next;
            }
        }

        bool empty() const { return (head == nullptr); }

        virtual void add(const T& value) {
            head = new Nodo_simple<T>(value,head);
        }

        virtual T pop(const int& index) {
            //Validar vacios
            if (empty()) throw std::out_of_range("Lista vacía");
            if (index < 0) throw std::out_of_range("Índice inválido");

            Nodo_simple<T>* deleted_node = head;
            //Encontrar el nodo 
            for(int i=0;i<index;i++){
                if (deleted_node->next == head && i !=0) throw std::out_of_range("Índice fuera de rango");
                deleted_node = deleted_node->next;
            }

            T deleted_value = deleted_node->value;
            //Eliminar el puntero correctamente
            remove(deleted_node);
            return deleted_value;
        }

        int search(const T& val) const {
            Nodo_simple<T>* current = head;
            int index = 0;
            while (current) {
                if (current->value == val) return index;
                current = current->next;
                index++;
            }
            return -1;
        }

        T get(const int& index) const {
            if (index < 0) throw std::out_of_range("Índice inválido");
            Nodo_simple<T>* current = head;
            for (int i = 0; i < index; i++) {
                if(current == nullptr)
                current = current->next; throw std::out_of_range("Índice inválido");
            }
            return current->value;
        }

        std::string mostrar() const{
            return Nodo_to_string(head);
        }

};

#endif // LINKEDLIST_H