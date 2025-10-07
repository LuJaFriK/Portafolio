#include <string>
#include <iostream>
#include <stdexcept>

struct Bool{
    private:
        bool value;
    public:
        Bool(bool boolean):value(boolean){}
        bool equals(bool& boolean){return (value==boolean);}
        bool get(){return value;}
};

template<typename var>
class Bicola {

    private:

        struct Nodo{
            var valor;
            Nodo* back;
            Nodo* front;
            Nodo(var val):valor(val),back(nullptr),front(nullptr){}
        };

        Nodo* head;
        Nodo* back;
        Bool* entrada_or_salida;

        static void append(Nodo*& anterior, Nodo*& posterior){
            anterior->front = posterior;
            posterior->back = anterior;
        }


    public:
        Bicola(bool entrada_or_salida):head(nullptr),back(nullptr),entrada_or_salida(new Bool(entrada_or_salida)){}

        Bicola():head(nullptr),back(nullptr),entrada_or_salida(nullptr){}

        ~Bicola(){
            while(!empty()) desencolar(false);
        }

        bool empty() const {
            return (head == nullptr);
        }

        void mostrar(){
            Nodo* current = head;
            while(current!=nullptr){
                std::cout<<current->valor<<std::endl;

                current = current->front;
            }
        }

        void encolar(bool alternate, var valor){
            Nodo* nuevo = new Nodo(valor);

            if(empty()) {
                head = nuevo;
                back = nuevo;
                return;
            }

            if(alternate && !restrict_entrada_or_salida){
                append(back,nuevo);
                back = nuevo;
            }else{
                append(nuevo,head);
                head = nuevo;
            }
        }

        var pull()const{
            if(empty()) throw std::out_of_range("No hay elementos en la cola.");

            return head->valor;
        }

        var desencolar(bool alternate){
           if(empty()) throw std::out_of_range("No hay elementos en la cola.");
           Nodo* del;
            if(alternate && !restrict_entrada_or_salida){
                del = back;
                back = back->back;
           }else{
                del = head;
                head = head->front;
           }

           const var val = del->valor;
           delete del;

           return val;

        }
};

int menu(){
    int opcion;
    std::cout<<"1. Ingresar un dato."<<std::endl;
    std::cout<<"2. Mostrar los datos en el largo."<<std::endl;
    std::cout<<"3. Eliminar un dato."<<std::endl;
    std::cout<<"4. ."<<std::endl;
    std::cin>> opcion;
    return opcion;

}

int main(){
    Bicola<std::string> cola(true);
    while(true){
        int opc = menu();
        if (opc == 1){
            try {
                std::string nombre;
                std::cout<<"Ingresa el dato: ";
                std::cin>> nombre;
                cola.encolar(nombre);
            } catch (std::out_of_range) {
                std::cout<< "La cola esta llena"<<std::endl;
            }
        }
        else if(opc == 2) cola.mostrar();
        else if (opc == 3){
            try {
                std::cout<<cola.desencolar( )<<" eliminado."<<std::endl;
            } catch (std::out_of_range) {
                std::cout<< "La cola esta vacia"<<std::endl;
            }
        }else if(opc == 4) return 0;
        else{
            std::cout<<"Error. opción no válida."<<std::endl;
        }

        
    }
    return 0;
}