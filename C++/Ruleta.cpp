#include "Lista_enlazada.h"
#include <string>
#include <iostream>
#include <random>

class Ruleta : Linked_circular_list<std::string>{
    private:
        int length;

    public:
        Ruleta() : Linked_circular_list<std::string>(),length(0) {} 

        int random_index() const {
            static thread_local std::mt19937 gen(std::random_device{}());
            std::uniform_int_distribution<int> dis(0, length - 1); 
            return dis(gen);
        }

        void remove_random() {
            int index = random_index();
            
            if (index > -1) {
                std::string eliminado = this->pop(index); 
                std::cout << "Elemento eliminado al azar: " << eliminado << "\n";
            }
        }
};