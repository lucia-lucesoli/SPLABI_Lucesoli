#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "input.h"
#include "libro.h"
#include "controller.h"

int guardar_ll_mapeada(void *lista);
int guardar_ll_filtrada(void *lista);
int guardar_ll_filtrada_autor(void *lista);

int main()
{
	setbuf(stdout, NULL);

	LinkedList *lista = ll_newLinkedList();

	// El nombre del archivo se debe pasar como parametro por linea de comandos
	printf("***        PROGRAMA LIBROS        ***\n\n"
			"\n- Se leera un archivo con los datos de los libros."
			"\n- Se ordenara la lista de libros."
			"\n- Se realizaran porcentajes de descuentos del 20 para EDITORIAL PLANETA y 10 para EDITORIAL SIGLO XXI EDITORIES."
			"\n- Se generara un archivo de salida: mapeado.csv"
			"\n- Se filtrara una lista por la editorial MINOTAURO.\n\n");

	char archivo[100];
	carga_archivo(archivo);

	if (archivo != NULL)
	{
		// Leer un archivo con los datos de libros, guardandolos en una linkedlist de entidades eLibro
		if (!leerArchivoTexto(lista, archivo))
		{
			printf("Lista cargada con exito\n");
			print_libros(lista);
			printf("\n\n--------------------------------------------------------------------------------------------------------------------------\n");
			printf("Lista ordenada por Autor\n");
			// Ordenar la lista generada en el item anterior, con la funcion ll_sort, segun el criterio de ordenamiento "Autor" de manera ascendente
			ll_sort(lista, sort_libros_autor, 1);
			// Imprimir por pantalla todos los datos de los libros
			print_libros(lista);
			// Desarrollar funcion ll_map que aplicara descuentos
			if (!guardar_ll_mapeada(lista))
			{
				printf("Guardada lista mapeada en mapeado.csv\n");
			}
			if (!guardar_ll_filtrada(lista))
			{
				printf("Guardada lista filtrada en minotauroLibros.csv\n");
			}

			printf("\n\nDesea filtrar por autor? (S/N): ");
			if (get_YN_input())
			{
				guardar_ll_filtrada_autor(lista);
			}
		}
		else
		{
			printf("\nNo se encontro el archivo especificado. El mismo debe colocarse en la carpeta src del proyecto.\n");
		}
	}

	system("pause");

	return EXIT_SUCCESS;
}

int guardar_ll_mapeada(void *lista)
{
	int error = 1;
	LinkedList *ll_mapeada = ll_map(lista, aplicar_descuento);
	if (ll_mapeada != NULL && !guardar_texto("mapeado.csv", lista))
	{
		error = 0;
	}
	return error;
}
int guardar_ll_filtrada(void *lista)
{
	int error = 1;
	LinkedList *ll_filtrada = ll_filter(lista, filtrar_libros_minotauro);
	if (ll_filtrada != NULL && !guardar_texto("minotauroLibros.csv", ll_filtrada))
	{
		error = 0;
	}
	return error;
}
int guardar_ll_filtrada_autor(void *lista)
{
	int error = 1;
	print_autores(lista);
	char autor[100];
	fflush(stdin);
	scanf("%s", autor);
	LinkedList *ll_filtrada = ll_filter_autor(lista, libro_escrito_por_autor, autor);
	if (ll_filtrada != NULL && !guardar_texto("filtroAutor.csv", ll_filtrada))
	{
		error = 0;
	}
	return error;
}
