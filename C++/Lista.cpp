#include <iostream>
#include <string>

class Lista{
    private:
        struct Nodo{
            std::string value;
            Nodo* front;
            Nodo* prev;
            Nodo(std::string nombre):value(nombre),front(nullptr),prev(nullptr){}
        };
        
        Nodo* head;
        Nodo* back;

        static Nodo* link(Nodo*back,Nodo*front,bool which){
            back->front = front;
            front->prev = back;

            if(which) return front;
            return back; 
        }

        bool empty()const{return head == nullptr;}

        Nodo* order(std::string nombre){
            //Valida primero las puntas de la lista para evitar validaciones extras
            if(empty()) return nullptr;
            if(head->value < nombre) return head;
            if(back->value > nombre) return back;
            
            Nodo* nodo = head;
            //Recorre la lista hasta encontrar el lugar del nuevo nodo
            while(nodo->value < nombre && nodo->front != nullptr){
                nodo = nodo->front;
            }
            return nodo;
        }
    public:

        Lista():head(nullptr),back(nullptr){}

        void add(std::string name){
            //Encontrar el lugar del nuevo nodo
            Nodo* nodo = order(name);
            //Si el lugar es nullptr, entonces el nuevo nodo es la cabeza y/o la cola
            if(nodo == nullptr){
                nodo = new Nodo(name);
                head = nodo;
                back = nodo;
            }else{
                //Obtener los nodos adyacentes
                Nodo* front = nodo->front;
                Nodo* prev = nodo->prev;
                //Crear el nuevo nodo
                Nodo* nuevo = new Nodo(name);
                //Enlazar los nodos
                link(prev,nuevo,false);
                link(nuevo,front,true);
                //Actualizar las puntas de la lista
                if (prev == nullptr) head = nuevo;
                if (front == nullptr) back = nuevo;
            }
        }

        std::string get(int index)const{
            if(index < 0 || empty()) throw std::out_of_range("Índice inválido");
            Nodo* nodo = head;
            for(int i = 0; i < index; i++) nodo = nodo->front;

            if(nodo == nullptr) throw std::out_of_range("Índice inválido");

            return nodo->value;
        }

        void remove(std::string name){
            Nodo* del = head;
            while(del->value != name){
                del = del->front;
            }
            link(del->prev,del->front,true);
            if (del == head) head = del->front;
            if (del == back) back = del->prev;
            delete del;
        }

};