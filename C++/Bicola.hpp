#pragma once

#include "Nodo.hpp"
#include <stdexcept>
#include <string>
#include <optional>

template<typename T>
class Bicola {
private:
    Nodo_doble<T>* head;
    Nodo_doble<T>* back;
    std::optional<bool> restriccion_entrada; // true for front, false for back
    std::optional<bool> restriccion_salida; // true for front, false for back

    bool es_operacion_restringida(bool from_front, bool encolando) const {
        if (encolando) {
            if (!restriccion_entrada.has_value()) {
                return false; // No restrictions
            }
            return restriccion_entrada.value() == from_front;
        } else { // Desencolando
            if (!restriccion_salida.has_value()) {
                return false; // No restrictions
            }
            return restriccion_salida.value() == from_front;
        }
    }

public:
    Bicola() : head(nullptr), back(nullptr) {}
    Bicola(std::optional<bool> re, std::optional<bool> rs) : head(nullptr), back(nullptr), restriccion_entrada(re), restriccion_salida(rs) {}

    ~Bicola() {
        while (!empty()) {
            try {
                desencolar(true);
            } catch (const std::invalid_argument&) {
                try {
                    desencolar(false);
                } catch (const std::invalid_argument&) {
                    // Should not happen if logic is correct
                }
            }
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    void encolar(T valor, bool from_front) {
        if (es_operacion_restringida(from_front, true)) {
            throw std::invalid_argument("Operación de encolar restringida en este extremo.");
        }

        Nodo_doble<T>* nuevo = new Nodo_doble<T>(valor);
        if (empty()) {
            head = back = nuevo;
        } else if (from_front) {
            link(nuevo, head);
            head = nuevo;
        } else {
            link(back, nuevo);
            back = nuevo;
        }
    }

    T desencolar(bool from_front) {
        if (empty()) {
            throw std::out_of_range("La bicola está vacía.");
        }

        if (es_operacion_restringida(from_front, false)) {
            throw std::invalid_argument("Operación de desencolar restringida en este extremo.");
        }

        Nodo_doble<T>* nodo_a_eliminar;
        if (from_front) {
            nodo_a_eliminar = head;
            head = head->getNext();
            if (head) {
                head->setPrev(nullptr);
            } else {
                back = nullptr; // La cola quedó vacía
            }
        } else {
            nodo_a_eliminar = back;
            back = back->getPrev();
            if (back) {
                back->setNext(nullptr);
            } else {
                head = nullptr; // La cola quedó vacía
            }
        }

        T valor = nodo_a_eliminar->getValue();
        delete nodo_a_eliminar;
        return valor;
    }

    T peek(bool from_front) const {
        if (empty()) {
            throw std::out_of_range("La bicola está vacía.");
        }
        return from_front ? head->getValue() : back->getValue();
    }

    std::string mostrar() const {
        return Nodo_to_string(head);
    }
};