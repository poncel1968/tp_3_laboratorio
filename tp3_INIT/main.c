#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int ll_sort2(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* auxiliar;
    int i;
    int flagSwap;
    long contadorSeguridad = ll_len(this);

    if(this!=NULL && (order==0 || order==1) && pFunc!=NULL && ll_len(this)>0)
    {
        returnAux=0;
        do
        {
            flagSwap=0;
            for(i=0;i<(ll_len(this)-1);i++)
            {

                if(ll_get(this,i)!=NULL && ll_get(this,i+1)!=NULL)
                {
                    if(pFunc(ll_get(this,i),ll_get(this,i+1))==-1)
                    {
                        auxiliar=ll_get(this,i);
                        ll_set(this,i,ll_get(this,i+1));
                        ll_set(this,i+1,auxiliar);
                        flagSwap=1;
                    }
                }
            }
           // contadorSeguridad--;
           //printf("\n%d",contadorSeguridad);
        }while(flagSwap && contadorSeguridad);
    }
    return returnAux;

}

int main()
{
    int option = 1;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:

                printf("\nSize de la lista %d",ll_len(listaEmpleados));
                controller_loadFromText("data.csv",listaEmpleados);
                printf("\nSize de la lista %d",ll_len(listaEmpleados));
                option = 6;
                break;
            case 6:

                ll_sort2(listaEmpleados,employee_criterioSortNombre,1);

                controller_ListEmployee(listaEmpleados);
                option = 10;
                break;
        }
    }while(option != 10);
    return 0;
}
