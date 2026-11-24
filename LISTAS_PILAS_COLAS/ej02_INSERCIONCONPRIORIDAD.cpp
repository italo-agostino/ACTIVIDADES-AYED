#include <iostream>
#include <string>

// Plantilla para el Nodo genérico
// Cada nodo almacena un valor de tipo T, una prioridad y un puntero al siguiente.
template <typename T>
struct Nodo {
    T valor;
    int prioridad;
    Nodo<T>* proximo;

    // Constructor para facilitar la creación de nodos
    Nodo(T val, int prio) : valor(val), prioridad(prio), proximo(nullptr) {}
};

// Plantilla para la Lista Enlazada genérica
template <typename T>
class ListaPriorizada {
private:
    Nodo<T>* cabeza; // Puntero al primer nodo de la lista

public:
    // Constructor: inicializa la lista como vacía
    ListaPriorizada() : cabeza(nullptr) {}

    // Destructor: libera toda la memoria asignada dinámicamente
    ~ListaPriorizada() {
        while (cabeza != nullptr) {
            Nodo<T>* nodoAEliminar = cabeza;
            cabeza = cabeza->proximo;
            delete nodoAEliminar;
        }

    }

    /**
     * Inserta un nuevo nodo en la lista según su prioridad.
     *
     * El método ubica el nuevo nodo ANTES del primer nodo que encuentre
     * con una prioridad menor o igual a la prioridad dada.
     * Las prioridades más altas (números mayores) quedan al principio.
     *
     * valor El valor del elemento a insertar.
     * prioridad La prioridad del nuevo elemento.
     */
    void insertar(T valor, int prioridad) {
        Nodo<T>* nuevo= new Nodo<T>(valor, prioridad);
        Nodo<T>* actual= cabeza;
        Nodo<T>* anterior = nullptr;
        while(actual && prioridad < actual->prioridad){
            anterior = actual;
            actual = actual->proximo;
        }
        if(actual){
            if (actual==cabeza){
                nuevo->proximo = cabeza;
                cabeza = nuevo;
            }
            else{
                anterior->proximo = nuevo;
                nuevo->proximo = actual;
            }
        }
        else{
            if(anterior){
                anterior->proximo = nuevo;
            }
            else{cabeza=nuevo;}
            nuevo->proximo = nullptr;
        }
    }

    // Método para imprimir la lista completa y ver su estado
    void imprimir() const {
        if (cabeza == nullptr) {
            std::cout << "La lista está vacía." << std::endl;
            return;
        }

        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            std::cout << "(Valor: " << actual->valor << ", Prio: " << actual->prioridad << ") -> ";
            actual = actual->proximo;
        }
        std::cout << "NULL" << std::endl;
    }
};
