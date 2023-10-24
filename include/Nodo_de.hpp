#ifndef TDAS_NODO_DE_H
#define TDAS_NODO_DE_H

template<typename T>
class Nodo_de {
private:
    T dato{};
    Nodo_de<T>* anterior;
    Nodo_de<T>* siguiente;
public:
    // Constructor.
    Nodo_de(T dato);

    // Constructor.
    Nodo_de(T dato, Nodo_de<T>* anterior, Nodo_de<T>* siguiente);

    // Pre: -
    // Post: Devuelve un puntero al nodo anterior.
    Nodo_de<T>* obtener_anterior();

    // Pre: -
    // Post: Devuelve un puntero al nodo siguiente.
    Nodo_de<T>* obtener_siguiente();

    // Pre: -
    // Post: Cambia el puntero al nodo anterior.
    void cambiar_anterior(Nodo_de<T>* nuevo);

    // Pre: -
    // Post: Cambia el puntero al nodo siguiente.
    void cambiar_siguiente(Nodo_de<T>* nuevo);

    // Pre: -
    // Post: Devuelve el dato almacenado.
    T obtener_dato();

    // Destructor.
    ~Nodo_de() = default;
};

template<typename T>
Nodo_de<T>::Nodo_de(T dato) {
    this->dato = dato;
    anterior = nullptr;
    siguiente = nullptr;
}

template<typename T>
Nodo_de<T>::Nodo_de(T dato, Nodo_de<T>* anterior, Nodo_de<T>* siguiente) {
    this->dato = dato;
    this->anterior = anterior;
    this->siguiente = siguiente;
}

template<typename T>
Nodo_de<T>* Nodo_de<T>::obtener_anterior() {
    return anterior;
}

template<typename T>
Nodo_de<T>* Nodo_de<T>::obtener_siguiente() {
    return siguiente;
}

template<typename T>
void Nodo_de<T>::cambiar_anterior(Nodo_de<T>* nuevo) {
    anterior = nuevo;
}

template<typename T>
void Nodo_de<T>::cambiar_siguiente(Nodo_de<T>* nuevo) {
    siguiente = nuevo;
}

template<typename T>
T Nodo_de<T>::obtener_dato() {
    return dato;
}

#endif