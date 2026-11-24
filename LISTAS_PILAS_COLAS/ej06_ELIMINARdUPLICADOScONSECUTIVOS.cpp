void eliminarDuplicadosConsecutivos(Pila& miPila){

    if (miPila.estaVacia()) return;

    Pila aux;
    int actual, ultimoApilado;
    while(!miPila.estaVacia()){
        actual=miPila.desapilar();

        if(aux.estaVacia()) {
            aux.apilar(actual);
            ultimoApilado=actual;
        }

        else if(actual!=ultimoApilado){
            aux.apilar(actual);
            ultimoApilado=actual;
        }
    }

    while(!aux.estaVacia()){
        miPila.apilar(aux.desapilar());
    }
}