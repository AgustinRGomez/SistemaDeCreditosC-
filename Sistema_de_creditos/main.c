#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Clientes.h"
#include "lista.h"
#include "Credito.h"

/*Created on: Jan 24, 2020
 *      Author: Agustin
 *
 */
int main(void) {

	int opc = 0;
	char nombre[50];
	char*p;
	char apellido[50];
	char*t;
	char motivo[50];
	char* m;
	char archivo[50];
	char* a;
	int edad;
	Credito p1;
	/* las variables x,edad1,edad2 y list2
	 * son para las opciones de la forma
	 * de imprimir la lista
	 */
	lista list2;
	inicializacion(&list2);
	int x = 0;
	int edad1;
	int edad2;

	double prestamo, dinero;
	lista list;
	inicializacion(&list);

	while (opc != 9) {

		printf("\n");
		printf("SISTEMA DE CREDITOS \n");
		printf("1.- agregar cliente a la lista \n");
		printf("2.- eliminar cliente de la lista \n");
		printf("3.- agregar credito al cliente \n");
		printf("4.- pagar credito del cliente \n");
		printf("5.- cancelar credito del cliente \n");
		printf("6.- imprimir lista \n");
		printf("7.- guardar lista \n");
		printf("8. -borrar lista  \n");
		printf("9. -salir \n");

		printf("Indica la opcion: ");
		fflush( stdin);
		scanf("%d", &opc);

		switch (opc) {

		case 1:

			printf("ingresar nombre del cliente :");
			fflush( stdin);
			scanf("%s", nombre);
			p = nombre;
			printf("ingresar apellido del cliente :");
			fflush( stdin);
			scanf("%s", apellido);
			t = apellido;

			printf("ingresar edad del cliente :");
			fflush( stdin);
			scanf("%d", &edad);

			if (edad >= 18 && edad <= 70) {

				Clientes c1;

				cliente_init(&c1, p, t, edad);

				ins_inicio_lista(&list, &c1);

				printf("CLIENTE AGREGADO CON EXITO");
				printf("\n");
			} else {
				printf("La edad ingresada del cliente es incorrecta."
						"La edad debe estar entre los 18 a 70 ");
				printf("\n");
			}
			fflush( stdin);
			break;

		case 2:

			printf("ingresar nombre del cliente :");
			fflush( stdin);
			scanf("%s", nombre);
			p = nombre;

			printf("ingresar apellido del cliente :");
			fflush( stdin);
			scanf("%s", apellido);
			t = apellido;

			eliminar_cliente_de_lista(&list, p, t);

			printf("CLIENTE ELIMINADO CON EXITO");
			printf("\n");
			printf("\n");

			fflush( stdin);
			break;
		case 3:

			printf("1.- forma tradicional \n");
			printf("2.- por nombre \n");
			printf("3.- por rango de edad \n");

			printf("Indica la opcion: ");

			fflush( stdin);
			scanf("%d", &x);

			switch (x) {
			case 1:
				printf("ingresar nombre del cliente :");
				fflush( stdin);
				scanf("%s", nombre);
				p = nombre;

				printf("ingresar apellido del cliente :");
				fflush( stdin);
				scanf("%s", apellido);
				t = apellido;

				printf("ingresar el valor del credito :");
				fflush( stdin);
				scanf("%lf", &prestamo);
				getchar();

				printf("ingresar motivo del credito :");
				m = gets(motivo);

				if (prestamo > 0 && prestamo <= 100000) {

					credito_init(&p1, prestamo, m);

					agregar_credito_a_cliente(&list, p, t, &p1);

					printf("CREDITO AGREGADO CON EXITO");

					printf("\n");
				} else {
					printf(
							"El valor del prestamo es incorrecto.Recuerde que el "
									"prestamo tiene que se mayor a 0 y menor o igual a 100000 ");
				}
				break;
			case 2:
				printf("ingresar nombre :");
				fflush( stdin);
				scanf("%s", nombre);
				p = nombre;

				printf("ingresar el valor del credito :");
				fflush( stdin);
				scanf("%lf", &prestamo);
				getchar();

				printf("ingresar motivo del credito :");
				m = gets(motivo);

				if (prestamo > 0 && prestamo <= 100000) {
					credito_init(&p1, prestamo, m);

					agregar_credito_a_cliente2(&list, p, &p1);

					printf("CREDITOS AGREGADOS CON EXITO");
					printf("\n");
				} else {
					printf(
							"El valor del prestamo es incorrecto.Recuerde que el "
									"prestamo tiene que se mayor a 0 y menor o igual a 100000 ");
				}
				break;
			case 3:

				printf("ingresar el valor del credito :");
				fflush( stdin);
				scanf("%lf", &prestamo);
				getchar();
				printf("ingresar motivo del credito :");
				m = gets(motivo);

				printf("ingresar edad1 :");
				fflush( stdin);
				scanf("%d", &edad1);
				printf("ingresar edad2 :");
				fflush( stdin);
				scanf("%d", &edad2);

				if (prestamo > 0 && prestamo <= 100000) {
					credito_init(&p1, prestamo, m);

					if (edad1 >= 0 && edad1 <= edad2 && edad2 <= 70) {

						agregar_credito_a_cliente3(&list, edad1, edad2, &p1);
						printf("CREDITOS AGREGADOS CON EXITO");
					} else {
						printf(
								"la/as edad/es esta/an fuera de rango "
										".Recordar que edad1 tiene que ser mayor o igual a 0 "
										"y edad2 tiene que ser menor o igual a 70");
					}
				} else {
					printf(
							"El valor del prestamo es incorrecto.Recuerde que el "
									"prestamo tiene que se mayor a 0 y menor o igual a 100000 ");
				}
				printf("\n");
				break;

			}

			printf("\n");

			break;
		case 4:

			printf("ingresar nombre del cliente :");
			scanf("%s", nombre);
			p = nombre;

			printf("ingresar apellido del cliente :");
			fflush( stdin);
			scanf("%s", apellido);
			t = apellido;

			printf("ingresar el valor a pagar :");
			fflush( stdin);
			scanf("%lf", &dinero);
			getchar();

			printf("ingresar motivo del prestamo :");
			m = gets(motivo);

			pagar_credito_del_cliente(&list, p, t, m, dinero);
			printf("SE CONCRETO EL PAGO DEL CREDITO");
			printf("\n");
			break;
		case 5:

			printf("ingresar nombre del cliente :");
			scanf("%s", nombre);
			p = nombre;

			printf("ingresar apellido del cliente :");
			fflush( stdin);
			scanf("%s", apellido);
			t = apellido;

			getchar();
			printf("ingresar motivo del prestamo :");
			fflush( stdin);
			m = gets(motivo);

			cancelar_credito_del_cliente(&list, p, t, m);
			printf("CREDITO CANCELADO CON EXITO");
			printf("\n");
			break;

		case 6:

			printf("1.- lista completa \n");
			printf("2.- lista por nombre \n");
			printf("3.- lista por rango de edad \n");

			printf("Indica la opcion: ");

			fflush( stdin);
			scanf("%d", &x);

			switch (x) {
			case 1:
				ver_lista_clientes(&list);

				printf("\n");
				break;
			case 2:
				printf("ingresar nombre :");
				scanf("%s", nombre);
				p = nombre;

				buscar_clientes_por_nombre(&list2, &list, p);

				ver_lista_clientes(&list2);
				destruir(&list2);
				printf("\n");

				break;
			case 3:
				printf("ingresar edad1 :");
				fflush( stdin);
				scanf("%d", &edad1);
				printf("ingresar edad2 :");
				fflush( stdin);
				scanf("%d", &edad2);
				if (edad1 >= 0 && edad1 <= edad2 && edad2 >= edad1
						&& edad2 <= 70) {
					buscar_clientes_por_rango(&list2, &list, edad1, edad2);

					ver_lista_clientes(&list2);
					destruir(&list2);
				} else {
					printf(
							"la/as edad/es esta/an fuera de rango "
									".Recordar que edad1 tiene que ser mayor o igual a 0 "
									"y edad2 tiene que ser menor o igual a 70");
				}
				printf("\n");
				break;

			}

			printf("\n");
			break;

		case 7:
			printf("1.- lista completa \n");
			printf("2.- lista por nombre \n");
			printf("3.- lista por rango de edad \n");

			printf("Indica la opcion: ");

			fflush( stdin);
			scanf("%d", &x);

			switch (x) {
			case 1:

				getchar();
				printf("ingresar nombre del archivo :");
				a = gets(archivo);

				guardar_lista_de_clientes(&list, a);
				printf("SE GUARDO EXITOSAMENTE LA LISTA DE CLIENTES");
				destruir(&list2);
				printf("\n");
				break;
			case 2:
				printf("ingresar nombre :");
				scanf("%s", nombre);
				p = nombre;

				buscar_clientes_por_nombre(&list2, &list, p);

				getchar();
				printf("ingresar nombre del archivo :");
				a = gets(archivo);

				guardar_lista_de_clientes(&list2, a);
				printf("SE GUARDO EXITOSAMENTE LA LISTA DE CLIENTES");
				destruir(&list2);
				printf("\n");

				break;
			case 3:
				printf("ingresar edad1 :");
				fflush( stdin);
				scanf("%d", &edad1);
				printf("ingresar edad2 :");
				fflush( stdin);
				scanf("%d", &edad2);
				if (edad1 >= 18 && edad1 <= edad2 && edad2 >= edad1
						&& edad2 <= 70) {

					buscar_clientes_por_rango(&list2, &list, edad1, edad2);

					getchar();
					printf("ingresar nombre del archivo :");
					a = gets(archivo);

					guardar_lista_de_clientes(&list2, a);
					printf("SE GUARDO EXITOSAMENTE LA LISTA DE CLIENTES");

					destruir(&list2);
				} else {
					printf(
							"la/as edad/es esta/an fuera de rango "
									".Recordar que edad1 tiene que ser mayor o igual a 0 "
									"y edad2 tiene que ser menor o igual a 70");
				}
				printf("\n");
				break;

			}

			break;

		case 8:

			destruir(&list);
			printf("LA LISTA DE CLIENTES SE BORRO EXITOSAMENTE");
			printf("\n");
			break;

		case 9:

		default:
			printf("La opcion que ingreso es incorrecta");
			printf("\n");
			break;
		}
	}

	return 0;
}
