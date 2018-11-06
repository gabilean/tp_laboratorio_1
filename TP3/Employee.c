#include "Employee.h"
#include "LinkedList.h"
#include "myLibrary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Asigna espacio en memoria para un empleado
* \param void
* \return Employee* Devuelve un puntero a Employee con espacio en memoria reservado
*/

Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

/**
* \brief Libera espacio en memoria
* \param Employee* this
* \return void
*/

void Employee_delete(Employee* this)
{
    free(this);
}

/**
* \brief Libera espacio en memoria
* \param char* id
* \param char* nombre
* \param char* horasTrabajadas
* \param char* sueldo
* \return Employee* Devuelve puntero a empleado con datos seteados, si falla devuelve NULL
*/

Employee* Employee_newConParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo)
{
    Employee* this;
    this=Employee_new();
    int idInt;
    int sueldoInt;
    int horasTrabajadasInt;

    idInt = myLibrary_getIntAsCharReturnInt(id);
    sueldoInt = myLibrary_getIntAsCharReturnInt(sueldo);
    horasTrabajadasInt = myLibrary_getIntAsCharReturnInt(horasTrabajadas);

    if(idInt != -1 && sueldoInt != -1 && horasTrabajadasInt != -1)
    {
        if(
        !Employee_setId(this,idInt)&&
        !Employee_setNombre(this,nombre)&&
        !Employee_setHorasTrabajadas(this,horasTrabajadasInt)&&
        !Employee_setSueldo(this,sueldoInt))
            return this;
    }

    Employee_delete(this);
    return NULL;
}

/**
* \brief Obtiene siguiente ID a partir del 1001
* \param void
* \return int Siguiente id
*/

int Employee_getNextIdFromLL(void)
{
    int static id = 1001;
    return id++;
}

/**
* \brief Asigna un valor al campo id de Employee
* \param Employee* this
* \param int id
* \return 0 seteo correcto, -1 seteo incorrecto
*/

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

/**
* \brief Obtiene el valor del campo id de Employee
* \param Employee* this
* \param int id
* \return 0 obtencion correcta, -1 obtencion incorrecta
*/

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

/**
* \brief Asigna un valor al campo nombre de Employee
* \param Employee* this
* \param char* nombre
* \return 0 seteo correcto, -1 seteo incorrecto
*/

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

/**
* \brief Obtiene el valor del campo nombre de Employee
* \param Employee* this
* \param char* nombre
* \return 0 obtencion correcta, -1 obtencion incorrecta
*/

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

/**
* \brief Asigna un valor al campo horasTrabajadas de Employee
* \param Employee* this
* \param int horasTrabajadas
* \return 0 seteo correcto, -1 seteo incorrecto
*/

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

/**
* \brief Obtiene el valor del campo horasTrabajadas de Employee
* \param Employee* this
* \param int* horasTrabajadas
* \return 0 obtencion correcta, -1 obtencion incorrecta
*/

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

/**
* \brief Asigna un valor al campo sueldo de Employee
* \param Employee* this
* \param int sueldo
* \return 0 seteo correcto, -1 seteo incorrecto
*/

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

/**
* \brief Obtiene el valor del campo sueldo de Employee
* \param Employee* this
* \param int* id
* \return 0 obtencion correcta, -1 obtencion incorrecta
*/

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

/**
* \brief Muestra menu de Employee
* \param void
* \return int con el numero de opcion
*/

int Employee_menuEmployee(void)
{
    int opcion;

    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)");
    printf("\n3. Alta de empleado");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    printf("\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario)");
    printf("\n10. Salir");
    myLibrary_getIntWithMessage(&opcion, 1024, "\nOpcion: ", "\nIngrese solo numeros", 2);

    return opcion;
}

/**
* \brief Agrega un empleado a la LinkedList
* \param LinkedList* pArrayListEmployee
* \return 0 carga correcta, -1 carga incorrecta
*/

