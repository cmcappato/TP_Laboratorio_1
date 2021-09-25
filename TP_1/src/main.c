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
	float numeroUno = 0, numeroDos = 0;
	float suma, resta, multiplicacion, division;
	int factorialUno = 0, factorialDos = 0, flagNumeroUno = 0, flagNumeroDos = 0;
	int opcion;

	do
	    {
	        printf("Seleccione la opcion deseada: \n");
	        printf("1- Para ingresar el primer numero: \n");
	        printf("2- Para ingresar el segundo numero: \n");
	        printf("3- Para realizar todas las operaciones: \n");
	        printf("4- Para mostrar resultados: \n");
	        printf("5- Para salir: \n");
	        printf("----------------------------------------\n");
	        printf("Los numeros ingresados son: %.2f y %.2f\n", numeroUno, numeroDos);
	        printf("Elija una opcion: ");
	        scanf("%d", &opcion);

	        switch (opcion)
	        {
	        case 1:
	        	numeroUno = getFloat ("Ingrese el primer numero: ");
	        	flagNumeroUno = 1;
	            break;
	        case 2:
	        	numeroDos = getFloat ("Ingrese el segundo numero: ");
	        	flagNumeroDos = 1;
	            break;
	        case 3:
	            if (flagNumeroUno == 1 && flagNumeroDos == 1)
	            {
	                suma = sumar (numeroUno, numeroDos);
	                resta = restar (numeroUno, numeroDos);
	                multiplicacion = multiplicar (numeroUno, numeroDos);
	                division = dividir (numeroUno, numeroDos);
	                factorialUno = (int) factorial (numeroUno);
	                factorialDos = (int) factorial (numeroDos);

	                printf("Se han realizado todos los calculos\n");
	            }
	            else
	            {
	                printf("No se han ingresado numeros \n");
	            }
	            break;
	        case 4:
	            if (flagNumeroUno == 1 && flagNumeroDos == 1)
	            {
	                printf("Resultados:\n");
	                printf("Suma: %.2f \n", suma);
	                printf("Resta: %.2f \n", resta);
	                printf("Multiplicacion: %.2f \n", multiplicacion);
	                if (numeroDos == 0)
	                {
	                    printf("No se puede dividir por cero \n");
	                }
	                else
	                {
	                    printf("Division: %.2f \n", division);
	                }
	                if (numeroUno < 0)
	                {
	                    printf("No se puede calcular factorial de un numero negativo\n");
	                }
	                else
	                {
	                    if (numeroUno == 0)
	                    {
	                    	factorialUno = 1;
	                        printf("Factorial del primer numero: %d\n", factorialUno);
	                    }
	                    else
	                    {
	                        printf("Factorial del primer numero: %d\n", factorialUno);
	                    }

	                }
	                if (numeroDos < 0)
	                {
	                    printf("No se puede calcular factorial de un numero negativo\n");
	                }
	                else
	                {
	                    if (numeroDos == 0)
	                    {
	                    	factorialDos = 1;
	                        printf("Factorial del segundo numero: %d\n", factorialDos);
	                    }
	                    else
	                    {
	                        printf("Factorial del segundo numero: %d\n", factorialDos);
	                    }
	                }
	            }
	            else
	            {
	                printf("No se han ingresado numeros, por lo tanto no hay nada para calcular\n");
	            }
	            break;
	        case 5:
	            opcion = '5';
	            printf("Gracias por utilizar la calculadora\n");
	            break;
	        default:
	            printf("La opcion ingresada no es correcta, intente nuevamente\n");
	            break;
	        }
	    }
	    while (opcion != '5');
	    return 0;
}
