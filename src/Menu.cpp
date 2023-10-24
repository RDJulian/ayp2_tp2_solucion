#include "Menu.hpp"
#include <random>
#include <iostream>

// Ignorar. Genero un Item al azar para no perder tiempo codeando interaccion con el usuario.
std::random_device rd;
std::mt19937 gen(rd());

int Menu::random(int low, int high) {
    std::uniform_int_distribution<> dist(low, high);
    return (dist(gen));
}

Item* Menu::generar_item_aleatorio() {
    Item* item;
    int r1 = random(0, 2);
    int r2 = random(1, 99);
    switch (r1) {
        case 0: {
            item = new Item("ItemTest" + std::to_string(r2), TIPO_PUZZLE);
            break;
        }
        case 1: {
            item = new Item("ItemTest" + std::to_string(r2), TIPO_MUNICION);
            break;
        }
        default: {
            item = new Item("ItemTest" + std::to_string(r2), TIPO_CURATIVO);
            break;
        }
    }
    return item;
}

// Solución a partir de aca.
void Menu::imprimir_opciones_principal() {
    std::cout << "1: Usar el Inventario." << std::endl;
    std::cout << "2: Usar el Destino." << std::endl;
    std::cout << "3: Salir." << std::endl;
}

void Menu::imprimir_opciones_inventario() {
    std::cout << "1: Listar contenido." << std::endl;
    std::cout << "2: Usar un Item." << std::endl;
    std::cout << "3: Agregar un Item al Inventario." << std::endl;
    std::cout << "4: Salir." << std::endl;
}


void Menu::imprimir_opciones_destino() {
    std::cout << "1: Agregar evento Guardado." << std::endl;
    std::cout << "2: Agregar evento Apertura de Mapa." << std::endl;
    std::cout << "3: Definir destino." << std::endl;
    std::cout << "4: Mostrar suceso." << std::endl;
    std::cout << "5: Salir." << std::endl;
}

void Menu::ejecutar_menu(Inventario& inventario, Destino& destino) {
    std::string opcion;
    while (opcion != "3") {
        imprimir_opciones_principal();
        std::cout << "Ingrese una opcion" << std::endl;
        std::cin >> opcion;
        if (opcion == "1") {
            ejecutar_menu(inventario);
        } else if (opcion == "2") {
            ejecutar_menu(destino);
        } else if (opcion != "3") {
            std::cout << "Opcion incorrecta. Ingrese nuevamente." << std::endl;
        }
        std::cout << std::endl;
    }
}

void Menu::ejecutar_menu(Inventario& inventario) {
    std::string opcion, nombre;
    while (opcion != "4") {
        imprimir_opciones_inventario();
        std::cout << "Ingrese una opcion: ";
        getline(std::cin >> std::ws, opcion);
        std::cout << std::endl;
        if (opcion == "1") {
            inventario.listar_contenido();
        } else if (opcion == "2") {
            std::cout << "Ingrese el nombre del Item a eliminar: ";
            getline(std::cin >> std::ws, nombre);
            inventario.eliminar_item(nombre);
        } else if (opcion == "3") {
            // Tomar entrada del Usuario.
            Item* item = generar_item_aleatorio();
            inventario.agregar_item(item);
        } else if (opcion != "4") {
            std::cout << "Opcion incorrecta. Ingrese nuevamente." << std::endl;
        }
        std::cout << std::endl;
    }
}

void Menu::ejecutar_menu(Destino& destino) {
    std::string opcion;
    while (opcion != "5") {
        imprimir_opciones_destino();
        std::cout << "Ingrese una opcion" << std::endl;
        std::cin >> opcion;
        if (opcion == "1") {
            Evento* evento = new Evento(ACCION_GUARDADO);
            destino.agregar_evento(evento);
        } else if (opcion == "2") {
            Evento* evento = new Evento(ACCION_APERTURA_MAPA);
            destino.agregar_evento(evento);
        } else if (opcion == "3") {
            destino.determinar_perfil();
        } else if (opcion == "4") {
            destino.mostrar_suceso();
        } else if (opcion != "5") {
            std::cout << "Opcion incorrecta. Ingrese nuevamente." << std::endl;
        }
        std::cout << std::endl;
    }
}