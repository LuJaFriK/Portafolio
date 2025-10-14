#include <string>
#include <iostream>
#include <stdexcept>

struct Bool{
    private:
        bool value;
    public:
        Bool(bool boolean):value(boolean){}
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

        //El metodo append enlaza doblemente dos nodos cualesquiera
        static void append(Nodo*& anterior, Nodo*& posterior){
            anterior->front = posterior;
            posterior->back = anterior;
        }
        
        bool restriccion(bool alternate, bool queue_or_unqueue) {
            // Si no hay restricciones o si la operación no es alternativa, es factible.
            if (entrada_or_salida == nullptr || !alternate) return true;

            //En caso de ser alternativa o restrictiva, la operacion es factible mientras el nodo entre por el lado distinto al restricto
            return queue_or_unqueue != entrada_or_salida->get();
        }

        Nodo* head;
        Nodo* back;
        Bool* entrada_or_salida;


    public:
        Bicola(bool entrada_or_salida):head(nullptr),back(nullptr),entrada_or_salida(new Bool(entrada_or_salida)){}

        Bicola():head(nullptr),back(nullptr),entrada_or_salida(nullptr){}

        ~Bicola(){
            while(!empty()) desencolar(false);

            delete entrada_or_salida;
        }

        bool empty() const {return (head == nullptr && back == nullptr);}

        void mostrar(){
            Nodo* current = head;
            while(current!=nullptr){
                std::cout<<current->valor<<std::endl;

                current = current->front;
            }
        }

        void encolar(var valor,bool alternate){
            Nodo* nuevo = new Nodo(valor);

            //Si es infactible entonces !false == true 
            if (!restriccion(alternate,true)) throw std::invalid_argument("La cola es restrictiva de entrada.");

            //Dado que es factible:

            if(empty()) {
                head = nuevo;
                back = nuevo;
                return;
            }

            if(alternate){//Si quiere encolar por arriba
                
                append(nuevo,head);
                head = nuevo;

            }else{//Si quiere encolar por abajo

                append(back,nuevo);
                back = nuevo;
            }
        }

        var pull(bool alternate)const{
            if(empty()) throw std::out_of_range("No hay elementos en la cola.");
            
            //Si es infactible entonces !false == true
            if(!restriccion(alternate,false)) throw std::invalid_argument("La cola es restrictiva de salida.");

            //Si quiere sacar de abajo
            if(alternate) return back->valor;
            //Si quiere sacar de arriba
            else return head->valor;
        }

        var desencolar(bool alternate){
            if(empty()) throw std::out_of_range("No hay elementos en la cola.");

            //Si es infactible entonces !false == true
            if (!restriccion(alternate,false)) throw std::invalid_argument("La cola es restrictiva de salida.");
            
            //Dado que es factible:

            Nodo* del;
            if (head == back) { // si solo queda un nodo
                del = head;
                head = nullptr;
                back = nullptr;
            }
            else if(alternate){
                //Asigna el nodo a eliminar
                del = back;
                //Retroceder de nodo
                back = back->back;
                //cortar el enlace
                if (back) back->front = nullptr;
           }else{
                //Asigna el nodo a eliminar
                del = head;
                //Avanzar de nodo
                head = head->front;
                //cortar el enlace
                if(head) head->back = nullptr;
           }
           //Asigna el valor a retornar
           var val = del->valor;
           //Elimina el nodo y retorna
           delete del;
           return val;

        }
};

//Retorna true si la acción se hace por arriba y false si es por abajo
bool arriba_o_abajo(){
    int opcion;
    std::cout<<"1. Por arriba."<<std::endl;
    std::cout<<"2. Por abajo."<<std::endl;
    std::cin>> opcion;
    return (opcion==1);
}

//Retorna el valor seleccionado del menu
int menu(){
    int opcion;
    std::cout<<"1. Ingresar un dato."<<std::endl;
    std::cout<<"2. Mostrar los datos en el largo."<<std::endl;
    std::cout<<"3. Eliminar un dato."<<std::endl;
    std::cout<<"4. Salir."<<std::endl;
    std::cin>> opcion;
    return opcion;
}

int main(){

    Bicola<std::string>* cola = nullptr; 
    int opcion;
    std::cout<<"1. Bicola normal."<<std::endl;
    std::cout<<"2. Bicola restrictiva de entrada."<<std::endl;
    std::cout<<"3. Bicola restrictiva de salida."<<std::endl;
    std::cout<<"Elige una opcion: ";
    std::cin>> opcion;

    switch (opcion) {
        case 1:
            cola = new Bicola<std::string>();
            break;
        case 2:
            cola = new Bicola<std::string>(true);
            break;
        case 3:
            cola = new Bicola<std::string>(false);
            break; 
        default:
            std::cout<<"Mal ahí mi hermano. Opción no válida."<<std::endl;
            return 0;
    }
    
    while(true){
        int opc = menu();
        if (opc == 1){
            try {

                std::string nombre;
                std::cout<<"Ingresa el dato: ";
                std::cin>> nombre;
                
                cola->encolar(nombre, arriba_o_abajo()); 

            } catch (const std::invalid_argument& e) {
                 std::cerr << "Error de restriccion: " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout<< "La cola esta llena (imposible con new)"<<std::endl;
            }
        }
        else if(opc == 2) cola->mostrar();

        else if (opc == 3){
            try {

                std::cout<<cola->desencolar(!arriba_o_abajo())<<" eliminado."<<std::endl;
                
            } catch (const std::invalid_argument& e) {
                 std::cerr << "Error de restriccion: " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout<< "La cola esta vacia"<<std::endl;
            }
        }else if(opc == 4) {
            delete cola; 
            return 0;
        }

        else std::cout<<"Error. opción no válida."<<std::endl;
    }
    return 0;
}