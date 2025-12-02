#include <iostream>
#include <stdexcept>
#include "Vector_lista.hpp"
#include "InputUtils.hpp"

int main(){
    Vector<int> vector{input<int>("Largo del arreglo: ")};

    while(true){
        switch(input<int>("1.Modificar.\n2.Mostrar\n3.Borrar\n4.Salir\n")){
            case 1:
                try{
                    int value = input<int>("Ingresa el valor:");
                    int index = input<int>("Ingresa el índice:");
                    vector.set(index, value);
                }catch(std::out_of_range& e){
                    std::cout << e.what()<<std::endl;
                }
            break;
            case 2:
                std::cout << vector.to_string() << std::endl;
            break;
            case 3:
                try{
                    int value = 0;
                    int index = input<int>("Ingresa el índice:");
                    vector.set(index, value);
                }catch(std::out_of_range& e){
                    std::cout << e.what()<<std::endl;
                }
            break;
            case 4:
                std::cout << "Saliendo" << std::endl;
            return 0;
        }
    }


    return 0;
}

