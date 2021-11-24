#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct{
    int id;
    char nombre[50];
    char genero[50];
    int duracion;
}eMovies;

#endif // MOVIES_H_INCLUDED

eMovies* new_movie();
eMovies* pelicula_newParametros(char *idStr, char *peliculaStr, char *generoStr, char *duracionStr);
void pelicula_delete(eMovies *this);
int pelicula_setId(eMovies *this, int id);
int pelicula_getId(eMovies *this, int *id);
int pelicula_setNombre(eMovies *this, char *pelicula);
int pelicula_getNombre(eMovies *this, char *pelicula);
int pelicula_setGenero(eMovies *this, char *genero);
int pelicula_getGenero(eMovies *this, char *genero);
int pelicula_setDuracion(eMovies *this, int duracion);
int pelicula_getDuracion(eMovies *this, int *duracion);
int mostrarPelicula(eMovies* unaPelicula);
