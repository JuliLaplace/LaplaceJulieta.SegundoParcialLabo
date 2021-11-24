#include <stdio.h>
#include <stdlib.h>
#include"menu.h"

int menu(){

        int opcion;
        system("cls");

        printf("*****************************************************************************************\n");
        printf("\t\t\t   ********MENU DE OPCIONES********\n");
        printf("*****************************************************************************************\n");
        printf("1. CARGAR ARCHIVO.\n");
        printf("2. IMPRIMIR LISTA DE PELICULAS.\n");
        printf("3. ASIGNAR TIEMPOS.\n");
        printf("4. FILTRAR POR GENERO.\n");
        printf("5. MOSTRAR DURACIONES.\n");
        printf("6. GUARDAR PELICULAS.\n");
        printf("7. SALIR.\n");
        printf("*****************************************************************************************\n");
        fflush(stdin);
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        return opcion;

}

int subMenu(){

        int opcion;
        system("cls");

        printf("*****************************************************************************************\n");
        printf("\t\t\t   ********MENU DE GENEROS********\n");
        printf("*****************************************************************************************\n");
        printf("1. Adventure.\n");
        printf("2. Drama.\n");
        printf("3. Comedy.\n");
        printf("4. Horror.\n");
        printf("5. Musical.\n");
        printf("6. Action.\n");
        printf("*****************************************************************************************\n");
        fflush(stdin);
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        return opcion;

}
