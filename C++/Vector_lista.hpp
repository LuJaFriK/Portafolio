#ifndef VECTOR_LISTA_H
#define VECTOR_LISTA_H
#include "Data_structure.hpp"
#include <stdexcept>
#include <string>

template <typename T>
class Vector{
    private:
        Nodo_simple<T>* head = new Nodo_simple<T>();
        const int length;
    public:
        Vector(int size):length(size),head(nullptr){
            for(int i=0;i<size;i++) head = new Nodo_simple<T>(head);  
        }

        Vector(const Vector& other):head(nullptr),length(other.length){
            
            if(!other.head) return;

            head = new Nodo_simple<T>(other.head->getValue());
            
            Nodo_simple<T>* other_current = other.head->getNext();
            Nodo_simple<T>* current = head;

            while(other_current){
                //Asignar nueva memoria
                Nodo_simple<T>* nuevo = new Nodo_simple<T>(other_current->getValue());
                current->setNext(nuevo);
                //Avanzar apuntadores
                current = current->getNext();
                other_current = other_current->getNext();
            }
        }

        ~Vector(){
            while(head){
                Nodo_simple<T>* current = head;
                head = head->getNext();
                delete current;
            }
        }

        T get(int index){
            if(index<0 || index >= length) throw std::out_of_range("Indice fuera de rango");

            Nodo_simple<T>* current = head;
            for(int i=0;i<=index;i++) current = current->getNext();
            return current->getValue();
        }

        void set(int index,T value){
            if(index<0 || index >= length) throw std::out_of_range("Indice fuera de rango");
            
            Nodo_simple<T>* current = head;
            for(int i=0;i<index;i++) current = current->getNext();
            current->setValue(value);

        }

        int size()const{return length;}

        std::string to_string(){ return Nodo_to_string(head); }
};
#endif