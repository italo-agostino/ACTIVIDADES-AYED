#include <iostream>

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
    ListaSimple() : cabeza(nullptr) {}

    ~ListaSimple() {
        while (cabeza) {
            Nodo* t = cabeza;
            cabeza = cabeza->proximo;
            delete t;
        }
    }

    void insertarAlFinal(T valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevo;
            return;
        }
        Nodo* act = cabeza;
        while (act->proximo) act = act->proximo;
        act->proximo = nuevo;
    }

    void imprimir() const {
        if (!cabeza) {
            std::cout << "Lista Vacía" << std::endl;
            return;
        }
        Nodo* act = cabeza;
        while (act) {
            std::cout << "[" << act->valor << "] -> ";
            act = act->proximo;
        }
        std::cout << "NULL" << std::endl;
    }


    void calcularSumasAcumuladas() {
        if(!cabeza) return;
        Nodo* actual=cabeza;
        while(actual){
            T valoractual = actual->valor;
            if(actual->proximo) actual->proximo->valor += valoractual;
            actual=actual->proximo;
        }
    }
};