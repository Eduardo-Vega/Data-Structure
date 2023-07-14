/****************************************
   Description: 
        Busquedas en Lista Simplemente Enlazada
****************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo   // Define estructura nodo
{
    int num;          // dato
    struct nodo *sig; // apuntador
} nodo;

typedef nodo *apuntador; // Se define un tipo apuntador a nodo

// Declara contador de nodos
int tam = 0;


void insertaInicio(apuntador *P, int num)
{
    // Declara apuntador
    apuntador nuevo = NULL;

    // Asigna espacio de memoria al nuevo nodo
    nuevo = (nodo*) malloc(sizeof(nodo));

    // Asigna valores al nuevo nodo
    nuevo->num = num;
    nuevo->sig = *P;

    // Se asigna direccion al apuntador
    *P = nuevo;
    tam++;
}


void insertaFinal(apuntador *P, int num)
{
    // Declara apuntadores auxiliar y nuevo
    apuntador nuevo = NULL, aux = NULL;

    // Asigna apuntador a lista
    aux = *P;

    // Recorre la lista hasta encontrar el final
    while(aux->sig != NULL)
        aux = aux->sig;

    // Asigna espacio de memoria al nuevo nodo
    nuevo = (nodo*) malloc(sizeof(nodo));

    // Asigna valores al nuevo nodo
    nuevo->num = num;
    nuevo->sig = NULL;

    // Se asigna direccion al nodo final de lista
    aux->sig = nuevo;
    tam++;
}


void recorreRecursivo(apuntador P)
{
    if(P != NULL)
    {
        // Si hay nodo
        printf("\n  Direccion = %d | Numero = %d | Siguiente = %d |", P, P->num, P->sig);
        // Se mueve al siguiente nodo
        recorreRecursivo(P->sig);
    }
}



void busquedaDesordenada(apuntador *P, int numref)
{
    // Declara apuntadores auxiliar y nuevo
    apuntador ref = NULL;

    // Asigna apuntador a lista
    ref = *P;

    // Recorre la lista hasta encontrar el final
    while ((ref != NULL) && (ref->num != numref))
        ref = ref->sig;

    if(ref == NULL)
        printf("\n  El nodo %d no se encuentra en la lista! \n\n", numref);
    else
        printf("\n  El nodo %d esta ubicado en la direccion %d \n\n", ref->num, ref);
    system("pause");
}



void busquedaOrdenada(apuntador *P, int numref)
{
    // Declara apuntadores auxiliar y nuevo
    apuntador ref = NULL;

    // Asigna apuntador a lista
    ref = *P;

    // Recorre la lista hasta encontrar el final
    while ((ref != NULL) && (ref->num < numref))
        ref = ref->sig;

    if((ref == NULL) || (ref->num > numref))
        printf("\n  El nodo %d no se encuentra en la lista! \n\n", numref);
    else
        printf("\n  El nodo %d esta ubicado en la direccion %d \n\n", ref->num, ref);
    system("pause");
}


void busquedaRecursiva(apuntador P, int numref)
{
    if(P != NULL)
        if(P->num == numref)
            // Si se encuentra el nodo
            printf("\n  El nodo %d esta ubicado en la direccion %d \n\n", P->num, P);
        else
            // Se mueve al siguiente nodo
            busquedaRecursiva(P->sig, numref);
    else
        printf("\n  El nodo %d no se encuentra en la lista! \n\n", numref);
}


void main()
{
    // Declaraci�n de variables
    apuntador P = NULL;
    int op, num, numref;
    do {
        system("cls");
        printf("\n\n\n ---------------------------------------------");
        printf("\n  Operaciones con Lista Simplemente Enlazada  ");
        printf("\n ---------------------------------------------");
        printf("\n   1. Agregar nodo al Inicio");
        printf("\n   2. Agregar nodo al Final");
        printf("\n ---------------------------------------------");
        printf("\n   3. Mostrar elementos de la Lista");
        printf("\n ---------------------------------------------");
        printf("\n   4. Busqueda Desordenada");
        printf("\n   5. Busqueda Ordenada");
        printf("\n   6. Busqueda Desordenada Recursiva");
        printf("\n ---------------------------------------------");
        printf("\n   0. Salir");
        printf("\n\n Elige una opcion: ");
        scanf("%d",&op);
        switch(op) {
            case 1: system("cls");
                    printf("\n Ingresa un numero entero: ");
                    scanf("%d",&num);
                    insertaInicio(&P, num); // Direcci�n del apuntador
                    printf("\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

            case 2: system("cls");
                    printf("\n Ingresa un numero entero: ");
                    scanf("%d",&num);
                    insertaFinal(&P, num); // Direcci�n del apuntador
                    printf("\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

            case 3: system("cls");
                    printf("\n  P = %d", P);
                    recorreRecursivo(P);
                    printf("\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

            case 4: system("cls");
                    printf("\n     Numero de Referencia a buscar: ");
                    scanf("%d",&numref);
                    busquedaDesordenada(&P, numref);
                    break;

            case 5: system("cls");
                    printf("\n     Numero de Referencia a buscar: ");
                    scanf("%d",&numref);
                    busquedaOrdenada(&P, numref);
                    break;

            case 6: system("cls");
                    printf("\n     Numero de Referencia a buscar: ");
                    scanf("%d",&numref);
                    busquedaRecursiva(P, numref);
                    system("pause");
                    break;

        }
    }while(op);
}






