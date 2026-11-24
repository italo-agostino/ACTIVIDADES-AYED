//MI IMPLEMENTACION
Cola intercalarColas(Cola& cola1, Cola& cola2) {
    Cola nuevaCola;
    while(!cola1.estaVacia()||!cola2.estaVacia()){
        if (!cola1.estaVacia()) nuevaCola.encolar(cola1.desencolar());
        if (!cola2.estaVacia()) nuevaCola.encolar(cola2.desencolar());
    }
    return nuevaCola;
}