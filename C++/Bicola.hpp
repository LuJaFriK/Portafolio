#include "Cola.hpp"
#include <stdexcept>
#include <string>

struct Bool{
    private:
        bool value;
    public:
        Bool(bool boolean):value(boolean){}
        bool get(){return value;}
};

template<typename T>
class Bicola : public Cola<T>{

    private:
        
        bool restriccion(bool alternate, bool queue_or_unqueue) {
            // Si no hay restricciones o si la operación no es alternativa, es factible.
            if (entrada_or_salida == nullptr || !alternate) return true;

            //En caso de ser alternativa o restrictiva, la operacion es factible mientras el nodo entre por el lado distinto al restricto
            return queue_or_unqueue != entrada_or_salida->get();
        }
        Bool* entrada_or_salida;


    public:
        Bicola(bool entrada_or_salida):Cola<T>(),entrada_or_salida(new Bool(entrada_or_salida)){}

        Bicola():Cola<T>(),entrada_or_salida(nullptr){}

        ~Bicola(){ delete entrada_or_salida; }

        bool empty() const {return (this->head == nullptr && this->back == nullptr);}

        void encolar(T valor,bool alternate){
            Nodo_doble<T>* nuevo = new Nodo_doble<T>(valor);

            //Si es infactible entonces !false == true 
            if (!restriccion(alternate,true)) throw std::invalid_argument("La cola es restrictiva de entrada.");

            //Dado que es factible:

            if(empty()) {
                this->head = nuevo;
                this->back = nuevo;
                return;
            }

            if(alternate){//Si quiere encolar por arriba
                
                link(nuevo,this->head);
                this->head = nuevo;

            }else{//Si quiere encolar por abajo

                link(this->back,nuevo);
                this->back = nuevo;
            }
        }

        T pull(bool alternate)const{
            if(empty()) throw std::out_of_range("No hay elementos en la cola.");
            
            //Si es infactible entonces !false == true
            if(!restriccion(alternate,false)) throw std::invalid_argument("La cola es restrictiva de salida.");

            //Si quiere sacar de abajo
            if(alternate) return this->back->valor;
            //Si quiere sacar de arriba
            else return this->head->valor;
        }

        T desencolar(bool alternate){
            if(empty()) throw std::out_of_range("No hay elementos en la cola.");

            //Si es infactible entonces !false == true
            if (!restriccion(alternate,false)) throw std::invalid_argument("La cola es restrictiva de salida.");
            
            //Dado que es factible:

            Nodo_doble<T>* del;
            if (this->head == this->back) { // si solo queda un nodo
                del = this->head;
                this->head = nullptr;
                this->back = nullptr;
            }
            else if(alternate){
                //Asigna el nodo a eliminar
                del = this->back;
                //Retroceder de nodo
                this->back = this->back->getPrev();
                //cortar el enlace
                if (this->back) this->back->setNext(nullptr);
           }else{
                //Asigna el nodo a eliminar
                del = this->head;
                //Avanzar de nodo
                this->head = this->head->getNext();
                //cortar el enlace
                if(this->head) this->head->setPrev(nullptr);
           }
           //Asigna el valor a retornar
           T val = del->getValue();
           //Elimina el nodo y retorna
           delete del;
           return val;

        }

        std::string mostrar()const{ return Nodo_to_string(this->head); }
};