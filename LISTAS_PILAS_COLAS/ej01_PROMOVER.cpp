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

    // Agrega un elemento al final de la cola
    void encolar(T valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (estaVacia()) {
            frente = final = nuevoNodo;
        } else {
            final->proximo = nuevoNodo;
            final = nuevoNodo;
        }
    }

    // Quita el elemento del frente de la cola
    void desencolar() {
        if (estaVacia()) {
            return; // No hace nada si está vacía
        }
        Nodo* nodoAEliminar = frente;
        frente = frente->proximo;
        delete nodoAEliminar;
        if (frente == nullptr) {
            final = nullptr; // La cola quedó vacía
        }
    }

    // Retorna el valor del elemento del frente
    T obtenerFrente() const {
        if (estaVacia()) {
            throw std::runtime_error("La cola está vacía");
        }
        return frente->valor;
    }

    // Retorna el valor del elemento del fondo
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

    // ===============================================
    // TU TAREA: IMPLEMENTA EL SIGUIENTE MÉTODO
    // ===============================================
    bool promover(T valor) {
        Nodo* anterior = nullptr;
        Nodo* actual = frente;
        while (actual != nullptr && actual->valor != valor){
            anterior = actual;
            actual = actual->proximo;
        }
        //actual es nullptr cuando ya recorrio toda la cola y no esta el valor buscado
        //si actual contiene el calor que buscamos, se ejecuta el if
        if (actual && actual->valor==valor){
            //anterior es nullptr si actual es frente
            //si actual es frente, anterior debe apuntar
                if(anterior){
                    if (actual==final){
                        //el nuevo final es el anterior del nodo actual
                        final = anterior;
                        anterior->proximo = nullptr;
                    }
                    else{
                    //el puntero de anterior apunta al puntero de actual
                    anterior->proximo = actual->proximo;
                    }
                }
                //si actual es frente, no se debe mover, ya que al "promover" movemos el nodo al frente
                if(actual!=frente){
                    if (actual==final){
                        //el nuevo final es el anterior del nodo actual
                        final = anterior;
                    }
                        //el puntero apunta al primero de la cola
                        actual->proximo = frente;
                        //ahora el frente pasa a apuntar al nodo actual
                        frente = actual;
                }
                return true;
            }
        return false; // Placeholder
    }
};