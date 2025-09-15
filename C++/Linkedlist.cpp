#include <iostream>
#include <string>
#include <random>

template <typename var>
//var representa la clase del valor
class Linkedlist{
    private:

    struct Nodo{
        var value; //valor de cualquier tipo
        Nodo* next; //Nodo siguiente  
    };

    //Instancia cabecera de la clase nodo, el unico que necesita la lista
    Nodo* head;
    // largo de la lista
    int length;
    //Verifica si la lista esta vacia
    bool empty(){
        return !(length>0);
    }
    //Genera un numero aleatorio
    int randomval() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);
    return dis(gen);
    }

    public:
    //Constructor
        Linkedlist(){
            head = nullptr;
            length = 0;
        }
    //Destructor
        ~Linkedlist(){
            Nodo* current;
            //ciclo que reinicia la cuenta hasta eliminar todos los nodos
            while(head!=nullptr){
                current = head;
                //ciclo anidado que recorre la lista
                while (current!=nullptr) {
                    current = current->next;
                }
                delete current;
            }
        }

        int size() const{
            return length;
        }

        void random_linked_list(const int& length){
            //Ciclo que crea todos los nodos solicitados
            for (int i=0;i<length;i++) {
                //Inicializa un nuevo nodo
                Nodo* nodo = new Nodo();
                //Asigna un valor aleatorio
                nodo->value = randomval();
                //Asigna el nuevo nodo como la actual cabecera
                nodo->next = head;
                //Redirecciona el puntero de la cabecera a la nueva cabecera
                head = nodo;
            }
        }
        
        void add(const var& value){
            //Crea un nodo nuevo
            Nodo* new_head = new Nodo();
            //Agrega los valores correspondienes
            new_head->value = value;
            new_head->next = head;
            //Asigna la nueva cabecera
            head = new_head;
            //Actualiza el largo de la lista
            length++;
        }

        var pop(const int& index){
            //Valida si la lista está vacía
            if (empty()) throw std::out_of_range("Error: La lista está vacía.");
            //Valida si el índice está fuera el alcance
            if (!(index<length)) throw std::out_of_range("Error: El indice esta fuera de los limites.");
            //Valor a retornar
            var deleted_value;
            //Punteros
            Nodo* current = head;
            Nodo* deleted_node;
            //Si el indice es 0
            if(index==0){
                //Apunta el nodo a eliminar
                deleted_node = head;
                //Cambia la cabecera
                head = head->next;
                //Encuentra el valor de retorno
                deleted_value = head->value;
                //Elimina el nodo
                delete deleted_node;
                //retorna el valor eliminado
                return deleted_value;
            }
            //Ciclo que nos deja en un nodo antes del que se eliminara
            for(int i=0;i<index-1;i++) current = current->next;
            //Obtiene el valor a retornar
            deleted_value = current->next->value;
            //Selecciona el nodo a eliminar
            deleted_node = current->next;
            //enlaza los nodos remanentes
            current = current->next->next;
            //elimina el nodo 
            delete deleted_node;
            //actualiza el largo de la lista
            length--;
            //retorna el valor solicitado
            return deleted_value;
        }

        void remove(const var& val){
            //Valida que la lista no esté vacia
            if (empty()) throw std::out_of_range("Error: La lista está vacía.");
            //Crea los apuntadores
            Nodo* deleted_node;
            Nodo* current;
            //Si el valor se encuentra en la cabecera
            if (head->value == val){
                //nodo a eliminar apunta a la cabeza
                deleted_node = head;
                //cambia la cabecera
                head = head->next;
                //elimina el nodo sobrante
                delete deleted_node;
                return;
            }
            //Ciclo que encuentra el nodo a eliminar
            while (current->next!=nullptr) {
                //Si el nodo siguente al actual es el que estoy buscando, continuo el proceso
                if(current->next->value == val){
                    //Apunto al nodo a eliminar
                    deleted_node = current->next;
                    //Enlazo los nodos restantes
                    current->next = current->next->next;
                    //elimino el nodo
                    delete deleted_node;
                    return;
                }
                //Si la condición no se cumple, continua buscando
                current = current->next;
            }
        }
        

        int search(const var& val){
            //Valida que la lista no esté vacia
            if (empty()) throw std::out_of_range("Error: La lista está vacía.");
            //Crea el puntero
            Nodo* current = head;
            //Ciclo que itera la lista
            for(int i=0;current!=nullptr;i++){
                //Si el nodo contiene el valor buscado, retorna el indice
                if(current->value==val){
                    return i;
                }
                current = current->next;
            }
            //Si no lo encuentra, retorna un indice invalido
            return -1;
        }

        var search_index(const int& index){
            //valida primero que el indice exista
            if(index>length) throw std::out_of_range("Error: El indice está fuera de los límites.");
            Nodo* current;
            for(int i=0;i<=index;i++) current = current->next;
            return current->value;
        }    
};

int menu(){
    std::cout<< "Ingresa una de las siguientes opciones:" << std::endl;
    std::cout<< "1.- Crear una lista enlazada con valores aleatorios" << std::endl;
    std::cout<< "2.- Imprimir la lista" << std::endl;
    std::cout<< "3.- Buscar un numero en la lista" << std::endl;
    std::cout<< "4.- Eliminar un numero de la lista" << std::endl;
    std::cout<< "5.- Consultar un espacio del arreglo" << std::endl;
    std::cout<< "0.- Salir" << std::endl;
}

int main(){

    return 0;
}

