#ifndef AYP2_TP1_SOLUCION_MENU_HPP
#define AYP2_TP1_SOLUCION_MENU_HPP

#include "Inventario.hpp"
#include "Destino.hpp"

class Menu {
private:
    // Pre: -
    // Post: Devuelve un numero al azar entre low y high.
    static int random(int low, int high);

    // Pre: -
    // Post: Genera un Item con nombre y tipo aleatorio.
    static Item* generar_item_aleatorio();

    // Pre -
    // Post: Imprime el menu principal por pantalla.
    static void imprimir_opciones_principal();

    // Pre -
    // Post: Imprime el menu del Inventario por pantalla.
    static void imprimir_opciones_inventario();

    // Pre -
    // Post: Imprime el menu del Destino por pantalla.
    static void imprimir_opciones_destino();

public:
    // Pre: -
    // Post: Ejecuta el menu principal.
    static void ejecutar_menu(Inventario& inventario, Destino& destino);

    // Pre: -
    // Post: Ejecuta el menu del Inventario.
    static void ejecutar_menu(Inventario& inventario);

    // Pre: -
    // Post: Ejecuta el menu del Destino.
    static void ejecutar_menu(Destino& destino);
};

#endif