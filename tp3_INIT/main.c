#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

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


int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        printf("\n****************************************************\nMenu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n ");
        printf("3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n");
        printf("7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n");
        printf(" *****************************************************\n");
        utn_getInt(&option,5,"\nIngrese numero de opcion ","\nValor ingresado invalido \n");

        switch(option)
        {
            case 1:
                if (controller_loadFromText("data.csv",listaEmpleados)== 0)
                {
                        printf("Archivo texto subido con exito \n");
                }
                break;
            case 2:
                if (controller_loadFromBinary("dataB" , listaEmpleados)==0)
                {
                    printf("\nArchivo binario leido correctamente\n");
                }
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados)==0)
                {
                    printf("\nEmpleado dado de alta con exito \n");
                }
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                if(controller_removeEmployee(listaEmpleados)==0)
                {
                    printf("\nBaja exitosa\n");
                }
                break;
            case 6:
                if(controller_ListEmployee(listaEmpleados)==0)
                {
                    printf("\n Datos listados con exito\n");
                }
                break;
            case 7:
                if(controller_sortEmployee(listaEmpleados)== 0)
                {
                    printf("\n Registros ordenados\n");
                }
                break;
            case 8:
                if (controller_saveAsText("data.csv" , listaEmpleados)==0)
                {
                    printf("\nArchivo salvado con exito\n");
                }
                break;
            case 9:
                if (controller_saveAsBinary("dataB" ,listaEmpleados)==0)
                {
                    printf("\nArchivo binario salvado con exito\n ");
                }
                break;

        }
    }while(option != 10);

    return 0;
}
