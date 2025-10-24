#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "Nodo.hpp"
#include <stdexcept>
#include <string>

template </*Referencia*/typename U,/*Dato interno*/typename T>
class Diccionario {
    private:

        Nodo_dict<U,T>* search(const U& name){
            if(head == nullptr) return nullptr;

            Nodo_dict<U,T>* current = head;
            do{
                if(current->address == name) return current;
                current = current->getNext();
            }while(current != head);

            return nullptr;
        }
        
    protected:
        Nodo_dict<U,T>* head;
        Nodo_dict<U,T>* back;
    public:
        Diccionario():head(nullptr),back(nullptr){}

        ~Diccionario(){}

        Diccionario(const Diccionario& other)
        :head(new Nodo_dict<U,T>(other.head->address,other.head->getValue())),back(nullptr){
            
            link(back,head);
            Nodo_dict<U,T>* other_current = other.head->getNext();
            Nodo_dict<U,T>* current = head->getNext();

            do{
                Nodo_dict<U,T>* nodo = new Nodo_dict<U,T>(other_current->address,other_current->getValue());
                link(current,nodo);

                current = current->getNext();
                other_current = other_current->getNext();
            }while(other_current != other.head);
            back = current;
        }
        
        bool empty(){ return head == nullptr; }

        void set(const U& name, const T& value){
            Nodo_dict<U,T>* to_set = search(name);
            if(to_set) {
                to_set->setValue(value);
            }else{
                Nodo_dict<U,T>* nuevo = new Nodo_dict<U,T>(name,value);
                nuevo->setValue(value);
                
                if(!head){
                    head = nuevo;
                    back = nuevo;
                }else{
                    link(back, nuevo);
                    back = nuevo;
                }
                link(back,head);
            }
        }

        T get(const U& name){
            //Buscar el nodo
            Nodo_dict<U,T>* nodo = search(name);
            //Retornar un valor válido
            if(nodo) return nodo->getValue();
            else throw std::invalid_argument("El nombre no existe.");
        }

        void remove(const U& name){
            Nodo_dict<U,T>* del = search(name);
            if(del){

                if(del == head && del == back) head = back = nullptr;
            
                else if(del == head) head = head->getNext();
                else if(del == back) back = back->getPrev();
                

                if(head) link(del->getPrev(),del->getNext());
                
                delete del;
            }
        }
        
        void clear(){
            Nodo_dict<U,T>* current = head;
            Nodo_dict<U,T>* next = nullptr;

            while(current){
                next = current->getNext();
                delete current;
                current = next;
            }
            head = back = nullptr;
        }

        std::string mostrar(){ return Nodo_to_string(head); }

};


#endif 