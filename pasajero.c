#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pasajero.h"
#include "destino.h"

Pasajero *buscarPasajero(Pasajero *frente, int documento)
{
    Pasajero *aux = frente;

    while(aux != NULL)
    {
        if(aux->documento == documento)
        {
            return aux;
        }

        aux = aux->siguiente;
    }

    return NULL;
}

void registrarPasajero()
{
    Pasajero *nuevo;
    Pasajero *existe;
    Destino *destino;
    int codigoDestino;

    printf("\n========== REGISTRAR PASAJERO ==========\n");

    printf("Codigo del destino: ");
    scanf("%d", &codigoDestino);

    destino = buscarDestino(codigoDestino);

    if(destino == NULL)
    {
        printf("\nEl destino no existe.\n");
        return;
    }

    nuevo = (Pasajero *)malloc(sizeof(Pasajero));

    if(nuevo == NULL)
    {
        printf("\nError al reservar memoria.\n");
        return;
    }

    printf("Documento: ");
    scanf("%d", &nuevo->documento);

    existe = buscarPasajero(destino->frente, nuevo->documento);

    if(existe != NULL)
    {
        printf("\nError: Ya existe un pasajero con ese documento.\n");
        free(nuevo);
        return;
    }

    printf("Nombre: ");
    scanf(" %[^\n]", nuevo->nombre);

    printf("Edad: ");
    scanf("%d", &nuevo->edad);

    printf("\nTipo de documento\n");
    printf("1. Cedula\n");
    printf("2. Tarjeta de Identidad\n");
    printf("3. Pasaporte\n");
    printf("Seleccione: ");
    scanf("%d", &nuevo->tipoDocumento);

    nuevo->siguiente = NULL;

    if(destino->frente == NULL)
    {
        destino->frente = nuevo;
        destino->final = nuevo;
    }
    else
    {
        destino->final->siguiente = nuevo;
        destino->final = nuevo;
    }

    printf("\nPasajero registrado correctamente.\n");
    printf("Direccion frente: %p\n", (void *)destino->frente);
    printf("Direccion final : %p\n", (void *)destino->final);
}

void mostrarPasajerosDestino()
{
    int codigoDestino;
    Destino *destino;
    Pasajero *aux;

    printf("\n========== PASAJEROS DEL DESTINO ==========\n");

    printf("Codigo del destino: ");
    scanf("%d", &codigoDestino);

    printf("\nBuscando destino %d...\n", codigoDestino);

    destino = buscarDestino(codigoDestino);

    if(destino == NULL)
    {
        printf("\nERROR: El destino no existe.\n");
        return;
    }

    printf("\nDestino encontrado: %s\n", destino->nombre);
     printf("Direccion frente: %p\n", (void *)destino->frente);
printf("Direccion final : %p\n", (void *)destino->final);
    aux = destino->frente;

    if(aux == NULL)
    {
        printf("\nERROR: No hay pasajeros registrados en este destino.\n");
        return;
    }

    printf("\nMostrando pasajeros...\n");

    while(aux != NULL)
    {
        printf("\nDocumento : %d\n", aux->documento);
        printf("Nombre    : %s\n", aux->nombre);
        printf("Edad      : %d\n", aux->edad);

        aux = aux->siguiente;
    }
}
void consultarPasajero()
{
    int documento;
    Destino *destino;
    Pasajero *pasajero;

    printf("\n========== CONSULTAR PASAJERO ==========\n");

    printf("Documento del pasajero: ");
    scanf("%d", &documento);

    destino = listaDestinos;

    while(destino != NULL)
    {
        pasajero = buscarPasajero(destino->frente, documento);

        if(pasajero != NULL)
        {
            printf("\n========== PASAJERO ENCONTRADO ==========\n");
            printf("Documento : %d\n", pasajero->documento);
            printf("Nombre    : %s\n", pasajero->nombre);
            printf("Edad      : %d\n", pasajero->edad);
            printf("Tipo Doc. : %d\n", pasajero->tipoDocumento);
            printf("Destino   : %s\n", destino->nombre);
            return;
        }

        destino = destino->siguiente;
    }

    printf("\nNo existe un pasajero con ese documento.\n");
}