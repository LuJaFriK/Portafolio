#include <iostream>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib> // Para getpid() en Unix/Linux


//var representa la clase del valor
class Linkedlist{
    private:

    struct Nodo{
        int value; //valor de cualquier tipo
        Nodo* next; //Nodo siguiente  
    };

    //Instancia cabecera de la clase nodo, el unico que necesita la lista
    Nodo* head;
    // largo de la lista
    int length;
    //Verifica si la lista esta vacia
    bool empty(){
        return (length<=0);
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
            return this->length;
        }

        void random_linked_list(const int length){
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
            this->length = length;
        }
        
        void add(const int value){
            //Crea un nodo nuevo
            Nodo* new_head = new Nodo();
            //Agrega los valores correspondienes
            new_head->value = value;
            new_head->next = head;
            //Asigna la nueva cabecera
            head = new_head;
            //Actualiza el largo de la lista
            this->length++;
        }

        int pop(const int index){
            //Valida si la lista está vacía
            if (empty()) throw std::out_of_range("Error: La lista está vacía.");
            //Valida si el índice está fuera el alcance
            if (!(index<length)) throw std::out_of_range("Error: El indice esta fuera de los limites.");
            //Valor a retornar
            int deleted_value;
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
                delete [] deleted_node;
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

        void remove(const int val){
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
                delete [] deleted_node;
                return;
            }
            current = head;
            //Ciclo que encuentra el nodo a eliminar
            while (current->next!=nullptr) {
                //Si el nodo siguente al actual es el que estoy buscando, continuo el proceso
                if(current->next->value == val){
                    //Apunto al nodo a eliminar
                    deleted_node = current->next;
                    //Enlazo los nodos restantes
                    current->next = current->next->next;
                    //elimino el nodo
                    delete [] deleted_node;
                    return;
                }
                //Si la condición no se cumple, continua buscando
                current = current->next;
            }
        }

        int search(const int val){
            //Valida que la lista no esté vacia
            if (empty()) return -1;
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

        int get(const int index){
            //valida primero que el indice exista
            if(index>length) throw std::out_of_range("Error: El indice está fuera de los límites.");
            Nodo* current = head;
            for(int i=0;i<=index;i++) current = current->next;
            return current->value;
        }

        void print(){
            Nodo* current = head;
            std::cout << '[';
            while (current != nullptr) {
                std::cout << current->value;
                if (current->next!=nullptr) std::cout << ',';
                current = current->next;
            }
            std::cout << ']' <<std::endl;
        }
};



void test(){
    //Paso 1: Crear pila
    Linkedlist* lista = new Linkedlist();

    //Paso 2: Crear 50000 espacios
    lista->random_linked_list(50000);
        
    //Paso 3: imprimir lista
    lista->print();
        
    //Paso 4: metodo de busqueda
    int index = lista->search(6789);
    std::cout << index << std::endl;
        
    //Paso 5: Buscar valor
    int value = lista->get(67);
    std::cout << value << std::endl;
        
    //Paso 6: Eliminar el valor en el indice 47
     lista->remove(value);
    //Paso 7: Reimprimir lista
    lista->print();
}

long getMemoryUsage() {
    std::ifstream statusFile("/proc/self/status");
    std::string line;
    long vmRSS = 0;
    while (std::getline(statusFile, line)) {
        if (line.find("VmHWM") == 0) {  // VmHWM: Peak resident set size ("high water mark")
            std::istringstream iss(line);
            std::string dummy;
            iss >> dummy >> vmRSS;  // Lee el valor en KB
            return vmRSS * 1024;    // Convertir a bytes
        }
    }
    return 0;  // Valor por defecto si no se encuentra
}

int main() {
    // Simular limpieza de memoria (equivalente a runtime.gc())
    std::system("echo 3 > /proc/sys/vm/drop_caches"); // Nota: Requiere permisos de root, opcional
    // Forzar liberación manual (limitado en C++)
    std::cout.flush(); // Asegurar que los buffers se limpien

    // Medir memoria inicial (en bytes)
    long memoriaInicial = getMemoryUsage();

    // Medir tiempo inicial (en nanosegundos)
    auto inicio = std::chrono::high_resolution_clock::now();

    // Código a medir
    test();

    // Medir tiempo final
    auto fin = std::chrono::high_resolution_clock::now();
    auto tiempoEjecucion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio).count();

    // Simular limpieza de memoria antes de medir final
    std::system("echo 3 > /proc/sys/vm/drop_caches"); // Opcional, requiere permisos
    std::cout.flush();

    // Medir memoria final (en bytes)
    long memoriaFinal = getMemoryUsage();

    // Resultados
    std::cout << "Tiempo de ejecución: " << tiempoEjecucion / 1'000'000.0 << " ms" << std::endl;
    std::cout << "Memoria usada: " << (memoriaFinal - memoriaInicial) << " Bytes" << std::endl;

    return 0;
}