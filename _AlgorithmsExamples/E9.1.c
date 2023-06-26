/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo 9.1
   Descripción: Método de la Burbuja
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


void burbuja(int vector[], int N)
{
    int aux, acum = 1;
    for (j=0;j<=N;j+=1) {
        for (k=0;k<=(N-1-j);k+=1) {
            if (N-1>=(k+1)) {
                if (vector[k]>vector[k+1]) {
                    aux = vector[k];
					vector[k] = vector[k+1];
					vector[k+1] = aux;
				}
			}
		}
		printf(" \n");
		printf(" \n Arreglo despues del paso: %i\n",acum++);
		imprime(vector,N);
	}
}


void main(void)
{
    int Arreglo[8] = {5,3,7,9,2,8,4,1};
    printf("\n   Ordenamiento por Metodo de Burbuja  ");
    printf("\n --------------------------------------");
    printf("\n  Arreglo Original:");
    imprime(Arreglo,8);
    printf("\n --------------------------------------");
    burbuja(Arreglo,8);
    printf("\n\n");
    system("pause");
}
