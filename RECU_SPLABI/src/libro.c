#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libro.h"
#include "LinkedList.h"
#include "controller.h"

/**
 * @brief Crea un puntero a libro, reservando asi espacio en la memoria dinamica
 *
 * @return si se encontro espacio, retorna el puntero, de lo contrario NULL
 */
eLibro *new_libro(void)
{
	eLibro *nuevoLibro = (eLibro *)malloc(sizeof(eLibro));
	if (nuevoLibro != NULL)
	{
		nuevoLibro->id = -1;
		strcpy(nuevoLibro->titulo, "");
		strcpy(nuevoLibro->autor, "");
		nuevoLibro->precio = 0;
		strcpy(nuevoLibro->editorialId, "");
	}
	return nuevoLibro;
}
/**
 * @brief Recibe los parametros para inicializar todos los campos de un libro
 *
 * @param id
 * @param titulo
 * @param autor
 * @param precio
 * @param editorialId
 * @return un libro si hay lugar en memoria y los parametros son validos, de lo contrario NULL
 */
eLibro *new_libroParam(int id, char *titulo, char *autor, float precio, char *editorialId)
{
	eLibro *nuevoLibro = new_libro();
	if (nuevoLibro != NULL)
	{
		if (set_id_libro(nuevoLibro, id) || set_titulo_libro(nuevoLibro, titulo) || set_autor_libro(nuevoLibro, autor) || set_precio_libro(nuevoLibro, precio) || set_editorialId_libro(nuevoLibro, editorialId))
		{
			free(nuevoLibro);
			nuevoLibro = NULL;
		}
	}
	return nuevoLibro;
}
// Setters y Getters
int set_id_libro(eLibro *libro, int id)
{
	int error = 1;
	if (libro != NULL && validar_id(id))
	{
		libro->id = id;
		error = 0;
	}
	return error;
}
int get_id_libro(eLibro *libro, int *id)
{
	int error = 1;
	if (libro != NULL)
	{
		*id = libro->id;
		error = 0;
	}
	return error;
}
int set_titulo_libro(eLibro *libro, char *titulo)
{
	int error = 1;
	if (libro != NULL && validar_titulo(titulo))
	{
		strcpy(libro->titulo, titulo);
		error = 0;
	}
	return error;
}
int get_titulo_libro(eLibro *libro, char *titulo)
{
	int error = 1;
	if (libro != NULL)
	{
		strcpy(titulo, libro->titulo);
		error = 0;
	}
	return error;
}
int set_autor_libro(eLibro *libro, char *autor)
{
	int error = 1;
	if (libro != NULL && validar_autor(autor))
	{
		strcpy(libro->autor, autor);
		error = 0;
	}
	return error;
}
int get_autor_libro(eLibro *libro, char *autor)
{
	int error = 1;
	if (libro != NULL)
	{
		strcpy(autor, libro->autor);
		error = 0;
	}
	return error;
}
int set_precio_libro(eLibro *libro, float precio)
{
	int error = 1;
	if (libro != NULL && validar_precio(precio))
	{
		libro->precio = precio;
		error = 0;
	}
	return error;
}
int get_precio_libro(eLibro *libro, float *precio)
{
	int error = 1;
	if (libro != NULL)
	{
		*precio = libro->precio;
		error = 0;
	}
	return error;
}
int set_editorialId_libro(eLibro *libro, char *editorialId)
{
	int error = 1;
	if (libro != NULL && validar_editorialId(editorialId))
	{
		strcpy(libro->editorialId, editorialId);
		error = 0;
	}
	return error;
}
int get_editorialId_libro(eLibro *libro, char *editorialId)
{
	int error = 1;
	if (libro != NULL)
	{
		strcpy(editorialId, libro->editorialId);
		error = 0;
	}
	return error;
}
// Validaciones
int validar_id(int id)
{
	int valido = 0;
	if (id >= 1 && id <= 5000)
	{
		valido = 1;
	}
	return valido;
}
int validar_titulo(char *titulo)
{
	int valido = 0;
	if (titulo != NULL && strlen(titulo) >= 3 && strlen(titulo) <= 50)
	{
		valido = 1;
	}
	return valido;
}
int validar_autor(char *autor)
{
	int valido = 0;
	if (autor != NULL && strlen(autor) >= 3 && strlen(autor) <= 50)
	{
		valido = 1;
	}
	return valido;
}
int validar_precio(float precio)
{
	int valido = 0;
	if (precio >= 1)
		valido = 1;
	return valido;
}
int validar_editorialId(char *editorialId)
{
	int valido = 0;
	if (editorialId != NULL && strlen(editorialId) >= 3 && strlen(editorialId) <= 25)
	{
		valido = 1;
	}
	return valido;
}
int eliminar_libro(eLibro *libro)
{
	int error = 1;
	if (libro != NULL)
	{
		free(libro);
		libro = NULL;
		error = 0;
	}
	return error;
}
void print_libro(eLibro *libro)
{
	printf("%4d | %50s | %20s | %8.2f | %25s\n", libro->id, libro->titulo, libro->autor, libro->precio, libro->editorialId);
}
int print_libros(void *lista)
{
	int error = 1;
	if (lista != NULL)
	{
		int tam = ll_len(lista);
		printf("%4s | %50s | %20s | %8s | %25s\n", "ID", "Titulo", "Autor", "Precio", "Editorial");
		for (int i = 0; i < tam; i++)
		{
			eLibro *libro = (eLibro *)ll_get(lista, i);
			if (libro != NULL && !libro->isEmpty)
			{
				print_libro(libro);
			}
		}
		error = 0;
	}
	return error;
}
void print_autores(void *lista)
{
	int cantidadAutores = 0;
	int tam = ll_len(lista);
	for (int i = 0; i < tam; i++)
	{
		eLibro *lib = ll_get(lista, i);
		if (!lib->isEmpty)
		{
			cantidadAutores++;
		}
	}
	char autores[cantidadAutores][50];
	int contadorAutores = 0;
	int autorExiste = 0;
	for (int i = 0; i < tam; i++)
	{
		eLibro *lib = ll_get(lista, i);
		if (!lib->isEmpty)
		{
			for (int j = 0; j < cantidadAutores; j++)
			{
				if (strcmp(autores[j], lib->autor) == 0)
				{
					autorExiste = 1;
					break;
				}
			}
			if (!autorExiste)
			{
				strcpy(autores[contadorAutores], lib->autor);
				contadorAutores++;
			}
		}
	}

	for (int i = 0; i < contadorAutores; i++)
	{
		printf("%d: %s\n", (i + 1), autores[i]);
	}
}
// Ordenamientos
int sort_libros_id(void *libro1, void *libro2)
{
	int orden = 0;
	eLibro *l1 = (eLibro *)libro1;
	eLibro *l2 = (eLibro *)libro2;
	if (l1->id > l2->id)
	{
		orden = 1;
	}
	else if (l1->id < l2->id)
	{
		orden = -1;
	}
	return orden;
}
int sort_libros_titulo(void *libro1, void *libro2)
{
	int orden = 0;
	eLibro *l1 = (eLibro *)libro1;
	eLibro *l2 = (eLibro *)libro2;
	if (strcmp(l1->titulo, l2->titulo) > 0)
	{
		orden = 1;
	}
	else if (strcmp(l1->titulo, l2->titulo) < 0)
	{
		orden = -1;
	}
	return orden;
}
int sort_libros_autor(void *libro1, void *libro2)
{
	int orden = 0;
	eLibro *l1 = (eLibro *)libro1;
	eLibro *l2 = (eLibro *)libro2;
	if (strcmp(l1->autor, l2->autor) > 0)
	{
		orden = 1;
	}
	else if (strcmp(l1->autor, l2->autor) < 0)
	{
		orden = -1;
	}
	return orden;
}
int sort_libros_precio(void *libro1, void *libro2)
{
	int orden = 0;
	eLibro *l1 = (eLibro *)libro1;
	eLibro *l2 = (eLibro *)libro2;
	if (l1->precio > l2->precio)
	{
		orden = 1;
	}
	else if (l1->precio < l2->precio)
	{
		orden = -1;
	}
	return orden;
}
int sort_libros_editorialId(void *libro1, void *libro2)
{
	int orden = 0;
	eLibro *l1 = (eLibro *)libro1;
	eLibro *l2 = (eLibro *)libro2;
	if (strcmp(l1->editorialId, l2->editorialId) > 0)
	{
		orden = 1;
	}
	else if (strcmp(l1->editorialId, l2->editorialId) < 0)
	{
		orden = -1;
	}
	return orden;
}
// Buscar por ID
int get_libro_byId(void *lista, int id)
{
	int index = -1;
	if (lista != NULL && validar_id(id))
	{
		int tam = ll_len(lista);
		for (int i = 0; i < tam; i++)
		{
			eLibro *libro_aux = (eLibro *)ll_get(lista, i);
			if (libro_aux->id == id)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
int aplicar_descuento(void *libro)
{
	int error = 1;
	if (libro != NULL)
	{
		eLibro *lib = (eLibro *)libro;
		if (strcmp(lib->editorialId, "Planeta") == 0 && lib->precio >= 300)
		{
			lib->precio *= 0.8;
		}
		else if (strcmp(lib->editorialId, "SIGLO XXI EDITORES") == 0 && lib->precio <= 200)
		{
			lib->precio *= 0.9;
		}
		error = 0;
	}
	return error;
}
int filtrar_libros_minotauro(void *libro)
{
	int valido = 0;
	if (libro != NULL)
	{
		eLibro *lib = (eLibro *)libro;
		if (strcmp(lib->editorialId, "Minotauro") == 0)
		{
			valido = 1;
		}
	}
	return valido;
}
int libro_escrito_por_autor(void *libro, char *autor)
{
	int valido = 0;
	if (libro != NULL && strlen(autor) > 0)
	{
		eLibro *lib = (eLibro *)libro;
		if (strcmp(lib->autor, autor) == 0)
		{
			valido = 1;
		}
	}
	return valido;
}
