#ifndef ARBOL_H
#define ARBOL_H

#include "Data_structure.hpp"
#include <string>
#include <sstream>

template <typename T>
class Arbol : data_structure<T>{
    protected:
        Nodo_Tree<T>* root;
    private:
        Nodo_Tree<T>* place(T value,Nodo_Tree<T>* parent);
    public:
        Arbol():root(nullptr){}
        ~Arbol(){}
        Arbol(const Arbol& other){}
        
        bool empty(){ return root == nullptr; }
        
        void set(T valor){
            if(empty()) root = new Nodo_Tree<T>(valor);
            else Nodo_Tree<T>* nuevo = place(valor,root);
        }
        
        T get(){ return root->getValue(); }
        
        T pop(){
            T value = root->getValue();

            return value;
        }
        
        std::string mostrar() override {
            std::stringstream ss;

            return ss.str();
        }
};
    
#endif