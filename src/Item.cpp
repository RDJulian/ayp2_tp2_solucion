#include "Item.hpp"
#include <iostream>

Item::Item(std::string nombre, std::string tipo) {
    this->nombre = nombre;
    this->tipo = tipo;
}

void Item::listar_informacion() {
    std::cout << "Nombre: " << nombre << " Tipo: " << tipo;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << item.nombre << ',' << item.tipo;
    return os;
}

bool Item::operator==(const std::string& s) {
    return nombre == s;
}