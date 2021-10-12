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


int initEmployees (sEmployee list[], int limit)
{
    int index = ERROR;
    int i;

    if(limit > 0 && list != NULL)
    {
        index = 0;
        for(i = 0; i < limit; i++)
        {
            list[i].isEmpty = 0;
            list[i].isEmpty = 0;
            list[i].id = 0;
        }
    }

    return index;
}


int findEmptySpace (sEmployee list[], int len)
{
    int index = ERROR;
    int i;

    for (i=1; i<len; i++)
    {
        if (list[i].isEmpty == EMPTY)
        {
            index = i;
            break;
        }
    }
    return index;
}

int existEmployees(sEmployee list[], int len)
{
    int i;

    for( i = 0; i < len; i++)
    {
        if(list[i].isEmpty == OCCUPIED)
        {
            return SUCCESS;
        }
    }
    return ERROR;
}

int addEmployee (sEmployee list[], int len, int id, char name[], char lastName[], float salary, int sector)
{
    list[id].id = id;
    strcpy(list[id].name, name);
    strcpy(list[id].lastName, lastName);
    list[id].salary = salary;
    list[id].sector = sector;
    list[id].isEmpty = OCCUPIED;
    return id;
}

int modifyEmployee (sEmployee list[], int len)
{
    int index = ERROR;
    int modify;
    int findEmployee;
    char newName[CHARSIZE];
    char newLastName[CHARSIZE];
    float newSalary;
    int newSector;
    char proceed = 'n';
    int id;

    printf("Ingrese ID de empleado a modificar: ");
    scanf("%d", &id);

    findEmployee = findEmployeeById(list, len, id);

    if (findEmployee > 0)
    {
        do
        {
            printf("\250Que desea modificar? \n");
            printf("1- Nombre \n");
            printf("2- Apellido \n");
            printf("3- Salario \n");
            printf("4- Sector \n");
            printf("------------------------------------------ \n");
            scanf("%d", &modify);

            switch(modify)
            {
            case 1:
                getValidString("Ingrese nuevo nombre: ", "Error, ingrese solo letras: ", newName);
                strcpy(list[findEmployee].name, newName);
                break;
            case 2:
                getValidString("Ingrese nuevo apellido: ", "Error, ingrese solo letras: ", newLastName);
                strcpy(list[findEmployee].lastName, newLastName);
                break;
            case 3:
                newSalary = getValidFloat("Ingrese nuevo salario: ", "Error, ingrese solo numeros: ", 0, 10000000);
                list[findEmployee].salary = newSalary;
                break;
            case 4:
                newSector = getValidInt("Ingrese nuevo sector: ", "Error, ingrese solo numeros: ", 1, 1000);
                list[findEmployee].sector = newSector;
                break;
            default:
                printf("Ingrese una opcion del 1 al 4: ");
            }
            printf("\250Desea continuar? s/n :");
            setbuf(stdin, NULL);
            scanf("%c", &proceed);
        }
        while (proceed == 's');

        printf("Empleado modificado \n");
    }
    else
    {
        printf("No se encontro empleado con ese ID \n");
    }
   return index;
}

int findEmployeeById(sEmployee list[], int len, int id)
{
    int index = ERROR;
    int i;

    if (list != NULL && len > 0)
    {
        for (i=1; i<len; i++)
        {
            if (list[i].isEmpty == OCCUPIED && list[i].id == id)
            {
                return i;
            }
        }
    }
    return index;
}

int removeEmployee (sEmployee list[], int len, int employeeId)
{
    int findEmployee;

    findEmployee = findEmployeeById(list, len, employeeId);

    if (findEmployee > 0)
    {
        list[findEmployee].isEmpty = DELETED;
        printf("Empleado eliminado con exito \n");
    }
    else
    {
        printf("No se ha encontrado empleado con ese ID \n");
    }

    return findEmployee;
}

