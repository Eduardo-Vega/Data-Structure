/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo S12.2
   Descripción: Cola de Cadenas con Prioridad
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nom[30];
    int pri;
} elemento;


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


void ordenar(elemento *cola,int frente,int fin)
{
    int i,j;
    elemento aux;
    for(i=frente; i<fin-1; i++)
        for(j=i+1; j<fin; j++)
        {
            if(cola[i].pri>cola[j].pri)
            {
                aux=cola[i];
                cola[i]=cola[j];
                cola[j]=aux;
            }
        }
}


int insertar(elemento *cola, int frente, int *fin, int max, elemento dato)
{

    int u;
    u=*fin;
    if(cola_llena(u,max))
    {
        printf("\n\n ERROR: Desbordamiento, la cola esta llena!!! ");
        getche();
    }
    else
    {
        cola[u]=dato;
        u++;
        *fin=u;
    }
    ordenar(cola,frente,u);
}


int eliminar(elemento *cola, int *frente, int *fin, int max)
{
    int f, u;
    f = *frente;
    u = *fin;
    if(cola_vacia(f, u)){
        printf("\n\n ERROR: La Cola esta vacia!!!");
    }
    else
    {
        f++;
        *frente = f;
        printf("\n Se elimino el elemento!!!");
    }
    if(f==max)
    {
        f=0;
        *frente=f;
        u=0;
        *fin=u;
    }
}


void reporte(elemento *cola,int frente, int fin)
{
    int i;
    system("cls");
    printf("\n\n Elementos de la Cola  ");
    printf("\n -------------------------------");
    for(i=frente; i<fin; i++)
        printf("\n [%d] P: %d | E: %s",i,cola[i].pri,cola[i].nom);

}


void main()
{

    int op, band=0, frente=0, fin=0, max=5;
    elemento cola[5], dato;
    do
    {
        system("cls");
        printf("\n\n   Manejo de Colas de Cadenas  ");
        printf("\n           con Prioridad         ");
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
                printf("\n   Elemento: ");
                fflush(stdin);
                gets(dato.nom);
                printf("  Prioridad: ");
                scanf("%d",&dato.pri);
                insertar(cola, frente, &fin, max, dato);
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
                eliminar(cola, &frente, &fin, max);
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






