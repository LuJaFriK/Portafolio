#include <iostream>
template<typename var>
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

int menu(){
    int opcion;
    std::cout<<"1. Ingresar un dato."<<std::endl;
    std::cout<<"2. Mostrar los datos en el largo."<<std::endl;
    std::cout<<"3. Eliminar un dato."<<std::endl;
    std::cin>> opcion;
    return opcion;

}

int main(){
    int len;
    std::cout<<"Ingresa el largo de la cola."<<std::endl;
    std::cin>> len;
     





    return 0;
}