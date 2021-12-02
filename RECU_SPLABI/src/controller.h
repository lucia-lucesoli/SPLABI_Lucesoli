#include "LinkedList.h"
#include <stdio.h>

#ifndef READER_H_
#define READER_H_

int parser_text(FILE* pFile , LinkedList* lista);
int parser_binary(FILE* pFile , LinkedList* lista);
int leerArchivoTexto(LinkedList* lista, char* path);
int leerArchivoBinario(LinkedList* lista, char* path);
int guardar_texto(char* path , LinkedList* lista);


#endif /* READER_H_ */

