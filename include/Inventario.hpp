#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.hpp"
#include "Lista_de.hpp"

const size_t TAMANIO_MAXIMO = 15;

class Inventario {
private:
    Lista_de<Item*> items;
public:
    // Constructor
    Inventario();

    // Pre: Las lineas del SaveFile deben tener formato correcto.
    // Post: Carga el inventario con los Items del SaveFile.
    void cargar_inventario(std::string ruta);

    // Pre: -
    // Post: Genera un SaveFile en la ruta especificada.
    void guardar_inventario(std::string ruta);

    // Pre: -
    // Post: Lista el contenido del inventario por pantalla.
    void listar_contenido();

    // Pre: -
    // Post: Elimina el item deseado (en caso de existir).
    void eliminar_item(std::string item);

    // Pre: -
    // Post: Agrega el Item al inventario.
    void agregar_item(Item* item);

    // Destructor. NOTA: Elimina la memoria de los Items por ser la clase encargada de manejarla.
    ~Inventario();
};

#endif