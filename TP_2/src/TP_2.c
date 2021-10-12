/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#define CHARSIZE 51
#define SIZE 1000
#define EMPTY 0
#define OCCUPIED 1
#define SUCCESS 0
#define ERROR -1
#define DELETED -1

int main(void) {
	setbuf(stdout, NULL);

	sEmployee employeeList[SIZE];
	int option;
	int emptySpace;
	int order;
	int auxId = 1;
	char auxName[CHARSIZE];
	char auxLastName[CHARSIZE];
	float auxSalary = 0;
	int auxSector = 0;

	initEmployees (employeeList, SIZE);

	do
	{
		printf("------------------------------------------ \n");
		printf("1- Cargar empleado \n");
		printf("2- Modificar empleado \n");
		printf("3- Dar de baja empleado \n");
		printf("4- Mostrar empleados \n");
		printf("10- Finalizar \n");
		printf("------------------------------------------ \n");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			emptySpace = findEmptySpace(employeeList, SIZE);

			if(emptySpace != ERROR)
			{
				getValidString("Nombre del empleado: ", "Error, ingrese solo letras: ", auxName);
				setbuf(stdin, NULL);
				getValidString("Apellido del empleado: ", "Error, ingrese solo letras: ", auxLastName);
				setbuf(stdin, NULL);
				auxSalary = getValidFloat("Salario del empleado: ", "Error, ingrese solo numero flotante: ", 0, 10000000 );
				auxSector = getValidInt("Sector del empleado: ", "Error, ingrese solo numero: ", 1, 1000);

			addEmployee(employeeList, SIZE, emptySpace, auxName, auxLastName, auxSalary, auxSector);
			}
			else
			{
				printf("No se pueden cargar mas empleados ");
			}
			break;

			case 2:
				if(existEmployees(employeeList, SIZE) == SUCCESS)
				{
					modifyEmployee(employeeList, SIZE);
					 }
					 else
					 {
						printf("Debe ingresar al menos un empleado para continuar \n");
					 }
				break;
			case 3:
				if(existEmployees(employeeList, SIZE) == SUCCESS)
				{
				printf("Ingrese ID de empleado a eliminar: ");
				scanf("%d", &auxId);
				removeEmployee(employeeList, SIZE, auxId);
				}
				 else{
						printf("Debe ingresar al menos un empleado para continuar \n");
					 }
				break;
			case 4:
				if(existEmployees(employeeList, SIZE) == SUCCESS)
				{
				printf("\250Como desea ordenar a los empleados?: \n");
				printf("1- Ascendente \n");
				printf("2- Descendente \n");
				printf("------------------------------------------ \n");

				scanf("%d", &order);

				sortEmployeeByName(employeeList, SIZE, order);
				printEmployees(employeeList, SIZE);
				averageEmployeesSalary (employeeList, SIZE);
				}
				 else{
						printf("Debe ingresar al menos un empleado para continuar \n");
					 }
				break;


		case 10:
			printf("Usted ha finalizado el programa \n");
			break;
		default:
			printf("Opcion incorrecta \n");
		}

	}
	while (option!=10);

	return 0;
}
