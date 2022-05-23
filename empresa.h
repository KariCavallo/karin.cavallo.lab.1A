#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED


typedef struct{

int id;
char descripcion[20];

}eEmpresa;

#endif // EMPRESA_H_INCLUDED

/** \brief Le paso una estructura y su tamaño para poder motrarla en pantalla
 *
 * \param empresa[] eEmpresa
 * \param tam int
 * \return int
 *
 */
int listarEmpresa(eEmpresa empresa[], int tam);


/** \brief Segun un id correspondiente a la estructura se carga la descripcion de la misma
 *
 * \param empresa[] eEmpresa
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionEmpresa(eEmpresa empresa[], int tam, int id, char descripcion[]);


/** \brief Segun el Id correspondiente encuentra el indice del mismo
 *
 * \param empresa[] eEmpresa
 * \param tam int
 * \param id int
 * \param pIndice int*
 * \return int
 *
 */
int buscarEmpresa(eEmpresa empresa[], int tam, int id, int* pIndice);
