#include <string>
#include <iostream>
#include <stdexcept>
#include "InputUtils.hpp"
#include "Cola.hpp"
/*
int main(){
    Cola<std::string> cola{};
    while(true){
        switch(input<int>("1.Ingresar un nombre.\n2.Mostrar los datos en el largo.\n3.Eliminar un dato.\n4.Salir\n")){
            case 1:
                try {
                    std::string nombre;
                    std::cout<<"Ingresa el dato: ";
                    std::cin>> nombre;
                    cola.encolar(nombre);
                } catch (std::out_of_range) {
                    std::cout<< "La cola esta llena"<<std::endl;
                }
            break;
            case 2:
                std::cout << cola.mostrar()<<std::endl;
            break;
            case 3:
                try {
                    std::cout<<cola.desencolar()<<" eliminado."<<std::endl;
                } catch (std::out_of_range) {
                    std::cout<< "La cola esta vacia"<<std::endl;
                }
            break;
            case 4:
                std::cout<<"Saliendo..."<<std::endl;
            return 0;
            default:
                std::cout<<"Error. opción no válida."<<std::endl;
            break;
        }
    }
    return 0;
}
*/

int main(){
    Cola<std::string> cola{};
    while(true){
        switch(input<int>("1.Ingresar un nombre.\n2.Mostrar los datos en el largo.\n3.Eliminar un dato.\n4.Salir\n")){
            case 1:
                try {

                    std::string nombre = input<std::string>("Ingresa el dato: ");
                    cola.queue(nombre);
                } catch (std::out_of_range) {
                    std::cout<< "La cola esta llena"<<std::endl;
                }
            break;
            case 2:
                std::cout << cola.mostrar()<<std::endl;
            break;
            case 3:
                try {
                    std::cout<<cola.unqueue()<<" eliminado."<<std::endl;
                } catch (std::out_of_range) {
                    std::cout<< "La cola esta vacia"<<std::endl;
                }
            break;
            case 4:
                std::cout<<"Saliendo..."<<std::endl;
            return 0;
            default:
                std::cout<<"Error. opción no válida."<<std::endl;
            break;
        }
    }
    return 0;
}