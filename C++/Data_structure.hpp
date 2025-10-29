#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

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
        Nodo_simple(const T& value = T(), Nodo_simple* next = nullptr) : value(value) , next(next) {}
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
        Nodo_doble(const T& value = T(), Nodo_doble* prev = nullptr, Nodo_doble* next = nullptr) 
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
        Nodo_Tree(const T& value = T(), Nodo_Tree* next = nullptr): Nodo_simple<T>(value, next){}
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

        Nodo_dict(const U& address,const T& value = T(), Nodo_dict* prev = nullptr, Nodo_dict* next = nullptr):Nodo_doble<T>(value, prev, next),address(address){}
        ~Nodo_dict(){}
        
        Nodo_dict* getNext() const {
                    return static_cast<Nodo_dict*>(Nodo_simple<T>::getNext());
                }
        
        Nodo_dict* getPrev() const {
                    return static_cast<Nodo_dict*>(Nodo_doble<T>::getPrev());
        }

        std::string to_string()override{
            std::stringstream ss;
            ss << address << " : " << this->getValue();
            return ss.str();
        }
};

template <typename T>
class data_structure{
    protected:
        std::string to_string(Nodo_simple<T>* head) const{
            if (!head) return "[]";

            std::stringstream ss;
            ss << "[";
            Nodo_simple<T>* current = head;
            
            do {
                
                ss << current->getValue();
                current = current->getNext();
                if (current!=head && current!=nullptr) ss << ", "; 
                
            } while (current != head && current!=nullptr);//La condicion valida tanto estructuras circulares como lineales
            
            ss << "]";
            return ss.str();
        }
        
        void link(Nodo_doble<T>* back, Nodo_doble<T>* front) {
            if (back) back->setNext(front);
            if (front) front->setPrev(back);
        }
    public:
        virtual ~data_structure(){}

        virtual bool empty() const = 0;

        virtual std::string mostrar() const = 0;

        
};

#endif