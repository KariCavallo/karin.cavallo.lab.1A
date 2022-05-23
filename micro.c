#include "micro.h"
#include "tipo.h"
#include "empresa.h"
#include "validaciones.h"
#include "chofer.h"

#include <stdio.h>
#include <stdlib.h>

int menu()
{
    char opcion;
    system("cls");
    printf("     *** ABM Micros ***\n");
    printf("A- Alta Micro\n");
    printf("B- Modificar micro\n");
    printf("C- Baja micro\n");
    printf("D- Listar Micros\n");
    printf("E- Listar Empresas\n");
    printf("F- Listar Tipos\n");
    printf("G- Listar Destinos\n");
    printf("H- Alta viaje\n");
    printf("I- Listar viaje\n");
    printf("J- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    return opcion;

}

int inicializarMicros(eMicro vec[], int tamm)
{
    int todoOk = 0;
    if(vec != NULL && tamm > 0)
    {
        for(int i=0; i < tamm; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}



int buscarMicroLibre(eMicro vec[], int tamm, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tamm > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tamm; i++)
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

int altaMicro(eMicro vec[], int tamm, eTipo tipo[], int tam, eEmpresa empresa[] ,int* pId, int* pFlag, eChofer chofer[])
{
    int todoOk = 0;
    int indice;
    eMicro nuevoMicro;

    if(vec != NULL && tamm > 0 && pId != NULL)
    {
        if( buscarMicroLibre(vec, tamm, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                listarEmpresa( empresa, tam);
                printf("Ingrese Id empresa: ");
                scanf("%d", &nuevoMicro.idEmpresa);

                while( !validarEmpresa(empresa,  tam, nuevoMicro.idEmpresa) )
                {
                    printf("Id invalido.Ingrese Id empresa: ");
                    scanf("%d", &nuevoMicro.idEmpresa);
                }

                    listarTipo(tipo, tam);
                 printf("Ingrese Id tipo: ");
                scanf("%d", &nuevoMicro.idTipo);

                while( !validarTipo( tipo ,tam, nuevoMicro.idTipo) )
                {
                    printf("Id invalido.Ingrese Id tipo: ");
                    scanf("%d", &nuevoMicro.idTipo);
                }

                 printf("Ingrese la capacidad: ");
                scanf("%d", &nuevoMicro.capacidad);

                while( nuevoMicro.capacidad < 1 || nuevoMicro.capacidad > 50 )
                {
                    printf("Capacidad invalida.Ingrese capacidad: ");
                    scanf("%d", &nuevoMicro.capacidad);
                }

                listarChofer(chofer, tam);
                 printf("Ingrese Id del chofer: ");
                scanf("%d", &nuevoMicro.idChofer);

                while( !validarChofer( chofer ,tam, nuevoMicro.idChofer) )
                {
                    printf("Id invalido.Ingrese Id Chofer: ");
                    scanf("%d", &nuevoMicro.idChofer);
                }




                nuevoMicro.isEmpty = 0;
                nuevoMicro.id = *pId;
                *pId = *pId + 1;
                vec[indice] = nuevoMicro;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }

    *pFlag = 1;
    return todoOk;
}

int mostrarMicro(eMicro e,eEmpresa empresa[], eTipo tipo[] ,int tamm, eChofer chofer[])
{
    int todoOk = 0;
    char descEmpresa[20];
    char descTipo[20];
    char nombreChofer[20];


    if(empresa != NULL && tipo != NULL && chofer != NULL && tamm > 0)
    {
        cargarDescripcionEmpresa( empresa, tamm, e.idEmpresa, descEmpresa);
        cargarDescripcionTipo( tipo, tamm, e.idTipo, descTipo);
        cargarDescripcionChofer(chofer, tamm, e.idChofer, nombreChofer);


        printf("  %4d       %4d       %10s      %10s  %10s\n",
               e.id,
               e.capacidad,
               descTipo,
               descEmpresa,
               nombreChofer
              );
        todoOk = 1;
    }
    return todoOk;
}


int listarMicro(eMicro vec[], int tamm, eEmpresa empresa[],eTipo tipo[], int tam, eChofer chofer[])
{
    int todoOk = 0;


    if(vec != NULL && empresa != NULL && tipo != NULL && chofer != NULL && tamm > 0 && tam > 0)
    {
        system("cls");
        printf("          *** Listado de Micros ***\n\n");
        printf(" id         Capacidad       Tipo       Empresa    Chofer\n");
        printf("---------------------------------------------------------------\n");
        for(int i=0; i < tamm; i++)
        {
            if( !vec[i].isEmpty )
            {

{
                mostrarMicro(vec[i], empresa,tipo, tamm, chofer);

            }
        }



        todoOk = 1;
    }
    return todoOk;
}

}




int buscarMicro(eMicro vec[], int tamm,int id, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tamm > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tamm; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int bajaMicro(eMicro vec[], int tamm,eEmpresa empresa[],eTipo tipo[], int tam, eChofer chofer[])
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec != NULL && tam > 0)
    {
        listarMicro(vec, tamm,empresa,tipo, tam,chofer);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarMicro(vec, tamm, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un micro con id\n", id);
            }
            else
            {
                mostrarMicro(vec[indice], empresa,tipo, tamm, chofer);

                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar el micro\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int modificarMicro( eMicro  micro[], int tamm, eEmpresa empresa[],eTipo tipo[], int tam, eChofer chofer[])
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';


    if(micro != NULL && tam > 0)
    {
        listarMicro( micro, tamm,empresa,tipo, tam,chofer);

        printf("Ingrese id: ");
        scanf("%d", &id);
        if(  buscarMicro(micro, tamm, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un micro con id %d\n", id);
            }
            else
            {
                mostrarMicro(micro[indice], empresa,tipo, tamm,chofer);


                do
                {
                    switch(menuModificarMicro())
                    {

                    case 1:
                         listarTipo(tipo, tam);
                        printf("Ingrese el Id del nuevo Tipo: ");
                        scanf("%d", &micro[indice].idTipo);


                        while( !validarTipo( tipo ,tam, micro->idTipo) )
                {
                    printf("Id invalido.Ingrese Id tipo: ");
                    scanf("%d", &micro[indice].idTipo);
                    printf("Se ha modificado el tipo\n");
                }
                        break;

                    case 2:
                        printf("Ingrese la nueva capacidad: ");
                        scanf("%d", &micro[indice].capacidad);


                        while( micro[indice].capacidad < 1 || micro[indice].capacidad > 50 )
                {
                    printf("Capacidad invalida.Ingrese capacidad: ");
                     scanf("%d", &micro[indice].capacidad);
                        printf("Se ha modificado la capacidad\n");
                }


                        break;


                    case 3:
                        salir = 's';
                        break;
                    }

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar micro\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int menuModificarMicro()
{
    int opcion;
    printf("     *** Campos a modificar ***\n");
    printf("1- Tipo\n");
    printf("2- Capacidad\n");
    printf("3- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int ordenoPorEmpresaYCapacidad(eMicro micro[], int tamm)
{

    int todoOk = 0;

    eMicro auxMicro;


    if(micro != NULL && tamm > 0)
    {


        for(int i=0; i < tamm -1; i++)
        {
            for(int j= i + 1; j < tamm; j++)
            {

                if(micro[i].capacidad >  micro[j].capacidad && micro[i].idEmpresa == micro[j].idEmpresa)
                {
                    auxMicro = micro[i];
                    micro[i] = micro[j];
                    micro[j] = auxMicro;
                }
            }
        }
        todoOk = 1;


    }



    return todoOk;

}
