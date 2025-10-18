#include <iostream>
#include <ostream>
#include <string>
#include "Nodo.hpp"

class Lista_alfabetica{
    private:
        
        Nodo<std::string>* head;

        static void link(Nodo<std::string>*back,Nodo<std::string>*front){
            if(back){
                back->next = front;
            }
            if(front){
                front->prev = back;
            }
        }

        bool empty() const { return head == nullptr; }

    public:

        Lista_alfabetica():head(nullptr){}

        ~Lista_alfabetica(){
            Nodo<std::string>* current = head;
            while(current!=nullptr){
                Nodo<std::string>* del = current;
                current = current->next;
                delete del;
            }
        }

        void add(std::string name){     
            Nodo<std::string>* nuevo = new Nodo(name);

            if(empty()){
                head = nuevo;
            } else if (name < head->value) {
                link(nuevo, head);
                head = nuevo;
            } else {
                Nodo<std::string>* current = head;
                while (current->next != nullptr && current->next->value < name) {
                    current = current->next;
                }
                link(nuevo, current->next);
                link(current, nuevo);
            }
        }

        void mod(std::string original,std::string correct){
            remove(original);
            add(correct);
        }

        std::string get(int index)const{
            if(index < 0) throw std::out_of_range("Índice inválido");
            
            Nodo<std::string>* nodo = head;
            for(int i = 0; i < index; i++){
                if(nodo == nullptr) throw std::out_of_range("Índice inválido");
                nodo = nodo->next;
            } 
            if(nodo == nullptr) throw std::out_of_range("Índice inválido");

            return nodo->value;
        }

        void remove(std::string name){
            if(empty()){
                return;
            }
            
            Nodo<std::string>* del = head;
            while(del != nullptr && del->value != name){
                del = del->next;
            }

            if (del == nullptr){
                std::cout << "No existe el elemento" << std::endl;
                return;
            }
            
            if (del == head) {
                head = del->next;
            }
            
            link(del->prev, del->next);
            
            delete del;
        }

        void mostrar(){
            Nodo<std::string>* nodo = head;
            while(nodo!=nullptr){
                std::cout << nodo->value << std::endl;
                nodo = nodo->next;
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
