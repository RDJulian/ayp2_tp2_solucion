#ifndef DESTINO_H
#define DESTINO_H

#include <string>
#include <Evento.hpp>
#include <Cola.hpp>

const std::string SUCESOS[4] = {"Aumento de factores ambientales.",
                                "Aumento en la cantidad de enemigos.",
                                "Evento Pyramid Head adelantado.",
                                "Comportamiento aun no definido."};
const std::string PERFILES[4] = {"Desorientado",
                                 "Precavido",
                                 "Asustado",
                                 "No determinado"};
const int DESORIENTADO = 0;
const int PRECAVIDO = 1;
const int ASUSTADO = 2;
const int NO_DETERMINADO = 3;


class Destino {
private:
    int perfil_jugador;
    Cola<Evento*> eventos;

    // Pre: -
    // Post: Calcula y asigna el perfil dependiendo de los eventos analizados.
    void calcular_perfil(size_t guardados, size_t aperturas_mapa);

    // Pre: -
    // Post: Descola y cuenta los eventos hasta que se pueda determinar el perfil.
    void descolar_eventos(size_t& guardados, size_t& aperturas_mapa);

public:

    // Constructor.
    Destino();

    // Pre: -
    // Post: Agrega el Evento a los eventos.
    void agregar_evento(Evento* evento);

    // Pre: -
    // Post: Determina el tipo de jugador.
    void determinar_perfil();

    // Pre: -
    // Post: Muestra el suceso a ejecutar, dependiendo del perfil definido.
    void mostrar_suceso();

    // Destructor.
    ~Destino();
};

#endif