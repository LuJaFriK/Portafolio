#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "Nodo.hpp"
#include <stdexcept>
#include <string>

template </*Referencia*/typename U,/*Dato interno*/typename T>
class Diccionario {
    private:

        Nodo_dict<U,T>* search(const U& name){
            //Si la lista está vacía, no hay nada que buscar
            if(head == nullptr) return nullptr;
            //Buscar en la lista
            Nodo_dict<U,T>* current = head;
            do{
                if(current->address == name) return current;
                current = current->getNext();
            }while(current != head);
            //Si no encontra nada, devuelve nullptr
            return nullptr;
        }
        
    protected:
        //Punteros
        Nodo_dict<U,T>* head;
        Nodo_dict<U,T>* back;
    public:
        Diccionario():head(nullptr),back(nullptr){}
        
        //Destructor virtual por si se atora una herencia
        virtual ~Diccionario(){ clear(); }
        
        //Constructor de copia
        Diccionario(const Diccionario& other)
        :head(new Nodo_dict<U,T>(other.head->address,other.head->getValue())),back(nullptr){
            //Enlazar punteros
            link(back,head);
            Nodo_dict<U,T>* other_current = other.head->getNext();
            Nodo_dict<U,T>* current = head->getNext();

            do{
                //Asignar memoria y enlazar
                Nodo_dict<U,T>* nodo = new Nodo_dict<U,T>(other_current->address,other_current->getValue());
                link(current,nodo);
                //Avanzar punteros
                current = current->getNext();
                other_current = other_current->getNext();
            
            //El ciclo termina antes de llegar al inicio
            }while(other_current != other.head);
            //Apuntar back al último nodo
            back = current;
        }
        
        bool empty()const{ return head == nullptr; }

        void set(const U& name, const T& value){
            Nodo_dict<U,T>* to_set = search(name);
            //Caso existente
            if(to_set) {
                to_set->setValue(value);
            //Caso no existente
            }else{
                Nodo_dict<U,T>* nuevo = new Nodo_dict<U,T>(name,value);
                nuevo->setValue(value);
                //Caso vacío
                if(!head){
                    head = nuevo;
                    back = nuevo;
                //Caso encolar
                }else{
                    link(back, nuevo);
                    back = nuevo;
                }
                //De cualquier modo, enlazar el nuevo nodo con el primero
                link(back,head);
            }
        }

        T get(const U& name)const{
            //Buscar el nodo
            Nodo_dict<U,T>* nodo = search(name);
            //Retornar un valor válido
            if(nodo) return nodo->getValue();
            else throw std::invalid_argument("El nombre no existe.");
        }

        void remove(const U& name){
            //Buscar el nodo
            Nodo_dict<U,T>* del = search(name);
            //Si el nodo existe
            if(del){
                //Caso eliminar el único elemento
                if(del == head && del == back) head = back = nullptr;
                //Caso eliminar el primer o último elemento
                else if(del == head) head = head->getNext();
                else if(del == back) back = back->getPrev();
                
                //Caso nodo intermedio
                if(head) link(del->getPrev(),del->getNext());
                //Finalmente, eliminar el nodo
                delete del;
            }
        }
        //Limpiar el diccionario
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
        //Mostrar el diccionario
        std::string mostrar(){ return Nodo_to_string(head); }

};


#endif 