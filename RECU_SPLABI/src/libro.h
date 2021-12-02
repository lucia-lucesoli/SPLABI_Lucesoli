
#ifndef LIBRO_H_
#define LIBRO_H_

struct eLibro
{
	int id;
	char titulo[50];
	char autor[50];
	float precio;
	char editorialId[25];
	int isEmpty;
} typedef eLibro;

#endif /* LIBRO_H_ */

eLibro *new_libro(void);
eLibro *new_libroParam(int id, char *titulo, char *autor, float precio, char *editorialId);

// Setters y Getters
int set_id_libro(eLibro *libro, int id);
int get_id_libro(eLibro *libro, int *id);
int set_titulo_libro(eLibro *libro, char *titulo);
int get_titulo_libro(eLibro *libro, char *titulo);
int set_autor_libro(eLibro *libro, char *autor);
int get_autor_libro(eLibro *libro, char *autor);
int set_precio_libro(eLibro *libro, float precio);
int get_precio_libro(eLibro *libro, float *precio);
int set_editorialId_libro(eLibro *libro, char *editorialId);
int get_editorialId_libro(eLibro *libro, char *editorialId);

// Validaciones
int validar_id(int id);
int validar_titulo(char *titulo);
int validar_autor(char *autor);
int validar_precio(float precio);
int validar_editorialId(char *editorialId);

// Eliminar
int eliminar_libro(eLibro *libro);

// Mostrar Libros
void print_libro(eLibro *libro);
int print_libros(void *lista);
void print_autores(void *lista);

// Ordenamientos
int sort_libros_id(void *libro1, void *libro2);
int sort_libros_titulo(void *libro1, void *libro2);
int sort_libros_autor(void *libro1, void *libro2);
int sort_libros_precio(void *libro1, void *libro2);
int sort_libros_editorialId(void *libro1, void *libro2);

// Buscar por ID
int get_libro_byId(void *lista, int id);

// Aplicar descuentos
int aplicar_descuento(void *libro);
int filtrar_libros_minotauro(void *libro);
int libro_escrito_por_autor(void *libro, char *autor);