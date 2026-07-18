#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "destino.h"

Destino *listaDestinos = NULL;

Destino *buscarDestino(int codigo)
{
    Destino *aux = listaDestinos;

    while(aux != NULL)
    {
        if(aux->codigo == codigo)
        {
            return aux;
        }

        aux = aux->siguiente;
    }

    return NULL;
}

void registrarDestino()
{
    Destino *nuevo;
    Destino *aux;
    int codigo;

    printf("\n========== REGISTRAR DESTINO ==========\n");

    printf("Codigo del destino: ");
    scanf("%d", &codigo);

    if(buscarDestino(codigo) != NULL)
    {
        printf("\nError: Ya existe un destino con ese codigo.\n");
        return;
    }

    nuevo = (Destino *)malloc(sizeof(Destino));

    if(nuevo == NULL)
    {
        printf("\nError al reservar memoria.\n");
        return;
    }

    nuevo->codigo = codigo;

    printf("Nombre del destino: ");
    scanf(" %[^\n]", nuevo->nombre);

    printf("Empresa responsable: ");
    scanf(" %[^\n]", nuevo->empresa);

    nuevo->frente = NULL;
    nuevo->final = NULL;
    nuevo->siguiente = NULL;

    if(listaDestinos == NULL)
    {
        listaDestinos = nuevo;
    }
    else
    {
        aux = listaDestinos;

        while(aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }

        aux->siguiente = nuevo;
    }
printf("\nPrueba de la lista:\n");

if(listaDestinos == NULL)
{
    printf("La lista sigue vacia.\n");
}
else
{
    printf("Primer destino: %d - %s\n",
           listaDestinos->codigo,
           listaDestinos->nombre);
}
    printf("\nDestino registrado correctamente.\n");
}

void mostrarDestinos()
{
    Destino *aux = listaDestinos;

    if(aux == NULL)
    {
        printf("\nNo hay destinos registrados.\n");
        return;
    }

    printf("\n========== LISTA DE DESTINOS ==========\n");

    while(aux != NULL)
    {
        printf("\nCodigo : %d\n", aux->codigo);
        printf("Nombre : %s\n", aux->nombre);
        printf("Empresa: %s\n", aux->empresa);

        aux = aux->siguiente;
    }
}