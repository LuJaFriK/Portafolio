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

        Nodo_doble<T>* parent_place(T value,Nodo_doble<T>* parent){

            if(parent->getValue() == value) return nullptr;
            //Recorre el arbol
            if(parent->getValue()>value && parent->getPrev()) return parent_place(value,parent->getPrev());
            if(parent->getValue()<value && parent->getNext()) return parent_place(value,parent->getNext());
            //En caso que no hay un hijo con el que comparar
            return parent;
        }

        Nodo_doble<T>* search(T value,Nodo_doble<T>* current){
            if(!current) return nullptr;
            if(current->getValue()==value) return current;

            if(current->getValue()>value) return search(value, current->getPrev());
            else return search(value, current->getNext());
        }

        int get_level(const T& value,Nodo_doble<T>* current,int nivel){
            if(!current) return -1;

            if(current->getValue()==value) return nivel;

            if(current->getValue()>value) return get_level(value, current->getPrev(),nivel+1);
            else return get_level(value, current->getNext(),nivel+1);
        }

        int get_grade(Nodo_doble<T>* current){
            int grade{0};
            if(current->getPrev()) grade++;
            if(current->getNext()) grade++;
            return grade;
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
        
        bool empty()const { return root == nullptr; }
        
        void add(T valor){
            if(empty()){
                root = new Nodo_doble<T>(valor);
                return;
            }
            Nodo_doble<T>* parent = parent_place(valor,root);
            if(parent){
                //Crear nodo
                Nodo_doble<T>* nuevo = new Nodo_doble<T>(valor);
                //Asignar segun valor
                if(parent->getValue()<valor) parent->setNext(nuevo);
                else parent->setPrev(nuevo);
            }

            
        }

        std::string buscar_valor(const int& value){
            Nodo_doble<T>* nodo = search(value,root);
            if(nodo){
                return "El grado del nodo es: " + std::to_string(get_grade(nodo))
                +" El nivel es:"+std::to_string(get_level(value,root, 0))+"."; 
            }else{
                return "No se encontró el nodo.";
            }
            
        }
        
        T get(){ return root->getValue(); }
        
        void remove(T value){
            

            
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