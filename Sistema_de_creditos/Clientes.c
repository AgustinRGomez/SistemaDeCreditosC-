/*
 * Clientes.c
 *
 *  Created on: Jan 24, 2020
 *      Author: Agustin
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Clientes.h"
#include "Credito.h"

/*
 * inicializa un cliente
 */
void cliente_init(Clientes* this, char* nombre, char* apellido, int edad) {

	this->monto = 0;
	if (edad >= 18 && edad <= 70) {

		this->edad = edad;
	}
	this->apellido = (char*) malloc(sizeof(char) * (strlen(apellido) + 1));

	strcpy(this->apellido, apellido);

	this->nombre = (char*) malloc(sizeof(char) * (strlen(nombre) + 1));

	strcpy(this->nombre, nombre);

	this->total = 0;

	this->lista.inicio = NULL;
	this->lista.fin = NULL;
	this->lista.tam = 0;

}
/*
 * libera los datos del cliente
 */
void eliminar_cliente(Clientes* this) {
	if (this->nombre) {
		free(this->nombre);
	}
	if (this->apellido) {
		free(this->apellido);
	}
	if (this->edad) {
		this->edad = 0;
	}
	this->nombre = 0x0;
	this->apellido = 0x0;

}
/*
 * me imprime los datos de un cliente
 */
void imprimir_cliente(Clientes* this) {
	Clientes* self = (Clientes*) this;

	printf("Nombre y apellido : %s %s , Edad : %d , Monto : %f \n",
			self->nombre, self->apellido, self->edad, self->monto);

	ver_lista_cre(&self->lista);
}
void ver_lista_cre(lista2* lista) {
	Nodo2 *actual;
	actual = lista->inicio;
	printf("Lista de Creditos { \n");
	while (actual != NULL) {
		imprimir_credito(&actual->credito);
		actual = actual->siguiente;
	}
	printf("                  }");
	printf("cantidad de creditos : %d \n", lista->tam);
	printf("\n");
}
void guardar_cliente_en_archivo(FILE *file, Clientes cliente) {

	fprintf(file, "Nombre y Apellido : %s %s", cliente.nombre,
			cliente.apellido);
	fputs(" , ", file);
	fprintf(file, "Edad : %d ", cliente.edad);
	fputs(" , ", file);
	fprintf(file, "Monto : %f ", cliente.monto);
	fputs("\n", file);

	Nodo2 *act;
	act = cliente.lista.inicio;

	fputs("Lista de Creditos : { ", file);
	fputs("\n", file);
	while (act != NULL) {
		guardar_credito(file, &act->credito);
		act = act->siguiente;
	}
	fputs("                    }", file);
	fprintf(file, "cantidad de creditos : %d ", cliente.lista.tam);
	fputs("\n", file);

}

