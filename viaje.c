#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "viaje.h"
#include "destino.h"

Viaje *raiz = NULL;

/* Buscar un viaje en el árbol */
Viaje *buscarViaje(Viaje *raiz, int codigoViaje)
{
    if(raiz == NULL)
    {
        return NULL;
    }

    if(codigoViaje == raiz->codigoViaje)
    {
        return raiz;
    }

    if(codigoViaje < raiz->codigoViaje)
    {
        return buscarViaje(raiz->izquierdo, codigoViaje);
    }

    return buscarViaje(raiz->derecho, codigoViaje);
}

/* Insertar un viaje en el árbol */
Viaje *insertarViaje(Viaje *raiz, Viaje *nuevo)
{
    if(raiz == NULL)
    {
        return nuevo;
    }

    if(nuevo->codigoViaje < raiz->codigoViaje)
    {
        raiz->izquierdo = insertarViaje(raiz->izquierdo, nuevo);
    }
    else
    {
        raiz->derecho = insertarViaje(raiz->derecho, nuevo);
    }

    return raiz;
}

/* Registrar un viaje */
void registrarViaje()
{
    Viaje *nuevo;
    int codigoDestino;

    nuevo = (Viaje *)malloc(sizeof(Viaje));

    if(nuevo == NULL)
    {
        printf("\nError al reservar memoria.\n");
        return;
    }

    printf("\n========== REGISTRAR VIAJE ==========\n");

    printf("Codigo del viaje: ");
    scanf("%d", &nuevo->codigoViaje);

    if(buscarViaje(raiz, nuevo->codigoViaje) != NULL)
    {
        printf("\nYa existe un viaje con ese codigo.\n");
        free(nuevo);
        return;
    }

    printf("Codigo del destino: ");
    scanf("%d", &codigoDestino);

    if(buscarDestino(codigoDestino) == NULL)
    {
        printf("\nEl destino no existe.\n");
        free(nuevo);
        return;
    }

    nuevo->codigoDestino = codigoDestino;

    printf("Fecha (dd/mm/aaaa): ");
    scanf(" %14s", nuevo->fecha);

    printf("Hora (hh:mm): ");
    scanf(" %9s", nuevo->hora);

    printf("Capacidad: ");
    scanf("%d", &nuevo->capacidad);

    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;

    raiz = insertarViaje(raiz, nuevo);

    printf("\nViaje registrado correctamente.\n");
}

    

    

    
