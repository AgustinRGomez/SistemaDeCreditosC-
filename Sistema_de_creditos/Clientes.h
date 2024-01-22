/*
 * Clientes.h
 *
 *  Created on: Jan 24, 2020
 *      Author: Agustin
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista_de_credito.h"
#include "Credito.h"

typedef struct _Clientes {
	char* nombre;
	char* apellido;
	int edad;
	double monto;
	double total;
	lista2 lista;

} Clientes;

/*
 *nombre de los metodos del cliente
 */
void cliente_init(Clientes* this, char* nombre, char* apellido, int edad);
void eliminar_cliente(Clientes* this);
void imprimir_cliente(Clientes* this);
void ver_lista_cre(lista2* lista);
void guardar_cliente_en_archivo(FILE *file, Clientes cliente);



#endif /* CLIENTES_H_ */
