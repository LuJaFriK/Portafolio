#include <iostream>

class Pila{
    private:
    
    struct Nodo{
        
        int valor;
        Nodo* anterior;
        
        Nodo(int valor,Nodo* anterior){
            this->valor = valor;
            this->anterior = anterior;
        }
    };
        Nodo* tope;
    public:

        Pila(){
            tope = nullptr;
        }

        void push(int valor){
            tope = new Nodo(valor,tope);
        }

        int pull(){
            return tope->valor;
        }

        int pop(){
            Nodo* eliminar = tope;
            int val = eliminar->valor;
            tope = tope->anterior;
            delete eliminar;
            return val;
        }

        bool empty(){
            return (tope == nullptr);
        }

    
};



int main(){

    Pila* pila = new Pila();

    for (int i=0;i<67;i++) pila->push(i);

    for (int i=0;i<67;i++) std::cout<<pila->pop()<<std::endl;





    return 0;
}