#include "destino.h"
#include <stdio.h>
#include <stdlib.h>

int listarDestino(eDestino destino[], int tam){
int todoOk = 0;

    if(destino != NULL && tam > 0){

        printf("   *** Lista de Destinos ***\n");
        printf("  Id    Descripcion  Precio\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s  $ %d\n", destino[i].id, destino[i].descripcion, destino[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionDestino(eDestino destino[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarDestino(destino,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, destino[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarDestino(eDestino destino[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(destino != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(destino[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
