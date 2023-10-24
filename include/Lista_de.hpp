#ifndef TDAS_LISTA_DE_H
#define TDAS_LISTA_DE_H

#include <exception>
#include <cstdlib>
#include "Nodo_de.hpp"

class Lista_exception : public std::exception {
};

template<typename T>
class Lista_de {
private:
    Nodo_de<T>* primer_nodo;
    Nodo_de<T>* ultimo_nodo;
    Nodo_de<T>* cursor;
    // Nota: puede ser que no utilicen el indice.
    int indice_cursor;
    size_t cantidad_datos;

    // Pre: El indice debe ser menor que la cantidad de datos.
    // Post: Devuelve un puntero al nodo asociado al indice deseado.
    Nodo_de<T>* obtener_nodo(size_t indice);

public:
    // Constructor.
    Lista_de();

    // Pre: -
    // Post: Agrega el dato al final de la lista.
    void alta(T dato);

    // Pre: La lista no puede estar vacia.
    // Post: Elimina el ultimo dato.
    // NOTA: Considerar que se puede dar de baja el nodo cursor.
    T baja();

    // Pre: El indice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posicion indicada.
    // Si el indice es igual a la cantidad de datos, simplemente agrega al final.
    void alta(T dato, size_t indice);

    // Pre: El indice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posicion indicada.
    // Si el indice es igual a la cantidad de datos - 1, simplemente elimina el ultimo dato.
    // NOTA: Considerar que se puede dar de baja el nodo cursor.
    T baja(size_t indice);

    // Pre: La lista no puede estar vacia.
    // Post: Devuelve el primer dato en la lista.
    T primero();

    // Pre: La lista no puede estar vacia.
    // Post: Devuelve el último dato en la lista.
    T ultimo();

    // Pre: El indice debe ser menor que la cantidad de datos.
    // Post: Devuelve el dato en la posicion deseada.
    T elemento(size_t indice);

    // Pre: -
    // Post: Devuelve true si se puede avanzar (esto es, que el cursor no sea nullptr).
    bool puede_avanzar();

    // Pre: Se debe poder avanzar.
    // Post: Devuelve el dato del cursor actual y luego lo mueve una posición en la dirección deseada.
    T avanzar(bool siguiente);

    // Pre: -
    // Post: Reinicia el cursor al principio o al final, según lo indicado.
    // Si la lista está vacia, se reinicia el cursor al estado inicial
    // (esto es, cursor == nullptr e indice_cursor == -1).
    void reiniciar_cursor(bool principio);

    // Pre: -
    // Post: Devuelve la cantidad de datos de la lista.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la lista esta vacia (es decir, si no hay datos).
    bool vacio();

    // El constructor de copia está deshabilitado.
    Lista_de(const Lista_de& l) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Lista_de& l) = delete;

    // Destructor.
    ~Lista_de();
};

template<typename T>
Lista_de<T>::Lista_de() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cursor = nullptr;
    indice_cursor = -1;
    cantidad_datos = 0;
}

template<typename T>
Nodo_de<T>* Lista_de<T>::obtener_nodo(size_t indice) {
    if (indice >= cantidad_datos) {
        throw Lista_exception();
    }
    if (indice == cantidad_datos - 1) {
        reiniciar_cursor(false);
    } else if (indice == 0) {
        reiniciar_cursor(true);
    } else {
        // Calculo los pasos (iteraciones) desde cada puntero disponible.
        bool primero = false;
        int pasos, pasos_cabecera, pasos_cursor;
        pasos_cursor = (int) (indice) - indice_cursor;
        if (indice <= cantidad_datos / 2) {
            pasos_cabecera = (int) indice;
            primero = true;
        } else {
            pasos_cabecera = (int) (indice) - ((int) (cantidad_datos) - 1);
        }
        // Reviso la forma mas eficaz.
        if (abs(pasos_cabecera) < abs(pasos_cursor)) {
            reiniciar_cursor(primero);
            pasos = pasos_cabecera;
        } else {
            pasos = pasos_cursor;
        }
        // Recorre.
        for (int i = 0; i < abs(pasos); i++) {
            avanzar(pasos >= 0);
        }
    }
    return cursor;
}

template<typename T>
void Lista_de<T>::alta(T dato) {
    Nodo_de<T>* nuevo;
    if (vacio()) {
        nuevo = new Nodo_de<T>(dato);
        primer_nodo = nuevo;
        ultimo_nodo = nuevo;
    } else {
        nuevo = new Nodo_de<T>(dato, ultimo_nodo, nullptr);
        ultimo_nodo->cambiar_siguiente(nuevo);
        ultimo_nodo = nuevo;
    }
    cantidad_datos++;
    // No es necesario corregir el cursor.
}

