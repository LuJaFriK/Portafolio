#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

template <typename T>
   T solicitar(const std::string& mensaje) {
    while (true) { 
            std::cout << mensaje;
            std::string linea;
            std::getline(std::cin, linea); 
    
            std::stringstream ss(linea); 
            T valor;
    
            if (ss >> valor && ss.eof()) {
                return valor; 
            }
            
         std::cout << "Entrada no válida. Por favor, inténtelo de nuevo." << std::endl;
        }
    }
    
template <>
inline std::string solicitar<std::string>(const std::string& mensaje) {
    std::cout << mensaje;
    std::string linea;
    std::getline(std::cin, linea);
    return linea;
}





#endif