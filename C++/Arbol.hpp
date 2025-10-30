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

            if(parent->getValue() == value) return nullptr;
            //Recorre el arbol
            if(parent->getValue()>value && parent->getPrev()) return place(value,parent->getPrev());
            if(parent->getValue()<value && parent->getNext()) return place(value,parent->getNext());
            //En caso que no hay un hijo con el que comparar
            return parent;
        }

        void concatenate_preorden(std::stringstream& ss, Nodo_doble<T>* current) {
            if (!current) return;

            ss << current->to_string() << "\n";
            concatenate_preorden(ss, current->getPrev());
            concatenate_preorden(ss, current->getNext());
        }

        void concatenate_inorden(std::stringstream& ss, Nodo_doble<T>* current) {
            if (!current) return;

            concatenate_inorden(ss, current->getPrev());
            ss << current->to_string() << "\n";
            concatenate_inorden(ss, current->getNext());
        }

        void concatenate_postorden(std::stringstream& ss, Nodo_doble<T>* current) {
            if (!current) return;

            concatenate_postorden(ss, current->getPrev());
            concatenate_postorden(ss, current->getNext());
            ss << current->to_string() << "\n";
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
        
        std::string mostrar(int option) {
            std::stringstream ss;

            switch(option){
                case 1: concatenate_preorden(ss,root); break;

                case 2: concatenate_inorden(ss, root); break;

                case 3: concatenate_postorden(ss, root); break;

                default: concatenate_inorden(ss, root); break;
            }
            return ss.str();
        }
};
    
#endif