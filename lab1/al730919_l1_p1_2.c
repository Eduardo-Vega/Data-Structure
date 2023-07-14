#include <stdio.h>

/******************************************************************
 Description:
        Conteo de la cantidad de positivos, negativos y nulos en el arreglo
        ingresado.
********************************************************************/

void main(){
    int i, n=0, pos=0, neg=0, nul=0;
    int arr[n];
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Ingrese el valor %d \n", i+1);
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
        if (arr[i] > 0){
            pos ++;
        }
        else if(arr[i]<0){
            neg++;
        }
        else{
            nul++;
        }
    }

    printf("Se encontraron: \n %d numero(s) positivo(s). \n %d numero(s) negativo(s).\n %d numero(s) nulo(s).", pos, neg, nul);
}