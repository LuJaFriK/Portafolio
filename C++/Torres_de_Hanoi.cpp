#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>


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
        
        int* get(){
            return Data;
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
            if(SP==-1) return -1; 
            return Data[SP--];
        }
};

class Torres{
    private:

        Pila* A;
        Pila* B;
        Pila* C;
        
        //Para obtener la torre segun el nombre
        Pila* getTorre(const char name){
            std::cout<< "Se ejecuta     ";
            if(name == 'A') {
                std::cout<< "Se ejecuta A     ";
                return this->A;
            }
            if(name == 'B') {
                std::cout<< "Se ejecuta B    ";
                return this->B;
            }
            if(name == 'C') {
                std::cout<< "Se ejecuta C     ";
                return this->C;
            }
            return nullptr;
        }
    
    public:

        Torres(int length){
            length-=1;
            A = new Pila(length);
            B = new Pila(length);
            C = new Pila(length);
            for(int i=length+1;i>0;i--) A->push(i);
        }

        void insert(const char sends, const char gets){
            //Inicializa las pilas
            Pila* sender = getTorre(sends);
            Pila* receptor = getTorre(gets);

            if((sender == nullptr) || (receptor==nullptr)) throw std::invalid_argument("Los caracteres no son validos.");

            if (sender->pull() < receptor->pull()){
                receptor->push(sender->pop());
            }
            else throw std::invalid_argument("No puedes colocar ese disco ahí.");
        }

        bool status(){
            //Si alguna de las pilas está llena retorna verdadero y termina el juego
            return (!B->full()||!C->full());
        }

        void print(){
            Pila arr[] = {*A,*B,*C};
            for(Pila torre : arr){
                while(true){
                    int disco = torre.pop();
                    if(disco==-1) break;
                    std::cout<<disco;
                }
                std::cout<<std::endl;
            }
        }
        
};

int menu(){
    int opcion;
    std::cout<<"Ingresa una opción: "<<std::endl;
    std::cout<<"1.-. Mover de una casilla a otra."<<std::endl;
    std::cout<<"0.-. Salir."<<std::endl;
    std::cin>>opcion;
    return opcion;
}


int main(){
    int cant;
    std::cout<<"¿Cuántos discos quieres en tu juego? "<<std::endl;
    std::cin>> cant;
    Torres* torres = new Torres(cant);
    while(torres->status()){
        torres->print();
        switch (menu()) {
            case 1:
                //mueve una ficha de un lugar a otro
                char torre1;
                char torre2;
                std::cout<<"Ingresa la torre que envia: (A,B,C)"<<std::endl;
                std::cin>> torre1;
                std::cout<<"Ingresa la torre que recibe: (A,B,C)"<<std::endl;
                std::cin>> torre2;
                torres->insert(torre1, torre2);
                break;
            case 0:
                return 0;
            default:
                std::cout<< "Opción no válida."<<std::endl;
                break;
        }
    }
    std::cout<< "Felicidades, haz terminado el juego."<<std::endl;
    return 0;
}