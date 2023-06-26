/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo S14.3
   Descripción: Fibonacci Recursivo
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int N)
{
    if(N < 2)
        return N;
    else
        return fibonacci(N-1) + fibonacci(N-2);
}

void imprime(int N)
{
    for (int i=0; i<=N; i++)
    {
        printf("\n f(%d) = %d", i, fibonacci(i));
    }
}

void main()
{
    int Num, Res;
    printf("\n --------------------------");
    printf("\n    Serie de Fibonacci()   ");
    printf("\n --------------------------");
    printf("\n Ingrese numeros f(n): ");
    scanf("%d",&Num);
    // Impresión de los primeros dos números

    imprime(Num);
    printf("\n\n");
    system("pause");
}
