#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


typedef struct{

int id;
char descripcion[20];

}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief Le paso una estructura y su tamaño para poder motrarla en pantalla
 *
 * \param tipo[] eTipo
 * \param tam int
 * \return int
 *
 */
int listarTipo(eTipo tipo[], int tam);

/** \brief Segun un id correspondiente a la estructura se carga la descripcion de la misma
 *
 * \param tipo[] eTipo
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionTipo(eTipo tipo[], int tam, int id, char descripcion[]);

/** \brief Segun el Id correspondiente encuentra el indice del mismo
 *
 * \param tipo[] eTipo
 * \param tam int
 * \param id int
 * \param pIndice int*
 * \return int
 *
 */
int buscarTipo(eTipo tipo[], int tam, int id, int* pIndice);
