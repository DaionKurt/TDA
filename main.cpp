#include <iostream>
#include "lib/Lista.hpp"
#include "lib/ListaLigada.hpp"
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

int main() {
    pruebasListaEstatica();
    return 0;
}

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