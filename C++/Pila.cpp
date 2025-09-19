#include <iostream>
#include <stdexcept>
#include <string>
//Ayuda a definir una plantilla para la clase en concreto
template <typename var>
class Pila {
    private:
        int SP;
        var* Data;
        int capacity;

    public:
        Pila(int size): SP(-1), capacity(size){
            Data = new var[size];
        }

        ~Pila(){
            delete[] Data;
        }

        //retorna si la Pila está vacia
        bool empty()const{
            return (SP<0);
        }
        //retorna si la pila está llena
        bool full()const{
            return (SP==capacity-1);
        }
        //retorna el objeto en la cabecera
        var pull()const{
            if(!empty()) return Data[SP]; 
            else throw std::out_of_range("Error: La pila está vacía.");
        }
        //ingresa un nuevo dato
        void push(const var dato){
            if (!full()){
                SP++;
                Data[SP] = dato;
            }else{
               throw std::out_of_range("Error: La pila está llena.");
            }
        }
        //Elimina y retorna un dato de la pila
        var pop(){
            if(!empty()){
                var deleted = Data[SP];
                SP--;
                return deleted;
            }else{
                throw std::out_of_range("Error: La pila está vacía.");
            }
        }
};

int menu(){
    int orden;
    std::cout<< "Elige una opción a continuación: " <<std::endl;
    std::cout<< "1.- Ingresar un dato. " <<std::endl;
    std::cout<< "2.- Mostar un dato. " <<std::endl;
    std::cout<< "3.- Eliminar un dato. " <<std::endl;
    std::cout<< "0.- Salir."<<std::endl;
    std::cin >> orden; 
    return orden;
}

int main(){
    int cantidad;
    std::cout<<"Ingresa la cantidad de datos: "<<std::endl;
    std::cin>>cantidad;
    Pila<std::string>* pila = new Pila<std::string>(cantidad);
    do{
        int opc = menu();
        if(opc==1){
            try {
                std::string entrada;
                std::cout << "Ingresa el contenido: ";
                std::cin >> entrada; 
                pila->push(entrada);
            } catch (std::out_of_range) {
                std::cout<< "Error. La pila no puede guardar más datos. "<<std::endl;
            }
        }else if (opc==2){
            try {
                std::cout<< pila->pull() <<std::endl;
            } catch (std::out_of_range) {
                std::cout<< "Error. La pila no tiene datos. "<<std::endl;
            }
        }else if(opc==3){
            try{
                std::cout<<"El elemento "<< pila->pop() << " ha sido eliminado."<<std::endl;
            }catch(std::out_of_range){
                std::cout<< "Error. La pila no tiene datos. "<<std::endl;
            }
        }else if(opc==0){
        std::cout<< "Saliendo..."<<std::endl;
        return 0;
        }else{
            std::cout << "Opción no válida."<<std::endl;
            continue;
        }
    }while(true);
    return 0;
}