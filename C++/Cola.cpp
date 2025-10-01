#include <iostream>
#include <stdexcept>
class Cola{
    private:
        int in;
        int out;
        int length;
        int* Data;

        bool empty()const{
            return (in == out);
        }

        bool full()const{
            return ((in + 1) % length == out);
        }

    public:
        
        Cola(int length):in(0),out(0),length(length){
            Data = new int[length];
        }

        ~Cola(){
            delete Data;
        }

        void encolar(int val){
            if (full()) throw std::out_of_range("La cola está llena.");
            Data[in] = val;
            in = (in+1) % length;
        }

        int pull(){
            if(empty()) throw std::out_of_range("La cola está vacía.");
            
            return Data[out];
        }

        int desencolar(){
            if(empty()) throw std::out_of_range("La cola está vacía.");

            const int val = Data[out];
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

int main(){
    Cola cola(6);
    for (int i=0;i<5;i++) cola.encolar(i);
    cola.desencolar();
    cola.encolar(55);
    cola.mostrar();
    return 0;
}