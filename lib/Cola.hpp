// Created by Carlos A. Fernández on 14/02/2017.
// Copyright (c) 2017 Lexem All rights reserved.

#ifndef TDA_COLA_HPP
#define TDA_COLA_HPP

template <typename T>
class Cola{
    T** elementos;
    int cola;
    int cantidad;
    std::string nombre;
public:
    Cola();
    Cola(int);
    Cola(int,std::string);
    T* frente();
    bool encola(T*);
    T* desencola();
    bool vacia();
    bool llena();
    std::string get_nombre();
    int size();
    int tamanio();
};

template <typename T>
Cola<T>::Cola():Cola(30){}

template <typename T>
Cola<T>::Cola(int catidad):Cola(cantidad,"Init"){}

template <typename T>
Cola<T>::Cola(int cantidad, std::string nombre){
    elementos = new T*[this->cantidad=cantidad];
    cola=-1;
    this->nombre=nombre;
}

template <typename T>
T* Cola<T>::frente(){
    return (!vacia())?elementos[0]: nullptr;
}

template <typename T>
bool Cola<T>::encola(T* elemento){
    if(!llena()){
        elementos[++cola]=elemento;
        return true;
    }else return false;
}

template <typename T>
T* Cola<T>::desencola(){
    T* elemento = elementos[0];
    for(int i=0;i<cola;i++)
        elementos[i] = elementos[i+1];
    cola--;
    return elemento;
}

template <typename T>
bool Cola<T>::vacia(){
    return cola<0;
}

template <typename T>
bool Cola<T>::llena(){
    return cola>=cantidad-1;
}

template <typename T>
std::string Cola<T>::get_nombre(){
    return nombre;
}

template <typename T>
int Cola<T>::size(){
    return cola+1;
}

template <typename T>
int Cola<T>::tamanio(){
    return cantidad;
}


#endif //TDA_COLA_HPP
