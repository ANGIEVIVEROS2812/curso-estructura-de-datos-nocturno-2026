#ifndef PASAJERO_H
#define PASAJERO_H


typedef struct Pasajero
{
    int documento;
    char nombre[50];
    int edad;
    int tipoDocumento;

    struct Pasajero *siguiente;

} Pasajero;

void registrarPasajero();
void mostrarPasajerosDestino();
void consultarPasajero();
Pasajero *buscarPasajero(Pasajero *frente, int documento);

#endif

