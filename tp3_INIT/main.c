#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "ll.h"

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
    99. Salir
*****************************************************/


int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosFiltrados = ll_newLinkedList();

    do{
        printf("\n****************************************************\nMenu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n ");
        printf("3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n");
        printf("7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10.Nueva lista Filtrada por sueldos menores a 17000\n11.Imprimir lista empleados\n");
        printf("12.Listados de empleados aplicaron filtro\n99. Salir\n ");
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
            case 10:
                listaEmpleadosFiltrados=controller_filter(listaEmpleados);
                if (listaEmpleadosFiltrados!=NULL)
                {
                    controller_showList(listaEmpleadosFiltrados);
                }
                break;
            case 11:

                if (controller_showList(listaEmpleados)== 0)
                {
                    printf("***Fin de la lista***");
                }
                break;
            case 12:
                if (controller_showList(listaEmpleadosFiltrados)==0)
                {
                    printf(" \n***Fin lista empleados aplicaron filtro");
                    printf("Tamaño lista empleados filtrados %d",ll_len(listaEmpleadosFiltrados));
                }
                break;
        }
    }while(option != 99);

    return 0;
}
