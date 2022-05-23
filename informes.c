#include <stdio.h>
#include <stdlib.h>
#include "destino.h"
#include "empresa.h"
#include "fecha.h"
#include "micro.h"
#include "tipo.h"
#include "viaje.h"
#include "chofer.h"
#include "informes.h"
#include "validaciones.h"


int informarMicrosEmpresa(eMicro vec[], int tamm, eEmpresa empresa[],eTipo tipo[],eChofer chofer[], int tam)
{
    int todoOk = 0;
    int idEmpresa;
    int flag = 1;
    char descripcion[20];


    if(vec != NULL && empresa != NULL && tipo != NULL && chofer != NULL && tamm> 0 && tam > 0)
    {
        system("cls");
        printf("   *** Listado de Micros de una Empresa ***\n");
        printf("---------------------------------------------------\n");

        listarEmpresa(empresa, tam);

        printf("Ingrese Id empresa: ");
        scanf("%d", &idEmpresa);

        while( !validarEmpresa(empresa,tam, idEmpresa))
        {
            printf("Empresa invalida.Ingrese Id empresa: ");
            scanf("%d", &idEmpresa);
        }

        for(int i=0; i < tamm; i++)
        {
            if( !vec[i].isEmpty && vec[i].idEmpresa == idEmpresa)
            {

                mostrarMicro(vec[i], empresa, tipo , tamm, chofer);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionEmpresa(empresa,tam, idEmpresa, descripcion);
            printf("No hay micros registrados con la empresa %s\n", descripcion );
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}

int informarMicrosTipo(eMicro vec[], int tamm, eEmpresa empresa[],eTipo tipo[],eChofer chofer[], int tam)
{
    int todoOk = 0;
    int idTipo;
    int flag = 1;
    char descripcion[20];


    if(vec != NULL && empresa != NULL && tipo != NULL && chofer != NULL && tamm> 0 && tam > 0)
    {
        system("cls");
        printf("   *** Listado de Micros de un Tipo ***\n");
        printf("---------------------------------------------------\n");

        listarTipo(tipo, tam);

        printf("Ingrese Id tipo: ");
        scanf("%d", &idTipo);

        while( !validarTipo(tipo,tam, idTipo))
        {
            printf("Tipo invalido.Ingrese Id tipo: ");
            scanf("%d", &idTipo);
        }

        for(int i=0; i < tamm; i++)
        {
            if( !vec[i].isEmpty && vec[i].idTipo == idTipo)
            {

                mostrarMicro(vec[i], empresa, tipo , tamm, chofer);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionTipo(tipo,tam, idTipo, descripcion);
            printf("No hay micros registrados con ese tipo %s\n", descripcion );
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}


int promedioTipoEmpresa(eMicro vec[], int tamm,eEmpresa empresa[],eTipo tipo[],int tam,int idEmpresa, float* pPromedio)
{
    int todoOk = 0;
    float promedio = 0;
    float contTipos= 0;
    int contMicros = 0;
    int idTipo = 5003;
    if(vec != NULL && empresa != NULL && tipo != NULL && pPromedio != NULL && tam > 0 && tamm > 0 && validarEmpresa(empresa, tam, idEmpresa))
    {
        for(int i = 0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].idEmpresa == idEmpresa)
            {

                contMicros++;

                if(vec[i].idTipo == idTipo){

                    contTipos++;



                }

            }
        }
        if(contMicros != 0)
        {
            promedio = contTipos/contMicros;
        }

        *pPromedio = promedio;
        todoOk = 1;
    }
    return todoOk;
}


int promedioTipoEmpresaElegido(eMicro vec[], int tamm, eEmpresa empresa[],eTipo tipo[], int tam)
{

    int todoOk = 0;
    int idEmpresa;
    char descripcion[20];
    float promedio;


    if(vec != NULL && empresa != NULL && tipo!= NULL && tam > 0 && tam > 0)
    {
        system("cls");
        printf("   *** Promedio de tipos de una empresa ***\n");
        printf("---------------------------------------------------\n");

        listarEmpresa(empresa, tam);

        printf("Ingrese Id empresa: ");
        scanf("%d", &idEmpresa);

        while( !validarEmpresa(empresa,tam, idEmpresa))
        {
            printf("Empresa invalida.Ingrese Id empresa: ");
            scanf("%d", &idEmpresa);
        }

        promedioTipoEmpresa( vec, tamm, empresa,tipo, tam, idEmpresa, &promedio);
        cargarDescripcionEmpresa(empresa, tam, idEmpresa, descripcion);

        printf("Promedio de tipos en el sector %s:  %2.f\n\n", descripcion, promedio);
        todoOk = 1;
    }
    return todoOk;
}
int informarMicrosPorEmpresa(eMicro vec[], int tamm,eEmpresa empresa[],eTipo tipo[], eChofer chofer[], int tam)
{
    int todoOk = 0;
    int flag;

    if(vec != NULL && empresa != NULL && tipo != NULL && chofer != NULL && tamm > 0 && tam > 0)
    {
        system("cls");
        printf("    *** Listado de Micros por Empresa  ***\n");
        printf("-----------------------------------------------------\n");

        for(int s=0; s < tam; s++)
        {
            printf("Empresa: %s\n\n", empresa[s].descripcion);
            printf(" id         Capacidad       Tipo       Empresa    Chofer\n");
            printf("---------------------------------------------------------------\n");
            flag = 1;
            for(int e = 0; e < tam; e++)
            {
                if( !vec[e].isEmpty && vec[e].idEmpresa == empresa[s].id)
                {
                     mostrarMicro(vec[e], empresa, tipo , tamm, chofer);
                    flag = 0;
                }
            }
            if(flag)
            {
                printf("No hay empleados\n");
            }
            printf("\n\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int empresaMayorCapacidad(eMicro vec[], int tamm,eEmpresa empresa[], int tam){
int todoOk = 0;
float totalesCapacidad[tam];
float mayor;
int flag = 1;

   if(vec != NULL && empresa != NULL  && tamm > 0 && tam > 0)
    {
        system("cls");
        printf("   *** Empresa que mas capacidad tiene ***\n");
        printf("---------------------------------------------------\n");


        for(int i=0; i < tam; i++){
            totalesCapacidad[i] = 0;
        }

        for(int s = 0; s < tam; s++){
            for(int e = 0; e < tamm; e++){
                if(!vec[e].isEmpty && vec[e].idEmpresa == empresa[s].id){
                    totalesCapacidad[s] += vec[e].capacidad;
                }
            }
        }

        for(int s = 0; s < tam; s++){
            if(flag || totalesCapacidad[s] > mayor){
                mayor = totalesCapacidad[s];
                flag = 0;
            }
        }

        printf("La Empresa que mas capacidad tiene  %.2f y es :\n", mayor);
          for(int s = 0; s < tam; s++){
            if(totalesCapacidad[s] == mayor){
                printf("%s\n", empresa[s].descripcion);
            }
        }
      todoOk = 1;
    }
    return todoOk;
}


int empresaMenorMicros(eMicro vec[], int tamm,eEmpresa empresa[], int tam){
int todoOk = 0;
int totalesMicros[tamm];
int menor = 1000;
int flag = 1;

   if(vec != NULL && empresa != NULL  && tamm > 0 && tam > 0)
    {
        system("cls");
        printf("   *** Empresa que menor micros tiene ***\n");
        printf("---------------------------------------------------\n");


        for(int i=0; i < tamm; i++){
            totalesMicros[i] = 0;

        }




        for(int s = 0; s < tamm; s++){
            for(int e = 0; e < tam; e++){
                if(!vec[e].isEmpty && vec[e].idEmpresa == empresa[s].id){


                    totalesMicros[s]++;
                }
            }
        }

        for(int s = 0; s < tamm; s++){
            if(flag || totalesMicros[s] > menor){
                menor = totalesMicros[s];
                flag = 0;
            }
        }

        printf("La Empresa que menos micros tiene  %d y es :\n", menor);
          for(int s = 0; s < tamm; s++){
            if(totalesMicros[s] == menor){
                printf("%s\n", empresa[s].descripcion);
            }
        }
      todoOk = 1;
    }
    return todoOk;
}
