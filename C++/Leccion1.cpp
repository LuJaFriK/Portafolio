#include <iostream>
#include <string>

using namespace std;

string variables(){
int edad = 0;
    const double pi = 3.141529;
    char letra = 'A';
    bool estudiante = true;
    string nombre = "Juan";
    return nombre;
}

int operadores(){
    int a = 5*5+1/2; //aritmeticos
    if (a != 0) cout << "Operadores logicos";
    a*=1;
    a/=2;
    
    return a;
}

int main(){
    cout <<"Nombre: "<<variables()<<endl;
    return 0;
}



