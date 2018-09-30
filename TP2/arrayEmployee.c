#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "myLibrary.h"
#define ELEMENTS 1
#define TRUE 1
#define FALSE 0

void arrayEmployee_menuEmployee(void)
{
    Employee empleados[ELEMENTS];
    arrayEmployee_initEmployees(empleados, ELEMENTS);

    int opcion = 0;

    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int flag = 0;

    do
    {
        printf("\n\nMenu");
        printf("\n1. Alta");
        printf("\n2. Baja");
        printf("\n3. Modificacion");
        printf("\n4. Informar");
        printf("\n5. Salir");
        printf("\n\nOpcion: ");
        scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    myLibrary_getNombre(name, 51, "\nIngrese nombre: ", "\nIngrese solo letras!", 1);
                    myLibrary_getNombre(lastName, 51, "\nIngrese apellido: ", "\nIngrese solo letras!", 1);
                    salary = myLibrary_getFloat("\nIngrese salario: ");
                    printf("\nIngrese sector: ");
                    scanf("%d", &sector);
                    arrayEmployee_addEmployee(empleados, ELEMENTS, arrayEmployee_assignID(), name, lastName, salary, sector);
                    flag = 1;
                break;
                case 2:
                    if(flag != 0)
                    {
                        arrayEmployee_removeEmployee(empleados, ELEMENTS, arrayEmployee_findEmployee(empleados, ELEMENTS, arrayEmployee_obtainID()));
                    }
                    else
                    {
                        printf("\nDebe ingresar al menos un empleado!");
                    }
                break;
                case 3:

                break;
                case 4:
                    arrayEmployee_printEmployees(empleados, ELEMENTS);
                    break;
                default:
                    opcion = 5;
            }
        }while(opcion != 5);
}

int arrayEmployee_initEmployees(Employee* list, int len)
{
    int i;
    int retorno = -1;

    if(list != NULL && len > 0)
    {
        for(i=0; i<=len; i++)
        {
            list[i].isEmpty = TRUE;
        }

        retorno = 0;
    }

    return retorno;
}

int arrayEmployee_isEmpty(Employee* list, int len)
{
    int i;
    int retorno = -1;

    if(list != NULL && len >= 0)
    {
        for(i=0; i<=len; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int arrayEmployee_obtainID(void)
{
    int retorno = -1;

    printf("\nIngrese ID: ");
    scanf("%d", &retorno);

    return retorno;
}

int arrayEmployee_assignID(void)
{
    static int id = 0;

    return id++;
}

int arrayEmployee_addEmployee(Employee* list, int len, int id, char* name, char* lastName, float salary, int sector)
{
    int retorno = -1;
    int indice;

    if(list != NULL && len >= 0 && id >= 0 && name != NULL && lastName != NULL && salary >= 0 &&  sector >= 0)
    {
        indice = arrayEmployee_isEmpty(list, len);

        printf("\n\nINDICE: %d", indice);

        if(indice != -1)
        {
            list[indice].id = id;
            strncpy(list[indice].name, name, 51);
            strncpy(list[indice].lastName, lastName, 51);
            list[indice].salary = salary;
            list[indice].sector = sector;
            list[indice].isEmpty = FALSE;
            retorno = 0;
        }
        else
        {
            printf("\nNo queda más espacio en el array!");
        }
    }

    return retorno;
}

int arrayEmployee_findEmployee(Employee* list, int len, int id)
{
    int i;
    int retorno = -1;

    if(list != NULL && len >= 0 && id >= 0)
    {
        for(i=0; i<=len; i++)
        {
            if(list[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int arrayEmployee_removeEmployee(Employee* list, int len, int id)
{
    int retorno = -1;

    if(list != NULL && len >= 0 && id >= 0)
    {
        list[id].isEmpty = TRUE;
        retorno = 0;
    }
    return retorno;
}

int arrayEmployee_modifyEmployee(Employee* list, int len, int id)
{

}

/*int arrayEmployee_sortEmployees(Employee* list, int len, int order)
{

}*/
int arrayEmployee_printEmployees(Employee* list, int len)
{
    int retorno = -1;
    int i;

    if(list != NULL && len >= 0)
    {
        printf("\n\nListado de empleados\n\n");

        for(i=0; i<=len; i++)
        {
            if(list[i].isEmpty != TRUE)
            {
                printf("ID: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d - Empty: %d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector, list[i].isEmpty);
            }
        }

        retorno = 0;
    }

    return retorno;
}
