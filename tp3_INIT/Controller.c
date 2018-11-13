#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

    FILE* pArchivo;
    int retorno=-1;
    pArchivo=fopen(path,"r");
    retorno = parser_EmployeeFromText(pArchivo,pArrayListEmployee);
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
    FILE* pArchivo;
    int retorno=-1;
    pArchivo=fopen(path,"rb");

    if (pArchivo != NULL && pArrayListEmployee != NULL)
    {
        retorno = parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
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
    Employee* newEmployee;
    char nombre[128];
    char horasTrabajadasStr[15];
    char sueldoStr[15];
    char idStr[3];
    int retorno=-1;

    if ( !utn_getString(nombre,128,"\nIngrese Nombre del empleado : ","\nError Nombre empleado") &&
         !utn_getString(horasTrabajadasStr,15,"\nIngrese Horas Trabajadas : ", "\nError horas trabajadas")&&
         !utn_getString(sueldoStr,15,"\nIngrese Sueldo : ","\nError suedo") &&
         !utn_getString(idStr,3,"\nIngrese Id : ","\nError Id"))
        {
            newEmployee = Employee_newConParametros(idStr,nombre,horasTrabajadasStr,sueldoStr);
            ll_add(pArrayListEmployee,newEmployee);
            retorno=0;
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
    int retorno=-1;
    Employee* empleado=NULL;
    int idBuscado;
    int i;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int opcion;


    if (pArrayListEmployee != NULL && utn_getInt(&idBuscado,8,"\nIngrese id del empleado a Modificar :","\nError Id ")==0 && idBuscado >0 )
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            empleado = (Employee*) ll_get(pArrayListEmployee,i);
            Employee_getId(empleado,&id);
            if (id==idBuscado)
            {
                retorno=0;
                break;
            }
        }
        if(retorno==0)
        {
                printf("Seleccione dato a Modificar : Datos anteriores -> \n");
                Employee_getNombre(empleado,nombre);
                printf("1=Nombre Anterior : %s \n",nombre);
                Employee_getHorasTrabajadas(empleado,&horasTrabajadas);
                printf("2=Horas trabajadas : %d \n",horasTrabajadas);
                Employee_getSueldo(empleado,&sueldo);
                printf("3=Sueldo : %d \n",sueldo);
                utn_getInt(&opcion,5,"Ingrese opcion : (99 para salir)"," Error opcion" );

                switch (opcion)
                {
                    case 1:
                        if (utn_getString(nombre,128,"\nNuevo nombre : ", "Error nombre")==0)
                        {
                            Employee_setNombre(empleado,nombre);
                        }
                        break;
                    case 2:
                        if (utn_getInt(&horasTrabajadas,128,"\nNuevo horas trabajadas : ", "Error nombre")==0)
                        {
                            Employee_setHorasTrabajadas(empleado,horasTrabajadas);
                        }
                        break;
                    case 3:
                        if (utn_getInt(&sueldo,128,"\nNuevo sueldo : ", "Error nombre")==0)
                        {
                            Employee_setHorasTrabajadas(empleado,sueldo);
                        }
                        break;
                    case 99:
                        printf("\n**Fin menu de modificacion**\n");
                        break;
                    default :
                        printf("\n ***Opcion modificar invalida ***");
                }
        }
        else
        {
            printf("\nId inexistente \n");
        }

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

    int retorno=-1;
    Employee* empleado=NULL;
    int idBuscado;
    int i;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int opcion;


    if (pArrayListEmployee != NULL && utn_getInt(&idBuscado,50,"\nIngrese id del empleado a dar de Baja :","\nError Id ")==0 && idBuscado >0 )
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            empleado = (Employee*) ll_get(pArrayListEmployee,i);
            Employee_getId(empleado,&id);
            if (id==idBuscado)
            {
                retorno=0;
                break;
            }
        }
        if(retorno==0)
        {
                printf("Datos de empleado a dar de baja  -> \n");
                Employee_getNombre(empleado,nombre);
                printf("Nombre  : %s \n",nombre);
                Employee_getHorasTrabajadas(empleado,&horasTrabajadas);
                printf("Horas trabajadas : %d \n",horasTrabajadas);
                Employee_getSueldo(empleado,&sueldo);
                printf("Sueldo : %d \n",sueldo);
                utn_getInt(&opcion,5,"\nPara confirmar ingrese 1 ->  "," Error opcion" );

                switch (opcion)
                {
                    case 1:
                            ll_remove(pArrayListEmployee,idBuscado);
                        break;

                    default :
                        printf("\n ***Opcion modificar invalida ***");
                }
        }
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
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* auxPunteroEmpleado;
    char nombre[50];
    int id;
    int sueldo;

    if(pArrayListEmployee != NULL )
    {
        retorno=0;
        for (i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxPunteroEmpleado=ll_get(pArrayListEmployee,i);
            Employee_getNombre(auxPunteroEmpleado,nombre);
            Employee_getId(auxPunteroEmpleado,&id);
            Employee_getSueldo(auxPunteroEmpleado,&sueldo);
            printf("\n Nombre: %s, Id: %d , Sueldo  %d" ,nombre,id,sueldo);
            printf("\nCantidad de empleados : %d",ll_len(pArrayListEmployee));
        }
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if (pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee, Employee_criterio, 0);
        retorno=0;
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
    int retorno=-1;
    Employee * pEmpleado;
    int id;
    int sueldo;
    int horasTrabajadas;
    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    FILE* pFile=fopen(path,"w");
    int i;

    if(pFile!=NULL && pArrayListEmployee !=NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmpleado=ll_get(pArrayListEmployee,i);
            Employee_getId(pEmpleado,&id);
            Employee_getNombre(pEmpleado,bufferNombre);
            Employee_getSueldo(pEmpleado,&sueldo);
            Employee_getHorasTrabajadas(pEmpleado,&horasTrabajadas);
            sprintf(bufferInt, "%d", id);
            sprintf(bufferSueldo,"%d",sueldo);
            sprintf(bufferHorasTrabajadas,"%d",horasTrabajadas);
            fprintf(pFile,"%s,%s,%s,%s\n",bufferInt,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            printf("%s,%s,%s,%s\n",bufferInt,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        }
    fclose(pFile);
    retorno=0;
    }
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
    int retorno=-1;
    FILE* pFile;
    pFile=fopen(path,"wb");
    Employee* empleado;
    int i;

    if (pFile!= NULL && pArrayListEmployee !=NULL)
    {
       for (i=0;i<ll_len(pArrayListEmployee);i++)
       {
            empleado=ll_get(pArrayListEmployee,i);
            fwrite(empleado,140,1,pFile);
       }
        retorno=0;
        fclose(pFile);
    }
    return retorno;
}

