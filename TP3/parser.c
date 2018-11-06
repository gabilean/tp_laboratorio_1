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

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado = NULL;
    int retorno = -1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            pEmpleado = Employee_new();
            fread(pEmpleado, sizeof(Employee), 1, pFile);
            ll_add(pArrayListEmployee, pEmpleado);
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados al archivo dataBackup.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeSavetoText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee = NULL;
    int retorno = -1;
    int i;
    int bufferId;
    int bufferSueldo;
    int bufferHorasTrabajadas;
    char bufferNombre[1024];


    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i == 0)
            {
                fprintf(pFile, "id,nombre,horas,sueldo\n");
            }

            pEmployee = ll_get(pArrayListEmployee, i);
            Employee_getNombre(pEmployee, bufferNombre);
            Employee_getId(pEmployee, &bufferId);
            Employee_getSueldo(pEmployee, &bufferSueldo);
            Employee_getHorasTrabajadas(pEmployee, &bufferHorasTrabajadas);

            fprintf(pFile, "%d, %s, %d, %d\n", bufferId, bufferNombre, bufferSueldo, bufferHorasTrabajadas);

            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados al archivo dataBackup.bin (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeSavetoBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado = NULL;
    int retorno = -1;
    int i;

    if(pFile != NULL)
    {
        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado,sizeof(Employee), 1, pFile);
            retorno = 0;
        }

        retorno = 0;
    }

    return retorno;
}

