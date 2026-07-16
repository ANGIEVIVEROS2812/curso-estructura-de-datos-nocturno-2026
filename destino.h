#ifndef DESTINO_H
#define DESTINO_H

typedef struct Destino
{
    int codigo;

    char nombre[50];

    char empresa[50];

    struct Destino *siguiente;

}Destino;

extern Destino *listaDestinos;

void registrarDestino();

void mostrarDestinos();

Destino *buscarDestino(int codigo);

#endif