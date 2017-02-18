// Created by Carlos A. Fernández on 14/02/2017.
// Copyright (c) 2017 Lexem All rights reserved.

#ifndef TDA_LISTA_HPP
#define TDA_LISTA_HPP

constexpr int cantidad_defecto = 30;

template <typename T>
class Lista{
private:
    T** elementos;
    int tamanio;
    int ult;
    std::string nombre;
public:
    Lista();
    Lista(int tamanio);
    Lista(int tamanio,std::string nombre);
    inline bool inserta(T* elemento);
    inline bool inserta(T* elemento,int posicion);
    int localiza(T* elemento);
    T* recupera(int posicion)const;
    int siguiente(int elemento);
    int anterior(int elemento);
    T* suprime(int posicion);
    int primero()const;
    int ultimo();
    int fin()const;
    bool vacia();
    bool llena();
    Lista<T>* concatena(Lista* lista);
    Lista<T> concatena(Lista& l);
    void purga();
    int get_tamanio();
    std::string get_nombre();
    friend inline std::ostream&operator<<(std::ostream& s, const Lista<T>& l){
        for(int i=l.primero(),j=l.fin();i<j;i++)
            s<<*l.recupera(i)<<std::endl;
        return s;
    }
};

template <typename T>
Lista<T>::Lista():Lista(cantidad_defecto){}

template <typename T>
Lista<T>::Lista(int tamanio):Lista(tamanio,"Init"){}

template <typename T>
Lista<T>::Lista(int tamanio, std::string nombre){
    this->nombre=nombre;
    ult=-1;
    elementos = new T*[this->tamanio=tamanio];
}

template <typename T>
inline bool Lista<T>::inserta(T* elemento){
    return inserta(elemento,fin());
}

template <typename T>
inline bool Lista<T>::inserta(T* elemento, int posicion){
    if(!llena()&&(posicion>=primero()&&posicion<=fin())){
        for(int i=ult;i>=posicion;i--)
            elementos[i+1] = elementos[i];
        ult++;
        elementos[posicion]=elemento;
        return true;
    }else return false;
}

template <typename T>
int Lista<T>::localiza(T* elemento){
    for(int i=primero(),j=fin();i<j;i++)
        if(recupera(i)==elemento) return i;
    return -1;
}

template <typename T>
T* Lista<T>::recupera(int posicion)const{
    return (posicion>=primero()&&posicion<fin())?elementos[posicion]:nullptr;
}

template <typename T>
int Lista<T>::siguiente(int posicion){
    return (posicion>=primero()&&posicion<fin())?posicion+1:-1;
}

template <typename T>
int Lista<T>::anterior(int posicion){
    return (posicion>primero()&&posicion<=fin())?posicion-1:-1;
}

template <typename T>
T* Lista<T>::suprime(int posicion){
    T* elemento = elementos[posicion];
    for(int i=posicion;i<ult;i++)
        elementos[i] = elementos[i+1];
    ult--;
    return elemento;
}

template <typename T
>
int Lista<T>::primero()const{return 0;}

template <typename T>
int Lista<T>::ultimo(){return anterior(fin());}

template <typename T>
int Lista<T>::fin()const{return ult+1;}

template <typename T>
bool Lista<T>::vacia(){return ult<0;}

template <typename T>
bool Lista<T>::llena(){return ult>=tamanio-1;}

template <typename T>
int Lista<T>::get_tamanio(){return tamanio;}

template <typename T>
std::string Lista<T>::get_nombre(){return nombre;}

template <typename T>
Lista<T>* Lista<T>::concatena(Lista* l) {
    Lista<T>* lista = new Lista;
    for(int i=primero(),j=fin();i<j;i++)
        lista->inserta(recupera(i));
    for(int i=l->primero(),j=l->fin();i<j;i++)
        std::cout<<(lista->inserta(l->recupera(i)))<<std::endl;
    return lista;
}

template <typename T>
Lista<T> Lista<T>::concatena(Lista& l) {
    Lista<T> lista;
    for(int i=primero(),j=fin();i<j;i++)
        lista.inserta(recupera(i));
    for(int i=l->primero(),j=l->fin();i<j;i++)
        lista.inserta(l->recupera(i));
    return lista;
}

template <typename T>
void Lista<T>::purga(){
    int p,q;
    for(p=primero();p!=fin();p=siguiente(p)){
        q = siguiente(p);
        while(q!=fin()){
            if(*recupera(p)==*recupera(q)) delete suprime(q);
            else q = siguiente(q);
        }
    }
}

#endif //TDA_LISTA_HPP
