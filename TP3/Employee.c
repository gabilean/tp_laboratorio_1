#include "Employee.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void Employee_delete(Employee* this)
{
    free(this);
}

Employee* Employee_newConParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo)
{
    Employee* this;
    this=Employee_new();
    int idInt;
    int sueldoInt;
    int horasTrabajadasInt;

    //validaciones con isValid (Una por cada tipo de dato)(Lo unico que hace es llamar a funciones que ya tengo hechas y devuelve si los datos ingresados son correctos)
    idInt = atoi(id);
    sueldoInt = atoi(sueldo);
    horasTrabajadasInt = atoi(horasTrabajadas);

    if(
    !Employee_setId(this,idInt)&&
    !Employee_setNombre(this,nombre)&&
    !Employee_setHorasTrabajadas(this,horasTrabajadasInt)&&
    !Employee_setSueldo(this,sueldoInt))
        return this;

    Employee_delete(this);
    return NULL;
}

int Employee_getNextIdFromLL(void)
{
    int static id = 1001;
    return id++;
}

int Employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int Employee_menuEmployee(void)
{
    int opcion;

    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
    printf("\n3. Alta de empleado");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)");
    printf("\n10. Salir");
    printf("\n\nOpcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int Employee_addEmployeeToLL(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int retorno = -1;
    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];

    //Aca debería validar con los buffers!

    sprintf(bufferInt, "%d", Employee_getNextIdFromLL());
    printf("ID: %s", bufferInt);
    printf("\nNombre: ");
    scanf("%s", bufferNombre);
    printf("\nHoras trabajadas: ");
    scanf("%s", bufferHorasTrabajadas);
    printf("\nSueldo: ");
    scanf("%s", bufferSueldo);

    pEmpleado = Employee_newConParametros(bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);

    //Luego guardar en la estructura del linkedlist

    if(pEmpleado != NULL)
    {
        ll_add(pArrayListEmployee, pEmpleado);
        retorno = 0;
    }

    return retorno;
}

/**

*/

int Employee_modifyEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    int option;
    int retorno = 0;
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int idEmployee;

    printf("\nIngrese ID de empleado a modificar: ");
    scanf("%d", &idEmployee);
    pEmployee = ll_get(pArrayListEmployee, idEmployee-1);

    printf("\nDatos del emplpeado seleccionado:");
    printf("\nNombre: %s - Horas Trabajadas: %d - Sueldo: %d", pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);

    printf("\nQue desea modificar?");
    printf("\n1. Nombre");
    printf("\n2. Horas trabajadas");
    printf("\n3. Sueldo");
    printf("\n\nOpcion: ");

    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("\nNombre: ");
            scanf("%s", bufferNombre);
            Employee_setNombre(pEmployee, bufferNombre);
            //ll_set(pArrayListEmployee, idEmployee, pEmployee);
            break;
        case 2:
            printf("\nHoras trabajadas: ");
            scanf("%s", bufferHorasTrabajadas);
            Employee_setHorasTrabajadas(pEmployee, atoi(bufferHorasTrabajadas));
            break;
        case 3:
            printf("\nSueldo: ");
            scanf("%s", bufferSueldo);
            Employee_setSueldo(pEmployee, atoi(bufferSueldo));
            break;
        default:
            printf("\nIngreso una opcion invalida");
    }

    return retorno;
}

/**

*/

int Employee_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee = NULL;
    int idEmployee;
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("\nSeleccione el ID de un empleado a eliminar: ");
        scanf("%d", &idEmployee);

        pEmployee = ll_get(pArrayListEmployee, idEmployee-1);
        ll_remove(pArrayListEmployee, idEmployee-1);
        printf("El empleado: %s ha sido eliminado", pEmployee->nombre);

        retorno = 0;
    }

    return retorno;
}

/**


*/

int Employee_showEmployees(LinkedList* pArrayListEmployee, int sizeList)
{
    Employee* pEmployee;

    int i;
    int retorno = 0;
    char auxNombre[1024];
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;

    for(i=0; i<sizeList; i++)
    {
        pEmployee = ll_get(pArrayListEmployee, i);
        Employee_getNombre(pEmployee, auxNombre);
        Employee_getSueldo(pEmployee, &auxSueldo);
        Employee_getId(pEmployee, &auxId);
        Employee_getHorasTrabajadas(pEmployee, &auxHorasTrabajadas);

        printf("\n%d - %s - %d - %d", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
    }

    return retorno;
}

/**

*/

int Employee_criterioSortNombre(void* thisA, void* thisB)
{
    char nombreA[50];
    char nombreB[50];
    int retorno = 0;

    Employee_getNombre(thisA, nombreA);
    Employee_getNombre(thisB, nombreB);

    if(strcmp(nombreA, nombreB) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreA, nombreB) < 0)
    {
        retorno = -1;
    }

    return retorno;
}
