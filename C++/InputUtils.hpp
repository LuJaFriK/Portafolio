#ifndef INPUT_UTILS_HPP
#define INPUT_UTILS_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib> // Para EXIT_FAILURE

/**
 * @brief Implementa una función de entrada (como input() de Python) que 
 * permite 'castear' la entrada a un tipo específico (T).
 * * @tparam T El tipo de dato al que se debe convertir la entrada (ej: int, double, std::string).
 * @param prompt El mensaje de texto a mostrar.
 * @return T El valor casteado del tipo T.
 */
template <typename T>
T input(const std::string& prompt) {
    std::string userInput;
    T result;
    bool valid = false;

    // Repite la solicitud hasta que la conversión sea exitosa
    do {
        // 1. Mostrar el mensaje
        std::cout << prompt;
        
        // 2. Leer la línea completa de entrada como string
        if (!std::getline(std::cin, userInput)) {
            std::cerr << "Error de lectura de entrada o fin de archivo." << std::endl;
            exit(EXIT_FAILURE); 
        }

        // 3. Intentar la conversión (casteo) de string a tipo T
        std::stringstream ss(userInput);
        
        // Intenta extraer el valor Y verifica que se haya leído hasta el final de la cadena (ss.eof())
        if ((ss >> result) && ss.eof()) {
            valid = true;
        } else {
            std::cout << "\n Entrada inválida. Por favor, ingrese un valor del tipo requerido." << std::endl;
            
            // Si el estado de cin está fallido (por si acaso), lo limpiamos
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    } while (!valid);

    return result;
}

#endif // INPUT_UTILS_HPP