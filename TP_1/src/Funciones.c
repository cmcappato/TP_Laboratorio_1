/*
 * Funciones.c
 *
 *  Created on: 2 dic. 2021
 *      Author: caroc
 */

#include <stdio.h>
#include "Funciones.h"


int menu(float n1, float n2)
{
	int opcion = 0;

	printf("--------------CALCULADORA---------------\n");
	printf("Seleccione la opcion deseada: \n");
	printf("1- Ingresar el primer numero: \n");
	printf("2- Ingresar el segundo numero: \n");
	printf("3- Realizar todas las operaciones.\n");
	printf("4- Mostrar resultados.\n");
	printf("5- Salir.\n");
	printf("----------------------------------------\n");
	printf("Los numeros ingresados son: %.2f y %.2f\n", n1, n2);
	printf("Elija una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

float sumar(float n1, float n2)
{
	float resultado = 0;

	resultado = n1 + n2;

	return resultado;
}


float restar(float n1, float n2)
{
	float resultado = 0;

	resultado = n1 - n2;

	return resultado;
}

float multiplicar(float n1, float n2)
{
	float resultado = 0;

	resultado = n1 * n2;

	return resultado;
}

float dividir(float n1, float n2)
{
	float resultado = 0;

	if(n2 == 0)
		printf("No se puede dividir por 0.\n");
	else
		resultado = n1 / n2;

	return resultado;
}

int factorial(int num)
{
	int resultado = 0;

	if(num > 0)
		resultado = num * factorial(num - 1);
	else if(num == 0)
		resultado = 1;
	else
		printf("No se puede realizar el factorial de un número negativo.\n");

	return resultado;
}

float getFloat(char mensaje[])
{
    float auxiliarFloat;

    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);

    return auxiliarFloat;
}
