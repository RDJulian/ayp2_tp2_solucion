#ifndef ITEM_H
#define ITEM_H

#include <string>

const std::string TIPO_PUZZLE = "PUZZLE";
const std::string TIPO_MUNICION = "MUNICION";
const std::string TIPO_CURATIVO = "CURATIVO";

class Item {
private:
    std::string nombre;
    std::string tipo;
    // Otros atributos relacionados al item.

public:
    // Constructor
    Item(std::string nombre, std::string tipo);

    // Constructor default
    Item() = default;

    // Pre:
    // Post: Muestra por pantalla la informacion del item.
    void listar_informacion();

    // Pre:
    // Post: Carga la informacion al stream de salida, con el formato especificado.
    // NOTA: Utilizar este metodo (archivo << item) para cargar la informacion al archivo .csv.
    friend std::ostream& operator<<(std::ostream& os, const Item& item);

    // Pre:
    // Post: Devuelve true si el nombre coincide.
    bool operator==(const std::string& s);

    // Otros metodos relacionados al uso del item.
};

#endif