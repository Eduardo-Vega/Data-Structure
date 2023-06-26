#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i;

void Llenar(float arreglo[], int n){
    srand((unsigned)time(NULL));

    for ( i = 0; i < n; i++)
    {
        arreglo[i] = (rand()%41 + 10) / 3;
    }

}  

void Imprimir(float arreglo[], int n){
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%.5f \t", arreglo[i]);
    }
}

void Cambiar(float arreglo[], int n){
    for ( i = 0; i < n; i++)
    {
        arreglo[i] = (rand()%41 + 10) / 3;
    }
}
void main()
{
    
    // int *p, d=123, *x; PUNTEROS EN C
    // p=&d;
    // printf("Direccion de la variable d: %p , %d\n", &d, &d);
    // printf("Valor de la variable d: %d\n", d);
    // printf("Direccion de la variable p: %p , %d\n", &p, &p);
    // printf("Valor de la variable p: %p , %d\n", p, p);
    // printf("Valor al que apunta la variable p:  %d\n", *p);

    int n;
    printf("--------ARREGLO DE NUMEROS ALEATOREOS-------\n");
    printf("Ingrese la cantidad de elementos en el arreglo: ");
    scanf("%d", &n);
    float arr[n];
    
    Llenar(arr, n);
    Imprimir(arr, n);
    printf("\n");

    system("PAUSE");
}

