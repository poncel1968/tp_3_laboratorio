#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "ll.h"

int getNextId(int idAnterior, int* pId)
{
    if (idAnterior>=0 && pId != NULL)
    {
        *pId=idAnterior+1;
        return 0;
    }
    return -1;
}

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

Employee* Employee_newConParametros(char* idStr,char* nombre,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    this=Employee_new();


    if(!Employee_setId(this,atoi(idStr))&& !Employee_setNombre(this,nombre)&& !Employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))&&
    !Employee_setSueldo(this,atoi(sueldoStr)))
    {
         return this;
    }


    Employee_delete(this);
    return NULL;
}


int Employee_setId(Employee* this,int id)
{
    int retorno=-1;
    int proximoId=-1;

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

int Employee_criterio(void* this, void* other)
{
    int sueldo1;
    int sueldo2;
    int criterio;
    int retorno;
    Employee* empleado1 = this;
    Employee* empleado2 = other;

    Employee_getSueldo(empleado1, &sueldo1);
    Employee_getSueldo(empleado2, &sueldo2);
    criterio =sueldo1-sueldo2;
    if(criterio<0)
    {
        retorno=-1;
    }
    else if (criterio<0)
    {
        retorno=1;
    }
    else
    {
        retorno=0;
    }

    return retorno;

}

int Employee_show(void* this)
{
    Employee* pEmpleado;
    pEmpleado=this;
    int retorno=-1;
    char nombre[128];
    int sueldo=0;

    if (pEmpleado != NULL)
    {
        printf("Datos del empleado ***\n");
        Employee_getNombre(this,nombre);
        printf("Nombre: %s \n",nombre);
        Employee_getSueldo(this,&sueldo);
        printf("Sueldo : %d \n",sueldo );
        retorno=0;
    }

    return retorno;
}

int Employee_criterioFiltro(void* this)
{
    int retorno=-1;
    int sueldo=0;
    Employee* pEmpleado;
    pEmpleado=this;


    if (this != NULL )
    {
        Employee_getSueldo(pEmpleado,&sueldo);
        if (sueldo <10000)
        {
            retorno = 0;
        }

    }

    return retorno;
}

