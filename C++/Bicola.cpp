#include <string>
#include <iostream>
#include <stdexcept>
#include "InputUtils.hpp"
#include "Bicola.hpp"



//Retorna true si la acción se hace por arriba y false si es por abajo
bool arriba_o_abajo(){
    int opcion = input<int>("1. Por arriba.\n2. Por abajo.\n");
    return (opcion==1);
}

int main(){

    Bicola<std::string>* cola = nullptr; 
    int opcion = input<int>("1. Bicola normal.\n2. Bicola restrictiva de entrada.\n3. Bicola restrictiva de salida.\n");

    switch (opcion) {
        case 2:
            cola = new Bicola<std::string>(true);
            break;
        case 3:
            cola = new Bicola<std::string>(false);
            break;
        default:
            cola = new Bicola<std::string>();
            break; 
    }
    
    while(true){
        switch(input<int>("1. Bicola normal.\n2. Bicola restrictiva de entrada.\n3. Bicola restrictiva de salida.\n")){
            case 1:
                try {

                    std::string nombre;
                    std::cout<<"Ingresa el dato: ";
                    std::cin>> nombre;
                    
                    cola->encolar(nombre, arriba_o_abajo()); 

                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error de restriccion: " << e.what() << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cout<< "La cola esta llena (imposible con new)"<<std::endl;
                }
            break;
            case 2:
                std::cout << cola->mostrar()<<std::endl;
            break;
            case 3:
                try {

                    std::cout<<cola->desencolar(!arriba_o_abajo())<<" eliminado."<<std::endl;
                
                } catch (const std::invalid_argument& e) {
                     std::cerr << "Error de restriccion: " << e.what() << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cout<< "La cola esta vacia"<<std::endl;
                }
            break;
            case 4:
                delete cola;
                std::cout<<"Saliendo..."<<std::endl;
            return 0;
            default:
                std::cout<<"Error. opción no válida."<<std::endl;
            break;
        }
    return 0;
    }
}