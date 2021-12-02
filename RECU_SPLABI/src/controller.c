#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "LinkedList.h"
#include "libro.h"

/**
 * @brief Parsea los datos desde el archivo .csv (modo texto)
 *
 * @param pFile
 * @param lista
 * @return
 */
int parser_text(FILE* pFile , LinkedList* lista)
{
	int retorno = -1;

	if (pFile != NULL && lista != NULL) {
		int cant;
		int salida = 0;
		eLibro* libro;
		char idStr[50], titulo[50], autor[50], precioStr[50], editorialId[50];

		while (!salida) {
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, titulo, autor, precioStr, editorialId);
			if (cant == 5) {
				libro = new_libroParam(atoi(idStr), titulo, autor, atof(precioStr), editorialId);
				if (libro != NULL) {
					ll_add(lista, libro);
				}
			}
			salida = feof(pFile);
		}
		retorno = atoi(idStr);
	}

	return retorno;
}
/**
 * @brief Parsea los datos desde el archivo .bin (modo binario)
 *
 * @param pFile
 * @param lista
 * @return
 */
int parser_binary(FILE* pFile , LinkedList* lista)
{
	int retorno = -1;
	eLibro* libro = NULL;
	int id;
	char titulo[50];
	char autor[50];
	float precio;
	char editorialId[25];

	if (pFile != NULL && lista != NULL) {
		do {
			if (fread(&id, sizeof(int), 1, pFile)
				&& fread(titulo, 50, 1, pFile)
				&& fread(autor, 50, 1, pFile)
				&& fread(&precio, sizeof(float), 1, pFile)
				&& fread(editorialId, 25, 1, pFile)
			) {
				libro = new_libroParam(id, titulo, autor, precio, editorialId);
				if (libro != NULL) {
					ll_add(lista, libro);
					retorno = id;
				}
			}
		} while (!feof(pFile));
	}

	return retorno;
}
int leerArchivoTexto(LinkedList* lista, char* path)
{
	int error = 1;
	if (lista != NULL && path != NULL) {
		FILE* f = fopen(path, "r");
		if (f != NULL && parser_text(f, lista) > 0) {
			error = 0;
		}
		fclose(f);
	}
	return error;
}
int leerArchivoBinario(LinkedList* lista, char* path)
{
	int error = 1;
	if (lista != NULL && path != NULL) {
		FILE* f = fopen(path, "rb");
		if (f != NULL && parser_binary(f, lista) > 0) {
			error = 0;
		}
		fclose(f);
	}
	return error;
}
int guardar_texto(char* path , LinkedList* lista)
{
    int error = 1;
    int tam = ll_len(lista);
    eLibro* libro = (eLibro*) malloc(sizeof(eLibro));
    if (lista != NULL && tam > 0) {
    	FILE* f = fopen(path, "w");
    	for (int i = 0; i < tam; i++) {
    		libro = ll_get(lista, i);
    		if (libro != NULL) {
    			fprintf(f, "%d,%s,%s,%.2f,%s\n", libro->id, libro->titulo, libro->autor, libro->precio, libro->editorialId);
    		}
    	}
    	error = 0;
    	free(libro);
    	fclose(f);
    }

    return error;
}


