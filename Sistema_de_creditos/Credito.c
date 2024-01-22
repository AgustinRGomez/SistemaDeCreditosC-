/*
 * Credito.c
 *
 *  Created on: Feb 8, 2020
 *      Author: Agustin
 */

#include <stdio.h>
#include <String.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Credito.h"
#include "lista_de_credito.h"
#include "Clientes.h"

void credito_init(Credito* credito, double prestamo, char* motivo) {

	credito->estado = true;

	credito->motivo = (char*) malloc(sizeof(char) * (strlen(motivo) + 1));

	strcpy(credito->motivo, motivo);

	if (prestamo > 0 && prestamo <= 100000) {

		credito->prestamo = prestamo;
	}

}
/*eliminar credito */
void cancelar_credito(Credito* this) {

	if (this->estado == 1) {

		if (this->motivo) {
			free(this->motivo);
		}

		if (this->prestamo) {
			this->prestamo = 0;
		}
		if (this->estado) {
			this->estado = true;
		}
	}
	this->motivo = 0x0;

}

/* pagar prestamo*/
void pagar_credito(Credito* this, double monto) {

	if (this->prestamo != 0) {

		this->prestamo = this->prestamo - monto;
	}
	if (this->prestamo == 0) {
		this->estado = 0;
	}

}
void imprimir_credito(Credito* this) {
	Credito* self = (Credito*) this;
	char* a;
	if (self->estado == 0) {
		a = "pagado";
	} else {
		a = "no pagado";
	}
	printf("                  Estado : %s , Prestamo : %f , Motivo : %s \n", a,
			self->prestamo, self->motivo);

}
void guardar_credito(FILE* file, Credito* this) {
	Credito* self = (Credito*) this;
	char* a;
	if (self->estado == 0) {
		a = "pagado";
	} else {
		a = "no pagado";
	}
	fprintf(file, "                     Estado : %s", a);
	fputs(" , ", file);
	fprintf(file, "Prestamo: %f ", self->prestamo);
	fputs(" , ", file);
	fprintf(file, "Motivo : %s ", self->motivo);
	fputs("\n", file);

}
