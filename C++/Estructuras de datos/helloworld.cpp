#include <iostream>
#include <string>

void print(const std::string& mensaje){
    std::cout << mensaje;
}

void print(const int mensaje){
     std::cout << mensaje;
}

void print(const float mensaje){
    std::cout << mensaje;
}

void print(const double mensaje){
    std::cout << mensaje;
}

void println(const std::string& mensaje){
    std::cout << mensaje << std::endl;
}

void println(const int mensaje){
     std::cout << mensaje << std::endl;
}

void println(const float mensaje){
    std::cout << mensaje << std::endl;
}

void println(const double mensaje){
    std::cout << mensaje << std::endl;
}

int factorial(const int numero){
    if (numero == 0) {
        return 1;
    }
    return numero * factorial(numero-1);
}

int sumatoria(const int numero){
    if (numero ==0) return 0;
    return numero + sumatoria(numero-1);
}

int pot(const int numero, int n){
    if (n == 1) return numero;
    else return numero * pot(numero, n-1);
}

int main(){
    int tamaño = 0;
    double a;
    float b = 0.2;
    println("Hola Mundo");
    println(factorial(5));
    println(sumatoria(5));
    println(pot(5, 2));
    return 0;
}

