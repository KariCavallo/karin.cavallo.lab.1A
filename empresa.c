#include "empresa.h"
#include <stdio.h>
#include <stdlib.h>


int listarEmpresa(eEmpresa empresa[], int tam){
int todoOk = 0;

    if(empresa != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Empresas  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", empresa[i].id, empresa[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionEmpresa(eEmpresa empresa[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarEmpresa(empresa,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, empresa[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarEmpresa(eEmpresa empresa[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(empresa != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(empresa[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

