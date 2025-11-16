#include <iostream>
#include <string>

int hola(const int& a){
    return a;
}
double hola(const double& a){
    return a;
}
std::string hola(const std::string& a){
    return a;
}

int main(){
    std::string one{"Hello"};
    double two{3.14159265358979323846};
    int three{42};
    
    auto four = hola(one);
    auto five = hola(two);
    auto six = hola(three);
    std::cout << four << std::endl;
    std::cout << five << std::endl;
    std::cout << six << std::endl;
    return 0;
}