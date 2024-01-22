/*
 * lista.h
 *
 *  Created on: Feb 4, 2020
 *      Author: Agustin
 */

#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Clientes.h"
#include "Credito.h"
#include "lista_de_credito.h"

typedef struct Nodo {
	Clientes cliente;
	struct Nodo* siguiente;
} Nodo;

typedef struct lista {
	Nodo* inicio;
	Nodo* fin;
	int tam;

} lista;



/* inicialización de la lista */
void inicializacion(lista* lista);

/* inserción al inicio de la lista */
int ins_inicio_lista(lista* lista, Clientes* cliente);

/* busca clientes por el nombre y los guarda en una lista*/
void buscar_clientes_por_nombre(lista* a, lista*b, char* dato);

/*buscar clientes por rango de edad y los guarda en una lista*/
void buscar_clientes_por_rango(lista* a, lista*b, int edad1, int edad2);

/* supresion al inicio de la lista */
int sup_inicio(lista* lista);

/* supresion en otra parte de la lista */
int sup_en_lista(lista* lista, int pos);

/*elimina una lista*/
void destruir(lista* lista);

/*muestra la lista de los clientes*/
void ver_lista_clientes(lista* lista);


/* agregar credito a una cliente*/
void agregar_credito_a_cliente(lista*lista,char* nombre,char* apellido,Credito* credito);

/* agrega credito a clientes que tengan el mismo nombre*/
void agregar_credito_a_cliente2(lista*lista,char* nombre,Credito* credito);

/* agrega credito a clientes que tengan el mismo nombre*/
void agregar_credito_a_cliente3(lista*lista,int edad1,int edad2,Credito* credito);

/* paga credito a una cliente*/
void pagar_credito_del_cliente(lista * lista,char* nombre,char* apellido,char* motivo,double dinero);
/* cancela credito a una cliente*/
void cancelar_credito_del_cliente(lista * lista,char* nombre,char* apellido,char* motivo);

/* elimina un cliente de la lista*/
void eliminar_cliente_de_lista(lista* lista,char* nombre,char* apellido);

/* te guarda la lista de clientes en un archivo ,dicho nombre de archivo es */
void guardar_lista_de_clientes(lista* lista,char* archivo);

#endif /* LISTA_H_ */
