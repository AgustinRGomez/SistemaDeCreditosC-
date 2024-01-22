/*
 * lista_de_credito.c
 *
 *  Created on: Feb 8, 2020
 *      Author: Agustin
 */
#include <stdlib.h>
#include <string.h>
#include "lista_de_credito.h"
#include "Credito.h"
#include "lista.h"

/* inicialización de la lista */
void iniciar_lista(lista2* lista) {
	lista->inicio = NULL;
	lista->fin = NULL;
	lista->tam = 0;
}
int ingresar_credito(lista2* lista, Credito* credito) {

	Nodo2 *n_nodo;
	if ((n_nodo = (Nodo2 *) malloc(sizeof(Nodo2))) == NULL) {

		return -1;
	}

	credito_init(&n_nodo->credito, credito->prestamo, credito->motivo);

	n_nodo->siguiente = NULL;

	if (lista->inicio == NULL) {
		n_nodo->siguiente = NULL;
		lista->inicio = n_nodo;
		lista->fin = n_nodo;
		lista->tam++;
	} else {
		n_nodo->siguiente = lista->inicio;
		lista->inicio = n_nodo;
		lista->tam++;
	}
	return 0;
}

/* supresion al inicio de la lista */
int sup_credito(lista2* lista) {

	if (lista->tam == 0)
		return -1;

	Nodo2 *sup_elemento;
	sup_elemento = lista->inicio;
	lista->inicio = lista->inicio->siguiente;

	if (lista->tam == 1)
		lista->fin = NULL;

	cancelar_credito(&sup_elemento->credito);
	free(sup_elemento);

	lista->tam--;
	return 0;
}
/* supresion en otra parte de la lista */
int sup_credito_en(lista2 * lista, int pos) {
	if (lista->tam <= 1 || pos < 1 || pos >= lista->tam)
		return -1;
	int i;
	Nodo2 *actual;
	Nodo2 *sup_elemento;
	actual = lista->inicio;

	for (i = 1; i < pos; ++i)
		actual = actual->siguiente;

	sup_elemento = actual->siguiente;
	actual->siguiente = actual->siguiente->siguiente;
	if (actual->siguiente == NULL)
		lista->fin = actual;
	cancelar_credito(&sup_elemento->credito);
	free(sup_elemento);
	lista->tam--;
	return 0;
}

/*elimina una lista*/
void destruir_lista(lista2* lista) {
	while (lista->tam > 0)
		sup_credito(lista);
}
/*muestra la lista de creditos*/


