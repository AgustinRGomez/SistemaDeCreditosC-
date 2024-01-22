/*
 * lista_de_credito.h
 *
 *  Created on: Feb 8, 2020
 *      Author: Agustin
 */

#ifndef LISTA_DE_CREDITO_H_
#define LISTA_DE_CREDITO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Credito.h"



typedef struct Nodo2 {
	Credito credito;
	struct Nodo2* siguiente;
} Nodo2;

typedef struct lista2 {
	Nodo2* inicio;
	Nodo2* fin;
	int tam;

} lista2;

/* inicialización de la lista */
void iniciar_lista(lista2* lista);

/* inserción al inicio de la lista */
int ingresar_credito(lista2* lista,Credito* credito);

/* supresion al inicio de la lista */
int sup_credito(lista2* lista);

/* supresion en otra parte de la lista */
int sup_credito_en(lista2 * lista, int pos);

/*elimina una lista*/
void destruir_lista(lista2* lista);


#endif /* LISTA_DE_CREDITO_H_ */
