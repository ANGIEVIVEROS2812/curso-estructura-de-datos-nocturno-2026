#ifndef DESTINO_H
#define DESTINO_H

#include "pasajero.h"

typedef struct Destino
{
    int codigo;
    char nombre[50];
    char empresa[50];

    Pasajero *frente;
    Pasajero *final;

    struct Destino *siguiente;

} Destino;

extern Destino *listaDestinos;

void registrarDestino();
void mostrarDestinos();
Destino *buscarDestino(int codigo);

#endif