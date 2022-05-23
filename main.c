#include <stdio.h>
#include <stdlib.h>
#include "destino.h"
#include "empresa.h"
#include "fecha.h"
#include "micro.h"
#include "tipo.h"
#include "viaje.h"
#include "chofer.h"



#define TAM 4
#define TAMM 50
#define TAMV 100


int main()
{

    char salir = 'n';
    int id = 1;
    int idViaje = 100;
    int flag = 0;
    int flagViaje = 0;
    eMicro micro[TAMM];

    eViaje viaje[TAMV];

     eEmpresa empresa[TAM] =
    {
        {1000, "Plusmar"},
        {1001, "Flecha Bus"},
        {1002, "Tas"},
        {1003, "El Rapido"},

    };

 eTipo tipo[TAM] =
    {
        {5000, "Comun"},
        {5001, "CocheCama"},
        {5002, "Doble"},
        {5003, "Vip"},

    };
 eDestino destino[TAM] =
    {
        {20000, "Calafate",22250},
        {20001, "Bariloche",103000},
        {20002, "Iguazu",84400},
        {20003, "Mendoza",95600},

    };

    eChofer chofer[TAM] =

    {
        {200, "Juan",'m'},
        {201, "Maria",'f'},
        {202, "Juana",'f'},
        {203, "Lucio",'m'},

    };


     inicializarMicros( micro, TAMM);
     inicializarViaje(viaje, TAMV);

     do
    {
        switch(menu())
        {

        case 'A':

                    if( altaMicro(micro, TAMM,tipo,TAM,empresa, &id, &flag, chofer))
            {
                printf("Micro agregado con exito!!!\n");
            }
            else
            {
                printf("Problema al hacer el alta del micro\n");
            }
            break;

        case 'B':
                        if(flag == 1){


                                if(  modificarMicro(micro, TAMM, empresa, tipo, TAM, chofer) == 0)
                                    {
                                printf("Problema al modificar del micro\n");
                                    }

                        }
                        else {

                            printf("Primero debe hacer el alta de un micro\n");
                        }

            break;

        case 'C':

                         if(flag == 1){

                        if( bajaMicro(micro, TAMM, empresa, tipo, TAM, chofer) == 0)
                        {
                                printf("Problema al hacer la baja del micro\n");
                        }

                    }
                        else {

                            printf("Primero debe hacer el alta de un micro\n");
                        }

            break;

        case 'D':

            if(flag == 1){

                ordenoPorEmpresaYCapacidad( micro, TAMM);

                listarMicro( micro, TAMM,empresa,tipo, TAM, chofer);

               // informarMicrosEmpresa( micro, TAMM, empresa,tipo, chofer, TAM);


                    //promedioTipoEmpresaElegido(micro, TAMM, empresa, tipo, TAM);

                    //informarMicrosPorEmpresa(micro, TAMM, empresa, tipo,  chofer, TAM);

                   //empresaMayorCapacidad(micro,  TAMM, empresa, TAM);

                   //empresaMenorMicros(micro, TAMM, empresa, TAM);

                 }
                        else {

                            printf("Primero debe hacer el alta de un micro\n");
                        }


            break;

        case 'E':
                    listarEmpresa( empresa, TAM);
            break;

        case 'F':
                    listarTipo(tipo, TAM);
            break;

        case 'G':
                    listarDestino(destino, TAM);
            break;

        case 'H':

             if(flag == 1){



                            if(   altaViaje(viaje, TAMV, micro, TAMM,empresa, TAM, tipo,destino, &idViaje, &flagViaje, chofer) == 0)
                                {
                                printf("Problema al hacer la alta del viaje\n");
                                }

             }
             else {

                            printf("Primero debe hacer el alta de un micro\n");
                        }


            break;

        case 'I':
                    if(flagViaje == 1){


                            listarViaje( viaje, TAMV,  micro, TAMM,destino, empresa, tipo, TAM);

                    }
             else {

                            printf("Primero debe hacer el alta de un viaje\n");
                        }

            break;




        case 'J':

            salir = 's';

            break;
        }

        system("pause");

    }while(salir != 's');

    return 0;
}

