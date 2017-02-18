// Created by Carlos A. Fernández on 14/02/2017.
// Copyright (c) 2017 Lexem All rights reserved.

#ifndef TDA_LISTALIGADA_HPP
#define TDA_LISTALIGADA_HPP

#include <sstream>
#include "Estructura.hpp"

template <typename T>
class Lista{
    Nodo<T>* encabezado;
    int contador;
    std::string nombre;
    Nodo<T>* reserva();
    void libera(Nodo<T>*);
public:
    Lista();
    Lista(std::string);
    void inserta(T*);
    void inserta(T*,Nodo<T>*);
    void suprime(Nodo<T>*);
    Nodo<T>* localiza(T*);
    T* recupera(Nodo<T>*);
    Nodo<T>* siguiente(Nodo<T>*);
    Nodo<T>* anterior(Nodo<T>*);
    Nodo<T>* primero();
    Nodo<T>* ultimo();
    Nodo<T>* fin();
    bool vacia();
    int get_tamanio();
    std::string get_nombre();
    std::string get_impresion();
};

template <typename T>
Nodo<T>* Lista<T>::reserva(){
    contador++;
    return new Nodo<T>;
}

template <typename T>
void Lista<T>::libera(Nodo<T>* nodo){
    contador--;
    delete(nodo);
}

template <typename T>
Lista<T>::Lista():Lista("Init"){}

template <typename T>
Lista<T>::Lista(std::string nombre){
    encabezado = reserva();
    encabezado->siguiente = nullptr;
    contador=0;
    this->nombre=nombre;
}

template <typename T>
void Lista<T>::inserta(T *elemento){
    inserta(elemento,fin());
}

template <typename T>
void Lista<T>::inserta(T* elemento,Nodo<T>* posicion){
    Nodo<T>* temporal = posicion->siguiente;
    posicion->siguiente = reserva();
    posicion->siguiente->elemento = elemento;
    posicion->siguiente->siguiente = temporal;
}

template <typename T>
void Lista<T>::suprime(Nodo<T>* posicion){
    Nodo<T>* temporal = posicion->siguiente;
    if(temporal!= nullptr){
        posicion->siguiente=temporal->siguiente;
        libera(temporal);
    }
}

template <typename T>
Nodo<T>* Lista<T>::localiza(T* elemento){
    for(Nodo<T>* posicion=encabezado;posicion->siguiente!=nullptr;posicion=posicion->siguiente)
        if(*recupera(posicion)==*elemento) return posicion;
    return fin();
}

template <typename T>
T* Lista<T>::recupera(Nodo<T>* posicion){
    return (posicion->siguiente!= nullptr)?posicion->siguiente->elemento: nullptr;
}

template <typename T>
Nodo<T>* Lista<T>::siguiente(Nodo<T>* posicion){
    return posicion->siguiente!=nullptr?posicion->siguiente: nullptr;
}

template <typename T>
Nodo<T>* Lista<T>::anterior(Nodo<T>* posicion){
    Nodo<T>* anterior = encabezado;
    while(anterior!= nullptr && anterior->siguiente!=posicion)
        anterior = anterior->siguiente;
    return anterior!= nullptr?anterior: nullptr;
}

template <typename T>
Nodo<T>* Lista<T>::primero(){ return !vacia()?encabezado:fin();}

template <typename T>
Nodo<T>* Lista<T>::ultimo(){return vacia()?nullptr:anterior(fin());}

template <typename T>
Nodo<T>* Lista<T>::fin(){
    Nodo<T>* posicion = encabezado;
    while(posicion->siguiente!= nullptr) posicion=posicion->siguiente;
    return posicion;
}

template <typename T>
bool Lista<T>::vacia(){ return encabezado->siguiente== nullptr;}

template <typename T>
int Lista<T>::get_tamanio(){ return contador-1;}

template <typename T>
std::string Lista<T>::get_nombre(){ return nombre;}

template <typename T>
std::string Lista<T>::get_impresion(){
    std::stringstream str;
    for(Nodo<T>* posicion=encabezado;posicion->siguiente!= nullptr;posicion=posicion->siguiente)
        str<<*recupera(posicion)<<std::endl;
    return str.str();
}
#endif //TDA_LISTALIGADA_HPP
