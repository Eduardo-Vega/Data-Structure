/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo S12.3
   Descripción: Cola Circular
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insertar(int cola[], int *frente, int fin, int max, int dato)
{
    if((fin==max && *frente==0) || ((fin+1)==*frente))
    {
        printf("\n\n ERROR: Desbordamiento, la cola esta llena!!! ");
        getche();
    }
    else
    {
        if(fin==max)
            fin=0;

        cola[fin]=dato;
        fin++;

        if(*frente==-1)
            *frente=0;
    }
    return fin;
}


int eliminar(int cola[],int frente, int *fin, int max)
{
    int dato;
    if(frente==-1)
    {
        printf("\n\n ERROR: La Cola esta vacia!!!");
    }
    else
    {
        dato = cola[frente];
        cola[frente] = 0;
        if(frente==*fin)
        {
            frente=-1;
            *fin=0;
        }
        else {
            if(frente==max)
                frente=0;
            else
                frente++;
        }
        printf("\n Se elimino el elemento %d !!!", dato);
    }
    return frente;
}



void reporte(int cola[], int frente, int max)
{
    int i;
    system("cls");
    printf("\n\n Elementos de la Cola  ");
    printf("\n -------------------------------");
    if(frente==-1)
    {
        printf("\n\n ERROR: La Cola esta vacia!!!");
    }
    else
    {

        for(i=0; i<max; i++)
            printf("\n Elemento [%d] : %d",i,cola[i]);
    }
}


void main()
{

    int cola[5]={0}, dato, band, op, frente=0, fin=0, max=5;
    do
    {
        system("cls");
        printf("\n\n     Manejo de Cola Circular    ");
        printf("\n ---------------------------------");
        printf("\n [1] Agregar elemento (Enqueue)   ");
        printf("\n [2] Quitar elemento  (Dequeue)   ");
        printf("\n [3] Imprimir Cola                ");
        printf("\n [0] Salir                        ");
        printf("\n\n Opcion: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
                system("cls");
                printf("\n\n Agregar Elementos (Enqueue) ");
                printf("\n -------------------------------");
                printf("\n  Elemento: ");
                fflush(stdin);
                scanf("%d",&dato);
                fin = insertar(cola, &frente, fin, max, dato);
                break;
        case 2:
                frente = eliminar(cola, frente, &fin, max);
                getche();
                break;
        case 3:
                reporte(cola, frente, max);
                printf("\n\n");
                getche();
                break;
        }
    }
    while(op);
}






