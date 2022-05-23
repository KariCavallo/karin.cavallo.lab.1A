#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED



typedef struct{

int id;
char descripcion[25];
int precio;

}eDestino;
#endif // DESTINO_H_INCLUDED

/** \brief Le paso una estructura y su tamaño para poder motrarla en pantalla
 *
 * \param destino[] eDestino
 * \param tam int
 * \return int
 *
 */
int listarDestino(eDestino destino[], int tam);

/** \brief Segun el Id correspondiente encuentra el indice del mismo
 *
 * \param destino[] eDestino
 * \param tam int
 * \param id int
 * \param pIndice int*
 * \return int
 *
 */
int buscarDestino(eDestino destino[], int tam, int id, int* pIndice);

/** \brief   Segun un id correspondiente a la estructura se carga la descripcion de la misma
 *
 * \param destino[] eDestino
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionDestino(eDestino destino[], int tam, int id, char descripcion[]);
