#include <iostream>
#include <stdexcept>
template <typename var>
class Tree{
    private:
        struct Nodo{
            var val;
            Nodo* left;
            Nodo* right;
            Nodo(var val):val(val),left(nullptr),right(nullptr){}
        };

        Nodo* root;
        int length;

        Nodo* copy(Nodo* nodo){
            if(nodo == nullptr) return nullptr;

            Nodo* nuevo = new Nodo(nodo->val);

            nuevo->left = copy(nodo->left);

            nuevo->right = copy(nodo->right);

            return nuevo;

        }

        static Nodo* add_recursivo(Nodo* current,var nuevo){
            if (current == nullptr) return new Nodo(nuevo);

            if (current->val == nuevo) throw std::invalid_argument("El valor ya se encuentra en el arbol");

            //Si es menor, a la izquierda, si es mayor, a la derecha
            if(nuevo<current->val) current->left = add_recursivo(current->left,nuevo);
            
            else current->right = add_recursivo(current->right,nuevo);
            

            return current;
        }

        static void print(Nodo* root){
            
        }

    public:
        Tree():root(nullptr),length(0){}

        Tree(const Tree& otro){
            
        }

        ~Tree(){}

        void add(var val){
            root = add_recursivo(root, val);
            length++;
        }

        void mostrar(){
            print(root);
        }
};