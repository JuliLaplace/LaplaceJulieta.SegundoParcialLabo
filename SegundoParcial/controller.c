#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include"movies.h"
#include <string.h>
#include "parser.h"


int controller_loadFromText(char* path, LinkedList* pArrayList)
{
	   int todoOk = 0;

	    if(path!=NULL && pArrayList!=NULL){

	        FILE* file = fopen(path, "r"); //lee archivo texto

	        if(file==NULL){
	            printf("No se pudo abrir el archivo\n");
	            exit(1);
	        }else{
	          todoOk = parser_peliculasFromText(file, pArrayList);

	        }
	        fclose(file);        //cierra archivo
	    }

	    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* pArrayList)
{
		int todoOk;
	    eMovies* aux;

	    	if(path!=NULL && pArrayList!=NULL){
	    		FILE* file= fopen(path, "w");
				if(file==NULL)
				{
					printf("Error en abrir el archivo.\n");
					todoOk=0;
				}
				fprintf(file,"Id,Nombre,Genero,Duracion.\n");
				for(int i=0; i<ll_len(pArrayList); i++)
				{
					aux=ll_get(pArrayList,i);
					if(aux!=NULL)
					{
						fprintf(file,"%d,%10s,%10s,%d\n", aux->id, aux->nombre, aux->genero, aux->duracion);


							todoOk=1;
						}
					}
					fclose(file);
				}






	    return todoOk;
}


int controller_listPeliculas(LinkedList* pArrayList)
{
    eMovies* aux=NULL;
    int todoOk=0;
    int flag=0;

    if(pArrayList!=NULL)
    {
        printf("************************************************\n");
        printf("ID         Nombre        Tipo        Tiempo\n");
        printf("************************************************\n");
        for(int i=0; i<ll_len(pArrayList); i++)
        {
           aux= (eMovies*)ll_get(pArrayList,i);
           mostrarPelicula(aux);
           flag=1;
           todoOk=1;
        }
        printf("\n\n");
        if(flag==0)
        {
            printf("No hay peliculas para mostrar\n");
        }
    }
    return todoOk;
}




void* asignarTiempos(void* pElement)
{
    eMovies* aux=NULL;
    int tiempo;
    int max = 240;
    int min = 100;

    if(pElement != NULL )
    {
        aux=(eMovies*) pElement;
        tiempo = rand() % (max - min + 1) + min;
        aux->duracion = tiempo;

    }
    return aux;
}

int filtrarTipoAdventure(void* pElement)
{
    int retorno=0;
    eMovies* aux=NULL;
    if(pElement!=NULL)
    {
        aux=(eMovies*) pElement;
        if(strcmp(aux->genero,"Adventure")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}
int filtrarTipoDrama(void* pElement)
{
    int retorno=0;
    eMovies* aux=NULL;
    if(pElement!=NULL)
    {
        aux=(eMovies*) pElement;
        if(strcmp(aux->genero,"Drama")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarTipoHorror(void* pElement)
{
    int retorno=0;
    eMovies* aux=NULL;
    if(pElement!=NULL)
    {
        aux=(eMovies*) pElement;
        if(strcmp(aux->genero,"Horror")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarTipoComedy(void* pElement)
{
    int retorno=0;
    eMovies* aux=NULL;
    if(pElement!=NULL)
    {
        aux=(eMovies*) pElement;
        if(strcmp(aux->genero,"Comedy")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}
int filtrarTipoMusical(void* pElement)
{
    int retorno=0;
    eMovies* aux=NULL;
    if(pElement!=NULL)
    {
        aux=(eMovies*) pElement;
        if(strcmp(aux->genero,"Musical")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarTipoAction(void* pElement)
{
    int retorno=0;
    eMovies* aux=NULL;
    if(pElement!=NULL)
    {
        aux=(eMovies*) pElement;
        if(strcmp(aux->genero,"Action")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}


//////////////////////////////////////////////////////////////////////////





int controller_sortPeliculas(LinkedList* pArrayList)
{
	int todoOk=0;
	if(pArrayList!=NULL){


				ll_sort(pArrayList,ordenarPorGeneros,1);
				controller_listPeliculas(pArrayList);
				todoOk=1;

	}

	    return todoOk;
}



int ordenarPorGeneros(void* a, void* b){

    eMovies* movie1;
    eMovies* movie2;
    int todoOk=-2;

    movie1= (eMovies*)a;
    movie2= (eMovies*)b;

	if(a!=NULL && b!=NULL){
            if(strcmp(movie1->genero,movie2->genero)>0)
        {
            todoOk=1;
        }
        else if(strcmp(movie1->genero,movie2->genero)==0)
        {
            todoOk=0;
        }
	}

	    return todoOk;

}
