/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo S14.3
   Descripci�n: Fibonacci Iterativo
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fibonacci(int N)
{
    int i, Pri = 0, Seg = 1, Sig;
    for (int i=2; i<=N; i++)
    {
        Sig = Pri + Seg;
        Pri = Seg;
        Seg = Sig;
        printf("\n f(%d) = %d", i, Sig);
    }
}

void main()
{
    int Num;
    printf("\n --------------------------");
    printf("\n    Serie de Fibonacci()   ");
    printf("\n --------------------------");
    printf("\n Ingrese numeros f(n): ");
    scanf("%d",&Num);
    // Impresi�n de los primeros dos n�meros
    printf("\n f(0) = 0");
    printf("\n f(1) = 1");
    if (Num > 2)
        fibonacci(Num);
    printf("\n\n");
    system("pause");
}
