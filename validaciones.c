#include "validaciones.h"
#include "destino.h"
#include "empresa.h"
#include "micro.h"
#include "fecha.h"
#include "chofer.h"

#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>


int validarTipo(eTipo tipo[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarTipo(tipo, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int validarEmpresa(eEmpresa empresa[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarEmpresa(empresa, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int validarMicro(eMicro micro[], int tamm, int id){
    int esValido = 0;
    int indice;

    buscarMicro(micro, tamm, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int validarDestino(eDestino destino[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarDestino(destino, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int validarChofer(eChofer chofer[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarChofer(chofer, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


int validarFecha(eFecha fecha){


int fechaCorrecta = 0;

    if ( fecha.mes >= 1 && fecha.mes <= 12 )
    {
        switch ( fecha.mes )
        {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 : if ( fecha.dia >= 1 && fecha.dia <= 31 && fecha.anio > 2021 ){
                          fechaCorrecta = 1;
                            }
                      break;

            case  4 :
            case  6 :
            case  9 :
            case 11 : if ( fecha.dia >= 1 && fecha.dia <= 30 && fecha.anio > 2021 ){
                         fechaCorrecta = 1;
                         }
                      break;

            case  2 : if ( ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || (fecha.anio % 400 == 0)) && (fecha.anio > 2021) )
                      {
                          if ( fecha.dia >= 1 && fecha.dia <= 29 )
                              fechaCorrecta = 1;
                      }
                      else
                          if ( fecha.dia >= 1 && fecha.dia <= 28 )
                              fechaCorrecta = 1;
        }
    }



    if ( fechaCorrecta )
        return 0;
    else
        return 1;
 }
