#include "Menu.hpp"

/* Dejo como ejercicio para el lector el modificar la clase Menu para que
 * valide las opciones y use un switch (no es para nada fiaca...) */

int main() {
    Inventario inventario;
    Destino destino;
    inventario.cargar_inventario("SaveFile.csv");
    Menu::ejecutar_menu(inventario, destino);
    inventario.guardar_inventario("SaveFile.csv");
    return 0;
}