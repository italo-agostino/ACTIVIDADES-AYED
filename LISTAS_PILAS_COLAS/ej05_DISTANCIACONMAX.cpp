#include <iostream>
#include <cmath>     // Para usar std::abs
#include <limits>    // Para el valor mínimo inicial

template <typename T>
class ListaSimple {
private:
    struct Nodo {
        T valor;
        Nodo* proximo;
        Nodo(T val) : valor(val), proximo(nullptr) {}
    };
    Nodo* cabeza;

public:
    // (Constructor, destructor, insertarAlFinal, imprimir son idénticos al anterior)
    ListaSimple() : cabeza(nullptr) {}
    ~ListaSimple() { while (cabeza) { Nodo* t = cabeza; cabeza = cabeza->proximo; delete t; } }
    void insertarAlFinal(T valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!cabeza) { cabeza = nuevo; return; }
        Nodo* act = cabeza;
        while (act->proximo) act = act->proximo;
        act->proximo = nuevo;
    }
    void imprimir() const {
        if (!cabeza) { std::cout << "Lista Vacía" << std::endl; return; }
        Nodo* act = cabeza;
        while (act) { std::cout << "[" << act->valor << "] -> "; act = act->proximo; }
        std::cout << "NULL" << std::endl;
    }

    //MI IMPLEMENTACION
    void distanciaAlMaximo() {
        Nodo* actual = cabeza;
        T maximo;
        if (actual) { maximo=actual->valor;}
        else{return;}

        while(actual){
            if(actual->valor>maximo){
                maximo=actual->valor;
            }
            actual=actual->proximo;
        }

        actual = cabeza;

        while(actual){
            actual->valor= abs (maximo) - abs(actual->valor);
            actual=actual->proximo;
        }
    }
};