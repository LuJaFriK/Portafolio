#include <iostream>
#include "Diccionario.hpp"
#include "InputUtils.hpp"
#include <string>

int main(){
    Diccionario</*Referencia*/std::string,/*Dato interno*/ int> diccionario{};

    while(true){
        switch(input<int>("1.Agregar/Modificar.\n2.Mostrar\n3.Borrar\n4.Salir\n")){
            case 1:{
                    //Meter en el diccionario
                    std::string nombre = input<std::string>("Ingresa el índice:\n");
                    int valor = input<int>("Ingresa el valor:\n");
                    //Agregar al diccionario
                    diccionario.set(nombre, valor);
                }
                break;
            case 2:
                std::cout << diccionario.mostrar() << std::endl;
                break;
            case 3:{
                    std::string nombre = input<std::string>("Ingresa el índice:\n");
                    diccionario.remove(nombre);
                }
                break;
            case 4:
                std::cout << "Saliendo" << std::endl;
            return 0;
        }
    }


    return 0;
}

