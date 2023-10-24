#include <iostream>
#include "Inventario.hpp"
#include "Lector.hpp"

Inventario::Inventario() = default;

void Inventario::cargar_inventario(std::string ruta) {
    Lector::procesar_archivo(this, ruta);
}

void Inventario::guardar_inventario(std::string ruta) {
    // Polémico, pero no rompe encapsulamiento. La clase cede voluntariamente un atributo.
    Lector::guardar_items(items, ruta);
}

void Inventario::listar_contenido() {
    for (size_t i = 0; i < items.tamanio(); i++) {
        items.elemento(i)->listar_informacion();
        std::cout << std::endl;
    }
}

void Inventario::eliminar_item(std::string item) {
    size_t i = 0;
    bool eliminado = false;
    while (i < items.tamanio() && !eliminado) {
        if (*items.elemento(i) == item) {
            eliminado = true;
            Item* item_eliminado = items.baja(i);
            delete item_eliminado;
        }
        i++;
    }
}

void Inventario::agregar_item(Item* item) {
    if (items.tamanio() < TAMANIO_MAXIMO) {
        items.alta(item);
    } else {
        std::cout << "El inventario esta lleno." << std::endl;
        delete item;
    }
}

Inventario::~Inventario() {
    for (size_t i = 0; i < items.tamanio(); i++) {
        delete items.elemento(i);
    }
}