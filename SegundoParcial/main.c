#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include"menu.h"
#include"controller.h"
int main()
{
    srand(time(NULL));
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaGeneros = ll_newLinkedList();
    LinkedList* listaGenerosDuraciones = ll_newLinkedList();
    char archivoAbrir[20];
    int flagCarga=0;
    int flagDuraciones=0;
    char respuesta='s';

    do{
        switch(menu()){
        case 1:
                printf("Ingrese nombre del archivo que desea abrir (ya existe el archivo movies.csv): ");
                fflush(stdin);
                gets(archivoAbrir);
            	if(controller_loadFromText(archivoAbrir,lista)){
                    printf("Datos de peliculas cargados desde el archivo %s con exito.\n ", archivoAbrir);
                    flagCarga=1;
                }else{
                    printf("Error en carga de archivo.\n ");
                }
            break;
        case 2:
            if(!flagCarga){
                printf("Primero debes cargar un archivo (opcion 1).\n");
            }else{
                controller_listPeliculas(lista);
            }
            break;
        case 3:
            if(flagCarga)
            {
                ll_map(lista,asignarTiempos);
                controller_listPeliculas(lista);
                printf("Se aplico el tiempo a las peliculas correctamente\n");
            }
            else
            {
                printf("Primero debes cargar un archivo (opcion 1).\n");
            }
            break;
        case 4:
            if(flagCarga)
            {
                switch(subMenu()){
                case 1:
                    listaGeneros = ll_filter(lista, filtrarTipoAdventure);
                    controller_saveAsText("peliculasTipoAdventure.csv", listaGeneros);
                    printf("Peliculas guardadas correctamente.\n");
                    break;
                case 2:
                    listaGeneros = ll_filter(lista, filtrarTipoDrama);
                     controller_saveAsText("peliculasTipoDrama.csv", listaGeneros);
                    printf("Peliculas guardadas correctamente.\n");
                    break;
                case 3:
                    listaGeneros = ll_filter(lista, filtrarTipoComedy);
                     controller_saveAsText("peliculasTipoComedy.csv", listaGeneros);
                    printf("Peliculas guardadas correctamente.\n");
                    break;
                case 4:
                    listaGeneros = ll_filter(lista, filtrarTipoHorror);
                     controller_saveAsText("peliculasTipoHorror.csv", listaGeneros);
                    printf("Peliculas guardadas correctamente.\n");
                    break;
                case 5:
                    listaGeneros = ll_filter(lista, filtrarTipoMusical);
                     controller_saveAsText("peliculasTipoMusical.csv", listaGeneros);
                    printf("Peliculas guardadas correctamente.\n");
                    break;
                case 6:
                    listaGeneros = ll_filter(lista, filtrarTipoAction);
                     controller_saveAsText("peliculasTipoAction.csv", listaGeneros);
                    printf("Peliculas guardadas correctamente.\n");
                    break;
                default:
                    printf("La opcion ingresada es incorrecta.\n");
                    break;
                }
            }
            else
            {
                printf("Primero debes cargar un archivo (opcion 1).\n");
            }
            break;
        case 5:
            if(flagCarga)
            {
                controller_sortPeliculas(lista);
                controller_listPeliculas(lista);
                flagDuraciones=1;
            }
            else
            {
                printf("Primero debes cargar un archivo (opcion 1).\n");
            }
            break;
        case 6:
            if(flagCarga && flagDuraciones)
            {
                controller_saveAsText("peliculasListaGeneroDuracion.csv", listaGenerosDuraciones);
                printf("Peliculas guardadas correctamente.\n");
            }else if(flagCarga && (!flagDuraciones)){
                printf("Primero debes ordenar las peliculas por genero (opcion 5).\n");
            }
            else
            {
                printf("Primero debes cargar un archivo (opcion 1).\n");
            }
            break;
        case 7:
            printf("Usted salio del programa.\n");
            respuesta='n';
            system("pause");

        default:
            printf("La opcion ingresada es incorrecta. Reintente.\n");
            break;
        system("pause");
        }
        system("pause");
    }while(respuesta=='s');
    return 0;
}
