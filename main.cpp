#include <iostream>
//#include "lib/Lista.hpp"
//#include "lib/ListaLigada.hpp"
#include "lib/ListaDoblementeLigada.hpp"
#include "lib/ListaCircular.hpp"
#include "lib/Pila.hpp"
#include "lib/Cola.hpp"
#include "lib/ColaCircular.hpp"
#include "lib/Arbol.hpp"
#include "lib/AVL.hpp"
#include "lib/Grafo.hpp"

int cuenta;
class Integer{
    int valor;
public:
    Integer(int valor){this->valor=valor; cuenta++;}
    virtual ~Integer(){cuenta--;}
    int value(){return valor;}
    bool operator==(Integer& x){
        return valor==x.value();
    }
    friend inline std::ostream& operator<<(std::ostream& s,const Integer& integer){
        s<<integer.valor;
        return s;
    }
};

void pruebasListaEstatica();
void pruebasPilaEstatica();
void pruebasColaEstatica();
void pruebasListaDinamica();
void pruebasListaDoblementeLigada();


int main() {
    //pruebasListaEstatica();
    //pruebasPilaEstatica();
    //pruebasColaEstatica();
    //pruebasListaDinamica();
    pruebasListaDoblementeLigada();
    return 0;
}
/*
void pruebasListaEstatica(){
    Lista<Integer>* lista = new Lista<Integer>(2);
    Lista<Integer>* lista1 = new Lista<Integer>(5);
    Lista<Integer> *lista_de_listas = new Lista<Integer>[3];
    std::cout<<lista->get_tamanio()<<std::endl;
    std::cout<<lista->get_nombre()<<std::endl;
    std::cout<<lista->vacia()<<std::endl;
    std::cout<<lista->llena()<<std::endl;
    Integer* a = new Integer(7);
    Integer* b = new Integer(6);
    Integer* c = new Integer(6);
    Integer* d = new Integer(4);
    std::cout<<"Cuenta: "<<cuenta<<std::endl;
    std::cout<<(lista->inserta(a)?"Bien":"Mal")<<std::endl;
    std::cout<<lista->vacia()<<std::endl;
    std::cout<<lista->llena()<<std::endl;
    std::cout<<(lista->inserta(b)?"Bien":"Mal")<<std::endl;
    std::cout<<(lista1->inserta(c)?"Bien":"Mal")<<std::endl;
    std::cout<<(lista1->inserta(d)?"Bien":"Mal")<<std::endl;
    std::cout<<lista->fin()<<std::endl;
    std::cout<<lista->primero()<<std::endl;
    std::cout<<lista->recupera(1)<<std::endl;
    std::cout<<lista->localiza(a)<<std::endl;
    std::cout<<lista->localiza(b)<<std::endl;
    std::cout<<lista->anterior(1)<<std::endl;
    std::cout<<lista->anterior(0)<<std::endl;
    std::cout<<lista->siguiente(0)<<std::endl;
    std::cout<<lista->siguiente(1)<<std::endl;
    std::cout<<lista->recupera(1)->value()<<std::endl;
    std::cout<<lista->ultimo()<<std::endl;
    std::cout<<lista->primero()<<std::endl;
    std::cout<<*lista<<std::endl;
    lista1 = lista1->concatena(lista);
    lista1->purga();
    std::cout<<*lista1<<std::endl;
    std::cout<<"Cuenta: "<<cuenta<<std::endl;
    delete(lista->suprime(lista->localiza(a)));
    delete(lista1->suprime(lista1->localiza(c)));
    delete(lista1->suprime(lista1->localiza(d)));
    delete(lista);
    delete(lista1);
    delete[](lista_de_listas);
    std::cout<<"Cuenta: "<<cuenta<<std::endl;
}
void pruebasListaDinamica(){
    Lista<Integer> *lista = new Lista<Integer>("Prueba");
    Integer* a = new Integer(6);
    Integer* b = new Integer(5);
    Integer* c = new Integer(4);
    Integer* d = new Integer(3);
    std::cout<<lista->get_nombre()<<std::endl;
    std::cout<<lista->vacia()<<std::endl;
    std::cout<<lista->get_tamanio()<<std::endl;
    lista->inserta(a);
    lista->inserta(b);
    std::cout<<lista->get_impresion();
    lista->inserta(c);
    lista->inserta(d);
    std::cout<<"--------------"<<std::endl;
    std::cout<<lista->get_impresion();
    lista->suprime(lista->ultimo());
    std::cout<<"--------------"<<std::endl;
    std::cout<<lista->get_impresion();
    std::cout<<lista->vacia()<<std::endl;
    std::cout<<lista->get_tamanio()<<std::endl;
    std::cout<<"Ultimo: "<<*lista->siguiente(lista->ultimo())->elemento<<std::endl;
    std::cout<<"Primero: "<<*lista->siguiente(lista->primero())->elemento<<std::endl;
    std::cout<<"Anterior: "<<*lista->anterior(lista->ultimo())->elemento<<std::endl;
    std::cout<<"Recupera Primero: "<<*lista->recupera(lista->primero())<<std::endl;
    std::cout<<"Recupera Ultimo: "<<*lista->recupera(lista->ultimo())<<std::endl;
    std::cout<<"--------------"<<std::endl;
    std::cout<<lista->get_impresion();
    delete(lista);
    delete(a);
    delete(b);
    delete(c);
    delete(d);
    std::cout<<"Cuenta: "<<cuenta<<std::endl;
}

 */
