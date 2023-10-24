#ifndef AYP2_TP1_SOLUCION_LECTOR_HPP
#define AYP2_TP1_SOLUCION_LECTOR_HPP

#include "Inventario.hpp"

class Lector {
private:
    // Pre: La linea debe tener formato correcto (Nombre_Item,Tipo_Item,Cantidad_Usos).
    // Post: Genera un Item con la informacion y devuelve un puntero.
    static Item* generar_item(std::string linea);

public:
    // Pre: Las lineas del SaveFile deben tener formato correcto.
    // Post: Carga el inventario con los Items del SaveFile.
    static void procesar_archivo(Inventario* inventario, std::string ruta);

    // Pre: -
    // Post: Genera un SaveFile en la ruta especificada.
    static void guardar_items(Lista_de<Item*>& items, std::string ruta);
};

#endif