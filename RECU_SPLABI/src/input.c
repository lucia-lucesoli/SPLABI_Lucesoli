#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "libro.h"
#include "LinkedList.h"

int carga_nuevo_libro(void* lista, int id)
{
	int error = 1;
	if (lista != NULL && id > 0) {
		eLibro* libro = NULL;
		printf("Ingrese el titulo del libro: ");
		char titulo[50];
		fflush(stdin);
		scanf("%s", titulo);

		printf("Ingrese el autor del libro: ");
		char autor[50];
		fflush(stdin);
		scanf("%s", autor);

		printf("Ingrese el precio del libro: ");
		float precio;
		fflush(stdin);
		scanf("%f", &precio);

		printf("Ingrese la editorial del libro: ");
		char editorialId[50];
		fflush(stdin);
		scanf("%s", editorialId);

		libro = new_libroParam(id, titulo, autor, precio, editorialId);
		if (libro != NULL) {
			ll_add(lista, libro);
			error = 0;
		}
	}
	return error;
}
int carga_archivo(char* path)
{
	int error = 1;
	printf("Ingrese el nombre del archivo: ");
	fflush(stdin);
	scanf("%s", path);
	if (strlen(path) > 3) {
		error = 0;
	}

	return error;
}
int input_autor_filtrado(char* autor)
{
	int error = 1;
	printf("Ingrese el nombre del autor a filtrar: ");
	fflush(stdin);
	scanf("%s", autor);
	if (strlen(autor) > 3) {
		error = 0;
	}
	return error;
}
int get_YN_input()
{
	int retorno = -1;
	printf("Ingrese S o N: ");
	char cont;
	fflush(stdin);
	scanf("%c", &cont);
	if (cont == 'S') retorno = 1;
	if (cont == 'N') retorno = 0;
	return retorno;
}

