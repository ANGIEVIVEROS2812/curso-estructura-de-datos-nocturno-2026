#include <stdio.h>

#include "menu.h"
#include "destino.h"
#include "pasajero.h"
#include "viaje.h"
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
              registrarViaje();
              break;
                


            case 5:
              consultarViaje();
              break;
                
                

            case 6:
              printf("\n========== ARBOL DE VIAJES ==========\n");
               mostrarArbol(raiz);
                break;
                
                

            case 7:
               realizarEmbarque();
                break;
                
                

            case 8:
              consultarPasajero();
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