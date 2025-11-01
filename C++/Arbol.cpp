#include <iostream>
#include "Arbol.hpp"
#include "InputUtils.hpp"

int main(){
    Arbol<int> arbol{};
    while(true){
        switch(input<int>("1.Agregar.\n2.Mostrar\n3.Buscar un nodo\n4.Salir\n")){
            case 1:
                arbol.add(input<int>("Ingresa el valor:"));
            break;
            case 2:
                std::cout << arbol.mostrar(input<int>("1.Preorden.\n2.Inorden\n3.Postorden\n")) << std::endl;
            break;
            case 3:
                std::cout << arbol.buscar_valor(input<int>("Ingresa el valor a buscar: ")) <<std::endl;
            break;
            case 4:
                std::cout << "Saliendo" << std::endl;
            return 0;
        }
    }


    return 0;
}

