// Implementaciones hechas por mi:
"minNode", "maxNode"
template <class T>
const Nodo<T>* ABB<T>::minNode(const Nodo<T>* p) const{
    if(!p) throw std::runtime_error("ABB vacio");
    if(p->izq) return minNode(p->izq);
    return p;
}

template <class T>
const Nodo<T>* ABB<T>::maxNode(const Nodo<T>* p) const{
    if(!p) throw std::runtime_error("ABB vacio");
    if(p->der) return maxNode(p->der);
    return p;
}

// Wrappers públicos que devuelven referencias a T
template <class T>
const T& ABB<T>::min() const{
    const Nodo<T>* minimo = minNode(raiz);
    return minimo->dato;
}

template <class T>
const T& ABB<T>::max() const{
    const Nodo<T>* maximo = maxNode(raiz);
    return maximo->dato;
}
