/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo S14.5
   Descripción: Impresion de Arreglo Recursivo
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int imprime(int A[],int N)
{
    if(N >0)
    {
        imprime(A,N-1);
        printf("\n Arreglo[%d]: %d", N, A[N-1]);

    }
}
/*
void imprime(int N)
{
    for (int i=0; i<=N; i++)
    {
        printf("\n f(%d) = %d", i, fibonacci(i));
    }
}
*/

void main()
{
    int Num, Res;
    int arreglo[] = {98,25,48,37,36,91,27,18,77,64};
    printf("\n -----------------------------");
    printf("\n  Imprime Arreglo Recursivo ");
    printf("\n -----------------------------");
    printf("\n Numeros a Imprimir [1-10]: ");
    scanf("%d",&Num);
    imprime(arreglo, Num);
    printf("\n\n");
    system("pause");
}
