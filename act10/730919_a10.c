/********************
Description: 
    
********************/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    struct node *next;
}node;

typedef node *prompter;

int size = 0;

void insertFirst(prompter *P, int num){
    prompter nuevo = NULL;
    nuevo = (node*) malloc(sizeof(node));
    nuevo->num = num;
    nuevo->next = *P;
    *P = nuevo;
    size++;
}

void insertEnd(prompter *P, int num){
    prompter nuevo = NULL, aux = NULL;
    aux = *P;
    while(aux->next != NULL){
        aux = aux->next;
    }
    nuevo = (node*) malloc(sizeof(node));
    nuevo->num = num;
    nuevo->next = NULL;
    aux->next = nuevo;
    size++;
}

void deleteFirst(prompter *P){
    prompter ref = NULL;
    ref = *P;
    printf("\n   El nodo = %d || Numero = %d || Siguiente = %d ||", ref, ref->num, ref->next);
    *P = ref->next;
    free(ref);
    size--;
    printf("\n   Borrado = %d || Numero = %d || Siguiente = %d||\n", ref, ref->num, ref->next);
}

void deleteEnd(prompter *P){
    prompter ant = NULL, ref = NULL;
    ref = *P;
    if(ref->next == NULL)
        *P = NULL;
    else{
        while(ref->next != NULL){
            ant = ref;
            ref = ref->next;
        }
        ant->next = NULL;
    }
    printf("\n   El nodo = %d || Numero = %d || Siguiente = %d ||", ref, ref->num, ref->next);
    free(ref);
    size--;
    printf("\n   Borrado = %d || Numero = %d || Siguiente = %d||\n", ref, ref->num, ref->next);
}

void PrintList(prompter P){
    node* ref = P;
    while(ref){
        printf("\n     Direccion = %d || Numero = %d || Siguiente = %d ||", ref, ref->num, ref->next);
        ref = ref->next;
    }
}

void main(){
    prompter P = NULL;
    int op, num;
    do{
        system("cls");
        printf("\n--------------------------------------------------");
        printf("\n        Actividad 10 Equipo 5");
        printf("\n--------------------------------------------------");
        printf("\n     [1] AGREGAR NODO AL PRINCIPIO");
        printf("\n     [2] AGREGAR NODO AL FINAL");
        printf("\n     [3] ELIMINAR PRIMER NODO");
        printf("\n     [4] ELIMINAR ULTIMO NODO");
        printf("\n     [5] MOSTRAR LISTA");
        printf("\n     [0] SALIR");
        printf("\n--------------------------------------------------");
        printf("\n  Porfavor ingrese la opcion que desea insertar:\t");
        scanf("%d", &op);
        switch(op){
        case 1:
            // system("cls");
            printf("\n   Porfavor ingresa un numero entero:\t");
            scanf("%d", &num);
            insertFirst(&P, num);
            printf("\n\n   Cantidad de nodos:\t%d\n\n", size);
            system("pause");
            break;
        case 2:
            // system("cls");
            printf("\n   Porfavor ingresa un numero entero:\t");
            scanf("%d", &num);
            insertEnd(&P, num);
            printf("\n\n   Cantidad de nodos:\t%d\n\n", size);
            system("pause");
            break;
        case 3:
            // system("cls");
            deleteFirst(&P);
            printf("\n\n   Cantidad de nodos:\t%d\n\n", size);
            system("pause");
            break;
        case 4:
            // system("cls");
            deleteEnd(&P);
            printf("\n\n   Cantidad de nodos:\t%d\n\n", size);
            system("pause");
            break;
        case 5:
            // system("cls");
            PrintList(P);
            printf("\n\n   Cantidad de nodos:\t%d\n\n", size);
            system("pause");
            break;
        }
    }while(op);
    printf("Saliendo...\n");
    system("PAUSE");
}