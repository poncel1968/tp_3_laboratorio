#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"
#include "LinkedList.h"


LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* retorno = NULL;
    int i;
    LinkedList* listfilter;
    void * pElement=NULL;

    if(this != NULL && pFunc!=NULL)
    {
        listfilter=ll_newLinkedList();
        for (i=0; i<ll_len(this); i++)
        {
            pElement=ll_get(this,i);
            if(pFunc(pElement)==0)
            {
                ll_add(listfilter,pElement);
            }
        }
        retorno = listfilter;
    }
    return retorno;
}


int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int retorno=-1;
    int i;
    void * pElement=NULL;

    if(this !=NULL && pFunc !=NULL)
    {
        for (i=0;i<ll_len(this);i++)
        {
            pElement= ll_get(this,i);
            pFunc(pElement);
        }
        retorno=0;
    }

    return retorno;
}