int printEmployees (sEmployee list[], int len)
{
    int index = ERROR;
    int i;

    if(len > 0)
    {
        printf("ID\tNombre\t\tApellido\t\tSalario\t\tSector \n");

        for(i=0; i<len; i++)
        {
            if (list[i].isEmpty == OCCUPIED)
            {
                setbuf(stdin, NULL);
                printf("%d\t%s\t\t%s\t\t\t%.2f\t\t%d \n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            }
        }
        index = SUCCESS;
    }
    return index;
}

int sortEmployeeByName(sEmployee list[], int len, int order)
{
    int index = ERROR;

    sEmployee auxiliar;

    if(len > 0 && list != NULL)
    {
        switch(order)
        {
            case 1:
                if(len > 0 && list != NULL)
                {
                    for(int i=0; i<len - 1; i++)
                    {
                        for(int j=i+1; j<len; j++)
                        {
                            if(strcmp(list[j].lastName, list[i].lastName) < 0)
                            {
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                            else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector)
                            {
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                        }
                    }
                index = SUCCESS;
                break;
            case 2:
                for(int i = 0; i < len - 1; i++)
                {
                    for(int j = i + 1; j < len; j++)
                    {
                        if(strcmp(list[j].lastName, list[i].lastName) > 0)
                        {
                            auxiliar = list[i];
                            list[i] = list[j];
                            list[j] = auxiliar;
                        }
                        else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector)
                        {
                            auxiliar = list[i];
                            list[i] = list[j];
                            list[j] = auxiliar;
                        }
                    }
                }
                index = SUCCESS;
                break;
            default:
                printf("Ingrese 1 para ascendente o 2 para descendente \n");
            }
        }
    }
    return index;
}

void averageEmployeesSalary (sEmployee list[], int len)
{
    float average = 0;
    float total = 0;
    int employeeCounter = 0;
    int salaryGreaterThanAverage = 0;
    int i;

    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty == OCCUPIED)
        {
            employeeCounter ++;
            total = total + list[i].salary;
        }
    }
    average = total / employeeCounter ;

    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty == OCCUPIED && list[i].salary >average)
        {
            salaryGreaterThanAverage ++;
        }
    }

    printf("Total de salarios: %.2f \n", total);
    printf("Promedio de salarios: %.2f \n", average);
    printf("Cantidad de empleados con salario mayor al promedio: %d \n", salaryGreaterThanAverage);

}

void getString (char message[], char input[])
{
    printf("%s",message);
    scanf ("%s", input);
}

char getChar(char message[])
{
    char auxiliar;

    printf("%s",message);
    setbuf(stdin, NULL);
    scanf("%c",&auxiliar);

    return auxiliar;
}

void getValidString(char requestMessage[],char errorMessage[], char input[])
{
    while(1)
    {
        if (!getStringLetters(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }
}

int getStringLetters(char message[],char input[])
{
    char aux[256];

    getString(message, aux);

    if(isOnlyLetters(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int isOnlyLetters(char str[])
{
    int i=0;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];

    float auxFloat;

    while(1)
    {
        if (!getStringFloatNumbers(requestMessage, auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }

        auxFloat = atof(auxStr);

        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxFloat;
    }
}

int getStringFloatNumbers(char message[],char input[])
{
    char aux[256];

    getString(message, aux);

    if(isNumericFloat(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int isNumericFloat(char str[])
{
    int i=0;

    int pointCounter = 0;

    while(str[i] != '\0')
    {
        if (str[i] == '.' && pointCounter == 0)
        {
            pointCounter++;
            i++;
            continue;
        }
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }

        i++;
    }
    return 1;
}

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];

    int auxInt;

    while(1)
    {
        if (!getStringNumbers(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
}

int getStringNumbers(char message[],char input[])
{
    char aux[256];

    getString(message,aux);

    if(isNumeric(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int isNumeric(char str[])
{
    int i=0;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

void cleanStdin(void)
{
    int c;

    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}
