#include <iostream>
#include <string>

// Nodo genérico para lista enlazada simple
template <typename T>
struct Nodo {
    T valor;
    Nodo<T>* proximo;

    explicit Nodo(const T& v) : valor(v), proximo(nullptr) {}
};

// Lista enlazada genérica
template <typename T>
class Lista {
private:
    Nodo<T>* cabeza;

    // (Opcional) Función auxiliar recursiva sugerida:
    // Devuelve true si la sublista que comienza en 'nodo' está ordenada (no-decreciente).
    bool estaOrdenadaRec(Nodo<T>* n) const{
        if(!n||!n->proximo){return true;}
        else{
            if (n->valor <= n->proximo->valor){
                return estaOrdenadaRec(n->proximo);
            }else return false;
        }
    }

public:
    Lista() : cabeza(nullptr) {}

    ~Lista() {
        while (cabeza) {
            Nodo<T>* e = cabeza;
            cabeza = cabeza->proximo;
            delete e;
        }
    }

    // Inserta al final para facilitar pruebas
    void insertarAlFinal(const T& v) {
        Nodo<T>* nuevo = new Nodo<T>(v);
        if (!cabeza) { cabeza = nuevo; return; }
        Nodo<T>* it = cabeza;
        while (it->proximo) it = it->proximo; // <- este bucle es solo para construir la lista
        it->proximo = nuevo;
    }

    // MI IMPLEMENTACION
    bool estaOrdenada() const {
        return estaOrdenadaRec(cabeza);
    }

    void imprimir() const {
        const Nodo<T>* it = cabeza;
        while (it) {
            std::cout << it->valor << " -> ";
            it = it->proximo;
        }
        std::cout << "NULL\n";
    }
};
