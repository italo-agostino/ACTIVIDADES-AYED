#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Cola {
private:
    // Nodo interno de la cola
    struct Nodo {
        T valor;
        Nodo* proximo;
        Nodo(T val) : valor(val), proximo(nullptr) {}
    };

    Nodo* frente; // Puntero al primer elemento
    Nodo* final;  // Puntero al último elemento

public:
    Cola() : frente(nullptr), final(nullptr) {}

    ~Cola() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    bool estaVacia() const {
        return frente == nullptr;
    }
    /*
    Implementaciones hechas por mi
    encolar
    desencolar
    obtenerFrente
    obtenerFondo
    */
    void desencolar() {
        if (estaVacia()) return;
        Nodo* nodoAEliminar = frente;
        frente = frente->proximo;
        delete nodoAEliminar;
        if (frente == nullptr) {
            final = nullptr;
        }
    }

    T obtenerFrente() const {
        if (estaVacia()) {
            throw std::runtime_error("La cola está vacía");
        }
        return frente->valor;
    }

    T obtenerFondo() const {
        if (estaVacia()) {
            throw std::runtime_error("La cola está vacía");
        }
        return final->valor;
    }

    // Método para visualizar la cola
    void imprimir() const {
        if (estaVacia()) {
            std::cout << "COLA VACÍA" << std::endl;
            return;
        }
        Nodo* actual = frente;
        std::cout << "Frente -> ";
        while (actual != nullptr) {
            std::cout << "[" << actual->valor << "] ";
            actual = actual->proximo;
        }
        std::cout << "<- Final" << std::endl;
    }

    void encolar(const T& valor) {
        Nodo* actual = frente;
        Nodo* anterior = nullptr;
        while (actual && actual->valor != valor) {
            anterior = actual;
            actual = actual->proximo;
        }

        if (actual) {
            if (actual == final) {
                return; // ya está al final, no hay que hacer nada
            }
            // el resto sigue igual: desconexión + reconexión
            if (anterior) {
                anterior->proximo = actual->proximo;
            } else {
                frente = actual->proximo;
            }
            final->proximo = actual;
            final = actual;
            actual->proximo = nullptr;
        }else {
            if(anterior){
                //estoy al final de la cola y el valor no esta
                Nodo* nuevo = new Nodo(valor);
                final -> proximo=nuevo;
                final = nuevo;
            }else{
                //cola vacia
                Nodo* nuevo = new Nodo(valor);
                frente = nuevo;
                final = nuevo;
            }
        }
    }
};
