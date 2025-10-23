
#include <stdexcept>
#include <string>
#include <iostream>
#include <random>
#include "Lista_circular.hpp"
#include "InputUtils.hpp"

class Ruleta : public Linked_circular_list<std::string>{
    private:
        
        int counter;

        int random_index() const {
            static thread_local std::mt19937 gen(std::random_device{}());
            std::uniform_int_distribution<int> dis(0, 5); 
            return dis(gen);
        }

    public:
        Ruleta(int length) : Linked_circular_list<std::string>(),length(length), counter(0) {} 

        ~Ruleta(){}

        const int length;

        std::string kill() {
            
            if (counter <= 0) {
                return "No hay personas jugando.";
            }
            if (counter == 1) { 
                return "El ganador es: " + this->pull()+".";
            }
            
            int index = random_index();
            
            std::string eliminado = this->pop(index);
            counter--; 
            return "El jugador "+ std::to_string(index) +":" + eliminado +" ha perdido.";

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
//input agregado

int main(){
    //Definir tamaño de la ruleta
    int players = input<int>("Cuántos juegan? ");
    Ruleta ruleta(players);
    //Menu de juego
    while(true){
        
        switch(input<int>("Seleccione una opción: \n1. Agregar jugador\n2. Mostrar jugadores\n3. Jugar\n4. Salir\n")){
            case 1:
                try {
                    std::string nombre = input<std::string>("Ingresa el dato: ");
                    ruleta.add(nombre);
                } catch (std::out_of_range) {
                    std::cout<< "Ya se encuentran todos los jugadores."<<std::endl;
                }
                break;
            case 2:
                std::cout << ruleta.mostrar() << std::endl;
                break;
            case 3:
                while(ruleta.size()>1) std::cout << ruleta.kill() << std::endl;
                std::cout << ruleta.kill() << std::endl; 
                break;
            case 4:
                return 0;
            default:
                std::cout<<"Error. opción no válida."<<std::endl;
            break;   
        }
    }

    return 0;
}