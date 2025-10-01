#include <iostream>
#include <stdexcept>
class Cola{
    private:
        int in;
        int out;
        int counter;
        int* Data;

        void iterate(int& val){
            val = (val+1) % sizeof(*Data);
        }

        bool empty()const{
            return (counter == 0);
        }

        bool full()const{
            return (counter == *Data);
        }

    public:
        
        Cola(int length):in(0),out(0),counter(0){
            Data = new int[length];
        }

        ~Cola(){
            delete Data;
        }

        int get(){
            return *Data;
        }

        int size(){
            return counter;
        }

        void push(int val){
            if (full()) throw std::out_of_range("La cola está llena.");
            Data[in] = val;
            iterate(in);
            counter++;
        }

        int pull(){
            if(empty()) throw std::out_of_range("La cola está vacía.");
            
            return Data[out];
        }

        int pop(){
            if(empty()) throw std::out_of_range("La cola está vacía.");

            const int val = Data[out];
            iterate(out);
            counter--;
            return val;
        }

};

void llenar(Cola& cola){
    for(int i=0;true;i++){
        try{
            cola.push(i);
        }catch(std::out_of_range){
            break;
        }
    }
}

void imprimir(Cola& cola){
    while(true){
        try{
            std::cout<<cola.pop()<<std::endl;
        }catch(std::out_of_range){
            break;
        }
    }
}

int main(){
    Cola cola(6);
    for (int i=0;i<6;i++) cola.push(i);
    cola.pop();
    cola.push(55);
    imprimir(cola);
    return 0;
}