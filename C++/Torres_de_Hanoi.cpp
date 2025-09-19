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
            if(!empty()) return Data[SP]; 
            else return -1;
        }
        //ingresa un nuevo dato
        void push(const int dato){
            if (!full()){
                SP++;
                Data[SP] = dato;
            }else{
               throw std::out_of_range("Error: La pila está llena.");
            }
        }
        //Elimina y retorna un dato de la pila
        int pop(){
            if(!empty()){
                int deleted = Data[SP];
                SP--;
                return deleted;
            }else{
                throw std::out_of_range("Error: La pila está vacía.");
            }
        }
};

class Torres{
    private:

        Pila* A;
        Pila* B;
        Pila* C;
        
        //Para obtener la torre segun el nombre
        Pila* getTorre(const char name){
            if(name == 'A') return this->A;
            if(name == 'B') return this->B;
            if(name == 'C') return this->C;
            return nullptr;
        }
    
    public:

        Torres(){
            A = new Pila(4);
            B = new Pila(4);
            C = new Pila(4);
            for(int i=5;!A->full();i--) A->push(i);
        }

        void insert(const char sends, const char gets){
            //Inicializa las pilas
            Pila* sender = getTorre(sends);
            Pila* receptor = getTorre(gets);

            if((sender = nullptr) || (receptor==nullptr)) throw std::invalid_argument("Los caracteres no son validos.");

            if (sender->pull() < receptor->pull()){
                receptor->push(sender->pop());
            }
            else throw std::invalid_argument("No puedes colocar ese disco ahí.");
        }

        void print(){
            Pila* arr[] = {A,B,C};
            for(int i=0;i<3;i++){
                int* torre = arr[0]->get();
                std::cout << '|' << std::endl;
                std::cout << '|';
                for(int x=0;x<sizeof(torre);x++) std::cout << torre[x];  
                std::cout << '|' << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
            }
        }
        
};


int main(){
    return 0;
}