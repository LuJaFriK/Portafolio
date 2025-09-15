#include <iostream>
#include <random>
//Ayuda a definir una plantilla para la clase en concreto
template <typename var>
class Pila {
    private:
        int SP;
        var* Data;
        int capacity;

    public:
        Pila(int size): SP(0), capacity(size){
            Data = new var[size];
        }

        ~Pila(){
            delete[] Data;
        }

        //retorna si la Pila está vacia
        bool empty()const{
            return (SP==0);
        }
        //retorna si la pila está llena
        bool full()const{
            return (SP==capacity);
        }
        //retorna el objeto en la cabecera
        var pull()const{
            if(!empty()) return Data[SP];
            else throw std::out_of_range("Error: La pila está vacía.");
        }
        //ingresa un nuevo dato
        void push(const var& dato){
            if (!full()){
                Data[SP] = dato;
                SP++;
            }else{
               throw std::out_of_range("Error: La pila está llena.");
            }
        }
        //Elimina y retorna un dato de la pila
        var pop(){
            if(!empty()){
                var deleted = Data[SP-1];
                SP--;
                return deleted;
            }else{
                throw std::out_of_range("Error: La pila está llena.");
            }
        }
        //retorna la cantidad de espacios disponibles en la pila
        int availible() const{
            return (capacity - SP);
        }
        //retorna el largo de la pila
        int size() const{
            return (capacity);
        }
        //imprimir la pila
        void print(){
            std::cout<<"[";
            for (int i=0; i < SP; i++){
                std::cout<< Data[i];
                if (i < SP - 1) std::cout<<",";
            }
            std::cout<<"]"<<std::endl;
        }
};

void test(){

        //Paso 1: Crear pila
        Pila<int>* pila;

        //Paso 2: Crear 50000 espacios
        pila = new Pila<int>(5000);
        
        //Paso 3: imprimir lista
        pila->print();
        
        //Paso 4: metodo de busqueda
        System.out.println(list.searchNode(6789));
        
        //Paso 5: Buscar valor
        int value = list.searchIndex(67);
        System.out.println(value);
        
        //Paso 6: Eliminar valor
        list.deleteNode(value);
        
        //Paso 7: Reimprimir lista
        System.out.println(list);

}

int search(Pila<int>& pila, const int& value){
    while(pila.pull()!=nullptr){
        
    }

}

int main(){
    test();
    return 0;
}

