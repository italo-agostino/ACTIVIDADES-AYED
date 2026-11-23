#include <iostream>
#include <limits> // Para std::numeric_limits

// Estructura para representar un nodo del ABB
struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    // Constructor de Nodo
    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

// Clase para representar el Árbol Binario de Búsqueda (ABB)
class ABB {
public:
    Nodo* raiz;

    // Constructor del ABB
    ABB() : raiz(nullptr) {}

    // Destructor del ABB para liberar la memoria
    ~ABB() {
        destruirArbol(raiz);
    }

    // Función auxiliar recursiva para liberar la memoria de los nodos
    void destruirArbol(Nodo* nodo) {
        if (nodo) {
            destruirArbol(nodo->izquierda);
            destruirArbol(nodo->derecha);
            delete nodo;
        }
    }
    // MIS 3 IMPLEMENTACIONES SON "insertar", "insertarRecursivo", "encontrarMinimo", "encontrarMaximo"
    // --- 1. Inserción de un nuevo valor en el ABB ---
    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    // Función auxiliar recursiva para insertar un valor
    Nodo* insertarRecursivo(Nodo* nodo, int valor) {
        // Si el subárbol está vacío, creamos un nuevo nodo aquí
        if (nodo == nullptr) {
            return new Nodo(valor);
        }

        // Si el valor es menor, vamos a la izquierda
        if (valor < nodo->valor) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        }
        // Si el valor es mayor, vamos a la derecha
        else if (valor > nodo->valor) {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        }
        // Si el valor es igual, ya existe y no lo insertamos (no permitimos duplicados)
        return nodo; // Retorna el nodo actual sin cambios si es un duplicado
    }

    // --- 2. Encontrar el valor mínimo en el ABB ---
    int encontrarMinimo() {
        if (raiz==nullptr) {
            std::cout << "Error: El arbol esta vacio. No se puede encontrar el valor minimo." << std::endl;
            return -1;
        }
        Nodo* nodo=raiz;
        int min=nodo->valor;
        while(nodo->izquierda){
            min=nodo->izquierda->valor;
            nodo=nodo->izquierda;
        }
        return min;
    }

    // --- 3. Encontrar el valor máximo en el ABB ---
    int encontrarMaximo() {
        if (raiz==nullptr) {
            std::cout << "Error: El arbol esta vacio. No se puede encontrar el valor maximo."<<std::endl;
            return -1;
        }
        Nodo* nodo=raiz;
        int max=nodo->valor;
        while(nodo->derecha){
            max=nodo->derecha->valor;
            nodo=nodo->derecha;
        }
        return max;
    }

    // Función auxiliar para imprimir el árbol en orden (opcional, para verificación)
    void recorrerInorden() {
        std::cout << "Elementos del ABB (Inorden): ";
        recorrerInordenRecursivo(raiz);
        std::cout << std::endl;
    }

    void recorrerInordenRecursivo(Nodo* nodo) {
        if(nodo==nullptr) return;
        recorrerInordenRecursivo(nodo->izquierda);
        std::cout << nodo->valor << " ";
        recorrerInordenRecursivo(nodo->derecha);
    }
};