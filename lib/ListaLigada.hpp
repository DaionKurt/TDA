// Created by Carlos A. Fernández on 14/02/2017.
// Copyright (c) 2017 Lexem All rights reserved.

#ifndef TDA_LISTALIGADA_HPP
#define TDA_LISTALIGADA_HPP

template <typename T>
class Nodo{
public:
    T* elemento;
    Nodo* sig;
    Nodo* ant;
};

template <typename T>
class Lista{
    Nodo* encabezado;
    long contador;
    std::string nombre;
    Nodo* reserva();
    void libera(Nodo*);
public:
    Lista();
    Lista(std::string);
    ~Lista();
    void inserta(T*);
    void inserta(T*,Nodo*);
    Nodo* localiza(T*);
    T* recupera(Nodo*);
    T* suprime(Nodo*);
    Nodo* siguiente(Nodo*);
    Nodo* anterior(Nodo*);
    Nodo* primero();
    Nodo* fin();
    Nodo* ultimo();
    bool vacia();
    bool llena();
    bool mismo(T*,T*);
    Lista<T>* concatena(Lista*);
    Lista<T> concatena(Lista&);
    void purga();
    int get_tamanio();
    std::string get_nombre();
};

template <typename T>
Lista<T>::Lista():Lista("Init"){}

template <typename T>
Lista<T>::Lista(std::string nombre){
    this->nombre=nombre;
    contador=0;
    encabezado = reserva();
    encabezado->sig = nullptr;
    encabezado->ant = nullptr;
}

template <typename T>
Lista::~Lista(){}

template <typename T>
void Lista<T>::inserta(T *elemento){
    inserta(elemento,fin());
}

template <typename T>
void Lista<T>::inserta(T *elemento,Nodo* posicion){

//    Nodo* nuevo = reserva();
//    nuevo->elemento = elemento;
//    nuevo->sig = posicion->sig;
//    nuevo->ant = posicion;
//    posicion->sig = nuevo;
//    if(nuevo->sig!= nullptr)
//        nuevo->sig->ant=nuevo;
}

#endif //TDA_LISTALIGADA_HPP
