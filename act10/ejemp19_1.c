
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


void insertaAntes(apuntador *P, int num, int numref)
{
    // Declara apuntadores y bandera
    apuntador nuevo = NULL, ant = NULL, ref = NULL;
    int band = 1;

    // Asigna apuntador a lista
    ref = *P;

    // Recorre la lista hasta encontrar la referencia
    while((ref->num != numref) && band) {
        // Si no es el ultimo elemento
        if (ref->sig !=NULL) {
            //Asigna referencia a anterior
            ant = ref;
            // Asigna siguiente a referencia
            ref = ref->sig;
        } else
            band = 0;
    }

    // Si se encontr� la referencia
    if (band) {
        // Asigna espacio de memoria al nuevo nodo
        nuevo = (nodo*) malloc(sizeof(nodo));

        // Asigna valores al nuevo nodo
        nuevo->num = num;

        if (*P == ref) { // Si ref es el primer nodo

            nuevo->sig = ref;
            *P = nuevo;
        } else {       // Si ref no es el primer nodo
            ant->sig = nuevo;
            nuevo->sig = ref;
        }
        tam++;
    } else {
        printf("\n\n No se encontro el nodo de referencia \n\n");
        system("pause");
    }
}


void insertaDespues(apuntador *P, int num, int numref)
{
    // Declara apuntadores y bandera
    apuntador nuevo = NULL, ref = NULL;
    int band = 1;

    // Asigna apuntador a lista
    ref = *P;

    // Recorre la lista hasta encontrar la referencia
    while((ref->num != numref) && band) {
        // Si no es el ultimo elemento
        if (ref->sig !=NULL)
            // Asigna siguiente a referencia
            ref = ref->sig;
        else
            band = 0;
    }

    // Si se encontr� la referencia
    if (band) {
        // Asigna espacio de memoria al nuevo nodo
        nuevo = (nodo*) malloc(sizeof(nodo));

        // Asigna valores a los nodos nuevo y ref
        nuevo->num = num;
        nuevo->sig = ref->sig;
        ref->sig = nuevo;
        tam++;
    } else {
        printf("\n\n No se encontro el nodo de referencia \n\n");
        system("pause");
    }
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


void main()
{
    // Declaracion de variables
    apuntador P = NULL, U = NULL;
    int op, num, numref;
    do {
        system("cls");
        printf("\n\n\n ---------------------------------------------");
        printf("\n  Operaciones con Lista Simplemente Enlazada  ");
        printf("\n ---------------------------------------------");
        printf("\n   1. Agregar nodo al Inicio");
        printf("\n   2. Agregar nodo al Final");
        printf("\n   3. Agregar nodo antes de otro nodo");
        printf("\n   4. Agregar nodo despues de otro nodo");
        printf("\n   5. Mostrar elementos de la Lista");
        printf("\n   0. Salir");
        printf("\n\n Elige una opcion: ");
        scanf("%d",&op);
        switch(op) {
            case 1: system("cls");
                    printf("\n Ingresa un numero entero: ");
                    scanf("%d",&num);
                    insertaInicio(&P, num); // Direcci�n del apuntador
                    printf("\n\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

            case 2: system("cls");
                    printf("\n Ingresa un numero entero: ");
                    scanf("%d",&num);
                    insertaFinal(&P, num); // Direcci�n del apuntador
                    printf("\n\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

            case 3: system("cls");
                    printf("\n     Numero de Referencia: ");
                    scanf("%d",&numref);
                    printf(" Ingresa un numero entero: ");
                    scanf("%d",&num);
                    insertaAntes(&P, num, numref);
                    printf("\n\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

            case 4: system("cls");
                    printf("\n     Numero de Referencia: ");
                    scanf("%d",&numref);
                    printf(" Ingresa un numero entero: ");
                    scanf("%d",&num);
                    insertaDespues(&P, num, numref);
                    printf("\n\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

            case 5: system("cls");
                    printf("\n  P = %d", P);
                    recorreRecursivo(P);
                    printf("\n\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

        }
    }while(op);
}
