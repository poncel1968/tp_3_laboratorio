#include <stdio.h>
#include <stdlib.h>
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
    int retorno = -1;
    FILE* pArchivo;
    pArchivo = fopen(path , "r");
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
    int retorno = -1;
    FILE* pArchivo;
    pArchivo = fopen(path , "rb");
    retorno = parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
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
    /*
    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];

    int retorno = -1;

    Employee * pEmpleado;

    if (utn_getString(bufferNombre, 1024,"Ingrese Nombre : ","Error en nombre") &&
        utn_getInt(bufferHorasTrabajadas,1024,"Ingrese horas trabajadas : ","Error horas trabajadas") &&
        utn_getInt(bufferSuedo,10, "Ingresar Sueldo:", "error Sueldo"))
    {
        pEmpleado = employee_newConParametros(  bufferInt,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
    }

*/
    return 1;
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
    return 1;
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

    return 1;
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
    int retorno=-1;
    int i;
    void* auxPunteroEmpleado;
    char nombre[50];
    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            employee_getNombre(auxPunteroEmpleado,nombre);
            printf("\nNombre: %s", nombre);
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
    return 1;
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
    return 1;
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
    FILE *pArchivo= fopen(path,"wb");
    Employee* pEmpleado;
    int i;
///    char nombre[100];

    if  (pArchivo != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            ///employee_getNombre(pEmpleado,nombre);
            ///printf("\n%s",nombre);
            fwrite(pEmpleado,sizeof(Employee),1,pArchivo);///para binarios se usa fwrite
        }
    }
    fclose(pArchivo);

    return 1;
}







