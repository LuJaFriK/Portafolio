#ifndef NODO_H
#define NODO_H

#include <string>
#include <sstream> 

template <typename T>
class Nodo_simple {
    //Atributos
    private: 
        T value;
        Nodo_simple* next;
    public:
        //Constructores
        Nodo_simple(T value = T(), Nodo_simple* next = nullptr) : value(value) , next(next) {}
        //Destructor
        virtual ~Nodo_simple() {}
        //Constructor de copia
        Nodo_simple(const Nodo_simple& other) : value(other.getValue()), next(nullptr) {}
        
        T getValue() const { return value; }
        void setValue(T value) { this->value = value; }
        
        Nodo_simple* getNext() const { return next; }
        void setNext(Nodo_simple* next) { this->next = next; }

        virtual std::string to_string(){
            std::stringstream ss;
            ss << value;
            return ss.str();
        }
};

template <typename T>
class Nodo_doble : public Nodo_simple<T> {
    private:    
        Nodo_doble* prev;
    public:
        Nodo_doble(T value = T(), Nodo_doble* prev = nullptr, Nodo_doble* next = nullptr) 
        : Nodo_simple<T>(value, next), prev(prev) {} // 'next' (Nodo_doble*) se convierte a Nodo_simple*
        
        //Destructor
        ~Nodo_doble() {}
        //Constructor de copia
        Nodo_doble(const Nodo_doble& other) : Nodo_simple<T>(other), prev(nullptr) {}
        
         Nodo_doble* getNext() const { return static_cast<Nodo_doble*>(Nodo_simple<T>::getNext()); }
        
        Nodo_doble* getPrev() const { return prev; }
        void setPrev(Nodo_doble* p) { this->prev = p; }
};

template <typename T>
class Nodo_Tree : public Nodo_simple<T>{
    private:
        Nodo_Tree* parent;
    public:
        Nodo_Tree(T value = T(), Nodo_Tree* next = nullptr): Nodo_simple<T>(value, next){}
        ~Nodo_Tree(){}
        
        Nodo_Tree* getNext() const {
            return static_cast<Nodo_Tree*>(Nodo_simple<T>::getNext());
        }
        
        Nodo_Tree* getPrev() const {
            return static_cast<Nodo_Tree*>(Nodo_simple<T>::getPrev());
        }
        
        Nodo_Tree* getParent() const { return parent; }
        
        void setParent(Nodo_Tree* p) { this->parent = p; }
        
        
        std::string to_string()override{
            std::stringstream ss;
            ss << this->getValue();
            return ss.str();
        }
};

template </*Referencia*/typename U,/*Dato interno*/typename T>
class Nodo_dict : public Nodo_doble<T>{
    public:
        const U address;

        Nodo_dict(U address,T value = T(), Nodo_dict* prev = nullptr, Nodo_dict* next = nullptr):Nodo_doble<T>(value, prev, next),address(address){}
        ~Nodo_dict(){}
        
        Nodo_dict* getNext() const {
                    return static_cast<Nodo_dict*>(Nodo_simple<T>::getNext());
                }
        
        Nodo_dict* getPrev() const {
                    return static_cast<Nodo_dict*>(Nodo_doble<T>::getPrev());
        }

        std::string to_string()override{
            std::stringstream ss;
            ss << address << ':' << this->getValue();
            return ss.str();
        }
};

template <typename T>
void link(Nodo_doble<T>* back, Nodo_doble<T>* front) {
    if (back) back->setNext(front);
    if (front) front->setPrev(back);
}

template <typename T>
std::string Nodo_to_string(Nodo_simple<T>* head) {
    if (!head) return "[]";

    std::stringstream ss;
    ss << "[";
    Nodo_simple<T>* current = head;
    
    do {
        
        ss << current->getValue();
        if (current!=head) ss << ", "; 
        current = current->getNext();
        
    } while (current != head); 
    
    ss << "]";
    return ss.str();
}

template </*Referencia*/typename U,/*Dato interno*/typename T>
std::string Nodo_to_string(Nodo_dict<U,T>* head) { 
    if (!head) return "{}"; 

    std::stringstream ss;
    ss << "{";
    Nodo_dict<U,    T>* current = head;
    
    
    
    do {
       
        ss << current->to_string(); 
        
        
        current = current->getNext();
        
        if (current != head) {
           
            ss << ", "; 
        }
        
    } while (current != head); 
    
    ss << "}";
    return ss.str();
}

#endif