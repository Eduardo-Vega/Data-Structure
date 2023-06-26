/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo 10.2
   Descripción: Búsqueda Lineal
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


void BuscaLineal(int vector[], int N, int Num)
{
    int Band = 0;
    for (i=0;i<=N-1;i+=1) {
        if (vector[i] == Num){
            printf("\n --------------------------------------");
            printf("\n  El numero %d esta en la posicion: %d",Num,i);
            Band = 1;
        }
    }
    if (!Band)
        printf("\n Elemento no encontrado!");
}


void main(void)
{

    int Arreglo[10] = {5,16,7,9,2,8,4,1,12,3};
    int Num;
    printf("\n  Busqueda Lineal de elemento");
    printf("\n --------------------------------------");
    printf("\n  Arreglo Original:");
    imprime(Arreglo,10);
    printf("\n --------------------------------------");
    printf("\n  Elemento a buscar: ");
    scanf("%d", &Num);
    BuscaLineal(Arreglo, 10, Num);
    printf("\n\n");
    system("pause");
}
