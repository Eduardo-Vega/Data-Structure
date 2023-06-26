#include<stdio.h>

/******************************************************************
 Nombre: Ruben Eduardo Vega Mayorga
 Matricula: 730919
 Fecha: 7 de octubre del 2022
 Problema 2.1 Actividad 2
 Descripción:
        Se dibuja una serie de 1's en la diagonal de la matriz cuadrada A[NxN], 
        solicitando la dimensión de la misma.
********************************************************************/

void main()
{
    int n = 0, i, j;

    printf("Ingrese la medida de la matriz cuadrada A[NxN]: ");
    scanf("%d", &n);

    int array[n][n];

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (i == j)
            {
                array[i][j] = 1;
            } 
            else{
                array[i][j] =  0;
            }
            
        }
        
    }

    
    printf("\n El arreglo con diagonal en 1 queda de la siguiente manera: \n\n");
    for ( i = 0; i < n; i++)
    {
        printf("\t");
        for ( j = 0; j < n; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
}