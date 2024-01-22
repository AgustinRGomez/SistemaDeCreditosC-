/*
 * Credito.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Agustin
 */

#ifndef CREDITO_H_
#define CREDITO_H_

#include <stdio.h>
#include <String.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct _Credito {

	bool estado;
	double prestamo;
	char* motivo;


} Credito;

void credito_init(Credito* credito,double prestamo,char* motivo);
/*eliminar credito */
void cancelar_credito(Credito* this);

/* pagar prestamo*/
void pagar_credito(Credito* this,double monto);
void imprimir_credito(Credito* this);
void guardar_credito(FILE* file,Credito* this);


#endif /* CREDITO_H_ */
