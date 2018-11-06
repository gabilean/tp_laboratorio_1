#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pArchivo;
    int retorno = -1;

    pArchivo = fopen(path, "r");
    if(!parser_EmployeeFromText(pArchivo, pArrayListEmployee))
    {
        retorno = 0;
    }

    fclose(pArchivo);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pArchivo;
    int retorno = -1;

    pArchivo = fopen(path, "rb");
    if(!parser_EmployeeFromBinary(pArchivo, pArrayListEmployee))
    {
        retorno = 0;
    }

    fclose(pArchivo);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        Employee_addEmployeeToLL(pArrayListEmployee);
        retorno = 0;
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        Employee_modifyEmployee(pArrayListEmployee);
        retorno = 0;
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        Employee_removeEmployee(pArrayListEmployee);
        retorno = 0;
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

 int controller_showEmployees(LinkedList* pArrayListEmployee, int sizeList)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        Employee_showEmployees(pArrayListEmployee, sizeList);
        retorno = 0;
    }

    return retorno;
}

/*int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* auxPunteroEmpleado;
    char nombre[50];

    if(pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxPunteroEmpleado = ll_get(pArrayListEmployee, i);
            Employee_getNombre(auxPunteroEmpleado, nombre);
            printf("\nNombre: %s", nombre);
        }
    }

    return retorno;
}*/

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        Employee_sortEmployee(pArrayListEmployee);
        retorno = 0;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pArchivo;
    int retorno = -1;

    pArchivo = fopen(path, "w+");
    if(!parser_EmployeeSavetoText(pArchivo, pArrayListEmployee))
    {
        retorno = 0;
    }

    fclose(pArchivo);

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pArchivo;
    int retorno = -1;

    pArchivo = fopen(path, "wb+");
    if(!parser_EmployeeSavetoBinary(pArchivo, pArrayListEmployee))
    {
        retorno = 0;
    }

    fclose(pArchivo);

    return retorno;
}
