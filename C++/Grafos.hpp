#ifndef GRAFOS_H
#define GRAFOS_H

#include <stdexcept>
#include <string>
#include <sstream>
#include "Diccionario.hpp"


template<typename T>
struct arista{
  T nodo;
  int costo;
  arista(T nodo,int costo):nodo(nodo),costo(costo){}
};

template<typename U, typename T>
class Nodo{
    private:
        T value;
        Diccionario<U, arista<Nodo*> > conexiones;
        
    public:
        const U address;
        Nodo(U address,T value)
        :address(address),value(value){conexiones();}
        virtual ~Nodo(){}
        
        void add_arista(Nodo* other,int costo){
            arista ar(other,costo);
            conexiones.set(other->address, ar);
        }
        
        void remove_arista(U address){
            conexiones.remove(address);
        }
        
        bool isConected(Nodo* nodo)const{
            try{
                conexiones.get(nodo->address);
            }catch(std::invalid_argument){
                return false;
            }
        }
        
        bool isConected(const U& address)const{
            try{
                conexiones.get(address);
            }catch(std::invalid_argument){
                return false;
            }
        }
        
        std::string to_string(){
            std::stringstream ss;
            ss << address;
            ss << " : ";
            ss << conexiones.mostrar();
        }
    
};


template<typename U,typename T>
class Grafo{
    private:
        Diccionario<U,Nodo<U,T>> nodos;
    public:
        Grafo(){nodos();}
    
        ~Grafo(){};
        
        void agregar_nodo(const U& address, const T& value){
            nodos.set(address, new Nodo<U,T>(address,value));
        }
        
        void agregar_arista(const U& address1, const U& address2, int costo, int direccion = 0){
            try{
                Nodo<U,T>* nodo1 = nodos.get(address1);
                Nodo<U,T>* nodo2 = nodos.get(address2);
                if(direccion!=2) nodo1->add_arista(nodo2,costo);
                if(direccion!=1) nodo2->add_arista(nodo1,costo);
            }catch(std::invalid_argument){
                return;
            }
        }
        
        void remove_arista(const U& address1, const U& address2, int direccion = 0){
            try{
                Nodo<U,T>* nodo1 = nodos.get(address1);
                Nodo<U,T>* nodo2 = nodos.get(address2);
                if(direccion!=2) nodo1->remove_arista(nodo2);
                if(direccion!=1) nodo2->remove_arista(nodo1);
                }catch(std::invalid_argument){
                return;
            }
        }
        
        void remove_nodo(const U& address){
            delete nodos.get(address);
            
            
        }
        
        

  
};
#endif