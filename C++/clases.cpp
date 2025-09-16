#include <iostream>
#include <random>
//Ayuda a definir una plantilla para la clase en concreto
class Pila {
    private:
        int SP;
        int* Data;
        int capacity;

    public:
        Pila(int size): SP(0), capacity(size){
            Data = new int[size];
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
        int pull()const{
            if(!empty()) return Data[SP-1]; // CORREGIDO: SP -> SP-1
            else throw std::out_of_range("Error: La pila está vacía.");
        }
        //ingresa un nuevo dato
        void push(const int dato){
            if (!full()){
                Data[SP] = dato;
                SP++;
            }else{
               throw std::out_of_range("Error: La pila está llena.");
            }
        }
        //Elimina y retorna un dato de la pila
        int pop(){
            if(!empty()){
                int deleted = Data[SP-1];
                SP--;
                return deleted;
            }else{
                throw std::out_of_range("Error: La pila está vacía.");
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

        int get(const int index)const{
            if (index>=capacity) return -1;
            return (Data[index]);
        }

        int search(const int value)const{
            for(int i=0;i<capacity;i++){
                if (Data[i]==value) return (Data[i]);
            }
            return -1;
        }
};

int randomval() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);
    return dis(gen);
}

void test(){

    //Paso 1: Crear pila
    Pila* pila;

    //Paso 2: Crear 50000 espacios
    pila = new Pila(50000);
    for(int i=0;i<(pila->size());i++) pila->push(randomval());
        
    //Paso 3: imprimir lista
    pila->print();
        
    //Paso 4: metodo de busqueda
    int index = pila->search(3685);
    std::cout << index << std::endl;
        
    //Paso 5: Buscar valor
    int value = pila->get(49967);    //int value = searchindex(pila, 67);
    std::cout << value << std::endl;
        
    //Paso 6: Eliminar valores hasta llegar al valor en el indice 67 de adelante para atras
    int del = -1;
    do{
        del = pila->pop();
    }while(del!=value);        
    //Paso 7: Reimprimir lista
    pila->print();

}



int main(){
    test();
    return 0;
}

