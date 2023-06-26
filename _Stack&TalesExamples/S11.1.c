/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo S11.1
   Descripci�n: Pilas con arreglos
****************************************/
#include <stdio.h>
#include <stdlib.h>
int pila_vacia(int tope)
{
    if(tope==0)
        return 1;
    else
        return 0;
}

int pila_llena(int tope, int max)
{
    if(tope==max)
        return 1;
    else
        return 0;
}

void insertar(int *arr, int *tope, int max, int num)
{
    int t;
    t=*tope;
    if(pila_llena(t,max))
    {
        printf("\n\n ERROR: Desbordamiento, la pila esta llena!!! ");
        system("PAUSE");
    }
    else
    {
        arr[t]=num;
        t++;
        *tope=t;
    }
}

void eliminar(int *arr, int *tope)
{
    int t;
    t=*tope;
    if(pila_vacia(t))
    {
        printf("\n\n ERROR: La pila esta vacia!!!");
        system("PAUSE");
    }
    else
    {
        t--;
        *tope=t;
    }
}

void reporte(int *arr, int tope)
{
    int i;
    system("cls");
    printf("\n\n Elementos de la Pila  ");
    printf("\n -------------------------------");
    for(i=0; i<tope; i++)
        printf("\n Elemento [%d] : %d",i+1,arr[i]);

}


void main()
{
    int arr[10], tope=0, max=10, i, band, num, op;
    do
    {
        system("cls");
        printf("\n\n  Manejo de Pilas con Arraglos ");
        printf("\n -------------------------------");
        printf("\n [1] Agregar elemento (Apilar)");
        printf("\n [2] Quitar elemento (Despilar)");
        printf("\n [3] Imprimir Pila");
        printf("\n [0] Salir");
        printf("\n\n Opcion: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            do
            {
                system("cls");
                printf("\n\n Agregar Elementos (Apilar) ");
                printf("\n -------------------------------");
                printf("\n  Elemento: ");
                scanf("%d",&num);
                insertar(arr,&tope,max,num);
                printf("\n  Deseas agregar otro elemento (1=SI|0=NO): ");
                scanf("%d",&band);
            }
            while(band && tope<max);
            break;
        case 2:
            band=1;
            system("cls");
            printf("\n\n Quitar Elementos (Despilar) ");
            printf("\n -------------------------------");
            printf("\n  Deseas quitar algun elemento (1=SI|0=NO): ");
            scanf("%d",&band);
            while(band && tope>=0)
            {
                eliminar(arr,&tope);
                printf("\n  Deseas quitar algun elemento (1=SI|0=NO): ");
                scanf("%d",&band);
            }
            break;
        case 3:
            if(pila_vacia(tope))
            {
                printf("\n\n ERROR: La pila esta vacia!!!");
                system("PAUSE");
            }
            else
                reporte(arr,tope);
                printf("\n\n");
                system("PAUSE");
            break;
        }
    }
    while(op);
}






