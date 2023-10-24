#include "Destino.hpp"
#include <iostream>

Destino::Destino() {
    perfil_jugador = NO_DETERMINADO;
}

void Destino::agregar_evento(Evento* evento) {
    eventos.alta(evento);
}

void Destino::determinar_perfil() {
    size_t guardados = 0, aperturas_mapa = 0;
    descolar_eventos(guardados, aperturas_mapa);
    calcular_perfil(guardados, aperturas_mapa);
    std::cout << "Destino definido. El jugador es: " << PERFILES[perfil_jugador] << "." << std::endl;
}

void Destino::descolar_eventos(size_t& guardados, size_t& aperturas_mapa) {
    while (guardados < 8 && !eventos.vacio()) {
        Evento* evento = eventos.baja();
        if (*evento == ACCION_GUARDADO) {
            guardados += 1;
        } else if (*evento == ACCION_APERTURA_MAPA) {
            aperturas_mapa += 1;
        }
        delete evento;
    }
}

void Destino::calcular_perfil(size_t guardados, size_t aperturas_mapa) {
    if (guardados >= 8) {
        perfil_jugador = ASUSTADO;
    } else if (guardados > 5 && guardados > aperturas_mapa) {
        perfil_jugador = PRECAVIDO;
    } else if (aperturas_mapa > 5 && aperturas_mapa > guardados) {
        perfil_jugador = DESORIENTADO;
    } else {
        perfil_jugador = NO_DETERMINADO;
    }
}

Destino::~Destino() {
    while (!eventos.vacio()) {
        delete eventos.baja();
    }
}

void Destino::mostrar_suceso() {
    std::cout << SUCESOS[perfil_jugador] << std::endl;
}