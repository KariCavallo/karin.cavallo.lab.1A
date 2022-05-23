#include "viaje.h"
#include "destino.h"
#include "empresa.h"
#include "fecha.h"
#include "micro.h"
#include "tipo.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>


int inicializarViaje(eViaje vec[], int tamv)
{
    int todoOk = 0;
    if(vec != NULL && tamv > 0)
    {
        for(int i=0; i < tamv; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}




int buscarViajeLibre(eViaje vec[], int tamv, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tamv > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tamv; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaViaje(eViaje vec[], int tamv, eMicro micro[], int tamm, eEmpresa empresa[], int tam, eTipo tipo[],eDestino destino[], int* pIdViaje, int* pFLagViaje, eChofer chofer[])
{
    int todoOk = 0;
    int indice;
    eViaje nuevoViaje;
    eFecha fecha;

    if(vec != NULL && tamv > 0 && pIdViaje != NULL)
    {
        if( buscarViajeLibre(vec, tamv, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {


                listarMicro( micro,tamm,empresa, tipo, tam, chofer);

                printf("Ingrese el id del micro: ");
                 scanf("%d", &nuevoViaje.idMicro);

                while( !validarMicro(micro, tamm, nuevoViaje.idMicro))
                {
                     printf("Error, reingrese el id del micro: ");
                     scanf("%d", &nuevoViaje.idMicro);
                }

                listarDestino(destino, tam);
                printf("Ingrese el id del destino: ");
                 scanf("%d", &nuevoViaje.idDestino);

                while( !validarDestino(destino,tam, nuevoViaje.idDestino) )
                {
                     printf("Error, reingrese el id del destino: ");
                     scanf("%d", &nuevoViaje.idDestino);
                }




                printf("Ingrese Fecha ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                nuevoViaje.fIngreso = fecha;


                while(validarFecha(fecha) == 1){

                     printf("Error, reingrese Fecha ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                nuevoViaje.fIngreso = fecha;

                }


                nuevoViaje.isEmpty = 0;
                nuevoViaje.idViaje = *pIdViaje;
                *pIdViaje = *pIdViaje + 1;
                vec[indice] = nuevoViaje;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }

    *pFLagViaje = 1;
    return todoOk;
}

int mostrarViaje(eViaje e,eEmpresa empresa[], eTipo tipo[] ,eDestino destino[],int tamv, int tam)
{
    int todoOk = 0;
    char descDestino[20];


    if(empresa != NULL && destino != NULL &&  tipo != NULL && tamv > 0)
    {

        cargarDescripcionDestino( destino, tam,  e.idDestino, descDestino);

        printf("  %d       %d       %s     %02d/%02d/%d\n",
               e.idViaje,
               e.idMicro,
               descDestino,
               e.fIngreso.dia,
               e.fIngreso.mes,
               e.fIngreso.anio
              );
        todoOk = 1;
    }
    return todoOk;
}


int listarViaje(eViaje vec[], int tamv, eMicro micro[], int tamm ,eDestino destino[],eEmpresa empresa[],eTipo tipo[], int tam)
{
    int todoOk = 0;
    int flag = 0;

    if(vec != NULL && empresa != NULL && micro != NULL && tipo != NULL && tamv > 0 && tamm > 0 && tam > 0)
    {
        system("cls");
        printf("          *** Listado de Viajes ***\n\n");
        printf(" id         idMicro       Destino       Fecha\n");
        printf("---------------------------------------------------------------\n");
        for(int i=0; i < tamv; i++)
        {
            if( !vec[i].isEmpty )
            {


                mostrarViaje(vec[i], empresa,tipo,destino, tamv, tam);
                flag++;
            }
        }

        if(flag == 0)
        {
            printf("       No hay micros en el sistema");
        }


        todoOk = 1;
    }
    return todoOk;
}



