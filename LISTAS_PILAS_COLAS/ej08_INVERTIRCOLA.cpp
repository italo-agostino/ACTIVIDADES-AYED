void invertirCola(Cola& miCola) {
    //si la cola esta vacia, return
    //si la cola tiene algun nodo al frente, lo quito y lo mando a la fila
    Pila miPila;
    while(!miCola.estaVacia()){
        miPila.apilar(miCola.desencolar());
    }
    while(!miPila.estaVacia()){
        miCola.encolar(miPila.desapilar());
    }
}