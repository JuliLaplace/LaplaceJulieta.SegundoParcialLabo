#include <stdio.h>
#include <stdlib.h>
#include"LinkedList.h"
#include"movies.h"
#include"parser.h"
int parser_peliculasFromText(FILE* pFile , LinkedList* pArrayList)
{
        int todoOk = 0;
        int cantidad;
	    char buffer[4][150];
		eMovies* aux=NULL;

		if(pFile!=NULL && pArrayList!=NULL){

			fscanf(pFile,"[^\n]\n");//lectura fantasma

			while(!feof(pFile)){

				cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
                if(cantidad==4){
                    aux = pelicula_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                    if(aux != NULL){
                        if(!ll_add(pArrayList,aux)){
                            todoOk=1;
                        }
                    }
                }else{
                    pelicula_delete(aux);
                }

			}
			fclose(pFile);
		}
		return todoOk;
}
