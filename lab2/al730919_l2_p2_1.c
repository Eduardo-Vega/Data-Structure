#include <stdio.h>

/******************************************************************
 Description:
    Se calcula la suma total y el promedio de un arreglo bidimensional
    de celdas y valores ingresados.
********************************************************************/

void main(){
    int i, j, n=0, m=0;
    int arr[n][m];
    float avr, sum=0;
    printf("\nIngrese las dimensones del arreglo de tipo N x M");
    printf("\n Ingrese el valor de N: ");
    scanf("%d", &n);
    printf("\n Ingrese el valor de M: ");
    scanf("%d", &m);

    for(i=0; i<n; i++){

        for(j=0; j<m; j++){
            printf("\nIngrese el valor para la celda [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
            sum = sum + arr[i][j];
        }
    }

    avr = sum / (n*m);

    printf("\nLa suma total del arrego es: %.2f", sum);
    printf("\nEL promedio del arrego es: %.2f", avr);
    

}
