// Created by Carlos A. Fernández on 17/02/2017.
// Copyright (c) 2017 Lexem All rights reserved.

#ifndef TDA_LISTADOBLEMENTELIGADA_HPP
#define TDA_LISTADOBLEMENTELIGADA_HPP

#include <sstream>

template <typename T>
class Nodo{
public:
    T* elemento;
    Nodo* siguiente;
    Nodo* anterior;
};

template <typename T>
class ListaLigada{
    Nodo<T>* encabezado;
    int contador;
    std::string nombre;
    Nodo<T>* reserva();
    void libera(Nodo<T>*);
public:
    ListaLigada();
    ListaLigada(std::string);
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
Nodo<T>* ListaLigada<T>::reserva(){
    contador++;
    return new Nodo<T>;
}

template <typename T>
void ListaLigada<T>::libera(Nodo<T>* nodo){
    contador--;
    delete nodo;
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
void ListaLigada<T>::inserta(T* elemento,Nodo<T>* posicion){
    Nodo<T>* nuevo = reserva();
    nuevo->elemento = elemento;
    nuevo->siguiente = posicion->siguiente;
    nuevo->anterior = posicion;
    posicion->siguiente = nuevo;
    if(nuevo->siguiente!= nullptr)
        nuevo->siguiente->anterior = nuevo;
}

template <typename T>
void ListaLigada<T>::suprime(Nodo<T>* posicion){
    if(posicion->siguiente!= nullptr)
        posicion->siguiente->anterior = posicion->anterior;
    posicion->anterior->siguiente = posicion->siguiente;
    libera(posicion);
}

template <typename T>
Nodo<T>* ListaLigada<T>::localiza(T* elemento){
    for(Nodo<T>* posicion=encabezado;posicion!= nullptr;posicion=posicion->siguiente)
        if(recupera(posicion)==elemento)
            return posicion;
    return nullptr;
}

template <typename T>
T* ListaLigada<T>::recupera(Nodo<T>* posicion){
    return posicion->elemento;
}

template <typename T>
Nodo<T>* ListaLigada<T>::siguiente(Nodo<T>* posicion){ return posicion->siguiente;}

template <typename T>
Nodo<T>* ListaLigada<T>::anterior(Nodo<T>* posicion){ return posicion->anterior;}

template <typename T>
Nodo<T>* ListaLigada<T>::primero(){ return encabezado->siguiente;}

template <typename T>
Nodo<T>* ListaLigada<T>::ultimo(){ return anterior(fin());}

template <typename T>
Nodo<T>* ListaLigada<T>::fin(){
    Nodo<T>* posicion = encabezado;
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
    for(Nodo<T>* posicion=encabezado->siguiente;posicion!= nullptr;posicion=posicion->siguiente)
        str << *recupera(posicion) <<std::endl;
    return str.str();
}


#endif //TDA_LISTADOBLEMENTELIGADA_HPP
