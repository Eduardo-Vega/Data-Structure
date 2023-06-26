/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo S14.2
   Descripción: Factorial Recursivo
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n)
{
    int i, resultado = 1;
    if (n==0 || n==1) {
        // Caso Base -> Si n=0 o n=1, resultado es 1
            printf("\n   %d! = %d",n,resultado);
    }
    else if(n>1) {
        // Si n es mayor a 1, ejecuta recursion
            resultado = n * factorial(n-1);
            printf("\n   %d! = %d",n,resultado);

    }
    else {
        resultado = 0;
        printf("\n\n El Numero no es positivo!!! \n\n");
    }
    return resultado;
}

void main()
{

    int num;
    do
    {
        system("cls");
        printf("\n\n  Calculo de Factorial de un numero  ");
        printf("\n --------------------------------------");
        printf("\n\n Ingrese un numero positivo (Salir=0): ");
        scanf("%d",&num);
        printf("\n\n El Factorial de [%d] es: %d",num,factorial(num));
        printf("\n\n");
        system("pause");
    }
    while(num);
}






