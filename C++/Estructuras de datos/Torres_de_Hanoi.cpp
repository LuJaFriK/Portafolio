#include <iostream>
#include <stdexcept>
#include <stack>
#include <map>
#include "InputUtils.hpp"
#include <string>
#include <sstream>



class Torres_de_Hanoi{
    private:
        std::map<char,std::stack<int>> Torres;

        const int length;

        inline std::stack<int>* get_torre(const char& key){
            if (Torres.count(key)==0) return nullptr;

            return &this->Torres[key];
        }

        inline bool full(const std::stack<int>& st)const{
            return st.size()>=this->length;
        }
    
    public:

        Torres_de_Hanoi(int length):length(length){
            Torres['A'];
            Torres['B'];
            Torres['C'];
            for(int i=length-1;i<=0;i--){
                Torres['A'].push(i);
            }
        }

        void insert(const char& sends, const char& gets){
            //Inicializa las pilas
            auto sender = get_torre(sends), receptor = get_torre(gets);


            if((sender == nullptr) || (receptor==nullptr)) throw std::invalid_argument("Los caracteres no son validos.");

            if(sender->empty()) throw std::invalid_argument("No hay discos para colocar.");

            if ((sender->top() <= receptor->top()) || (receptor->empty())){
                receptor->push(sender->top());
                sender->pop();
            }else 
                throw std::invalid_argument("No puedes colocar ese disco ahí.");
        }

        bool status(){
            //Si alguna de las pilas está llena termina el juego
            return !(full(Torres['B'])||full(Torres['C']));
        }


        std::string str() const{
            std::stringstream ss;

            for(int i = 'A')
        }


        
};

int main(){
    int cant = input<int>("¿Cuántos discos quieres en tu juego? ");
    Torres_de_Hanoi torres(cant);
    while(torres.status()){
        std::cout << torres.str() <<std::endl;
        char torre1 = input<char>("Ingresa la torre que envia: (A,B,C)");
        char torre2 = input<char>("Ingresa la torre que recibe: (A,B,C)");
        try{
            torres.insert(torre1, torre2);
        }catch(std::invalid_argument){
            std::cout<<"La torre no existe"<<std::endl;
        }
    }
    std::cout<< "Felicidades, haz terminado el juego."<<std::endl;
    return 0;
}