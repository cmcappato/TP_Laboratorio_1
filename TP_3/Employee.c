#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "Parser.h"

/** \brief Almacena un espacio en memoria dinamica para un empleado
 *
 * \param -
 * \param -
 * \return retorna el emplead
 */
//Almacena un espacio en memoria dinamica para un empleado y retorna su direccion
Employee* employee_new()
{
    return (Employee*)calloc(1, sizeof(Employee));
}


/** \brief Creo nuevos empleados con parametros
 *
 * \param char* idStr Id generado
 * \param char* nombreStr Nombre generado
 * \param char* horasTrabajadasStr Horas trabajadas generadas
 * \param char* sueldoStr Sueldo
 * \return retorna la direccion del empleado
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* auxiliarEmpleado = employee_new();

    if( auxiliarEmpleado != NULL )
    {
        int id = atoi(idStr);
        employee_setId(auxiliarEmpleado, id);
        //employee_setNombre
        int horasTrabajadas = atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(auxiliarEmpleado, horasTrabajadas);

        float sueldo = atof(sueldoStr);
        employee_setSueldo(auxiliarEmpleado, sueldo);

        employee_setNombre(auxiliarEmpleado, nombreStr);
    }
    //Tengo que llamar a los set
    return auxiliarEmpleado;

}


/** \brief Libera espacio de un empleado eliminado
 *
 * \param -
 * \return -
 *
 */

void employee_delete(Employee* this)
{   ///LIBERA ESPACIO EN CADA EMPLEADO
    if(this!=NULL)
    free(this);
}


/** \brief Valida el id
 *
 * \param Employee* this Puntero del array de empleados
 * \param int id recibe una cantidad de id
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */

int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(this!=NULL)
    {
        if(id>0)
        {
            this->id = id;
            retorno = 1;
        }
    }
    return retorno;
}


/** \brief Valida el Nombre
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre recibe un nombre
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */

int employee_setNombre(Employee* this,char* nombre) ///MODIFICAR
{
    int retorno = 0;
    if(this!=NULL  && strlen(nombre) != 0)
    {
        strcpy( this->nombre, nombre );
        retorno = 1;
    }
    return retorno;
}


/** \brief Valida las horas de trabajo
 *
 * \param Employee* this Puntero del array de empleados
 * \param int horasTrabajadas Recibe una cantidad de horas de trabajo
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;
    if(this!=NULL)
    {
        if(horasTrabajadas > 0 || horasTrabajadas <24)
        {
            this->horasTrabajadas = horasTrabajadas;
            retorno = 1;
        }
    }
    return retorno;
}


/** \brief Valida el sueldo
 *
 * \param Employee* this Puntero del array de empleados
 * \param float sueldo Recibe una cantidad de sueldo
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno = 0;
    if(this!=NULL)
    {
        if(sueldo > 1000 || sueldo <90000)
        {
            this->sueldo = sueldo;
            retorno = 1;
        }
    }
    return retorno;
}


/** \brief Me escribe el parametro del nombre en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre Recibe un nombre
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this!=NULL)
    {
        strcpy ( nombre, this->nombre); //
        retorno = 1;
    }
    return retorno;
}


/** \brief Me escribe el parametro del id en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param int* id recibe un puntero al id
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this!=NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

/** \brief Me escribe el parametro de las horas trabajadas en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param int* horasTrabajadas Recibe un puntero a las horas trabajadas
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;
    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}


/** \brief Me escribe el parametro del sueldo en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param float* sueldo recibe un puntero del sueldo
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno = 0;
    if(this!=NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}


/** \brief Valida el id
 *
 * \param Employee* empleado Puntero del array de empleados
 * \return -
 *
 */

void mostrarEmpleado(Employee* empleado)
{

    printf("%5d  %10s %10d  %15.2f\n",empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
    ///Hacer un fprintf
}

/** \brief Compara dos parametros que serian int (por el id)
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return retorno Devuelve 1 si el empleadoA es igual a empleado B, devuelve -1 si el empleadoA es mayor al empleado B y devuelve 1 si el empleadoA es menor al empleado B
 *
 */
int employeeSortById(void* empleadoA, void* empleadoB)
{
    int retorno;

    Employee* empA;
    Employee*empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        if(empA->id == empB->id)
        {
             retorno = 1;
        }
        if(empA->id > empB->id)
        {
            retorno = -1;
        }
        if(empA->id < empB->id)
        {
            retorno = 0;
        }
    }

    return retorno;
}


/** \brief Compara dos parametros que serian string (por el nombre)
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return retorno Devuelve la comparacion de los dos parametros, o devuelve 0 si falla
 *
 */
int employeeSortByName(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        retorno = strcmp(empB->nombre, empA->nombre);
    }

    return retorno;
}


/** \brief Compara dos parametros que serian int (por las horas trabajadas)
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return retorno Devuelve 1 si el empleadoA es igual a empleado B, devuelve -1 si el empleadoA es mayor al empleado B y devuelve 1 si el empleadoA es menor al empleado B
 *
 */
int employeeSortByWorkHours(void* empleadoA, void* empleadoB)
{
    int retorno;

    Employee* empA;
    Employee*empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        if(empA->horasTrabajadas == empB->horasTrabajadas)
        {
             retorno = 1;
        }
        if(empA->horasTrabajadas> empB->horasTrabajadas)
        {
            retorno = -1;
        }
        if(empA->horasTrabajadas < empB->horasTrabajadas)
        {
            retorno = 0;
        }
    }

    return retorno;
}


/** \brief Compara dos parametros que serian float (por el salario)
 *
 * \param void* empleadoA
 * \param void* empleadoB
 * \return retorno Devuelve 1 si el empleadoA es igual a empleado B, devuelve -1 si el empleadoA es mayor al empleado B y devuelve 1 si el empleadoA es menor al empleado B
 *
 */
int employeeSortBySalary(void* empleadoA, void* empleadoB)
{
    int retorno;

    Employee* empA;
    Employee*empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        if(empA->sueldo == empB->sueldo)
        {
             retorno = 1;
        }
        if(empA->sueldo > empB->sueldo)
        {
            retorno = -1;
        }
        if(empA->sueldo < empB->sueldo)
        {
            retorno = 0;
        }
    }

    return retorno;
}


