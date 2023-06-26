#include <stdio.h>

/******************************************************************
 Nombre: Ruben Eduardo Vega Mayorga
 Matricula: 730919
 Fecha: 24 de septiembre del 2022
 Problema 1.3 Laboratorio 1
 Descripción:
        Calculo de la suma de dos arreglos ingresados.
********************************************************************/

void printArr(float arr[], int n){
    int i;
    for (i=0;i<n;i++){
        printf("%.2f ", arr[i]);
    }
}

void main()
{
    int n=0, i;
    float arr1[n], arr2[n], arr3[n];
    printf("\nIngrese la cantidad de elemetos para el arreglo 1 y 2: \n");
    scanf("%d",&n);
    printf("\nIngrese los valores de los arreglos: ");
    for (i=0;i<n;i++) {
        printf("\nArreglo 1[%d]: ", i+1);
        scanf("%f",&arr1[i]);
        printf("Arreglo 2[%d]: ", i+1);
        scanf("%f",&arr2[i]);
    }
    for (i=0;i<n;i++) {
        arr3[i] = arr1[i] + arr2[i];
    }
    printf("\nArreglos generados: \n\n");
    printf("Arreglo 1: ");
    printArr(arr1, n);

    printf("\nArreglo 2: ");
    printArr(arr2, n);

    printf("\nArreglo 3 suma de los anteriores: ");
    printArr(arr3, n);
}
