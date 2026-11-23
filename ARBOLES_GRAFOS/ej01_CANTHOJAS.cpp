#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class nodo {
public:
    T info;
    nodo* der, * izq;
};

template <class T> class arbol {
private:
    nodo<T>* raiz, * q;
    void ArbolBusq(T x, nodo<T>*& nuevo);
    int contarHojas(nodo<T>* aux);

public:
    arbol() { raiz = NULL; };
    ~arbol() {};
    void CreaArbolBus(T x);
    int ContarHojas() { return contarHojas(raiz); }

};

template <class T> void arbol<T>::CreaArbolBus(T x)
{
    ArbolBusq(x, raiz);
}
template <class T> void arbol<T>::ArbolBusq(T x, nodo<T>*& nuevo)
{
    if (nuevo == NULL) {
        nuevo = new nodo<T>;
        nuevo->info = x; nuevo->der = nuevo->izq = NULL;
    }
    if (x > nuevo->info) ArbolBusq(x, nuevo->der);
    if (x < nuevo->info) ArbolBusq(x, nuevo->izq);
}
/*
Implementaciones hechas por mi:
"contarHojas"
"tamRec", "size"
"esBSTValidoRecursivo"
"rangoRec"
"predecessorHelper", "lowerBoundHelper"
*/
template <class T>
int arbol<T>::contarHojas(nodo<T>* aux)
{
    if(!aux) return 0;
    if(contarHojas(aux->izq)==0&&contarHojas(aux->der)==0) return 1;
    return contarHojas(aux->izq) + contarHojas(aux->der);
}
template <class T>
int ABB<T>::tamRec(const Nodo<T>* p) const{
    if (!p) return 0;
    return 1 + tamRec(p->izq) + tamRec(p->der);
}

int ABB<T>::size() const{
    return tamRec(raiz);
}

bool BST::esBSTValidoRecursivo(Nodo* nodo, Nodo*& prev) {
    if (!nodo) return true;
    if(!esBSTValidoRecursivo(nodo->izquierdo, prev)) return false;
    if (prev&&prev->valor > nodo->valor) return false;
    prev = nodo;
    return esBSTValidoRecursivo(nodo->derecho, prev);
}

void ABB<T>::rangoRec(Nodo<T>* p, T a, T b, vector<T>& out){
    if(p==nullptr) return;
    if (a < p->dato) rangoRec(p->izq,a,b,out);
    if (!(p->dato < a) && !(b < p->dato)) {
        out.push_back(p->dato);
    }
    if (p->dato < b) rangoRec(p->der,a,b,out);
}

Nodo<T>* ABB<T>::predecessorHelper(Nodo<T>* p, T x){
    Nodo<T>* predecesor=nullptr;
    while(p){
        if(p->dato<x) {
            if(!predecesor||predecesor->dato<p->dato)predecesor=p;
            p=p->der;
        }else{
            p=p->izq;
        }
    }
    if(predecesor) return predecesor;
    else throw std::runtime_error("predecessor: no encontrado");
}
Nodo<T>* ABB<T>::lowerBoundHelper(Nodo<T>* p, T x){
    Nodo<T>* lb=nullptr;
    while(p){

        if(p->dato<x) p=p->der;

        else{
            if(!lb || p->dato < lb->dato) lb=p;
            p=p->izq;
        }
    }
    if(lb) return lb;
    throw std::runtime_error("lower_bound: no encontrado");
}
