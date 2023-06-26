/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo 10.3
   Descripción: Búsqueda Lineal Mayor y Meno
****************************************/
#include <stdio.h>
#include <stdlib.h>

int i,j,k;

void imprime(int Arr[], int N)
{
    printf("\n");
    printf("  Arreglo: ");
    for (i=0; i<N; i++)
         printf(" [%d] %d ",i ,Arr[i]);
}


void BuscaMayMen(int vector[], int N)
{
    int May, Men;
    May = vector[N-1];
    Men = vector[0];
    for (i=0;i<=N-1;i+=1) {
        if (vector[i] < Men)
            Men = vector[i];
        if (vector[i] > May)
            May = vector[i];
    }
    printf("\n --------------------------------------");
    printf("\n  Valor Mayor: %d ",May);
    printf("\n  Valor Menor: %d ",Men);
}


void main(void)
{

    int Arreglo[10] = {5,16,7,9,2,8,4,1,12,3};
    int Num;
    printf("\n  Busqueda de elemento Mayor y Menor");
    printf("\n --------------------------------------");
    printf("\n  Arreglo Original:");
    imprime(Arreglo,8);
    BuscaMayMen(Arreglo, 8);
    printf("\n\n");
    system("pause");
}
