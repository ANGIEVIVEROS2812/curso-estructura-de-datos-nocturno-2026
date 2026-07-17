#include <stdio.h>

#include "menu.h"
#include "destino.h"
#include "pasajero.h"

int main()
{
    int opcion;

    do
    {
        mostrarMenu();
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                registrarDestino();
                break;

            case 2:
                registrarPasajero();
                break;

            case 3:
            printf("\nENTRO A LA OPCION 3\n");
             mostrarPasajerosDestino();
             break;
                
                

            case 4:
                printf("\nRegistrar viaje...\n");
                break;

            case 5:
                printf("\nBuscar viaje...\n");
                break;

            case 6:
                printf("\nMostrar arbol...\n");
                break;

            case 7:
                printf("\nRealizar embarque...\n");
                break;

            case 8:
                printf("\nConsultar pasajero...\n");
                break;

            case 9:
                mostrarDestinos();
                break;

            case 0:
                printf("\nGracias por usar el sistema.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while(opcion != 0);

    return 0;
}