template<typename T>
T Lista_de<T>::baja() {
    if (vacio()) {
        throw Lista_exception();
    }
    T dato = ultimo_nodo->obtener_dato();
    if (cantidad_datos == 1) {
        delete ultimo_nodo;
        primer_nodo = nullptr;
        ultimo_nodo = nullptr;
        cursor = nullptr;
        indice_cursor = -1;
    } else {
        Nodo_de<T>* baja = ultimo_nodo;
        ultimo_nodo = baja->obtener_anterior();
        ultimo_nodo->cambiar_siguiente(nullptr);
        // Es necesario corregir el cursor. Si el nodo a eliminar
        // coincide con el cursor, es necesario setearlo a nullptr.
        if (cursor == baja) {
            cursor = nullptr;
        }
        delete baja;
    }
    cantidad_datos--;
    return dato;
}

template<typename T>
void Lista_de<T>::alta(T dato, size_t indice) {
    if (indice > cantidad_datos) {
        throw Lista_exception();
    }
    if (indice == cantidad_datos) {
        alta(dato);
        return;
    } else {
        Nodo_de<T>* nuevo;
        if (indice == 0) {
            nuevo = new Nodo_de<T>(dato, nullptr, primer_nodo);
            primer_nodo->cambiar_anterior(nuevo);
            primer_nodo = nuevo;
        } else {
            Nodo_de<T>* aux = obtener_nodo(indice);
            nuevo = new Nodo_de<T>(dato, aux->obtener_anterior(), aux);
            nuevo->obtener_anterior()->cambiar_siguiente(nuevo);
            nuevo->obtener_siguiente()->cambiar_anterior(nuevo);
        }
        cantidad_datos++;
        // Es necesario corregir el cursor.
        // Si no se agrega al final, siempre se mueve una posición "a la derecha".
        indice_cursor++;
    }
}

template<typename T>
T Lista_de<T>::baja(size_t indice) {
    if (indice >= cantidad_datos) {
        throw Lista_exception();
    }
    if (indice == cantidad_datos - 1) {
        return this->baja();
    } else {
        T dato;
        Nodo_de<T>* baja;
        if (indice == 0) {
            baja = primer_nodo;
            primer_nodo = baja->obtener_siguiente();
            primer_nodo->cambiar_anterior(nullptr);
            // Es necesario corregir el cursor. Si se elimina al principio,
            // el cursor siempre se mueve uno "a la izquierda". Si el nodo a eliminar
            // coincide con el cursor, es necesario setearlo a nullptr.
            if (cursor == baja) {
                cursor = nullptr;
            }
            indice_cursor--;
        } else {
            baja = obtener_nodo(indice);
            baja->obtener_siguiente()->cambiar_anterior(baja->obtener_anterior());
            baja->obtener_anterior()->cambiar_siguiente(baja->obtener_siguiente());
            // Es necesario corregir el cursor. Se reasigna porque
            // el cursor actual es el nodo a eliminar. El nodo que va a ocupar
            // el indice va a ser el siguiente al eliminado.
            cursor = baja->obtener_siguiente();
        }
        dato = baja->obtener_dato();
        delete baja;
        cantidad_datos--;
        return dato;
    }
}

template<typename T>
T Lista_de<T>::primero() {
    if (vacio()) {
        throw Lista_exception();
    }
    return primer_nodo->obtener_dato();
}

template<typename T>
T Lista_de<T>::ultimo() {
    if (vacio()) {
        throw Lista_exception();
    }
    return ultimo_nodo->obtener_dato();
}

template<typename T>
T Lista_de<T>::elemento(size_t indice) {
    if (indice >= cantidad_datos) {
        throw Lista_exception();
    }
    return obtener_nodo(indice)->obtener_dato();
}

template<typename T>
size_t Lista_de<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool Lista_de<T>::vacio() {
    return cantidad_datos == 0;
}

template<typename T>
void Lista_de<T>::reiniciar_cursor(bool principio) {
    if (vacio()) {
        cursor = nullptr;
        indice_cursor = -1;
    } else {
        if (principio) {
            cursor = primer_nodo;
            indice_cursor = 0;
        } else {
            cursor = ultimo_nodo;
            indice_cursor = (int) (cantidad_datos) - 1;
        }
    }
}

template<typename T>
bool Lista_de<T>::puede_avanzar() {
    return cursor;
}

template<typename T>
T Lista_de<T>::avanzar(bool siguiente) {
    if (!puede_avanzar()) {
        throw Lista_exception();
    }
    T dato = cursor->obtener_dato();
    if (siguiente) {
        cursor = cursor->obtener_siguiente();
        indice_cursor++;
    } else {
        cursor = cursor->obtener_anterior();
        indice_cursor--;
    }
    return dato;
}

template<typename T>
Lista_de<T>::~Lista_de() {
    while (!vacio()) {
        baja();
    }
}

#endif