#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int retorno=-1;
    int flagOnce=1;
    Employee * pEmpleado;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if( flagOnce)
            {
                flagOnce=0;
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferInt,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferInt,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            ///printf("%s,%s,%s,%s\n",bufferInt,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

        pEmpleado = Employee_newConParametros(bufferInt,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

        if(pEmpleado!=NULL)
        {
            retorno=0;
            ll_add(pArrayListEmployee,pEmpleado);
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
    int retorno=-1;
    int id;
    char idStr[10];
    char nombre[128];
    int horasTrabajadas;
    char horasTrabStr[64];
    int sueldo;
    char sueldoStr[64];
    int datosLeidos=0;
    Employee* pEmpleado=NULL;


    if(pFile!=NULL && pArrayListEmployee !=NULL)
    {
        rewind(pFile);
        while(!feof(pFile))
        {
            datosLeidos =  fread(&id,sizeof(int),1,pFile);
            datosLeidos =(fread(nombre,sizeof(char),128,pFile))+datosLeidos;
            datosLeidos =(fread(&sueldo,sizeof(int),1,pFile))+datosLeidos;
            datosLeidos=(fread(&horasTrabajadas,sizeof(int),1,pFile))+datosLeidos;
            sprintf(idStr,"%d",id);
            sprintf(horasTrabStr,"%d",horasTrabajadas);
            sprintf(sueldoStr,"%d",sueldo);

            if(datosLeidos==131)
            {
                pEmpleado = Employee_newConParametros(idStr,nombre,horasTrabStr,sueldoStr);
                ll_add(pArrayListEmployee,pEmpleado);
            }

        }
        printf("\n\n***Registros de archivo binario leidos correctamente***\n\n");
        retorno =0;
    }
    return retorno;
}
