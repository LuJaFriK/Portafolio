#ifndef COLA_H
#define COLA_H

#include <stdexcept> 
#include "Data_structure.hpp"

template<typename T>
class Cola : public data_structure<T>{

protected:
    Nodo_simple<T>* head;
    Nodo_simple<T>* back;
    
public:

    Cola():head(nullptr),back(nullptr){}

    ~Cola() override{ while(!empty()) unqueue(); }

    bool empty() const override { 
        return (head == nullptr); 
    }

    void queue(T value){
        Nodo_simple<T>* nodo = new Nodo_simple<T>(value);
        if(empty()){
            head = nodo;
            back = nodo;
        }else{
            back->setNext(nodo);
            back = nodo;
        }
        
    }

    T front() const {
        if(empty()) throw std::out_of_range("The structure is empty.");
        else return head->getValue();
    }

    T unqueue(){
        if(empty()) throw std::out_of_range("The structure is empty.");
        Nodo_simple<T>* del = head;
        T val = del->getValue();

        head = head->getNext();
        if(empty()) back = nullptr;

        delete del;
        return val;
    }

    std::string mostrar() const override { return this->to_string(head); }

};

#endif // COLA_H