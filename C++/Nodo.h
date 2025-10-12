#ifndef NODO_H
#define NODO_H
template <typename T>
struct Nodo{
    T value;
    Nodo* prev;
    Nodo* next;
    Nodo(T value):value(value),prev(nullptr),next(nullptr){}

};

#endif