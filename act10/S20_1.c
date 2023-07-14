/****************************************
   Description: 
        Eliminaciones en Lista Simplemente Enlazada
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
        if (ref->sig != NULL) {
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


void eliminaInicio(apuntador *P)
{
    apuntador ref = NULL;

    // Asigna apuntador a lista
    ref = *P;
    printf("\n  El nodo = %d | Numero = %d | Siguiente = %d | ha sido eliminado! \n", ref, ref->num, ref->sig);
    // Se actualiza el apuntador apuntador de la lista
    *P = ref->sig;
    // Se libera la direcci�n de memoria
    free(ref);
    tam--;
    printf("\n  Borrado = %d | Numero = %d | Siguiente = %d |\n", ref, ref->num, ref->sig);
}


void eliminaFinal(apuntador *P)
{
    apuntador ant = NULL, ref = NULL;
    // Asigna apuntador a lista
    ref = *P;

    // Verifica si es el �ltimo nodo
    if (ref->sig == NULL)
        *P = NULL;
    else {
        // Recorre la lista hasta encontrar la referencia
        while(ref->sig != NULL) {
            ant = ref;
            ref = ref->sig;
        }
        // Limpia enlace del pen�ltimo nodo
        ant->sig = NULL;
    }
    printf("\n  El nodo = %d | Numero = %d | Siguiente = %d | ha sido eliminado! \n", ref, ref->num, ref->sig);
    // Se libera la direcci�n de memoria
    free(ref);
    tam--;
    printf("\n  Borrado = %d | Numero = %d | Siguiente = %d |\n", ref, ref->num, ref->sig);
}


eliminaNodo(apuntador *P, int numref)
{
    // Declara apuntadores y bandera
    apuntador ant = NULL, ref = NULL;
    int band = 1;

    // Asigna apuntador a lista
    ref = *P;

    // Recorre la lista hasta encontrar la referencia
    while((ref->num != numref) && band) {
        // Si no es el ultimo elemento busca el numero
        if (ref->sig != NULL) {
            ant = ref;
            ref = ref->sig;
        } else
            band = 0;
    };

    // Si se encontr� la referencia
    if (band == 0) {
        printf("\n\n No se encontro el nodo de referencia \n\n");
        system("pause");
    } else {
        // Verifica si es el primer nodo
        if (*P == ref)
            *P = ref->sig;
        else
            ant->sig = ref->sig;

        printf("\n  El nodo = %d | Numero = %d | Siguiente = %d | ha sido eliminado! \n", ref, ref->num, ref->sig);
        // Se libera la direcci�n de memoria
        free(ref);
        tam--;
        printf("\n  Borrado = %d | Numero = %d | Siguiente = %d |\n", ref, ref->num, ref->sig);

    }
}


void eliminaAntes(apuntador *P, int numref)
{
    // Declara apuntadores y bandera
    apuntador ant = NULL, ref = NULL, aux = NULL;
    // Valida si es el primer nodo
    if ((*P)->num == numref) {
        printf("\n\n No hay un numero que preceda al nodo %d \n\n", numref);
        system("pause");
    } else {
        // Asigna apuntadores e inicializa bandera
        ref = *P;
        ant = *P;
        int band = 1;

        // Recorre la lista hasta encontrar la referencia
        while((ref->num != numref) && band) {
            // Si no es el ultimo elemento
            if (ref->sig != NULL) {
                //Asigna referencias
                aux = ant;
                ant = ref;
                // Asigna siguiente a referencia
                ref = ref->sig;
            } else
                band = 0;
        }
        if (band == 0) {
            printf("\n\n No se encontro el nodo de referencia \n\n");
            system("pause");
        } else {
            if ((*P) == ant) { // Si es el primer nodo
                *P = ant->sig;
            }
            else
                aux->sig = ant->sig;
            printf("\n  El nodo = %d | Numero = %d | Siguiente = %d | ha sido eliminado! \n", ant, ant->num, ant->sig);
            // Se libera la direcci�n de memoria
            free(ant);
            tam--;
            printf("\n  Borrado = %d | Numero = %d | Siguiente = %d |\n\n", ant, ant->num, ant->sig);   system("pause");
        }
    }
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
        printf("\n   3. Agregar nodo antes de otro nodo");
        printf("\n   4. Agregar nodo despues de otro nodo");
        printf("\n ---------------------------------------------");
        printf("\n   5. Mostrar elementos de la Lista");
        printf("\n ---------------------------------------------");
        printf("\n   6. Eliminar el primer nodo");
        printf("\n   7. Eliminar el ultimo nodo");
        printf("\n   8. Eliminar un nodo       ");
        printf("\n   9. Eliminar el nodo anterior al nodo X     ");
        printf("\n ---------------------------------------------");
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

            case 6: system("cls");
                    printf("\n  P = %d", P);
                    eliminaInicio(&P);
                    printf("\n\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

            case 7: system("cls");
                    printf("\n  P = %d", P);
                    eliminaFinal(&P);
                    printf("\n\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

            case 8: system("cls");
                    printf("\n     Numero de Referencia a eliminar: ");
                    scanf("%d",&numref);
                    printf("\n  P = %d", P);
                    eliminaNodo(&P, numref);
                    printf("\n\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;


            case 9: system("cls");
                    printf("\n     Numero de Referencia: ");
                    scanf("%d",&numref);
                    printf("\n  P = %d", P);
                    eliminaAntes(&P, numref);
                    printf("\n\n Cantidad actual de nodos: %d \n\n",tam);
                    system("pause");
                    break;

        }
    }while(op);
}






