#ifndef COLA_H
#define COLA_H

#include <stdexcept> // Para std::out_of_range
#include <iostream>  // Para std::cout
#include "Nodo.hpp"

/**
 * @brief Implementa una Cola (FIFO) dinámica usando una lista simplemente enlazada.
 * @tparam var El tipo de dato que almacenará la cola.
 */
template<typename var>
class Cola {
private:
    

    // Puntero al frente (cabeza) de la cola, por donde salen los elementos.
    Nodo<var>* head; 
    // Puntero a la parte trasera (cola) de la cola, por donde entran los elementos.
    Nodo<var>* back; 

public:
    // Constructor por defecto
    Cola() : head(nullptr), back(nullptr) {}

    // Destructor: libera toda la memoria al destruir el objeto.
    ~Cola();

    // Comprueba si la cola está vacía.
    bool empty() const;

    // Imprime los elementos de la cola desde head hasta back.
    void mostrar();

    // Agrega un elemento al final (back) de la cola.
    void encolar(var valor);

    // Muestra (peek) el valor del elemento al frente (head) sin removerlo.
    var pull() const;

    // Remueve y retorna el elemento al frente (head) de la cola.
    var desencolar();
    
    
    Cola(const Cola&) = delete;
    Cola& operator=(const Cola&) = delete;
};

template<typename var>
Cola<var>::~Cola() {
    // La implementación del destructor en el cuerpo de la clase es correcta:
    // while(!empty()) desencolar();
    
    // Se replica aquí para consistencia
    while(!empty()) {
        desencolar();
    }
}

template<typename var>
bool Cola<var>::empty() const {
    return (head == nullptr);
}

template<typename var>
void Cola<var>::mostrar() {
    Nodo<var>* current = head;
    while(current != nullptr) {
        std::cout << current->valor << std::endl;
        current = current->next;
    }
}

template<typename var>
void Cola<var>::encolar(var valor) {
    Nodo<var>* nuevo = new Nodo(valor);
    if(empty()){
        head = nuevo;
        back = nuevo;
    } else {
        back->next = nuevo;
        // El nuevo nodo ahora es el final de la cola
        back = nuevo; // Cambiado para ser más claro que back = back->next
    }
}

template<typename var>
var Cola<var>::pull() const {
    if(empty()) {
        throw std::out_of_range("No hay elementos en la cola.");
    }
    return head->valor;
}

template<typename var>
var Cola<var>::desencolar() {
    if(empty()) {
        throw std::out_of_range("No hay elementos en la cola.");
    }

    // 1. Guardar el valor a retornar
    const var val = head->valor;
    
    // 2. Apuntar al nodo a eliminar
    Nodo<var>* del = head;
    
    // 3. Mover la cabeza al siguiente nodo
    head = head->next;
    
    // 4. Liberar la memoria
    delete del;

    // 5. Caso especial: si la cola queda vacía, back también debe ser nullptr
    if(head == nullptr) {
        back = nullptr;
    }

    return val;
}

#endif // COLA_H