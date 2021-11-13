#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return i pocision que se cargo
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
   // FILE *pFile;
    Employee* auxiliarEmpleado = employee_new();
    int r;
    int i = 0;
    char idAux[50],nameAux[50],hoursWorkedAux[50],salaryAux[50];///Id, Nombre, horas trabajadas, sueldo
    if(pFile == NULL){
        return -1;
    }
    //leo los titulos
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nameAux,hoursWorkedAux,salaryAux);
    while(!feof(pFile))
    {
                r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nameAux,hoursWorkedAux,salaryAux);
        if(r==4){
                auxiliarEmpleado = employee_newParametros(idAux ,nameAux, hoursWorkedAux, salaryAux);
            //initialize(&arrayPersonas[i], var1, var2, var3, var4);
            ll_add(pArrayListEmployee, auxiliarEmpleado );
            i++;
        }
        else
            break;
    }

    printf("Se cargaron %d empleados a la lista con exito !\n", i);
    /// fclose(pFile); LO CIERRO AFUERA

    return i;

   //return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee empleadoAux; ///Se crea la struct
    int i = 0;
    fread(&empleadoAux, sizeof(Employee), 1, pFile);///necesito guardar el tamaño del sizeof dentro de la estructura del primer argumento osea el empleado Aux, leo 1 vez
   ///Necesito la direccion para leer el archivo y escribir en la direccion la informacion leida del archivo
    //Al ser archivo binario lo abr con fread, le paso la direccion de memoria del empleado auxiliar, luego cuantos bytes tiene que leer
    while(!feof(pFile))
    {
        // Crear un nuevo empleado en memoria dinamica (hacer un malloc para ese empleado)
        Employee* empleado = employee_new();
        employee_setId(empleado,empleadoAux.id); ///No tiene sentido que cargue el id que no existe  osea no poner empleado->
        employee_setHorasTrabajadas(empleado,empleadoAux.horasTrabajadas);
        employee_setNombre(empleado,empleadoAux.nombre);
        employee_setSueldo(empleado,empleadoAux.sueldo);
        i ++; //Cuento los empleados que se cargaron
        ll_add(pArrayListEmployee, empleado); //Los añado
        fread(&empleadoAux, sizeof(Employee), 1, pFile); ///Lo vuelvo a leer por si se agrego un nuevo empleado?) -preguntar bien
    }

    printf("Se han cargado %d de usuarios!\n", i);
    return 1;
}
