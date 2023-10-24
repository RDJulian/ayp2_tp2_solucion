#include "Lector.hpp"
#include <fstream>
#include <sstream>

Item* Lector::generar_item(std::string linea) {
    Item* item = nullptr;
    std::string nombre, tipo;
    std::stringstream linea_stream(linea);

    getline(linea_stream, nombre, ',');
    getline(linea_stream, tipo);

    if (tipo == TIPO_CURATIVO || tipo == TIPO_PUZZLE || tipo == TIPO_MUNICION) {
        item = new Item(nombre, tipo);
    }
    return item;
}

void Lector::procesar_archivo(Inventario* inventario, std::string ruta) {
    Item* item;
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        // Puede hacer otra cosa.
        return;
    } else {
        std::string linea;
        while (getline(archivo, linea)) {
            item = generar_item(linea);
            if (item) {
                inventario->agregar_item(item);
            }
        }
        archivo.close();
    }
}

// Este método esta altamente acoplado al Inventario, pero funciona para este TP.
void Lector::guardar_items(Lista_de<Item*>& items, std::string ruta) {
    std::ofstream archivo(ruta);
    for (size_t i = 0; i < items.tamanio(); i++) {
        archivo << *items.elemento(i) << std::endl;
    }
    archivo.close();
}