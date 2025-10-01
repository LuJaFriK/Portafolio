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
        int counter;

        bool empty(){
            return (head == nullptr);
        }

    public:
        Cola():head(nullptr),back(nullptr),counter(0){}

        ~Cola(){
            while(!empty()) pop();
        }

        int size()const{
            return counter;
        }

        void add(var valor){
            Nodo* nuevo = new Nodo(valor);
            if(empty()){
                head = nuevo;
                back = nuevo;
            }else{
                back->next = nuevo;
                back = back->next;
            }
            counter++;
        }

        var pull()const{
            if(empty()) throw std::out_of_range("No hay elementos en la cola.");

            return head->valor;
        }

        var pop(){

            if(empty()) throw std::out_of_range("No hay elementos en la cola.");

            const var val = head->valor;
            Nodo*del = head;

            head = head->next;
            delete del;

            if(head==nullptr) back = nullptr;

            counter--;

            return val;

        }
};

void llenar(Cola<int>& cola){
    for(int i=0;i<235;i++) cola.add(i);
}

void imprimir(Cola<int>& cola){
    while(true){
        try{
            std::cout<<cola.pop()<<std::endl;
        }catch(std::out_of_range){
            return;
        }
    }
}

int main(){
    Cola<int> cola;
    llenar(cola);
    imprimir(cola);
    return 0;
}