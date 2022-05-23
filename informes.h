#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

int informarMicrosEmpresa(eMicro vec[], int tamm, eEmpresa empresa[],eTipo tipo[],eChofer chofer[], int tam);

int informarMicrosTipo(eMicro vec[], int tamm, eEmpresa empresa[],eTipo tipo[],eChofer chofer[], int tam);

int promedioTipoEmpresa(eMicro vec[], int tamm,eEmpresa empresa[],eTipo tipo[],int tam,int idEmpresa, float* pPromedio);


int promedioTipoEmpresaElegido(eMicro vec[], int tamm, eEmpresa empresa[],eTipo tipo[], int tam);

int informarMicrosPorEmpresa(eMicro vec[], int tamm,eEmpresa empresa[],eTipo tipo[], eChofer chofer[], int tam);

int empresaMayorCapacidad(eMicro vec[], int tamm,eEmpresa empresa[], int tam);

int empresaMenorMicros(eMicro vec[], int tamm,eEmpresa empresa[], int tam);
