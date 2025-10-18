#include "Lista_circular.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <random>

class Ruleta : public Linked_circular_list<std::string>{
    private:
        const int length;
        int counter;

        int random_index() const {
            static thread_local std::mt19937 gen(std::random_device{}());
            std::uniform_int_distribution<int> dis(0, counter); 
            return dis(gen);
        }

    public:
        Ruleta(int length) : Linked_circular_list<std::string>(),length(length), counter(0) {} 

        ~Ruleta(){}

        std::string kill() {
            
            if (counter <= 0) {
                return "No hay elementos para eliminar";
            }
            if (counter == 1) { 
                return "El ganador es: " + head->value;
            }
            
            int index = random_index();
            
            std::string eliminado = this->pop(index);
            counter--; 
            return "Elemento eliminado al azar: " + eliminado;
        }

        int size()const{ return counter; }

        void add(const std::string& value){
            if(counter < length){
                Linked_circular_list<std::string>::add(value);
                counter++;
            }
            else throw std::out_of_range("Juego lleno");
            
        }




};


int menu(){
    int opcion;
    std::cout<<"1. Ingresar un jugador."<<std::endl;
    std::cout<<"2. Mostrar todos los participantes."<<std::endl;
    std::cout<<"3. Jugar a la ruleta."<<std::endl;
    std::cout<<"4. Terminar el juego."<<std::endl;
    std::cin>> opcion;
    return opcion;

}

int main(){
    //Definir tamaño de la ruleta
    std::cout << "Cuántos juegan?" << std::endl;
    int players;
    std::cin >> players;
    Ruleta ruleta(players);
    //Menu de juego
    while(true){
        int opc = menu();
        if (opc == 1){
            try {
                std::string nombre;
                std::cout<<"Ingresa el dato: ";
                std::cin>> nombre;
                ruleta.add(nombre);
            } catch (std::out_of_range) {
                std::cout<< "Ya se encuentran todos los jugadores."<<std::endl;
            }
        }
        //Mostrar los participantes
        else if(opc == 2) ruleta.mostrar();
        //Jugar
        else if (opc == 3) {
            while(ruleta.size()>1) std::cout << ruleta.kill() << std::endl;
            
            std::cout << ruleta.kill() << std::endl; 
        } 
        //Terminar el juego
        else if
        (opc == 4) return 0;
        //Default
        else std::cout<<"Error. opción no válida."<<std::endl;   
    }

    return 0;
}