#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "myLibrary.h"
#define ELEMENTS 100
#define TRUE 1
#define FALSE 0

/** \brief  Muestra menú ABM de empleados
 * \param void
 * \return void
 */

void arrayEmployee_menuEmployee(void)
{
    Employee empleados[ELEMENTS];
    arrayEmployee_initEmployees(empleados, ELEMENTS);

    int opcion = 0;
    int opcionInformes;
    int orden;

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
        myLibrary_getInt(&opcion, 10, "\nOpcion: ", "\nIngrese solo un numero!", 1);

            switch(opcion)
            {
                case 1:
                    myLibrary_getNombre(name, 51, "\nIngrese nombre: ", "\nIngrese solo letras!", 1);
                    myLibrary_getNombre(lastName, 51, "\nIngrese apellido: ", "\nIngrese solo letras!", 1);
                    myLibrary_getFloat(&salary, 100, "\nIngrese salario: ", "Ingrese solo numeros!", 1);
                    myLibrary_getInt(&sector, 100, "\nIngrese sector: ", "\nIngrese solo numeros!", 1);
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
                    if(flag != 0)
                    {
                      arrayEmployee_modifyEmployee(empleados, ELEMENTS, arrayEmployee_obtainID());
                    }
                    else
                    {
                        printf("\nDebe ingresar al menos un empleado!");
                    }

                    break;

                case 4:

                    if(flag != 0)
                    {
                        printf("\n1. Por apellido y sector");
                        printf("\n2. Total y promedio de salarios");
                        printf("\n\nOpcion:");
                        scanf("%d", &opcionInformes);

                        switch(opcionInformes)
                        {
                            case 1:
                                myLibrary_getInt(&orden, 10, "\nAscendente (1) o descendente (0): ", "\nIngrese solo numeros!", 1);
                                arrayEmployee_sortEmployees(empleados, ELEMENTS, orden);
                                arrayEmployee_printEmployees(empleados, ELEMENTS);
                                break;
                            case 2:
                                arrayEmployee_printSalariesEmployee(empleados, ELEMENTS);
                                break;
                            default:
                                printf("\nIngreso una opcion no valida! Saliendo...");
                        }
                    }
                    else
                    {
                        printf("\nDebe ingresar al menos un empleado!");
                    }
                    break;

                default:
                    opcion = 5;
            }
        }while(opcion != 5);
}

/** \brief  Indica que todas las posiciones en el array estan libres, esta funcion pone la bandera (isEmpty) en TRUE
 * en todas las posiciones del array
 * \param list Employee* Puntero al array de empleados
 * \param len int largo del array
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int arrayEmployee_initEmployees(Employee* list, int len)
{
    int i;
    int retorno = -1;

    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty = TRUE;
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief  Devuelve una posición del array de empleados que tenga la bandera isEmpty en TRUE
 * \param list Employee* Puntero al array de empleados
 * \param len int largo del array
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

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

/** \brief Pide un id
 * \param void
 * \return int return (-1) es error
 */

int arrayEmployee_obtainID(void)
{
    int retorno = -1;

    printf("\nIngrese ID: ");
    scanf("%d", &retorno);

    return retorno;
}

/** \brief Asigna un id
 * \param void
 * \return int return Primera devolucion es 0, luego incrementa
 */

int arrayEmployee_assignID(void)
{
    static int id = 0;

    return id++;
}

/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
 *   posición libre
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

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

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int return (-1) es error [Largo invalido o puntero nulo]
 */

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

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

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

/** \brief Modifica un empleado recibiendo como parámetro su Id
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int arrayEmployee_modifyEmployee(Employee* list, int len, int id)
{
    int opcion;
    int retorno = -1;

    printf("\n1. Nombre");
    printf("\n2. Apellido");
    printf("\n3. Salario");
    printf("\n4. Sector");
    printf("\nOpcion: ");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            myLibrary_getNombre(list[id].name, 51, "\nIngrese nombre: ", "\nIngrese solo letras!", 1);
            break;
        case 2:
            myLibrary_getNombre(list[id].lastName, 51, "\nIngrese apellido: ", "\nIngrese solo letras!", 1);
            break;
        case 3:
            myLibrary_getFloat(&list[id].salary, 100, "\nIngrese salario: ", "\nIngrese solo numeros!", 1);
            break;
        case 4:
            printf("\nIngrese sector: ");
            scanf("%d", &list[id].sector);
            break;
        default:
            printf("\nIngreso una opcion no valida! Saliendo...");
    }

    retorno = 0;

    return retorno;
}

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int arrayEmployee_sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmpleado;
    int i;
    int j;
    int retorno = -1;

    if(order == 0)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName, list[j].lastName) < 0)
                {
                    auxEmpleado = list[j];
                    list[j] = list[i];
                    list[i] = auxEmpleado;

                    retorno = 0;
                }
            }
        }
    }

    if(order == 1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName, list[j].lastName) > 0)
                {
                    auxEmpleado = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleado;

                    retorno = 0;
                }
            }
        }
    }


    return retorno;
}

/** \brief Imprime el array de empleados de forma encolumnada
 * \param list Employee*
 * \param len int
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int arrayEmployee_printEmployees(Employee* list, int len)
{
    int retorno = -1;
    int i;

    if(list != NULL && len >= 0)
    {
        printf("\n\nListado de empleados\n\n");

        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty != TRUE)
            {
                printf("ID: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            }
        }

        retorno = 0;
    }
    return retorno;
}

/** \brief Imprime total y promedio de salario de empleados
 * \param list Employee*
 * \param len int
 * \return int return (-1) es error [Largo invalido o puntero nulo] - (0) OK
 */

int arrayEmployee_printSalariesEmployee(Employee* list, int len)
{
    int retorno = -1;
    int acumulador = 0;
    float suma = 0;
    float promedio = 0;
    int i;

    if(list != NULL && len >= 0)
    {
        for(i=0; i<len; i++)
        {
            suma = suma + list[i].salary;
        }

        promedio = suma/len;

        for(i=0; i<len; i++)
        {
            if(list[i].salary > promedio)
            {
                acumulador++;
            }
        }

        printf("\nSuma total de salarios: %.2f", suma);
        printf("\nPromedio salarios: %.2f", promedio);
        printf("\nCantidad de salarios que superan el promedio: %d", acumulador);

        retorno = 0;
    }

    return retorno;
}
