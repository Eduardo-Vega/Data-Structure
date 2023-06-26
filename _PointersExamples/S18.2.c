/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo S18.2
   Descripción: Lista Simple Enlazada
****************************************/

#include<stdio.h>
#include<stdlib.h>

struct dato
{
    int num;          // dato
    struct dato *sig; // apuntador
};

struct dato *primer = NULL, *ultimo = NULL;


int insertaFinal(int tam)
{
    int band;
    struct dato *nuevo=NULL;
    do
    {
        system("cls");
        // Asigna espacio de memoria al nuevo nodo
        nuevo = (struct dato*) malloc(sizeof(struct dato));
        if(nuevo == NULL)
        {
            printf("\n No hay suficiente espacio! \n\n");
            system("pause");
        }
        else
        {
            printf("\n Ingresa un numero entero: ");
            scanf("%d",&nuevo->num);
            nuevo->sig = NULL;
            if(primer == NULL) // Si es el 1er nodo
            {
                primer = nuevo;
                ultimo = nuevo;
                tam++;
            }
            else             // Si no es el 1er. nodo
            {
                ultimo->sig = nuevo;
                ultimo = nuevo;
                tam++;
            }
        }
        printf("\n ... Deseas agregar otro numero? (1=SI|0=NO): ");
        scanf("%d",&band);
    } while(band);
    return tam;
}


void recorreLista()
{
    struct dato *aux = NULL;
    aux = primer;
    system("cls");
    if(aux == NULL)
    {
        // Si no hay nodos
        printf("\n Lista esta vacia! \n\n");
        system("pause");
    }
    else
    {
        // Mientras existan nodos
        while(aux != NULL)
        {
            printf("\n  Numero = %d", aux->num);
            aux = aux->sig;
        }
        printf("\n\n");
        system("pause");
    }
}


int quitaPrimer(int tam)
{
    if(primer == NULL)
    {
        // Si no hay nodos
        system("cls");
        printf("\n Lista esta vacia! \n\n");
        system("pause");
    }
    else
    {
        // Ahora primer toma valor de sig
        primer = primer->sig;
        tam--;
    }
    return tam;
}


void main()
{
    int op, tam=0;
    do
    {
        system("cls");
        printf("\n\n\n ---------------------------------------------");
        printf("\n  Operaciones con Lista Simplemente Enlazada  ");
        printf("\n ---------------------------------------------");
        printf("\n   1. Agregar nodo al final");
        printf("\n   2. Mostrar elementos de la Lista");
        printf("\n   3. Eliminar primer nodo");
        printf("\n   0. Salir");
        printf("\n\n Elige una opcion: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1: tam = insertaFinal(tam);
                    printf("\n Cantidad de nodos: %d\n",tam);
                    system("pause");
                    break;
            case 2: recorreLista();
                    break;
            case 3: tam = quitaPrimer(tam);
                    printf("\n Cantidad de nodos: %d \n\n",tam);
                    system("pause");
                    break;
        }
    }while(op);
}






