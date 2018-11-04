#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    //validaciones acá! o al contructor con parametros ya que deberia validar desde ahí!
    Employee* pEmpleado;
    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int flagOnce = 1;
    int retorno = -1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce = 0;

                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo); //Descarta primer linea
            }

            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            printf("%s - %s - %s - %s\n", bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);

            pEmpleado = Employee_newConParametros(bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);

            if(pEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, pEmpleado);
                retorno = 0;
            }
        }
    }

    return retorno;
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
    Employee* pEmpleado = NULL;
    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int flagOnce = 1;
    int retorno = -1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce = 0;

                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo); //Descarta primer linea
            }

            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            //printf("%s - %s - %s - %s\n", bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);

            if(pEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, pEmpleado);
                retorno = 0;
            }
        }
    }

    return retorno;
}
