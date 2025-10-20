#include <iostream>
#include "InputUtils.hpp"
#include "Nodo.hpp"
#include <string>
template<typename T>
class Pila{
    private:
    
        Nodo_simple<T>* tope;
    public:

        Pila(){
            tope = nullptr;
        }
        ~Pila(){
            while(!empty()){
                pop();
            }
        }
        
        Pila(const Pila& otra){
            Nodo_simple<T>* otro = otra.tope;
            Nodo_simple<T>* nuevo = nullptr;
            while(otro != nullptr){
                nuevo = new Nodo_simple<T>(otro->valor,nuevo);
                otro = otro->anterior;
            }
            this->tope = nuevo;
        }

        void push(T valor){
            tope = new Nodo_simple<T>(valor,tope);
        }

        T pull(){
            if (empty()) throw std::runtime_error("Pila vacía"); 
            return tope->value;
        }

        T pop(){
            if (empty()) throw std::runtime_error("Pila vacía"); 
            Nodo_simple<T>* eliminar = tope;
            T val = eliminar->getValue();
            tope = tope->getNext();
            delete eliminar;
            return val;
        }

        bool empty()const{ return (tope == nullptr); }
        
        std::string to_string() const {
            return Nodo_to_string(tope);
        }

    
};

int main(){
    Pila<std::string> pila{};
    while (true) {
        switch(input<int>("1. Ingresar un dato.\n2. Mostrar los datos en el largo.\n3. Eliminar un dato.\n4. Salir.\n")){
            case 1:
                pila.push(input<std::string>("Ingrese un dato: "));
                break;
            case 2:
                
                break;
            case 3:
                try{
                    pila.pop();
                }catch(std::runtime_error& e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 4:
                return 0;
            default:
                std::cout << "Opción inválida." << std::endl;
                break;
        }
    }
    return 0;
}