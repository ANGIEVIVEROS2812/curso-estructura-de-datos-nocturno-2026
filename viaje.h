#ifndef VIAJE_H
#define VIAJE_H

typedef struct Viaje
{
    int codigoViaje;
    int codigoDestino;
    char fecha[15];
    char hora[10];
    int capacidad;

    struct Viaje *izquierdo;
    struct Viaje *derecho;

} Viaje;

extern Viaje *raiz;

void registrarViaje();
void consultarViaje();
void mostrarArbol(Viaje *raiz);
Viaje *buscarViaje(Viaje *raiz, int codigoViaje);
Viaje *insertarViaje(Viaje *raiz, Viaje *nuevo);
#endif