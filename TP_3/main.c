#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
	setbuf(stdout, NULL);
    int opcion;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flag = 0, flag2 = 0;

    do
    {
        opcion = menu();
        switch(opcion)
        {
        case 1:
            if(flag == 0 && flag2 != 1)
            {
                controller_loadFromText("data.csv",listaEmpleados);
                flag = 1;
            }
            else
            {
                printf("Ya se han cargado los datos anteriormente.\n");
            }
            break;
        case 2:
            if(flag2 == 0 && flag != 1)
            {
                flag2 = 1;
                controller_loadFromBinary("data.bin", listaEmpleados);
            }
            else
            {
                printf("Ya se han cargado los datos anteriormente.\n");
            }
            break;
        case 3:
            if(flag == 1 || flag2 == 1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("No se han cargado los datos para dar el alta.\n");
            }
            break;
        case 4:
            if( flag == 1 || flag2 == 1)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos que mostrar.\n");
            }
            break;
        case 5:
            if( flag == 1 || flag2 == 1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos que mostrar.\n");
            }
            break;
        case 6:
            if( flag == 1 || flag2 == 1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos que mostrar.\n");
            }
            break;
        case 7:
            if( flag == 1 || flag2 == 1)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos que mostrar.\n");
            }
            break;
        case 8:
            controller_saveAsText("data.csv",listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("data.bin", listaEmpleados);
            break;
        case 10:
            printf("Gracias por utilizar el programa.\n");
            opcion = 11;
            break;
        default:
            printf("Opcion incorrecta.\n");
        }
    }
    while(opcion != 10);

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

