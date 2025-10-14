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

        static Nodo* order(Nodo* nodo,std::string nombre){
            
            if(nodo == nullptr) return new Nodo(nombre);

            if(nombre > nodo->value) nodo->front = order(nodo->front, nombre);

            return 

        }

    public:

        Lista():head(nullptr),back(nullptr){}

        void add(std::string name){

        }

        void get(int name)const{
            
        }

        void remove(std::string name){
            Nodo* del;


            delete del;
        }

};