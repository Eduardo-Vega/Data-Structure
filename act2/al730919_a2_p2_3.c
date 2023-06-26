#include <stdio.h>
#include <stdlib.h>
/******************************************************************
 Nombre: Ruben Eduardo Vega Mayorga
 Matricula: 730919
 Fecha: 7 de octubre del 2022
 Problema 2.3 Actividad 2
 Descripción:
        Se solicitan las dimensiones N y M y los valores para las matrices enteras A[MxN] y B[NxM]
        para calcular la suma de A más la matriz transpuesta de B.
********************************************************************/
void main()
{
    int n, m, i, j;

    printf("\nIngrese la medida de las matrices A[MxN] y B[NxM]: \n\nIngrese el valor de N: ");
    scanf("%d", &n);
    printf("Ingrese el valor de M: ");
    scanf("%d", &m);

    int A[m][n];
    int B[n][m];
    int C[m][n];

    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("Ingrese el valor para A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            printf("Ingrese el valor para B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    printf("\n----- MATRIZ A -----\n");

    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[j][i];
            printf("%d \t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n------ MATRIZ B -----\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
           printf("%d \t", B[i][j]);
        }
        printf("\n");
    }
    printf("\n---MATRIZ C SUMA DE A(MxN) + BTranspuesta(MxN)---\n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d \t", C[i][j]);
        }
        printf("\n");
    }
    system("PAUSE");
}
