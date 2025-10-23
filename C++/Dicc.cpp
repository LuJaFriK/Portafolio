#include <iostream>
#include <stdexcept>
#include "Diccionario.hpp"
#include "InputUtils.hpp"
#include <string>

int main(){
    Diccionario<int> diccionario{};

    while(true){
        switch(input<int>("1.Agregar.\n2.Mostrar\n3.Borrar\n4.Modificar\n5.Salir\n")){
            case 1:
                {   
                    //Meter en el diccionario
                    std::string nombre = input<std::string>("Ingresa el nombre del índice:\n");
                    int valor = input<int>("Ingresa el valor:\n");
                    //Agregar al diccionario
                    diccionario.add(nombre, valor);
                }
            break;
            case 2:
                std::cout << diccionario.mostrar() << std::endl;
            break;
            case 4:
                try{
                    int value = 0;
                    int index = input<int>("Ingresa el índice:");
                    vector.set(index, value);
                }catch(std::out_of_range& e){
                    std::cout << e.what()<<std::endl;
                }
            break;
            case 5:
                std::cout << "Saliendo" << std::endl;
            return 0;
        }
    }


    return 0;
}

