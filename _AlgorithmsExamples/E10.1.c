/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo 10.1
   Descripción: Método de Shell
****************************************/
#include <stdio.h>
#include <stdlib.h>

int i,j,k;

void imprime(int Arr[], int N)
{
    printf("\n");
    printf("  Arreglo: ");
    for (i=0; i<N; i++)
         printf(" %d ",Arr[i]);
}


void ordenaShell(int vector[], int N)
{
    int salto, aux, fin, acum = 1;
    salto = N ;
    while (salto>0)
    {
        salto = salto/2;
        do {
            fin = 1;
            k = N-salto ;
            for (i=0 ; i<k ; i++)
            {
                j = i+salto;
                if (vector[i] > vector[j])
                {
                    aux = vector[i];
                    vector[i] = vector[j];
                    vector[j] = aux;
                    fin = 0;

                    printf(" \n");
                    printf(" \n Arreglo despues del paso: %i\n",acum++);
                    imprime(vector,N);
                }
            }
        } while (!fin);
    }
}


void main(void)
{
    int Arreglo[10] = {5,16,7,9,2,8,4,1,12,3};
    //int Arreglo[11] = {16,15,14,13,12,11,10,9,8,7,6};
    printf("\n  Ordenamiento por Metodo de Shell ");
    printf("\n --------------------------------------");
    printf("\n  Arreglo Original:");
    imprime(Arreglo,10);
    printf("\n --------------------------------------");
    ordenaShell(Arreglo,10);
    printf("\n\n");
    system("pause");
}
