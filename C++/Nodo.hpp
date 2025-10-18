#ifndef NODO_H
#define NODO_H

template <typename T>
struct Nodo{
    T value;
    Nodo* prev;
    Nodo* next;
    Nodo(T value):value(value),prev(nullptr),next(nullptr){}

};

template <typename T>
void link(Nodo<T>*&back,Nodo<T>*&front){
            //Si back es un nodo valido, lo enlaza con front
            if(back) back->next = front;
            //Si front es un nodo valido, lo enlaza con back
            if(front) front->prev = back;
        }

#endif