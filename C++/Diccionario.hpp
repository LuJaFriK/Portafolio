#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "Data_structure.hpp"
#include <stdexcept>
#include <string>

template <typename U,typename T>
class Diccionario : public data_structure<T>{
    private:

        Nodo_dict<U,T>* search(const U& name)const{
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
        virtual ~Diccionario() override { clear(); }
        
        //Constructor de copia
        Diccionario(const Diccionario& other)
        :head(new Nodo_dict<U,T>(other.head->address,other.head->getValue())),back(nullptr){
            //Enlazar punteros
            this->link(back,head);
            Nodo_dict<U,T>* other_current = other.head->getNext();
            Nodo_dict<U,T>* current = head->getNext();

            do{
                //Asignar memoria y enlazar
                Nodo_dict<U,T>* nodo = new Nodo_dict<U,T>(other_current->address,other_current->getValue());
                this->link(current,nodo);
                //Avanzar punteros
                current = current->getNext();
                other_current = other_current->getNext();
            
            //El ciclo termina antes de llegar al inicio
            }while(other_current != other.head);
            //Apuntar back al último nodo
            back = current;
        }
        
        bool empty()const override { return head == nullptr; }

        void set(const U& name, const T& value){
            Nodo_dict<U,T>* nodo = search(name);
            //Caso existente
            if(nodo) {
                nodo->setValue(value);
            //Caso no existente
            }else{
                nodo = new Nodo_dict<U,T>(name,value);
                //Caso vacío
                if(!head){
                    head = nodo;
                    back = nodo;
                //Caso encolar
                }else{
                    this->link(back, nodo);
                    back = nodo;
                }
                //De cualquier modo, enlazar el nuevo nodo con el primero
                this->link(back,head);
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
                if(head) this->link(del->getPrev(),del->getNext());
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
        std::string mostrar() const override { 
            if (!head) return "{}"; 

            std::stringstream ss;
            ss << '{';
            Nodo_dict<U,T>* current = head;
            
            do {
                ss << current->to_string(); 
                current = current->getNext();
                if (current != head && current!=nullptr) ss << ", "; 

            } while (current != head && current!=nullptr); 
            
            ss << '}';
            return ss.str();
        }

};


#endif 