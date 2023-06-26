/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo 9.2
   Descripción: Método de Selección
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


void seleccion(int vector[], int N)
{
    int aux, indice, acum = 1;
	for (j=0;j<=N-1;j+=1) {
		/* Lectura de indice de la posición  */
		indice = j;
		/* Seleccionar el menor valor */
		for (k=(j+1);k<=N-1;k+=1) {
			if (vector[k]<vector[indice]) {
				indice = k;
			}
		}
		/* Intercambiar valores */
		aux = vector[j];
		vector[j] = vector[indice];
		vector[indice] = aux;

		printf(" \n");
		printf(" \n Arreglo despues del paso: %i\n",acum++);
		imprime(vector,N);
	}
}


void main(void)
{
    int Arreglo[8] = {5,3,7,9,2,8,4,1};
    printf("\n  Ordenamiento por Metodo de Seleccion ");
    printf("\n --------------------------------------");
    printf("\n  Arreglo Original:");
    imprime(Arreglo,8);
    printf("\n --------------------------------------");
    seleccion(Arreglo,8);
    printf("\n\n");
    system("pause");
}
