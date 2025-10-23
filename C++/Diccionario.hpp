#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "Nodo.hpp"
#include <stdexcept>
#include <string>

template <typename T>
class Diccionario {
    private:

        Nodo_dict<T>* search(std::string& name)const{
            if(head == nullptr) return nullptr;

            Nodo_dict<T>* current = head;
            do{
                if(current->address == name) return current;
                current = current->getNext();
            }while(current != head);

            return nullptr;
        }
        
    protected:
        Nodo_dict<T>* head;
        Nodo_dict<T>* back;
    public:
        Diccionario():head(nullptr),back(nullptr){}

        ~Diccionario(){}

        Diccionario(const Diccionario& other)
        :head(new Nodo_dict<T>(other.head->getValue())),back(new Nodo_dict<T>(other.back->getValue())){
            
            link(back,head);
            Nodo_dict<T>* other_current = other.head->getNext();
            Nodo_dict<T>* current = head->getNext();

            do{
                Nodo_dict<T>* nodo = new Nodo_dict<T>(other_current->getValue());
                link(current,nodo);

                current = current->getNext();
                other_current = other_current->getNext();
    //falta ver que pedo con el back papu
            }while(other_current != other.head);
        }

        void add(std::string& name,T& value){
            Nodo_dict<T>* nuevo = new Nodo_dict<T>(name);
            nuevo->setValue(value);
            if(!head){
                head = nuevo;
                back = nuevo;
                link(head,back);
            }else{
                link(nuevo, head); 
                link(back, nuevo);
                head = nuevo;
            }
        }

        void set(const std::string& name,T& value){
            Nodo_dict<T>* to_set = search(name);
            if(to_set) to_set->setValue(value);
        }

        T get(const std::string& name)const{
            //Buscar el nodo
            Nodo_dict<T>* nodo = search(name);
            //Retornar un valor válido
            if(nodo) return nodo->getValue();
            else throw std::invalid_argument("El nombre no existe.");
        }

        void remove(const std::string& name){
            Nodo_dict<T>* del = search(name);
            if(del){

                if(del == head && del == back) head = back = nullptr;
            
                else if(del == head) head = head->getNext();
                else if(del == back) back = back->getPrev();
                

                if(head) link(del->getPrev(),del->getNext());
                
                delete del;
            }
        }

        std::string mostrar(){return Nodo_to_string(head);}

};


#endif 