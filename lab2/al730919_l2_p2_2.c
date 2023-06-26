#include <stdio.h>

/******************************************************************
 Nombre: Ruben Eduardo Vega Mayorga
 Matricula: 730919
 Fecha: 24 de septiembre del 2022
 Problema 2.2 Laboratorio 2
 Descripción:
        Se suman dos arreglos bidimensionales de celdas y valores ingresados.
********************************************************************/

void main(){
    int i, j, n=0;

    printf("Ingrese la dimension del arreglo cuadrado N x N: ");
    scanf("%d", &n);

    int arr1[n][n], arr2[n][n], arr3[n][n];
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("Ingrese el valor para el arreglo 1 de la celda[%d][%d]: ", i, j);
            scanf("%d",&arr1[i][j]);
            printf("Ingrese el valor para el arreglo 2 de la celda[%d][%d]: ", i, j);
            scanf("%d",&arr2[i][j]);

            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("\nArreglo 1: \n");
    
    for ( i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            printf("%d \t", arr1[i][j]);
        }
        printf("\n");
    }
    printf("\nArreglo 2: \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d \t", arr2[i][j]);
        }
        printf("\n");
    }
    printf("\nArreglo 3: \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d \t", arr3[i][j]);
        }
        printf("\n");
    }


}