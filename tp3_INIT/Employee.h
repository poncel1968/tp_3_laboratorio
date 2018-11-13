#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* Employee_new();
Employee* Employee_newConParametros(char* idStr,char* nombre,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int Employee_setId(Employee* this,int id);
int Employee_getId(Employee* this,int* id);

int Employee_setNombre(Employee* this,char* nombre);
int Employee_getNombre(Employee* this,char* nombre);

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int Employee_setSueldo(Employee* this,int sueldo);
int Employee_getSueldo(Employee* this,int* sueldo);

int getNextId(int idAnterior, int* pId);
Employee* Employee_newConParametrosConsole(int* pId, char* nombre,char* horasTrabajadasStr,char* sueldoStr);
int Employee_criterio(void* this, void* other);

#endif // employee_H_INCLUDED
