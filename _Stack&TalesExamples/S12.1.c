/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo S12.1
   Descripción: Colas con Arreglos de Cadenas
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cola_llena(int fin, int max)
{
    if(fin == max)
        return 1;
    else
        return 0;
}


int cola_vacia(int frente, int fin)
{
    if(frente == fin)
        return 1;
    else
        return 0;
}


int insertar(char cola[][31], int fin, int max, char dato[])
{
    if(cola_llena(fin,max))
    {
        printf("\n\n ERROR: Desbordamiento, la cola esta llena!!! ");
        getche();
    }
    else
    {
        strcpy(cola[fin],dato);
        fin++;
    }
    return fin;
}


int eliminar(int frente, int *fin)
{
    if(cola_vacia(frente, *fin)){
        printf("\n\n ERROR: La Cola esta vacia!!!");
    }
    else
    {
        frente++;
        if(frente == *fin)
        {
            frente=0;
            *fin=0;
        }
        printf("\n Se elimino el elemento!!!");
    }
    return frente;
}



void reporte(char cola[][31],int frente, int fin)
{
    int i;
    system("cls");
    printf("\n\n Elementos de la Cola  ");
    printf("\n -------------------------------");
    for(i=frente; i<fin; i++)
        printf("\n Elemento [%d] : %s",i,cola[i]);

}


void main()
{

    int op, band=0, frente=0, fin=0, max=5;
    char cola[5][31], dato[31];
    do
    {
        system("cls");
        printf("\n\n  Manejo de Colas con Arreglos ");
        printf("\n\n  Cadenas de Caracteres        ");
        printf("\n --------------------------------");
        printf("\n [1] Agregar elemento (Enqueue)  ");
        printf("\n [2] Quitar elemento  (Dequeue)  ");
        printf("\n [3] Imprimir Cola               ");
        printf("\n [0] Salir                       ");
        printf("\n\n Opcion: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            do
            {
                system("cls");
                printf("\n\n Agregar Elementos (Enqueue) ");
                printf("\n -------------------------------");
                printf("\n  Elemento: ");
                fflush(stdin);
                gets(dato);
                fin = insertar(cola, fin, max, dato);
                printf("\n  Deseas agregar otro elemento (1=SI|0=NO): ");
                scanf("%d",&band);
            }
            while(band && fin<max);
            break;
        case 2:
            band=1;
            system("cls");
            printf("\n\n Quitar Elementos (Dequeue) ");
            printf("\n -------------------------------");
            printf("\n  Deseas quitar algun elemento (1=SI|0=NO): ");
            scanf("%d",&band);

            while(band && fin>0)
            {
                frente = eliminar(frente, &fin);
                printf("\n  Deseas quitar algun elemento (1=SI|0=NO): ");
                scanf("%d",&band);
            }
            break;
        case 3:
            if(cola_vacia(frente, fin))
            {
                printf("\n\n ERROR: La cola esta vacia!!!");
            }
            else
                reporte(cola, frente, fin);
                printf("\n\n");
                getche();
            break;
        }
    }
    while(op);
}






