#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>

int listarTipo(eTipo tipo[], int tam){
int todoOk = 0;

    if(tipo != NULL && tam > 0){

        printf("   *** Lista de Tipo  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", tipo[i].id, tipo[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionTipo(eTipo tipo[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarTipo(tipo,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, tipo[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarTipo(eTipo tipo[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(tipo != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(tipo[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
