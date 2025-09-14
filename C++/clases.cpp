#include <iostream>
#include <vector>
//Ayuda a definir una plantilla para la clase en concreto
template <typename var>
class Pila {
    private:
        int SP;
        std::vector<var> Data;
    public:
        Pila(int size): SP(0) ,Data(size){
        }
        //retorna si la Pila está vacia
        bool empty()const{
            return (SP==0);
        }
        //retorna si la pila está llena
        bool full()const{
            return (SP==Data.size());
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
            return (Data.size() - SP);
        }
        //retorna el largo de la pila
        int size() const{
            return (Data.size());
        }
        //imprimir la pila
        void print(){
            std::cout<<'[';
            for (int i=SP-1;i>=0;i--){
                std::cout<<Data[i];
                if (i>0) std::cout<<',';
            }
            std::cout<<']'<<std::endl;
        }
};

int main(){
    //Declarar una pila
    Pila<int> pila(6);

    //Llenar los datos de de pila
    for(int i=0;i<pila.size();i++){
        pila.push(i);
    }
    pila.print();
    //Consultar si la pila está llena
    std::cout << (pila.full() ? "La pila está llena" : "La pila no está llena") << std::endl;
    std::cout << pila.availible() << std::endl;
    return 0;
}