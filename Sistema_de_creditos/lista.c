/*
 * lista.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Agustin
 */

#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include "lista_de_credito.h"
#include "Credito.h"

void inicializacion(lista* lista) {
	lista->inicio = NULL;
	lista->fin = NULL;
	lista->tam = 0;
}

/* inserción al inicio de la lista */
int ins_inicio_lista(lista* lista, Clientes* cliente) {
	Nodo *n_nodo;
	if ((n_nodo = (Nodo *) malloc(sizeof(Nodo))) == NULL) {

		return -1;
	}
	cliente_init(&n_nodo->cliente, cliente->nombre, cliente->apellido,
			cliente->edad);

	n_nodo->cliente.lista = cliente->lista;

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

/* eliminación al inicio de la lista */
int sup_inicio(lista* lista) {

	if (lista->tam == 0)
		return -1;

	Nodo *sup_elemento;
	sup_elemento = lista->inicio;
	lista->inicio = lista->inicio->siguiente;

	if (lista->tam == 1)
		lista->fin = NULL;

	eliminar_cliente(&sup_elemento->cliente);

	lista->tam--;
	return 0;
}
int sup_en_lista(lista* lista, int pos) {
	if (lista->tam <= 1 || pos < 1 || pos >= lista->tam)
		return -1;
	int i;
	Nodo *actual;
	Nodo *sup_elemento;
	actual = lista->inicio;

	for (i = 1; i < pos; ++i)
		actual = actual->siguiente;

	sup_elemento = actual->siguiente;
	actual->siguiente = actual->siguiente->siguiente;
	if (actual->siguiente == NULL)
		lista->fin = actual;

	eliminar_cliente(&sup_elemento->cliente);

	lista->tam--;
	return 0;
}

/* imprime la lista de clientes*/
void ver_lista_clientes(lista* lista) {

	Nodo *actual;
	actual = lista->inicio;
	printf("Lista de Clientes [ \n");
	while (actual != NULL) {
		imprimir_cliente(&actual->cliente);

		actual = actual->siguiente;
	}

	printf("]");
	printf("cantidad de clientes : %d \n", lista->tam);
}
/* destruir la lista */
void destruir(lista* lista) {
	while (lista->tam > 0)
		sup_inicio(lista);
}
/* buscar clientes por nombre*/
void buscar_clientes_por_nombre(lista* a, lista*b, char* dato) {

	Nodo *actual;

	actual = b->inicio;
	while (actual != NULL) {
		if (!strcmp(actual->cliente.nombre, dato)) {

			ins_inicio_lista(a, &actual->cliente);
			a->inicio->cliente.monto = actual->cliente.monto;
		}
		actual = actual->siguiente;

	}

}
/* buscar clientes por nombre*/
void buscar_clientes_por_rango(lista* a, lista*b, int edad1, int edad2) {

	Nodo *actual;

	actual = b->inicio;
	while (actual != NULL) {
		if (actual->cliente.edad >= edad1 && actual->cliente.edad <= edad2) {

			ins_inicio_lista(a, &actual->cliente);
			a->inicio->cliente.monto = actual->cliente.monto;

		}
		actual = actual->siguiente;

	}

}
/*recorre la lista buscando el cliente,una vez encontrado le agrega credito al cliente.
 * El cliente puede pedir un credito de a lo sumo 100000 pesos como maximo.
 * Si quiere pedir mas debe pagar una parte del credito.
 *
 *  */
void agregar_credito_a_cliente(lista*lista, char* nombre, char* apellido,
		Credito*credito) {

	Nodo *actual;
	actual = lista->inicio;

	while (actual != NULL) {

		if (!strcmp(actual->cliente.nombre, nombre)
				&& !strcmp(actual->cliente.apellido, apellido)) {

			if (actual->cliente.total < 100000) {
				ingresar_credito(&actual->cliente.lista, credito);
				actual->cliente.monto += credito->prestamo;
				actual->cliente.total += credito->prestamo;
			}
		}

		actual = actual->siguiente;
	}

}
void agregar_credito_a_cliente2(lista*lista, char* nombre, Credito* credito) {
	Nodo *actual;
	actual = lista->inicio;

	while (actual != NULL) {

		if (!strcmp(actual->cliente.nombre, nombre)) {

			if (actual->cliente.total < 100000) {
				ingresar_credito(&actual->cliente.lista, credito);
				actual->cliente.monto += credito->prestamo;
				actual->cliente.total += credito->prestamo;
			}
		}

		actual = actual->siguiente;
	}
}
void agregar_credito_a_cliente3(lista*lista, int edad1, int edad2,
		Credito* credito) {
	Nodo *actual;
	actual = lista->inicio;

	while (actual != NULL) {

		if (actual->cliente.edad >= edad1 && actual->cliente.edad <= edad2) {

			if (actual->cliente.total < 100000) {
				ingresar_credito(&actual->cliente.lista, credito);
				actual->cliente.monto += credito->prestamo;
				actual->cliente.total += credito->prestamo;
			}
		}

		actual = actual->siguiente;
	}

}
void pagar_credito_del_cliente(lista * lista, char* nombre, char* apellido,
		char* motivo, double dinero) {

	if (dinero >= 0 && dinero <= 100000) {

		Nodo *actual;
		actual = lista->inicio;

		while (actual != NULL) {

			if (!strcmp(actual->cliente.nombre, nombre)
					&& !strcmp(actual->cliente.apellido, apellido)) {

				Nodo2 * act;
				act = actual->cliente.lista.inicio;

				while (act != NULL) {

					if (!strcmp(act->credito.motivo, motivo)
							&& (dinero <= 100000 && dinero >= 0
									&& dinero <= act->credito.prestamo)
							&& act->credito.prestamo != 0) {

						pagar_credito(&act->credito, dinero);
						actual->cliente.monto = actual->cliente.monto - dinero;
						actual->cliente.total = actual->cliente.total - dinero;
					}
					act = act->siguiente;
				}
			}

			actual = actual->siguiente;
		}
	}
}

void cancelar_credito_del_cliente(lista * lista, char* nombre, char* apellido,
		char* motivo) {

	Nodo *actual;
	actual = lista->inicio;
	int pos;

	while (actual != NULL) {

		if (!strcmp(actual->cliente.nombre, nombre)
				&& !strcmp(actual->cliente.apellido, apellido)) {

			Nodo2 * act;
			act = actual->cliente.lista.inicio;

			while (act != NULL) {

				if ((!strcmp(act->credito.motivo, motivo))
						&& act->credito.estado == 0
						&& act->credito.prestamo == 0) {

					if (pos == 0) {
						sup_credito(&actual->cliente.lista);

					} else {
						sup_credito_en(&actual->cliente.lista, pos);
						pos = 0;

					}

				} else {
					pos++;
				}

				act = act->siguiente;
			}
		}

		actual = actual->siguiente;
	}
}
void eliminar_cliente_de_lista(lista* lista, char* nombre, char* apellido) {

	Nodo *actual;
	actual = lista->inicio;
	int pos = 0;

	while (actual != NULL) {

		if (!strcmp(actual->cliente.nombre, nombre)
				&& (!strcmp(actual->cliente.apellido, apellido))) {

			if (pos == 0) {

				sup_inicio(lista);
			} else {

				sup_en_lista(lista, pos);
				pos = 0;
			}
		} else {
			pos++;
		}

		actual = actual->siguiente;
	}
}

void guardar_lista_de_clientes(lista* lista, char* archivo) {

	FILE* file = fopen(archivo, "a");

	if (file == NULL) {
		perror("Error en la creacion del archivo");

	} else {

		Nodo *actual;
		actual = lista->inicio;

		fputs("Lista de Clientes : [ ", file);
		fputs("\n", file);
		while (actual != NULL) {

			guardar_cliente_en_archivo(file, actual->cliente);

			actual = actual->siguiente;
		}
		fputs("]", file);
		fprintf(file, "cantidad de clientes : %d ", lista->tam);
		fputs("\n", file);

	}
	fflush(file);
	fclose(file);

}
