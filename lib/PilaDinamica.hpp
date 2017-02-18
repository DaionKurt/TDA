// Created by Carlos A. Fernández on 17/02/2017.
// Copyright (c) 2017 Lexem All rights reserved.

#ifndef TDA_PILADINAMICA_HPP
#define TDA_PILADINAMICA_HPP

#include <sstream>
#include "Estructura.hpp"

template <typename T>
class Pila{
    Nodo<T>* tope;
    int contador;
    std::string nombre;
    Nodo<T>* reserva();
    void libera(Nodo<T>*);
public:
    Pila();
    Pila(std::string);
    T* g_tope();
    void apila(T*);
    void desapila();
    bool vacia();
    std::string get_nombre();
    int get_cantidad();
};

template <typename T>
Nodo<T>* Pila<T>::reserva(){
    contador++;
    return new Nodo<T>;
}

template <typename T>
void Pila<T>::libera(Nodo<T>* posicion){
    contador--;
    delete(posicion);
}

template <typename T>
Pila<T>::Pila():Pila("Init"){}

template <typename T>
Pila<T>::Pila(std::string nombre){
    tope=nullptr;
    contador=0;
    this->nombre=nombre;
}

template <typename T>
T* Pila<T>::g_tope(){ return !vacia()?tope->elemento: nullptr;}

template <typename T>
void Pila<T>::apila(T* elemento){
    Nodo<T>* nuevo = reserva();
    nuevo->elemento=elemento;
    nuevo->siguiente=tope;
    tope = nuevo;
}

template <typename T>
void Pila<T>::desapila(){
    if(!vacia()){
        Nodo<T>* temporal = tope;
        tope=tope->siguiente;
        libera(temporal);
    }
}

template <typename T>
bool Pila<T>::vacia(){ return tope==nullptr;}

template <typename T>
std::string Pila<T>::get_nombre(){ return nombre;}

template <typename T>
int Pila<T>::get_cantidad(){ return contador;}




#endif //TDA_PILADINAMICA_HPP
