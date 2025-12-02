#include <iostream>
#include <stdexcept>
#include <string>
template <typename T>
class Cola{
    private:

        int in;
        int out;
        int length;
        T* Data;

    public:

        Cola(int length):in(0),out(0),length(length+1){
            Data = new T[length];
        }

        ~Cola(){
            delete Data;
        }

        bool empty()const{
            return (in == out);
        }

        bool full()const{
            return ((in + 1) % length == out);
        }

        void encolar(T val){
            if (full()) throw std::out_of_range("La cola está llena.");
            Data[in] = val;
            in = (in+1) % length;
        }

        T show()const{
            if(empty()) throw std::out_of_range("La cola está vacía.");
            
            return Data[out];
        }

        T desencolar(){
            if(empty()) throw std::out_of_range("La cola está vacía.");

            const T val = Data[out];
            out = (out+1) % length;
            return val;
        }

        void mostrar(){
            int i = out;
            while(i!=in){
                std::cout<<Data[i]<<std::endl;
                i = (i + 1) % length;
            }
        }

};

int menu(){
    int opcion;
    std::cout<<"1. Ingresar un dato."<<std::endl;
    std::cout<<"2. Mostrar los datos en el largo."<<std::endl;
    std::cout<<"3. Eliminar un dato."<<std::endl;
    std::cin>> opcion;
    return opcion;

}

int main(){
    int len;
    std::cout<<"Ingresa el largo de la cola."<<std::endl;
    std::cin>> len;
    Cola<std::string> cola(len);
    while(true){
        int opc = menu();
        if (opc == 1){
            try {
                std::string nombre;
                std::cout<<"Ingresa el dato: ";
                std::cin>> nombre;
                cola.encolar(nombre);
            } catch (std::out_of_range) {
                std::cout<< "La cola esta llena"<<std::endl;
            }
        }
        else if(opc == 2) cola.mostrar();

        else if (opc == 3){
            try {
                std::cout<<cola.desencolar()<<" eliminado."<<std::endl;
            } catch (std::out_of_range) {
                std::cout<< "La cola esta vacia"<<std::endl;
            }
        }
        
        else if(opc == 4) return 0;
        
        else std::cout<<"Error. opción no válida."<<std::endl;

        
    }
    return 0;
}