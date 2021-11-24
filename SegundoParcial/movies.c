#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"movies.h"

eMovies* new_movie(){
        eMovies* nuevaPelicula;
	    nuevaPelicula = (eMovies*) malloc(sizeof(eMovies));
	    if(nuevaPelicula!=NULL){
	        nuevaPelicula->id = 0;
	        strcpy(nuevaPelicula->nombre, " ");
	        strcpy(nuevaPelicula->genero, " ");
	        nuevaPelicula->duracion = 0;

	    }

	    return nuevaPelicula;
}
eMovies* pelicula_newParametros(char *idStr, char *peliculaStr, char *generoStr, char *duracionStr){
    eMovies* nuevaPelicula = new_movie(); //aca pido malloc de eMovie*

	if(nuevaPelicula!=NULL && idStr!=NULL && peliculaStr!=NULL && generoStr!=NULL && duracionStr!=NULL){
	        if(!(pelicula_setId(nuevaPelicula, atoi(idStr)) && pelicula_setNombre(nuevaPelicula, peliculaStr) && pelicula_setGenero(nuevaPelicula, generoStr)
              && pelicula_setDuracion(nuevaPelicula, atoi(duracionStr)))){
	            pelicula_delete(nuevaPelicula);
	            nuevaPelicula=NULL;
	        }
	    }

	    return nuevaPelicula;
}

void pelicula_delete(eMovies *this){
        free(this);


}
int pelicula_setId(eMovies *this, int id){
    int todoOk=0;
	    if(this!=NULL && id>0){
	        this->id=id;
	        todoOk=1;
	    }


	return todoOk;
}
int pelicula_getId(eMovies *this, int *id){
    int todoOk=0;
	    if(this!=NULL && id!=NULL){
	        *id= this->id;
	        todoOk=1;
	    }


	    return todoOk;
}
int pelicula_setNombre(eMovies *this, char *pelicula){
    int todoOk=0;
	    if(this!=NULL && pelicula!=NULL){
	       if(strlen(pelicula)<50 && strlen(pelicula)>2){
	            strcpy(this->nombre, pelicula);

	            todoOk=1;
	       }

	    }

	return todoOk;
}
int pelicula_getNombre(eMovies *this, char *pelicula){
     int todoOk=0;
    if(this!=NULL && pelicula!=NULL){
        strcpy(pelicula, this->nombre);
        todoOk=1;
    }


    return todoOk;
}

int pelicula_setGenero(eMovies *this, char *genero){
    int todoOk=0;
	    if(this!=NULL && genero!=NULL){
	       if(strlen(genero)<50 && strlen(genero)>2){
	            strcpy(this->nombre, genero);

	            todoOk=1;
	       }

	    }

	return todoOk;
}
int pelicula_getGenero(eMovies *this, char *genero){
     int todoOk=0;
    if(this!=NULL && genero!=NULL){
        strcpy(genero, this->nombre);
        todoOk=1;
    }


    return todoOk;
}
int pelicula_setDuracion(eMovies *this, int duracion){
    int todoOk = 0;
    if (this != NULL && duracion >= 0)
    {
        this->duracion = duracion;
        todoOk = 1;
    }
    return todoOk;
}
int pelicula_getDuracion(eMovies *this, int *duracion){
    int todoOk = 0;
    if (this != NULL && duracion!=NULL)
    {
        *duracion = this->duracion;
        todoOk = 1;
    }
    return todoOk;
}


int mostrarPelicula(eMovies* unaPelicula)
{
    int auxId;
    char auxNombre[50];
    char auxGenero[50];
    int auxDuracion;
    int todoOk=0;

    if(unaPelicula!=NULL && pelicula_getId(unaPelicula,&auxId) &&
            pelicula_getNombre(unaPelicula, auxNombre) &&
            pelicula_getGenero(unaPelicula, auxGenero) &&
            pelicula_getDuracion(unaPelicula, &auxDuracion))
    {
        printf("%2d  %10s  %10s  %2d\n", auxId, auxNombre, auxGenero,auxDuracion);
        todoOk=1;
    }
    return todoOk;
}
