#ifndef COLA_H
#define COLA_H

#include <stdexcept> 
#include "Nodo.hpp"

template<typename T>
class Cola{
    protected:

        Nodo_doble<T>* head;
        Nodo_doble<T>* back;


    public:
        Cola():head(nullptr),back(nullptr){}

        virtual ~Cola(){
            while(!empty()) desencolar();
        }

        bool empty() const { return (head == nullptr); }

        virtual void encolar(T valor){
            Nodo_doble<T>* nuevo = new Nodo_doble<T>(valor);
            if(empty()){
                head = nuevo;
                back = nuevo;
            }else{
                link(back,nuevo);
                back = nuevo;
            }
        }

        T pull()const{
            if(empty()) throw std::out_of_range("No hay elementos en la cola.");

            return head->valor;
        }

        virtual T desencolar(){

            if(empty()) throw std::out_of_range("No hay elementos en la cola.");

            const T val = head->getValue();
            
            Nodo_doble<T>*del = head;
            head = head->getNext();
            delete del;

            if(head==nullptr) back = nullptr;

            return val;

        }

        std::string mostrar()const{ return Nodo_to_string(head); }
};

#endif // COLA_H