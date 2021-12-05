/*
 * Funciones.h
 *
 *  Created on: 2 dic. 2021
 *      Author: caroc
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @brief
///
/// @param n1
/// @param n2
/// @return
int menu(float n1, float n2);

/// @brief Realiza la suma entre dos numeros
///
/// @param n1 Primer sumando
/// @param n2 Segundo sumando
/// @return Devuelve el resultado de la operacion
float sumar(float n1, float n2);

/// @brief Realiza la resta entre dos numeros
///
/// @param n1 Minuendo
/// @param n2 Sustraendo
/// @return Devuelve el resultado de la operacion
float restar(float n1, float n2);

/// @brief Multiplica dos números
///
/// @param n1 Primer factor
/// @param n2 Segundo factor
/// @return Devuelve el resultado de la operacion
float multiplicar(float n1, float n2);

/// @brief Divide dos números
///
/// @param n1 Dividendo
/// @param n2 Divisor
/// @return Devuelve el resultado de la operacion, o 0 en caso de no ser posible realizar la operacion
float dividir(float n1, float n2);

/// @brief Realiza el factorial de un número
///
/// @param n Numero
/// @return Devuelve el resultado de la operacion
int factorial(int n);

/// @brief Pide un numero al usuario
///
/// @param mensaje
/// @return El número ingresado por el usuario
float getFloat(char mensaje[]);


#endif /* FUNCIONES_H_ */
