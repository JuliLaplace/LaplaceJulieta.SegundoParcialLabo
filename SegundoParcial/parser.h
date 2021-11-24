#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED
/** \brief Parsea los datos los datos de las peliculas desde el archivo path* pasado como parametro (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_peliculasFromText(FILE* pFile , LinkedList* pArrayList);
