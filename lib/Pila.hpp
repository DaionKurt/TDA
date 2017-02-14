// Created by Carlos A. Fernández on 14/02/2017.
// Copyright (c) 2017 Lexem All rights reserved.

#ifndef TDA_PILA_HPP
#define TDA_PILA_HPP

template <typename T>
class Pila{
private:
    T** elementos;
    int cantidad;
    int tope;
    std::string nombre;
public:
    Pila();
    Pila(int);
    Pila(int,std::string);
    T* g_tope();
    bool apila(T*);
    T* desapila();
    bool vacia();
    bool llena();
    std::string get_nombre();
    int size();
    int tamanio();
};

template <typename T>
Pila<T>::Pila():Pila(30){}

template <typename T>
Pila<T>::Pila(int cantidad):Pila(cantidad,"Init"){}

template <typename T>
Pila<T>::Pila(int cantidad,std::string nombre){
    elementos=new T*[this->cantidad=cantidad];
    tope=-1;
    this->nombre=nombre;
}

template <typename T>
T* Pila<T>::g_tope(){
    return elementos[tope];
}

template <typename T>
bool Pila<T>::apila(T *elemento){
    if(!llena()) {
        elementos[++tope] = elemento;
        return true;
    }else return false;
}

template <typename T>
T* Pila<T>::desapila(){
    return (!vacia())?elementos[tope--]:nullptr;
}

template <typename T>
bool Pila<T>::vacia(){return tope<0;}

template <typename T>
bool Pila<T>::llena(){return tope>=cantidad-1;}

template <typename T>
std::string Pila<T>::get_nombre(){return nombre;}

template <typename T>
int Pila<T>::tamanio(){return cantidad;}

template <typename T>
int Pila<T>::size(){return tope+1;}

#endif //TDA_PILA_HPP

