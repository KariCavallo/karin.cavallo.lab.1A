#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "destino.h"
#include "empresa.h"
#include "micro.h"
#include "tipo.h"
#include "chofer.h"


#endif // VALIDACIONES_H_INCLUDED


int validarTipo(eTipo tipo[], int tam, int id);

int validarEmpresa(eEmpresa empresa[], int tam, int id);

int validarMicro(eMicro micro[], int tamm, int id);

int validarDestino(eDestino destino[], int tam, int id);

int validarFecha(eFecha fecha);

int validarChofer(eChofer chofer[], int tam, int id);
