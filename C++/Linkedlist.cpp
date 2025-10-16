#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib> // Para getpid() en Unix/Linux

template<typename type>
class Linkedlist{
    private:

    struct Nodo {
        type value;
        Nodo* next;
        Nodo(int v, Nodo* n = nullptr) : value(v), next(n) {}
    };

    //Instancia cabecera de la clase nodo, el unico que necesita la lista
    Nodo* head;
    // largo de la lista
    int length;
    //Genera un numero aleatorio
    int randomval() const {
        static thread_local std::mt19937 gen(std::random_device{}());
        static std::uniform_int_distribution<int> dis(1, 10000);
        return dis(gen);
    }

    public:
    //Constructor
        Linkedlist() : head(nullptr), length(0) {}
    //Destructor
        ~Linkedlist() {
            Nodo* current = head;
            while (current) {
                Nodo* next = current->next;
                delete current;
                current = next;
            }
        }
        //Verifica si la lista esta vacia
        bool empty() const{ return (length<=0); }
        //Retorna el largo de la lista
        int size() const{ return this->length; }

        void random_linked_list(int n) {
            for (int i = 0; i < n; i++) {
                head = new Nodo(randomval(), head);
            }
            length = n;
        }
        
        void add(type value) {
            head = new Nodo(value, head);
            length++;
        }


        type pop(int index) {
            if (empty()) throw std::out_of_range("Lista vacía");
            if (index < 0 || index >= length) throw std::out_of_range("Índice inválido");

            Nodo* deleted_node;
            type deleted_value;

            if (index == 0) {
                deleted_node = head;
                deleted_value = deleted_node->value;
                head = head->next;
            } else {
                Nodo* current = head;
                for (int i = 0; i < index - 1; i++) {current = current->next;}
                deleted_node = current->next;
                deleted_value = deleted_node->value;
                current->next = deleted_node->next;
            }

            delete deleted_node;
            length--;
            return deleted_value;
        }

        void remove(type val) {
            if (empty()) return;

            if (head->value == val) {
                Nodo* deleted_node = head;
                head = head->next;
                delete deleted_node;
                length--;
                return;
            }

            Nodo* current = head;
            while (current->next) {
                if (current->next->value == val) {
                    Nodo* deleted_node = current->next;
                    current->next = deleted_node->next;
                    delete deleted_node;
                    length--;
                    return;
                }
                current = current->next;
            }
        }

        int search(type val) const {
            Nodo* current = head;
            int index = 0;
            while (current) {
                if (current->value == val) return index;
                current = current->next;
                index++;
            }
            return -1;
        }

        type get(int index) const {
            if (index < 0 || index >= length) throw std::out_of_range("Índice inválido");
            Nodo* current = head;
            for (int i = 0; i < index; i++) current = current->next;
            return current->value;
        }

        void print() const {
            Nodo* current = head;
            std::cout << "[";
            while (current) {
                std::cout << current->value;
                if (current->next) std::cout << ",";
                current = current->next;
            }
            std::cout << "]\n";
        }

        std::string toString() {
            std::string lista = "";
            Nodo* current = head;
            
            // Si la lista está vacía, devolver "[]"
            if (current == nullptr) {
                return "[]";
            }
            
            // Empezar con el corchete inicial
            lista += "[";
            
            // Recorrer la lista
            while (current != nullptr) {
                // Agregar el valor del nodo actual
                lista.append(std::to_string(current->value)); // Convierte el valor a string si no lo es
                // Si hay un nodo siguiente, agregar una coma y espacio
                if (current->next != nullptr) {
                    lista += ", ";
                }
                current = current->next; // Avanzar al siguiente nodo
            }
            
            // Cerrar el corchete
            lista += "]";
            return lista;
        }

};



void test(){
    //Paso 1: Crear lista
    Linkedlist<int>* lista = new Linkedlist<int>();

    //Paso 2: Crear 50000 espacios
    lista->random_linked_list(50000);
        
    //Paso 3: imprimir lista
    lista->print();
    //std::cout << lista->toString() << std::endl;
        
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
    //std::cout << lista->toString() << std::endl;
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