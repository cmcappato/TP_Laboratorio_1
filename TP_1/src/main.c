/*
 ============================================================================
 Name        : TP_1.c
 Author      : Carolina Cappato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void) {

	setbuf(stdout, NULL);
	float numeroUno = 0, numeroDos = 0;
	float suma, resta, multiplicacion, division;
	int factorialUno, factorialDos, flagNumeroUno = 0, flagNumeroDos = 0;
	int opcion;

	do{
		opcion = menu(numeroUno, numeroDos);
		switch(opcion)
		{
			case 1:
				numeroUno = getFloat("Ingrese el primer numero: ");
	        	flagNumeroUno = 1;
				break;
			case 2:
				numeroDos = getFloat("Ingrese el segundo numero: ");
				flagNumeroDos = 1;
				break;
			case 3:
				if(flagNumeroUno == 1 && flagNumeroDos == 1)
				{
					suma = sumar(numeroUno, numeroDos);
					resta = restar(numeroUno, numeroDos);
					multiplicacion = multiplicar(numeroUno, numeroDos);
					division = dividir(numeroUno, numeroDos);
					factorialUno = (int)factorial(numeroUno);
					factorialDos = (int)factorial(numeroDos);

					printf("Se han realizado todos los calculos.\n");
				}
				else
					printf("No se han ingresado numeros.\n");
				break;
			case 4:
				if (flagNumeroUno == 1 && flagNumeroDos == 1)
				{
					printf("Resultados:\n");
					printf("Suma: %.2f \n", suma);
					printf("Resta: %.2f \n", resta);
					printf("Multiplicacion: %.2f \n", multiplicacion);
					printf("Division: %.2f \n", division);
					printf("Factorial del primer numero: %d\n", factorialUno);
					printf("Factorial del segundo numero: %d\n", factorialDos);
				}
	            else
	                printf("No se han ingresado numeros, por lo tanto no hay nada para calcular.\n");
				break;
			case 5:
				printf("Gracias por utilizar la calculadora.\n");
				break;
			default:
				printf("La opcion ingresada no es correcta, intente nuevamente.\n");
				break;
		}
	}while(opcion != 5);

	return 0;
}
