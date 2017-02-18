// Created by Carlos A. Fernández on 17/02/2017.
// Copyright (c) 2017 Lexem All rights reserved.

#ifndef TDA_ESTRUCTURA_HPP
#define TDA_ESTRUCTURA_HPP

template <typename T>
class Nodo{
public:
    T* elemento;
    Nodo* siguiente;
};

template <typename T>
class NodoD{
public:
    T* elemento;
    NodoD* siguiente;
    NodoD* anterior;
};

#endif //TDA_ESTRUCTURA_HPP
