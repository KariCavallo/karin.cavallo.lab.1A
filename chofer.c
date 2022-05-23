#include "chofer.h"
#include <stdio.h>
#include <stdlib.h>


int listarChofer(eChofer chofer[], int tam){
int todoOk = 0;

    if(chofer != NULL && tam > 0){

        printf("   *** Lista de Choferes ***\n");
        printf("  Id    Nombre  sexo\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s    %c\n", chofer[i].id, chofer[i].nombre, chofer[i].sexo);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionChofer(eChofer chofer[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarChofer(chofer,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, chofer[indice].nombre);
       todoOk = 1;
    }
  return todoOk;
}


int buscarChofer(eChofer chofer[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(chofer != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(chofer[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
