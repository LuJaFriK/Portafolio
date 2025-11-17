#ifndef GRAFOS_H
#define GRAFOS_H

#include <stdexcept>
#include <string>
#include <sstream>
#include "Data_structure.hpp"
#include "Diccionario.hpp"

template<typename U, typename T>
class Nodo_grafo{
    private:
        T value;
        Diccionario<U, arista<Nodo_grafo<U,T>*> > conexiones;
        
    public:
        const U address;
        Nodo_grafo(const U& address,const T& value)
        :address(address),value(value){conexiones();}
        virtual ~Nodo_grafo(){}
        
        void add_arista(Nodo_grafo<U,T>* other,int costo){
            arista ar(other,costo);
            conexiones.set(other->address, ar);
        }
        
        int get_arista(const U& address)const{
            try{
                return conexiones.get(address).costo;
            }catch(std::invalid_argument){
                return -1;
            }
        }
        
        T get_value()const{ return value; }
        
        void set_value(const T& value){ this->value = value; }
        
        void remove_arista(const U& address){
            conexiones.remove(address);
        }
        
        bool is_conected(const U& address)const{
            try{
                conexiones.get(address);
                return true;
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
class Grafo : public Diccionario<U,Nodo_grafo<U,T>>{
    public:
        Grafo():Diccionario<U,Nodo_grafo<U,T>>(){}
        
        Grafo(const Grafo& other)
        :Diccionario<U,Nodo_grafo<U,T>>(other){}
        
        void arista(const U& address1, const U& address2, int costo, int direccion = 0){
            try{
                Nodo_grafo<U,T> nodo1 = this->get(address1);
                Nodo_grafo<U,T> nodo2 = this->get(address2);
                if(direccion!=2) nodo1->add_arista(nodo2,costo);
                if(direccion!=1) nodo2->add_arista(nodo1,costo);
            }catch(std::invalid_argument){
                return;
            }
            
        }
        
        void arista(const U& address1, const U& address2){
            
        }
    
};

/* 
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
            Nodo<U, T> del = nodos.get(address);
        }
        
        int are_conected(const U& address1, const U& address2){
            int conections = 0;
            try{
                Nodo<U,T>* nodo1 = nodos.get(address1);
                Nodo<U,T>* nodo2 = nodos.get(address2);
                if(nodo1->is_conected(nodo2->address)) conections++;
                if(nodo2->is_conected(nodo1->address)) conections++;
            }catch(std::invalid_argument){
                return -1;
            }
        }
        
        

  
};*/
#endif