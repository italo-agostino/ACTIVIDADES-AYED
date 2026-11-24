bool Queue<EventoVehiculo>::revisarRecursivo(int cantidadRestante,
                                            bool hayAnterior,
                                            EventoVehiculo anterior,
                                            bool yaEncontro) {
    // Caso base: ya recorrí y roté todo, devuelvo lo que se acumuló
    if (cantidadRestante < 1) {
        return yaEncontro;
    }

    EventoVehiculo actual = front();
    dequeue();
    enqueue(actual);
    bool duplicadoAqui;
    if(hayAnterior) duplicadoAqui = actual.codigoEvento == anterior.codigoEvento;
    else duplicadoAqui = false;
    return revisarRecursivo(cantidadRestante - 1, true, actual, yaEncontro || duplicadoAqui);
}

bool Queue<EventoVehiculo>::tieneDuplicadosConsecutivosRecursivo() {
    if (size() <= 1) return false;
    return revisarRecursivo(size(), false, EventoVehiculo(), false);
}