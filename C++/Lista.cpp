#include <iostream>
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

        static Nodo* link(Nodo*back,Nodo*front){
            back->front = front;
            front->prev = back;

            return back; 
        }

        bool empty()const { return head == nullptr; }

        Nodo* order(std::string nombre)const{
            Nodo* nodo = head;
            //Recorre la lista hasta encontrar el lugar del nuevo nodo
            while(nodo->value < nombre && nodo->front != nullptr){
                nodo = nodo->front;
            }
            return nodo;
        }

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
            }else if(name < head->value){
                head = link(nuevo,head);
            }else{
                Nodo* nodo = order(name);   
                //Obtener el nodo anterior
                Nodo* prev = nodo->prev;
                //Enlazar los nodos
                link(prev,nuevo);
                link(nuevo,nodo);
            }
        }

        void mod(std::string original,std::string correct){
            remove(original);
            add(correct);
        }

        std::string get(int index)const{
            //Validar indice invalido
            if(index < 0) throw std::out_of_range("Índice inválido");
            //Encontrar el nodo a retornar su valor
            Nodo* nodo = head;
            for(int i = 0; i < index; i++){
                //Validar indice fuera del alcance
                if(nodo == nullptr) throw std::out_of_range("Índice inválido");
                nodo = nodo->front;
            } 

            return nodo->value;
        }

        void remove(std::string name){
            //Encontrar el nodo a eliminar 
            Nodo* del = head;
            while(del->value != name){
                del = del->front;
            }
            //Actualizar enlaces
            if (del == head) head = del->front;
            else link(del->prev,del->front);
            
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


int main(){
    
    Lista_alfabetica lista{};

    lista.add("Luis");
    lista.add("Fredy");
    lista.add("osvaldo");
    lista.add("Agustimbre");
    lista.mostrar();
    std::cout << "" << std::endl;
    lista.mod("osvaldo","Osvaldo");
    lista.remove("Agustimbre");
    lista.mostrar();    
       
    return 0;
}