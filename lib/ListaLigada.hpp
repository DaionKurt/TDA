// Created by Carlos A. Fernández on 14/02/2017.
// Copyright (c) 2017 Lexem All rights reserved.

#ifndef TDA_LISTALIGADA_HPP
#define TDA_LISTALIGADA_HPP

#include <sstream>

template <typename T>
class Nodo{
public:
    T* elemento;
    Nodo* siguiente;
};

template <typename T>
class Lista{
    Nodo<T>* encabezado;
    long contador;
    std::string nombre;
    Nodo<T>* reserva();
    void libera(Nodo<T>*);
public:
    Lista();
    Lista(std::string);
    void inserta(T*);
    void inserta(T*,Nodo<T>*);
    Nodo<T>* localiza(T*);
    T* recupera(Nodo<T>*);
    void suprime(Nodo<T>*);
    Nodo<T>* siguiente(Nodo<T>*);
    Nodo<T>* anterior(Nodo<T>*);
    Nodo<T>* primero();
    Nodo<T>* fin();
    Nodo<T>* ultimo();
    bool vacia();
    Lista<T>* concatena(Lista*);
    Lista<T> concatena(Lista&);
    int get_tamanio();
    std::string get_nombre();
    std::string get();
};

template <typename T>
Lista<T>::Lista():Lista("Init"){}

template <typename T>
Lista<T>::Lista(std::string nombre){
    contador=0;
    encabezado = reserva();
    encabezado->siguiente = nullptr;
    this->nombre=nombre;
}

template <typename T>
void Lista<T>::inserta(T *elemento){
    inserta(elemento,fin());
}

template <typename T>
void Lista<T>::inserta(T *elemento,Nodo<T>* posicion){
    Nodo<T>* temporal = posicion->siguiente;
    posicion->siguiente = reserva();
    posicion->siguiente->elemento = elemento;
    posicion->siguiente->siguiente = temporal;
}

template <typename T>
Nodo<T>* Lista<T>::reserva(){
    contador++;
    return new Nodo<T>;
}

template <typename T>
void Lista<T>::libera(Nodo<T>* posicion){
    contador--;
    delete(posicion);
}


template <typename T>
Nodo<T>* Lista<T>::localiza(T* elemento){
    Nodo<T>* posicion = encabezado;
    while(posicion->siguiente!=nullptr){
        if(recupera(posicion)==elemento)
            return posicion;
        posicion = posicion->siguiente;
    }
    return posicion;
}

template <typename T>
T* Lista<T>::recupera(Nodo<T>* posicion){
    Nodo<T>* temporal = posicion->siguiente;
    return temporal!= nullptr?temporal->elemento: nullptr;
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
Nodo<T>* Lista<T>::siguiente(Nodo<T>* posicion){
    return (posicion->siguiente!= nullptr)?posicion->siguiente:nullptr;
}

template <typename T>
Nodo<T>* Lista<T>::anterior(Nodo<T>* posicion){
    Nodo<T>* anterior = encabezado;
    while(anterior!= nullptr && anterior->siguiente!=posicion)
        anterior=anterior->siguiente;
    return anterior!= nullptr?anterior: nullptr;
}

template <typename T>
Nodo<T>* Lista<T>::primero(){
    return !vacia()?encabezado:fin();
}

template <typename T>
Nodo<T>* Lista<T>::fin(){
    Nodo<T>* posicion = encabezado;
    while(posicion->siguiente!= nullptr) posicion=posicion->siguiente;
    return posicion;
}

template <typename T>
Nodo<T>* Lista<T>::ultimo(){
    return vacia()? nullptr:anterior(fin());
}

template <typename T>
bool Lista<T>::vacia(){return encabezado->siguiente==nullptr;}

template <typename T>
Lista<T>* Lista<T>::concatena(Lista*){}

template <typename T>
Lista<T> Lista<T>::concatena(Lista&){}

template <typename T>
int Lista<T>::get_tamanio(){return contador-1;}

template <typename T>
std::string Lista<T>::get_nombre(){return nombre;}

template <typename T>
std::string Lista<T>::get(){
    std::stringstream str;
    Nodo<T>* p,*q;
    for(p=primero(),q=fin();p!=q;p=siguiente(p))
        str << *recupera(p) << std::endl;
    return str.str();
}

#endif //TDA_LISTALIGADA_HPP
