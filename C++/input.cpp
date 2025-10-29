#include <iostream>

class Pila {
    private:
        int SP;
        int* Data;
        int capacity;

    public:
        Pila(int size): SP(-1), capacity(size){
            Data = new int[size];
        }

        ~Pila(){
            delete[] Data;
        }
        
        int get(){
            return *Data;
        }

        //retorna si la Pila está vacia
        bool empty()const{
            return (SP<0);
        }
        //retorna si la pila está llena
        bool full()const{
            return (SP==capacity-1);
        }

        //retorna el objeto en la cabecera
        int pull()const{
            return Data[SP]; 
        }
        //ingresa un nuevo dato
        void push(const int dato){
                Data[++SP] = dato;
        }
        //Elimina y retorna un dato de la pila
        int pop(){ 
            return Data[SP--];
        }
};

int main(){
    Pila* pila = new Pila(5);
    for(int i=0;i<5;i++) pila->push(i);
    for(int i=0;i<6;i++) std::cout<<pila->pop();
    
    return 0;
}
