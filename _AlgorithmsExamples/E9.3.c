/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo 9.3
   Descripción: Método de Inserción
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


void insercion(int vector[], int N)
{
    int aux, indice, acum = 1;
    for (j=0;j<=N-1;j+=1) {
		/* Valor que se va a insertar */
		aux = vector[j];
		k = j-1;
		/* Se recorren los elementos ordenados  */
		while (k>=0 && vector[k]>aux) {
			vector[k+1] = vector[k];
			k = k-1;
		}
		/* Se inserta el elemento */
		vector[k+1] = aux;

		printf(" \n");
		printf(" \n Arreglo despues del paso: %i\n",acum++);
		imprime(vector,N);
	}
}


void main(void)
{
    int Arreglo[8] = {5,3,7,9,2,8,4,1};
    printf("\n  Ordenamiento por Metodo de Insercion ");
    printf("\n --------------------------------------");
    printf("\n  Arreglo Original:");
    imprime(Arreglo,8);
    printf("\n --------------------------------------");
    insercion(Arreglo,8);
    printf("\n\n");
    system("pause");
}
