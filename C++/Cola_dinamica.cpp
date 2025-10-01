#include <iostream>
#include <stdexcept>

template<typename var>
class Cola{
    private:
        struct Nodo{
            var valor;
            Nodo* next;
            Nodo(var val):valor(val),next(nullptr){}
        };

        Nodo* head;
        Nodo* back;

        bool empty(){
            return (head == nullptr);
        }

    public:
        Cola():head(nullptr),back(nullptr){}

        ~Cola(){
            while(!empty()) desencolar();
        }

        void mostrar(){
            Nodo* current = head;
            while(current!=nullptr){
                std::cout<<current->valor<<std::endl;

                current = current->next;
            }
        }

        void encolar(var valor){
            Nodo* nuevo = new Nodo(valor);
            if(empty()){
                head = nuevo;
                back = nuevo;
            }else{
                back->next = nuevo;
                back = back->next;
            }
        }

        var pull()const{
            if(empty()) throw std::out_of_range("No hay elementos en la cola.");

            return head->valor;
        }

        var desencolar(){

            if(empty()) throw std::out_of_range("No hay elementos en la cola.");

            const var val = head->valor;
            Nodo*del = head;

            head = head->next;
            delete del;

            if(head==nullptr) back = nullptr;

            return val;

        }
};

void llenar(Cola<int>& cola){
    for(int i=0;i<235;i++) cola.encolar(i);
}

int main(){
    Cola<int> cola;
    llenar(cola);
    cola.mostrar();
    return 0;
}