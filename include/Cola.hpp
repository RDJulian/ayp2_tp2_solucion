#ifndef COLA_HPP
#define COLA_HPP

#include <exception>
#include "Nodo.hpp"

class Cola_exception : public std::exception {
};

template<typename T>
class Cola {
private:
    Nodo<T>* primer_nodo;
    Nodo<T>* ultimo_nodo;
    size_t cantidad_datos;
public:
    // Constructor.
    Cola();

    // Pre: -
    // Post: Agrega el dato al final de la cola.
    void alta(T dato);

    // Pre: La cola no puede estar vacía.
    // Post: Elimina el primer dato.
    T baja();

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el primer dato en la cola.
    T primero();

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el último dato en la cola.
    T ultimo();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la cola.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la cola esta vacía (es decir, si no hay datos).
    bool vacio();

    // El constructor de copia está deshabilitado.
    Cola(const Cola& l) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Cola& l) = delete;

    // Destructor.
    ~Cola();
};

template<typename T>
Cola<T>::Cola() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cantidad_datos = 0;
}

template<typename T>
void Cola<T>::alta(T dato) {
    Nodo<T>* nuevo_nodo = new Nodo<T>(dato);
    if (vacio()) {
        primer_nodo = nuevo_nodo;
    } else {
        ultimo_nodo->cambiar_siguiente(nuevo_nodo);
    }
    ultimo_nodo = nuevo_nodo;
    cantidad_datos++;
}

template<typename T>
T Cola<T>::baja() {
    if (vacio()) {
        throw Cola_exception();
    } else {
        Nodo<T>* nodo_a_eliminar = primer_nodo;
        T dato_a_eliminar = nodo_a_eliminar->obtener_dato();
        if (cantidad_datos == 1) {
            primer_nodo = nullptr;
            ultimo_nodo = nullptr;
        } else {
            primer_nodo = primer_nodo->obtener_siguiente();
        }
        delete nodo_a_eliminar;
        cantidad_datos--;
        return dato_a_eliminar;
    }
}

template<typename T>
T Cola<T>::primero() {
    if (vacio()) {
        throw Cola_exception();
    } else {
        return primer_nodo->obtener_dato();
    }
}

template<typename T>
T Cola<T>::ultimo() {
    if (vacio()) {
        throw Cola_exception();
    } else {
        return ultimo_nodo->obtener_dato();
    }
}

template<typename T>
size_t Cola<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool Cola<T>::vacio() {
    return cantidad_datos == 0;
}

template<typename T>
Cola<T>::~Cola() {
    while (!vacio()) {
        baja();
    }
}

#endif