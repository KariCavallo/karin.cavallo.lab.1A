#ifndef CHOFER_H_INCLUDED
#define CHOFER_H_INCLUDED

typedef struct{

int id;
char nombre[15];
char sexo;

}eChofer;

#endif // CHOFER_H_INCLUDED

/** \brief Le paso una estructura y su tamaño para poder motrarla en pantalla
 *
 * \param chofer[] eChofer
 * \param tam int
 * \return int
 *
 */
int listarChofer(eChofer chofer[], int tam);

/** \brief Segun un id correspondiente a la estructura se carga la descripcion de la misma
 *
 * \param chofer[] eChofer
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionChofer(eChofer chofer[], int tam, int id, char descripcion[]);

/** \brief Segun el Id correspondiente encuentra el indice del mismo
 *
 * \param chofer[] eChofer
 * \param tam int
 * \param id int
 * \param pIndice int*
 * \return int
 *
 */
int buscarChofer(eChofer chofer[], int tam, int id, int* pIndice);
