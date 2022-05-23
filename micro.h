#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED
#include "fecha.h"
#include "tipo.h"
#include "empresa.h"
#include "chofer.h"



typedef struct{

int id;
int idEmpresa;
int idTipo;
int isEmpty;
int capacidad;
int idChofer;
}eMicro;

#endif // MICRO_H_INCLUDED

int menu();



int inicializarMicros(eMicro vec[], int tamm);

int buscarMicroLibre(eMicro vec[], int tamm, int* pIndex);

int altaMicro(eMicro vec[], int tamm, eTipo tipo[], int tam,eEmpresa empresa[], int* pId, int* pFlag, eChofer chofer[]);

int buscarMicro(eMicro vec[], int tamm,int id, int* pIndex);

int bajaMicro(eMicro vec[], int tamm,eEmpresa empresa[],eTipo tipo[], int tam, eChofer chofer[]);

int listarMicro(eMicro vec[], int tamm, eEmpresa empresa[],eTipo tipo[], int tam, eChofer chofer[]);

int mostrarMicro(eMicro e,eEmpresa empresa[], eTipo tipo[] ,int tamm, eChofer chofer[]);

int modificarMicro( eMicro  vec[], int tamm, eEmpresa empresa[],eTipo tipo[], int tam,eChofer chofer[]);

int menuModificarMicro();

int ordenoPorEmpresaYCapacidad(eMicro micro[], int tamm);