void pruebasPilaEstatica(){
    Pila<Integer>* pila = new Pila<Integer>(25,"Primera");
    std::cout<<pila->get_nombre()<<std::endl;
    std::cout<<pila->tamanio()<<std::endl;
    std::cout<<pila->size()<<std::endl;
    std::cout<<pila->vacia()<<std::endl;
    std::cout<<pila->llena()<<std::endl;
    Integer* a = new Integer(6);
    Integer* b = new Integer(5);
    Integer* c = new Integer(4);
    Integer* d = new Integer(3);
    pila->apila(a);
    pila->apila(b);
    pila->apila(c);
    std::cout<<*pila->g_tope()<<std::endl;
    std::cout<<*pila->desapila()<<std::endl;
    std::cout<<*pila->desapila()<<std::endl;
    std::cout<<*pila->desapila()<<std::endl;
    std::cout<<pila->size()<<std::endl;
    delete(a);
    delete(b);
    delete(c);
    pila->apila(d);
    std::cout<<*pila->desapila()<<std::endl;
    delete(d);
    delete(pila);
    std::cout<<"Cuenta: "<<cuenta<<std::endl;
}
void pruebasColaEstatica(){
    Cola<Integer>* cola = new Cola<Integer>(10,"Cola");
    std::cout<<cola->get_nombre()<<std::endl;
    std::cout<<cola->tamanio()<<std::endl;
    std::cout<<cola->size()<<std::endl;
    std::cout<<cola->vacia()<<std::endl;
    std::cout<<cola->llena()<<std::endl;
    Integer* a = new Integer(6);
    Integer* b = new Integer(5);
    Integer* c = new Integer(4);
    Integer* d = new Integer(3);
    cola->encola(a);
    cola->encola(b);
    cola->encola(c);
    std::cout<<"--------------------------------"<<std::endl;
    std::cout<<cola->frente()->value()<<std::endl;
    std::cout<<cola->size()<<std::endl;
    delete cola->desencola();
    std::cout<<cola->frente()->value()<<std::endl;
    std::cout<<cola->size()<<std::endl;
    delete cola->desencola();
    std::cout<<cola->frente()->value()<<std::endl;
    std::cout<<cola->size()<<std::endl;
    delete cola->desencola();
    std::cout<<cola->size()<<std::endl;
    std::cout<<"Cuenta: "<<cuenta<<std::endl;
    delete(d);
    delete(cola);
    std::cout<<"Cuenta: "<<cuenta<<std::endl;
}
void pruebasListaDoblementeLigada(){
    ListaLigada<Integer> *lista = new ListaLigada<Integer>("Prueba");
    Integer* a = new Integer(6);
    Integer* b = new Integer(5);
    Integer* c = new Integer(4);
    Integer* d = new Integer(3);
    std::cout<<lista->get_nombre()<<std::endl;
    std::cout<<lista->vacia()<<std::endl;
    std::cout<<lista->get_tamanio()<<std::endl;
    lista->inserta(a);
    lista->inserta(b);
    std::cout<<lista->get_impresion();
    lista->inserta(c);
    lista->inserta(d);
    std::cout<<"--------------"<<std::endl;
    std::cout<<lista->get_impresion();
    lista->suprime(lista->ultimo());
    std::cout<<"--------------"<<std::endl;
    std::cout<<lista->get_impresion();
    std::cout<<lista->vacia()<<std::endl;
    std::cout<<lista->get_tamanio()<<std::endl;
    std::cout<<"Ultimo: "<<*lista->siguiente(lista->ultimo())->elemento<<std::endl;
    std::cout<<"Primero: "<<*lista->siguiente(lista->primero())->elemento<<std::endl;
    std::cout<<"Anterior: "<<*lista->anterior(lista->ultimo())->elemento<<std::endl;
    std::cout<<"Recupera Primero: "<<*lista->recupera(lista->primero())<<std::endl;
    std::cout<<"Recupera Ultimo: "<<*lista->recupera(lista->ultimo())<<std::endl;
    std::cout<<"--------------"<<std::endl;
    std::cout<<lista->get_impresion();
    delete(lista);
    delete(a);
    delete(b);
    delete(c);
    delete(d);
    std::cout<<"Cuenta: "<<cuenta<<std::endl;
}