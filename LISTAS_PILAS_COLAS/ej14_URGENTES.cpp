#include <iostream>
#include <queue>

struct Tarea {
    int codigo;
    int urgencia;
};

class ColaDeTareasUrgentes : public std::queue<Tarea> {

public:
    /*
    Implementaciones hechas por mi:
    "contarUrgentesRecursivo"
    "obtenerPrimerUrgenteIterativo"
     */
    int contarUrgentesRecursivo(int nivelUrgencia) {
        return auxiliarContar(*this, nivelUrgencia);
    }
    int obtenerPrimerUrgenteIterativo(int nivelUrgencia){
        Tarea devuelvo;
        std::queue<Tarea> colaTemp;
        bool encontrada = false;
        while (!this->empty()){
            Tarea actual = this->front();
            this->pop();
            if(!encontrada && actual.urgencia >= nivelUrgencia){
                devuelvo = actual;
                encontrada=true;
            }
            colaTemp.push(actual);
        }
        while(!colaTemp.empty()){
            this->push(colaTemp.front());
            colaTemp.pop();
        }
        if (encontrada) return devuelvo.codigo;
        return -1;
    }

private:

    int auxiliarContar(std::queue<Tarea> cola, int nivelUrgencia) {
        //  Si la cola es vacia, devuelvo 0
        if (cola.empty()) return 0;
        //caso recursivo
        //  Si no esta vacia, comparo su valor con nivelurgencia,
        //si es asi, devuelvo 1+contarUrgentesRecursivo(cola,nivelUrgencia)
        Tarea tareaActual = cola.front();
        cola.pop();
        int resultado=0;
        if (tareaActual.urgencia >= nivelUrgencia){
            resultado = 1 + auxiliarContar(cola, nivelUrgencia);
        }else{
            resultado = auxiliarContar(cola, nivelUrgencia);
        }
        cola.push(tareaActual);
        return resultado;
    }

public:

    void agregarTarea(int codigo, int urgencia) {
        this->push({codigo, urgencia});
    }
};

