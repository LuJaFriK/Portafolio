#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.hpp"
#include <string>
#include <sstream>

template <typename T>
class Arbol{
    protected:
        Nodo_doble<T>* root;
    private:
    public:
        Arbol():root(nullptr){}
        ~Arbol(){}
        Arbol(const Arbol& other){}
        
        bool empty(){ return root == nullptr; }
        
        void insertar(T valor){
            if(empty()) root = new Nodo_doble<T>(valor);
            
        }
        
        T obtenerRaiz(){ return root->valor; }
        
        std::string mostrar(){
            std::stringstream ss;

            return ss.str();
        }
};
    
#endif