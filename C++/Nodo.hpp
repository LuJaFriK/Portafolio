#ifndef NODO_H
#define NODO_H

#include <string>
#include <sstream> 

//Nodo simple
template <typename T>
class Nodo_simple {
    //Atributos
    private: 
        T value;
        Nodo_simple* next;
    public:
        //Constructores
        Nodo_simple(T value, Nodo_simple* next = nullptr) : value(value) , next(next) {}
        //Destructor
        virtual ~Nodo_simple() {}
        //Constructor de copia
        Nodo_simple(const Nodo_simple& other) : value(other.getValue()), next(nullptr) {}
        
        T getValue() const { return value; }
        void setValue(T value) { this->value = value; }
        
        Nodo_simple* getNext() const { return next; }
        void setNext(Nodo_simple* next) { this->next = next; }
};

template <typename T>
class Nodo_doble : public Nodo_simple<T> {
    private:    
        Nodo_doble* prev;
    public:
        Nodo_doble(T value, Nodo_doble* prev = nullptr, Nodo_doble* next = nullptr) 
            : Nodo_simple<T>(value, next), prev(prev) {} // 'next' (Nodo_doble*) se convierte a Nodo_simple*
        //Destructor
        ~Nodo_doble() {}
        //Constructor de copia
        Nodo_doble(const Nodo_doble& other) : Nodo_simple<T>(other), prev(nullptr) {}
        
        Nodo_doble* getNext() { 
            return static_cast<Nodo_doble*>(Nodo_simple<T>::getNext()); 
        }
        
        Nodo_doble* getPrev() const { return prev; }
        void setPrev(Nodo_doble* p) { this->prev = p; }
};

template <typename T>
void link(Nodo_doble<T>* back, Nodo_doble<T>* front) {
    if (back) back->setNext(front);
    if (front) front->setPrev(back);
}

template <typename T>
std::string to_string(Nodo_simple<T>* head) {
    if (!head) return "[]";

    std::ostringstream oss;
    oss << "[";
    Nodo_simple<T>* current = head;

    do {
        oss << current->getValue(); 
        current = current->getNext();
        if (current && current != head) oss << ", ";
    } while (current && current != head); 
    
    oss << "]";
    return oss.str();
}

#endif