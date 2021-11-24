#include"LinkedList.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED
/** \brief Carga los datos de las peliculas desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo a abrir
 * \param pArrayList LinkedList* lista de linkedlist
 * \return int retorna 1 si logro cargar los datos correctamente o 0 si no pudo realizar la carga
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList);

/** \brief Guarda los datos de las peliculas en el archivo data.csv (modo texto).
 *
 * \param path char* archivo donde se guardaran los datos
 * \param pArrayList LinkedList* lista de linkedlist
 * \return int retorna 1 si logro guardar el archivo como texto, o 0 si no logro realizarlo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList);


/** \brief muestra las peliculas de la lista
 *
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_listPeliculas(LinkedList* pArrayList);

void* asignarTiempos(void* pElement);
int filtrarTipoAdventure(void* pElement);
int filtrarTipoDrama(void* pElement);
int filtrarTipoHorror(void* pElement);
int filtrarTipoComedy(void* pElement);
int filtrarTipoMusical(void* pElement);
int filtrarTipoAction(void* pElement);

/** \brief Ordena peliculas
 *
 * \param pArrayList LinkedList* lista de linkedlist
 * \return int retorna 1 si logro ordenarlos las peliculas correctamente o 0 si no pudo realizarlo
 *
 */
int controller_sortPeliculas(LinkedList* pArrayList);
int ordenarPorGeneros(void* a, void* b);
