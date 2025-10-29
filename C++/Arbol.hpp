#ifndef ARBOL_H
#define ARBOL_H

#include "Data_structure.hpp"
#include <string>
#include <sstream>

template <typename T>
class Arbol {
    protected:
        Nodo_doble<T>* root;
    private:

        Nodo_doble<T>* place(T value,Nodo_doble<T>* parent){
            //Si el valor ya esta en el arbol no se pone nada
            if(parent->getValue() == value) return nullptr;
            //Si el valor es menor, lo mandamos a la izquierda
            if(parent->getValue()>value && parent->getPrev()) return place(value,parent->getPrev());
            //Si el valor es mayor, lo mandamos a la derecha
            if(parent->getValue()<value && parent->getNext()) return place(value,parent->getNext());
            //En caso que no hay un hijo con el que comparar
            return parent;
        }

        void concatenate_inorden(std::stringstream& ss,Nodo_doble<T>* current){
            if(current->getPrev()) concatenate_postorden(ss, current->getPrev());
            ss << current->to_string()<<' '; 
            if(current->getPrev()){
                concatenate_postorden(ss, current->getPrev());
            }
        }

        void concatenate_postorden(std::stringstream& ss,Nodo_doble<T>* current){
            if(!current) return;

            concatenate(ss,current->getPrev());

            concatenate(ss,current->getNext());

            ss<<current->to_string()<<' ';
        }

    public:
        Arbol():root(nullptr){}
        ~Arbol(){}
        Arbol(const Arbol& other){}
        
        bool empty(){ return root == nullptr; }
        
        void set(T valor){
            if(empty()){
                root = new Nodo_doble<T>(valor);
                return;
            }
            Nodo_doble<T>* parent = place(valor,root);
            if(parent){
                //Crear nodo
                Nodo_doble<T>* nuevo = new Nodo_doble<T>(valor);
                //Asignar segun valor
                if(parent->getValue()<valor) parent->setNext(nuevo);
                else parent->setPrev(nuevo);
            }

            
        }
        
        T get(){ return root->getValue(); }
        
        T pop(){
            T value = root->getValue();

            return value;
        }
        
        std::string mostrar() {
            std::stringstream ss;
            ss<<'[';
            concatenate(ss, root);
            ss<<']';
            return ss.str();
        }
};
    
#endif