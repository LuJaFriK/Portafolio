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

        Torres(){
            A = new Pila(4);
            B = new Pila(4);
            C = new Pila(4);
            for(int i=5;i>0;i--) A->push(i);
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

        bool status(){
            //Si no hay discos en A ni C pero si en B o no hay en A ni B pero si en C
            if((A->pull()<0 && B->pull()> 0&& C->pull()<0) || (A->pull()<0 && B->pull()<0 && C->pull()>0)) return true;
            return false;
        }

        void print(){
            Pila* arr[] = {A,B,C};
            for(int i=0;i<3;i++){
                int* torre = arr[i]->get();
                std::cout << '|' << std::endl;
                std::cout << '|';
                for(int x=0;x<5;x++) std::cout << torre[x];  
                std::cout << '|' << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
            }
        }
        
};

int menu(){
    int opcion;
    std::cout<<"Ingresa una opción: "<<std::endl;
    std::cout<<"1.-. Mover de una casilla a otra."<<std::endl;
    std::cout<<"2.-. Verificar."<<std::endl;
    std::cout<<"0.-. Salir."<<std::endl;
    std::cin>>opcion;
    return opcion;
}


int main(){
    Torres* torres = new Torres();
    while(true){
        torres->print();
        switch (menu()) {
            case 1:
                //mueve una ficha de un lugar a otro
                char torre1=' ';
                char torre2=' ';
                std::cout<<"Ingresa la torre que envia: (A,B,C)"<<std::endl;
                std::cin>> torre1;
                std::cout<<"Ingresa la torre que recibe: (A,B,C)"<<std::endl;
                std::cin>> torre2;
                torres->insert(torre1, torre2);
                break;
            case 2:
                if(torres->status()) {
                    std::cout<< "Felicidades, haz terminado el juego."<<std::endl;
                }else std::cout<< "El juego aun no termina."<<std::endl;
                break;
            case 0:
                return 0;
            default:
                std::cout<< "Opción no válida."<<std::endl;
                break;
        }
    }
    return 0;
}