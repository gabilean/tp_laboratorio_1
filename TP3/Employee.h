#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


Employee* Employee_new();
void Employee_delete();
Employee* Employee_newConParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo);

int Employee_getNextIdFromLL(void);
int Employee_setId(Employee* this,int id);
int Employee_getId(Employee* this,int* id);

int Employee_setNombre(Employee* this,char* nombre);
int Employee_getNombre(Employee* this,char* nombre);

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int Employee_setSueldo(Employee* this,int sueldo);
int Employee_getSueldo(Employee* this,int* sueldo);

int Employee_menuEmployee(void);
int Employee_addEmployeeToLL(LinkedList* pArrayListEmployee);
int Employee_modifyEmployee(LinkedList* pArrayListEmployee);
int Employee_removeEmployee(LinkedList* pArrayListEmployee);
int Employee_showEmployees(LinkedList* pArrayListEmployee, int sizeList);
int Employee_criterioSortNombre(void* thisA, void* thisB);
