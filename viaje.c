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
    printf("\n*** ENTRE A registrarViaje ***\n");
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

/* Consultar un viaje */
void consultarViaje()
{
    int codigo;
    Viaje *viaje;

    printf("\n========== CONSULTAR VIAJE ==========\n");

    printf("Ingrese el codigo del viaje: ");
    scanf("%d", &codigo);

    viaje = buscarViaje(raiz, codigo);

    if(viaje == NULL)
    {
        printf("\nNo existe un viaje con ese codigo.\n");
        return;
    }

    printf("\n========== INFORMACION DEL VIAJE ==========\n");
    printf("Codigo del viaje : %d\n", viaje->codigoViaje);
    printf("Codigo destino   : %d\n", viaje->codigoDestino);
    printf("Fecha            : %s\n", viaje->fecha);
    printf("Hora             : %s\n", viaje->hora);
    printf("Capacidad        : %d\n", viaje->capacidad);
}

void mostrarArbol(Viaje *raiz)
{
    if(raiz == NULL)
    {
        return;
    }

    mostrarArbol(raiz->izquierdo);

    printf("\n==============================\n");
    printf("Codigo viaje   : %d\n", raiz->codigoViaje);
    printf("Codigo destino : %d\n", raiz->codigoDestino);
    printf("Fecha          : %s\n", raiz->fecha);
    printf("Hora           : %s\n", raiz->hora);
    printf("Capacidad      : %d\n", raiz->capacidad);

    mostrarArbol(raiz->derecho);
}
    

    
