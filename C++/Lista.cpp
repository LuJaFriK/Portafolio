#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

class Lista_alfabetica{
    private:
        struct Nodo{
            std::string value;
            Nodo* front;
            Nodo* prev;
            Nodo(std::string nombre):value(nombre),front(nullptr),prev(nullptr){}
        };
        
        Nodo* head;

        static void link(Nodo*back,Nodo*front){
            if(back){
                back->front = front;
            }
            if(front){
                front->prev = back;
            }
        }

        bool empty()const { return head == nullptr; }

    public:

        Lista_alfabetica():head(nullptr){}

        ~Lista_alfabetica(){
            Nodo* current = head;
            while(current!=nullptr){
                Nodo* del = current;
                current = current->front;
                delete del;
            }
        }

        void add(std::string name){     
            Nodo* nuevo = new Nodo(name);

            if(empty()){
                head = nuevo;
            } else if (name < head->value) {
                link(nuevo, head);
                head = nuevo;
            } else {
                Nodo* current = head;
                while (current->front != nullptr && current->front->value < name) {
                    current = current->front;
                }
                link(nuevo, current->front);
                link(current, nuevo);
            }
        }

        void mod(std::string original,std::string correct){
            remove(original);
            add(correct);
        }

        std::string get(int index)const{
            if(index < 0) throw std::out_of_range("Índice inválido");
            
            Nodo* nodo = head;
            for(int i = 0; i < index; i++){
                if(nodo == nullptr) throw std::out_of_range("Índice inválido");
                nodo = nodo->front;
            } 
            if(nodo == nullptr) throw std::out_of_range("Índice inválido");

            return nodo->value;
        }

        void remove(std::string name){
            if(empty()){
                return;
            }
            
            Nodo* del = head;
            while(del != nullptr && del->value != name){
                del = del->front;
            }

            if (del == nullptr){
                std::cout << "No existe el elemento" << std::endl;
                return;
            }
            
            if (del == head) {
                head = del->front;
            }
            
            link(del->prev, del->front);
            
            delete del;
        }

        void mostrar(){
            Nodo* nodo = head;
            while(nodo!=nullptr){
                std::cout << nodo->value << std::endl;
                nodo = nodo->front;
            }
        }

};

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
    
    Lista_alfabetica lista{};

    while(true){
        switch (menu()) {
        case 1:
            {
            std::string name;
            std::cout << "Ingresa el nombre: "<<std::endl;
            std::cin >> name;
            lista.add(name);
            }
        break;
        case 2:
            lista.mostrar();
        break;
        case 3:
            {
            std::string name;
            std::cout << "Ingresa el nombre: "<<std::endl;
            std::cin >> name;
            lista.remove(name);
            }
        break;
        case 4:
        return 0;
    }
    }    
       
    return 0;
}
