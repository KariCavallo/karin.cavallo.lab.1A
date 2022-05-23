#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

#include "destino.h"
#include "empresa.h"
#include "fecha.h"
#include "micro.h"
#include "tipo.h"




typedef struct{

int idViaje;
int idMicro;
int idDestino;
int isEmpty;
eFecha fIngreso;

}eViaje;
#endif // VIAJE_H_INCLUDED

int inicializarViaje(eViaje vec[], int tamv);

int buscarViajeLibre(eViaje vec[], int tamv, int* pIndex);

int altaViaje(eViaje vec[], int tamv, eMicro micro[], int tamm, eEmpresa empresa[], int tam, eTipo tipo[],eDestino destino[], int* pIdViaje,int* pFLagViaj, eChofer chofer[]);

int mostrarViaje(eViaje e,eEmpresa empresa[], eTipo tipo[] ,eDestino destino[],int tamv, int tam);

int listarViaje(eViaje vec[], int tamv, eMicro micro[], int tamm ,eDestino destino[],eEmpresa empresa[],eTipo tipo[], int tam);
