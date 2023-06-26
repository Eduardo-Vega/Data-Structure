/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo 10.4
   Descripción: Búsqueda Binaria
****************************************/
#include <stdio.h>
#include <stdlib.h>

int i,j,k;

void imprime(int vector[], int N)
{
    printf("\n");
    printf("  Arreglo: ");
    for (i=0; i<N; i++)
         printf(" %d ",vector[i]);
}


void ordenaShell(int vector[], int N)
{
    int salto, aux, fin, acum = 1;
    salto = N;
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
                }
            }
        } while (!fin);
    }
    imprime(vector,N);
}


void binaria(int vector[], int N, int Num)
{
    int Inicio, Fin, Indice, Band, Mitad;
    Inicio = 0;
    Fin = N-1;
    Indice = 0;
    Band = 0;
    while(Band==0 && Indice<=Fin) {
        Mitad = (Indice+Fin)/2; // Calcula Mitad
        if (Num == vector[Mitad])
            Band = 1;             // Fin de Busqueda
        else
            if (Num<vector[Mitad])
                Fin = Mitad-1;    // Toma 1era parte
            else
                Indice = Mitad+1; // Toma 2da parte

    }

    if (Band)
        printf("\n  El elemento %d esta ubicando en la posicion [%d]: ",Num ,Mitad+1);
    else
        printf("\n  El elemento %d no fue ubicando!", Num);
}


void main(void)
{
    int Arreglo[10] = {5,16,7,9,2,8,4,1,12,3};
    int Num;
    //int Arreglo[11] = {16,15,14,13,12,11,10,9,8,7,6};
    printf("\n  Busqueda Binaria de Elemento ");
    printf("\n --------------------------------------");
    printf("\n  Arreglo Original:");
    imprime(Arreglo,10);
    printf("\n --------------------------------------");
    printf("\n  Arreglo Ordenado:");
    ordenaShell(Arreglo,10);
    printf("\n --------------------------------------");
    printf("\n  Elemento a buscar: ");
    scanf("%d",&Num);
    printf("\n --------------------------------------");
    binaria(Arreglo,10,Num);
    printf("\n\n");
    system("pause");
}
