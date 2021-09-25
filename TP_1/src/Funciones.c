#include <stdio.h>
#include "Funciones.h"

float sumar (float numUno, float numDos)
{
	float resultado;

	resultado = numUno + numDos;

	return resultado;
}

float restar (float numUno, float numDos)
{
	float resultado;

	resultado = numUno - numDos;

	return resultado;
}


float multiplicar (float numUno, float numDos)
{
	float resultado;

	resultado = numUno * numDos;

	return resultado;
}


float dividir (float numUno, float numDos)
{
	float resultado;

	if (numDos != 0)
	{
		resultado = numUno / numDos;
	}

	return resultado;
}

int factorial(int numero)
{
	int resultado;

	if (numero > 0)
	{
		if (numero == 0)
		{
			resultado = 1;
		}
		else
		{
			resultado = numero * factorial(numero - 1);
		}
	}

	return resultado;
}

float getFloat(char mensaje[])
{
    float auxiliarFloat;

    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);

    return auxiliarFloat;
}
