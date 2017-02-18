// Created by Carlos A. Fernández on 17/02/2017.
// Copyright (c) 2017 Lexem All rights reserved.

#ifndef TDA_LISTADOBLEMENTELIGADA_HPP
#define TDA_LISTADOBLEMENTELIGADA_HPP

#include <sstream>
#include "Estructura.hpp"

template <typename T>
class ListaLigada{
    NodoD<T>* encabezado;
    int contador;
    std::string nombre;
    NodoD<T>* reserva();
    void libera(NodoD<T>*);
public:
    ListaLigada();
    ListaLigada(std::string);
    void inserta(T*);
    void inserta(T*,NodoD<T>*);
    void suprime(NodoD<T>*);
    NodoD<T>* localiza(T*);
    T* recupera(NodoD<T>*);
    NodoD<T>* siguiente(NodoD<T>*);
    NodoD<T>* anterior(NodoD<T>*);
    NodoD<T>* primero();
    NodoD<T>* ultimo();
    NodoD<T>* fin();
    bool vacia();
    int get_tamanio();
    std::string get_nombre();
    std::string get_impresion();
};

template <typename T>
NodoD<T>* ListaLigada<T>::reserva(){
    contador++;
    return new NodoD<T>;
}

template <typename T>
void ListaLigada<T>::libera(NodoD<T>* NodoD){
    contador--;
    delete NodoD;
}

template <typename T>
ListaLigada<T>::ListaLigada():ListaLigada("Init"){}

template <typename T>
ListaLigada<T>::ListaLigada(std::string nombre){
    encabezado=reserva();
    encabezado->siguiente=encabezado->anterior=nullptr;
    contador=0;
    this->nombre=nombre;
}

template <typename T>
void ListaLigada<T>::inserta(T* elemento){inserta(elemento,fin());}

template <typename T>
void ListaLigada<T>::inserta(T* elemento,NodoD<T>* posicion){
    NodoD<T>* nuevo = reserva();
    nuevo->elemento = elemento;
    nuevo->siguiente = posicion->siguiente;
    nuevo->anterior = posicion;
    posicion->siguiente = nuevo;
    if(nuevo->siguiente!= nullptr)
        nuevo->siguiente->anterior = nuevo;
}

template <typename T>
void ListaLigada<T>::suprime(NodoD<T>* posicion){
    if(posicion->siguiente!= nullptr)
        posicion->siguiente->anterior = posicion->anterior;
    posicion->anterior->siguiente = posicion->siguiente;
    libera(posicion);
}

template <typename T>
NodoD<T>* ListaLigada<T>::localiza(T* elemento){
    for(NodoD<T>* posicion=encabezado;posicion!= nullptr;posicion=posicion->siguiente)
        if(recupera(posicion)==elemento)
            return posicion;
    return nullptr;
}

template <typename T>
T* ListaLigada<T>::recupera(NodoD<T>* posicion){
    return posicion->elemento;
}

template <typename T>
NodoD<T>* ListaLigada<T>::siguiente(NodoD<T>* posicion){ return posicion->siguiente;}

template <typename T>
NodoD<T>* ListaLigada<T>::anterior(NodoD<T>* posicion){ return posicion->anterior;}

template <typename T>
NodoD<T>* ListaLigada<T>::primero(){ return encabezado->siguiente;}

template <typename T>
NodoD<T>* ListaLigada<T>::ultimo(){ return anterior(fin());}

template <typename T>
NodoD<T>* ListaLigada<T>::fin(){
    NodoD<T>* posicion = encabezado;
    while(posicion->siguiente!= nullptr)
        posicion=posicion->siguiente;
    return posicion;
}

template <typename T>
bool ListaLigada<T>::vacia(){ return encabezado->siguiente==nullptr;}

template <typename T>
int ListaLigada<T>::get_tamanio(){ return contador-1;}

template <typename T>
std::string ListaLigada<T>::get_nombre(){return nombre;}

template <typename T>
std::string ListaLigada<T>::get_impresion(){
    std::stringstream str;
    for(NodoD<T>* posicion=encabezado->siguiente;posicion!= nullptr;posicion=posicion->siguiente)
        str << *recupera(posicion) <<std::endl;
    return str.str();
}


#endif //TDA_LISTADOBLEMENTELIGADA_HPP
