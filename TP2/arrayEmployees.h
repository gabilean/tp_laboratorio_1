#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

void arrayEmployee_menuEmployee(void);
int arrayEmployee_initEmployees(Employee* list, int len);
int arrayEmployee_isEmpty(Employee* list, int len);
int arrayEmployee_obtainID(void);
int arrayEmployee_assignID(void);
int arrayEmployee_addEmployee(Employee* list, int len, int id, char* name, char* lastName, float salary, int sector);
int arrayEmployee_findEmployee(Employee* list, int len, int id);
int arrayEmployee_removeEmployee(Employee* list, int len, int id);
int arrayEmployee_sortEmployees(Employee* list, int len, int order);
int arrayEmployee_printEmployees(Employee* list, int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
