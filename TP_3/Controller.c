#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "r");
    int retorno = 0;

    if(pFile != NULL)
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
        retorno = 1;
    }
    else
    {
        printf("El archivo no se pudo cargar.\n");
    }

    fclose(pFile);
    return retorno;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "rb");
    int retorno = 0;

    if(pFile != NULL)
    {
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        retorno = 1;
    }
    else
    {
        printf("El archivo no se pudo cargar.\n");
    }

    fclose(pFile);
    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* nuevosEmpleados = employee_new();
    char idAux[50];
    char nameAux[50];
    char hoursWorkedAux[50];
    char salaryAux[50];
    int largoLista = ll_len(pArrayListEmployee);
    int auxIdInt;

    if(pArrayListEmployee !=NULL)
    {
        auxIdInt = getValidInt("Ingrese el ID: ", "Error ", 1, 5000);
        itoa(auxIdInt, idAux, 10);

        for(int i = 0; i < largoLista ; i++)
        {
            nuevosEmpleados = (Employee*)ll_get(pArrayListEmployee, i);
            if(nuevosEmpleados->id == auxIdInt)
            {
                mostrarEmpleado(nuevosEmpleados);
                retorno = 0;
                printf("El id que desea agregar ya existe.\n");
                break;
            }
        }
        if(nuevosEmpleados->id != auxIdInt)
        {
            getValidStringEspaciosYLetras("Ingrese el nombre del empleado: ", "Error, nombre no valido.", nameAux);
            getValidStringNumeros("Ingrese las horas trabajadas del empleado: ", "Error, horas no validas", hoursWorkedAux);
            getValidStringNumerosFlotantes("Ingrese el sueldo del empleado: ", "Error, sueldo no valido", salaryAux);
            nuevosEmpleados = employee_newParametros(idAux, nameAux, hoursWorkedAux, salaryAux);
            ll_add(pArrayListEmployee, nuevosEmpleados);
            retorno = 0;
        }
    }
    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int retorno = 1;
    int largoLista = ll_len(pArrayListEmployee);
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];
    int idAuxiliar;
    int horasTrabajadasAux;
    float sueldoAux;
    int opcion;
    int auxIdInt;
    char seguir = 'n';
    Employee* nuevosEmpleados;

    if(pArrayListEmployee != NULL)
    {
        largoLista = ll_len(pArrayListEmployee);
        idAuxiliar = getValidInt("Ingrese el id que desea modificar:  ", "Error, no es valido el id.", 1, 5000);
        for(int i = 0; i <largoLista ; i++ )
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i); //
            if(idAuxiliar == auxEmployee->id )
            {
                do
                {
                    mostrarEmpleado(auxEmployee);
                    printf("Elija la opcion que desea modificar: \n");
                    printf("1. ID\n");
                    printf("2. Nombre\n");
                    printf("3. Horas trabajadas\n");
                    printf("4. Sueldo\n");
                    printf("5. Salir\n");
                    scanf("%d", &opcion);
                    switch(opcion)
                    {
                    case 1:
                        auxIdInt = getValidInt(" Ingrese el ID: ","Error ", 1, 5000);
                        itoa(auxIdInt, auxId, 10);
                        for(int i = 0; i <largoLista ; i++)
                        {
                            nuevosEmpleados = (Employee*)ll_get(pArrayListEmployee, i); //
                            if( nuevosEmpleados->id == auxIdInt)
                            {
                                mostrarEmpleado(nuevosEmpleados);
                                retorno = 0;
                                printf("El id que desea agregar ya existe\n");
                                break;
                            }
                        }
                        if(nuevosEmpleados->id != auxIdInt)
                        {
                            idAuxiliar = atoi(auxId);
                            employee_setId(auxEmployee, idAuxiliar);
                        }
                        break;
                    case 2:
                        getValidString("Ingrese nuevo nombre: ", "Error al ingresar nombre", auxNombre);
                        employee_setNombre(auxEmployee, auxNombre);
                        break;
                    case 3:
                        if(getStringNumeros("Ingrese horas trabajadas: ", auxHorasTrabajadas)!=1)
                        {
                            printf("Error, ingrese solo numeros.\n");
                        }
                        horasTrabajadasAux = atoi(auxHorasTrabajadas);
                        employee_setHorasTrabajadas(auxEmployee, horasTrabajadasAux);
                        break;
                    case 4:
                        if(getStringNumerosFlotantes("Ingrese sueldo nuevo: ", auxSueldo) != 1)
                        {
                            printf("Error, ingrese solo numeros.\n");
                        }
                        sueldoAux = atof(auxSueldo);
                        employee_setSueldo(auxEmployee, sueldoAux);
                        break;
                    case 5:
                        printf("Volviendo al menu...\n");
                        seguir = 's';
                        break;
                    default:
                        printf("Error, dato no valido.\n");
                    }
                }
                while(seguir != 's');
                retorno = 0;
                break;
            }
        }
        if(idAuxiliar != auxEmployee->id)
        {
            printf("No existe ese ID.\n");
            retorno = 1;
        }
    }

    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int retorno = 1;
    int largoLista = ll_len(pArrayListEmployee);
    int idAuxiliar;

    if(pArrayListEmployee != NULL)
    {
        //El id que recibi como string lo transformo a entero ya que es un char (los parametros cargados como char)
        idAuxiliar = getValidInt("Ingrese el id que desea eliminar: ", "Error, no es valido el id.", 1, 5000);

        for(int i = 0; i < largoLista ; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxEmployee->id == idAuxiliar)
            {
                ll_remove(pArrayListEmployee, i);
                mostrarEmpleado(auxEmployee);
                retorno = 0;
                printf("Empleado borrado con exito.\n");
                employee_delete(auxEmployee);
                break;
            }

        }
        if( auxEmployee->id != idAuxiliar)
        {
            printf("El Id no existe.\n");
            retorno = 1;
        }
    }

    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleadoAux;
    int retorno = 0;
    int largoLista = ll_len(pArrayListEmployee);
    int idAuxiliar;
    char nombreAuxiliar[50];
    int horasAuxiliar;
    float sueldoAuxiliar;

    if(pArrayListEmployee!=NULL)
    {
        if(largoLista>0)
        {
            ///tengo todos los empleados cargados ya en una lista
            ///desde 0 hasta el largo de la lista
            ///ir recorriendo la lista, obteniendo cada empleado y mostrarlo
            printf("   Id       Nombre   Horas trabajadas   Sueldo\n");
            for(int i = 0; i < largoLista; i++)
            {
                pEmpleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(pEmpleadoAux, &idAuxiliar);
                employee_getNombre(pEmpleadoAux,nombreAuxiliar);
                employee_getHorasTrabajadas(pEmpleadoAux,&horasAuxiliar);
                employee_getSueldo(pEmpleadoAux,&sueldoAuxiliar);
                printf("%5d  %10s %10d  %15.2f\n",idAuxiliar, nombreAuxiliar, horasAuxiliar, sueldoAuxiliar);
            }
            retorno = 1;
        }
        else
        {
            printf("No se cargaron los datos.\n");
        }

    }
    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int opcion;
    if(pArrayListEmployee !=NULL)
    {
        printf("Ingrese la manera en que quiere ordenar los empleados : \n");
        printf("1. Ordenar por Id.\n");
        printf("2. Ordenar por nombre.\n");
        printf("3. Ordenar por horas trabajadas\n");
        printf("4. Ordenar por sueldo\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
			case 1:
				ll_sort(pArrayListEmployee, employeeSortById,0);
				printf("Ordenado con exito\n");
				break;
			case 2:
				ll_sort(pArrayListEmployee, employeeSortByName,0);
				printf("Ordenado con exito\n");
				break;
			case 3:
				ll_sort(pArrayListEmployee, employeeSortByWorkHours,0);
				printf("Ordenado con exito\n");
				break;
			case 4:
				ll_sort(pArrayListEmployee, employeeSortBySalary,0);
				printf("Ordenado con exito\n");
				break;
			default :
				printf("Se ha ingresado mal el dato.\n");
        }
        retorno = 1;
    }

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int largoLista = ll_len(pArrayListEmployee);
    Employee* pEmpleadoAux;
    FILE* pFile = fopen(path, "w");

    if(pFile == NULL)
    {
        printf("Error al abrir archivo para guardar\n");
        return retorno;
    }

    fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
    if(pArrayListEmployee!=NULL)
    {
        for(int i = 0; i < largoLista; i++)
        {
            pEmpleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(pFile, "%d,%s,%d,%f\n", pEmpleadoAux->id, pEmpleadoAux->nombre, pEmpleadoAux->horasTrabajadas, pEmpleadoAux->sueldo);
        }
        printf("Se ha realizado el guardado del archivo con exito \n");
        retorno = 1;
    }
    fclose(pFile);
    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int largoLista = ll_len(pArrayListEmployee);
    Employee* pEmpleadoAux;
    FILE* pFile = fopen(path, "wb");

    if(pFile==NULL)
    {
        printf("Error al guardar\n");
        return retorno;
    }
    if(pArrayListEmployee!=NULL)
    {
        for(int i = 0; i < largoLista; i++)
        {
            pEmpleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(pEmpleadoAux, sizeof(Employee), 1, pFile);
        }
        printf("Se guardó el archivo exitosamente. \n");
        retorno = 1;
    }
    fclose(pFile);
    return retorno;
}

int menu()
{
    int opcion;

    printf("-----------------Menu de opciones----------------\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir.\n");
    printf("Elija una opcion: ");
    scanf("%d",&opcion);

    return opcion;

}