int Employee_addEmployeeToLL(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int retorno = -1;
    int bufferInt;
    char bufferNombre[1024];
    int bufferSueldo;
    int bufferHorasTrabajadas;

    pEmpleado = Employee_new();
    //Aca debería validar con los buffers!
    if(pArrayListEmployee != NULL)
    {
        bufferInt = Employee_getNextIdFromLL();
        myLibrary_getNombreWithMessage(bufferNombre, 1024, "\nNombre: ", "\nIngrese solo letras", 2);
        myLibrary_getIntWithMessage(&bufferHorasTrabajadas, 1024, "\nHoras trabajadas:", "\nIngrese solo numeros", 2);
        myLibrary_getIntWithMessage(&bufferSueldo, 1024, "\nSueldo:", "\nIngrese solo numeros", 2);
        //Luego guardar en la estructura del linkedlist
        if(pEmpleado != NULL)
        {
            Employee_setId(pEmpleado, bufferInt);
            Employee_setNombre(pEmpleado, bufferNombre);
            Employee_setSueldo(pEmpleado, bufferSueldo);
            Employee_setHorasTrabajadas(pEmpleado, bufferHorasTrabajadas);
            ll_add(pArrayListEmployee, pEmpleado);
            retorno = 0;
        }
    }
    return retorno;
}

/**
* \brief Modifica un empleado de la LinkedList
* \param LinkedList* pArrayListEmployee
* \return 0 modificacion correcta, -1 modificacion incorrecta
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
* \brief Elimina un empleado de la LinkedList
* \param LinkedList* pArrayListEmployee
* \return 0 eliminacion correcta, -1 eliminacion incorrecta
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
* \brief Muestra empleados de la LinkedList
* \param LinkedList* pArrayListEmployee
* \param int sizeList
* \return 0 muestra correcta, -1 muestra incorrecta
*/

int Employee_showEmployees(LinkedList* pArrayListEmployee, int sizeList)
{
    Employee* pEmployee;

    int i;
    int retorno = -1;
    char auxNombre[1024];
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pArrayListEmployee != NULL && sizeList > 0)
    {
        for(i=0; i<sizeList; i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            Employee_getNombre(pEmployee, auxNombre);
            Employee_getSueldo(pEmployee, &auxSueldo);
            Employee_getId(pEmployee, &auxId);
            Employee_getHorasTrabajadas(pEmployee, &auxHorasTrabajadas);

            printf("\n%d - %s - %d - %d", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        }

        retorno = 0;
    }
    return retorno;
}

/**
* \brief Ordena empleados de la LinkedList
* \param LinkedList* pArrayListEmployee
* \return 0 muestra correcta, -1 muestra incorrecta
*/

int Employee_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
            printf("\n1. Ordernar por nombre");
            printf("\n2. Ordenar por sueldo");
            printf("\n3. Ordenar por horas trabajadas");
            printf("\n\nOpcion:");
            scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    ll_sort(pArrayListEmployee, Employee_criterioSortNombre, 1);
                    break;
                case 2:
                    ll_sort(pArrayListEmployee, Employee_criterioSortSueldo, 1);
                    break;
                case 3:
                    ll_sort(pArrayListEmployee, Employee_criterioSortHoras, 1);
                    break;
                default:
                    printf("\nOpcion invalida!");
            }

        retorno = 0;
    }

    return retorno;
}

/**
* \brief Criterio de ordenamiento para empleados segun nombre de la LinkedList
* \param void* thisA
* \param void* thisB
* \return 0 no se produce orden, 1 ordenamiento ascendente, -1 ordanmiento descendente
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

/**
* \brief Criterio de ordenamiento para empleados segun sueldo de la LinkedList
* \param void* thisA
* \param void* thisB
* \return 0 no se produce orden, 1 ordenamiento ascendente, -1 ordanmiento descendente
*/

int Employee_criterioSortSueldo(void* thisA, void* thisB)
{
    int sueldoA;
    int sueldoB;
    int retorno = 0;

    Employee_getSueldo(thisA, &sueldoA);
    Employee_getSueldo(thisB, &sueldoB);

    if(sueldoA > sueldoB)
    {
        retorno = 1;
    }
    else if(sueldoA < sueldoB)
    {
        retorno = -1;
    }

    return retorno;
}

/**
* \brief Criterio de ordenamiento para empleados segun horasTrabajadas de la LinkedList
* \param void* thisA
* \param void* thisB
* \return 0 no se produce orden, 1 ordenamiento ascendente, -1 ordanmiento descendente
*/

int Employee_criterioSortHoras(void* thisA, void* thisB)
{
    int horasA;
    int horasB;
    int retorno = 0;

    Employee_getHorasTrabajadas(thisA, &horasA);
    Employee_getHorasTrabajadas(thisB, &horasB);

    if(horasA > horasB)
    {
        retorno = 1;
    }
    else if(horasA < horasB)
    {
        retorno = -1;
    }

    return retorno;
}
