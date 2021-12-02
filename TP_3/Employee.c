#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "Parser.h"

Employee* employee_new()
{
    return (Employee*)calloc(1, sizeof(Employee));
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* auxiliarEmpleado = employee_new();

    if(auxiliarEmpleado != NULL )
    {
        int id = atoi(idStr);
        int horasTrabajadas = atoi(horasTrabajadasStr);
        float sueldo = atof(sueldoStr);
        employee_setId(auxiliarEmpleado, id);
        employee_setHorasTrabajadas(auxiliarEmpleado, horasTrabajadas);
        employee_setSueldo(auxiliarEmpleado, sueldo);
        employee_setNombre(auxiliarEmpleado, nombreStr);
    }

    return auxiliarEmpleado;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
    	free(this);
    }
}

int employee_setId(Employee* this, int id)
{
    int retorno = 0;
    if(this != NULL)
    {
        if(id > 0)
        {
            this->id = id;
            retorno = 1;
        }
    }
    return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = 0;

    if(this != NULL && strlen(nombre) != 0)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL)
    {
        if(horasTrabajadas > 0 || horasTrabajadas < 24)
        {
            this->horasTrabajadas = horasTrabajadas;
            retorno = 1;
        }
    }

    return retorno;
}

int employee_setSueldo(Employee* this, float sueldo)
{
    int retorno = 0;

    if(this != NULL)
    {
        if(sueldo > 1000 || sueldo < 90000)
        {
            this->sueldo = sueldo;
            retorno = 1;
        }
    }

    return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = 0;

    if(this != NULL)
    {
        strcpy(nombre, this->nombre); //
        retorno = 1;
    }

    return retorno;
}

int employee_getId(Employee* this, int* id)
{
    int retorno = 0;

    if(this != NULL)
    {
        *id = this->id;
        retorno = 1;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_getSueldo(Employee* this, float* sueldo)
{
    int retorno = 0;

    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }

    return retorno;
}

void mostrarEmpleado(Employee* empleado)
{
    printf("%5d  %10s %10d  %15.2f\n",empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
}

int employeeSortById(void* empleadoA, void* empleadoB)
{
    int retorno;
    Employee* empA;
    Employee*empB;

    if((empleadoA != NULL) && (empleadoB != NULL))
    {
        empA = (Employee*)empleadoA;
        empB = (Employee*)empleadoB;
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

int employeeSortByName(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;

    if((empleadoA != NULL) && (empleadoB != NULL))
    {
        empA = (Employee*)empleadoA;
        empB = (Employee*)empleadoB;
        retorno = strcmp(empB->nombre, empA->nombre);
    }

    return retorno;
}

int employeeSortByWorkHours(void* empleadoA, void* empleadoB)
{
    int retorno;
    Employee* empA;
    Employee* empB;

    if((empleadoA != NULL )&& (empleadoB != NULL))
    {
        empA = (Employee*)empleadoA;
        empB = (Employee*)empleadoB;
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

int employeeSortBySalary(void* empleadoA, void* empleadoB)
{
    int retorno;
    Employee* empA;
    Employee* empB;

    if((empleadoA != NULL) && (empleadoB != NULL))
    {
        empA = (Employee*)empleadoA;
        empB = (Employee*)empleadoB;
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
