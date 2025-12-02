#ifndef PILADINAMICA_H
#define PILADINAMICA_H

#include "Data_structure.hpp"
#include <string>
template<typename T>
class Pila : data_structure<T>{
    protected:
        Nodo_simple<T>* tope;
    public:

        Pila(){
            tope = nullptr;
        }
        ~Pila()override{
            while(!empty()){
                pop();
            }
        }
        
        Pila(const Pila& otra){
            Nodo_simple<T>* otro = otra.tope;
            Nodo_simple<T>* nuevo = nullptr;
            while(otro != nullptr){
                nuevo = new Nodo_simple<T>(otro->valor,nuevo);
                otro = otro->anterior;
            }
            this->tope = nuevo;
        }

        void push(T valor){
            tope = new Nodo_simple<T>(valor,tope);
        }

        T pull(){
            if (empty()) throw std::runtime_error("Pila vacía"); 
            return tope->value;
        }

        T pop(){
            if (empty()) throw std::runtime_error("Pila vacía"); 
            Nodo_simple<T>* eliminar = tope;
            T val = eliminar->getValue();
            tope = tope->getNext();
            delete eliminar;
            return val;
        }

        bool empty()const override{ return (tope == nullptr); }
        
        std::string mostrar() const override {
            return this->to_string(tope);
        }

    
};

#endif