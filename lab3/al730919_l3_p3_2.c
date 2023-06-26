#include <stdio.h>
#include <string.h>
/******************************************************************
 Nombre: Ruben Eduardo Vega Mayorga
 Matricula: 730919
 Fecha: 1 de octubre del 2022
 Problema 3.2 Laboratorio 3
 Descripcion:
    Se ingresan una n cantidad de cadenas de caracteres, y se realiza un intercambio
    con las cadena singresadas de forma que la primera sea la ultima, la segunda la
    penultima y así sucesivamente, se imprimen las cadenas originales y las resultantes.
********************************************************************/
void intercambio(char strng[][51], int n){
    int i, j;
    char copy[51];
    j = n - 1;
    for(i=0 ; i < n/2; i++){
        strcpy(copy, strng[i]);
        strcpy(strng[i], strng[j]);
        strcpy(strng[j], copy);
        j--;
    }
}

void main(){
    int n, i;
    char strng[20][51], copy[20][51];
    printf("\nCantidad de cadenas: ");
    scanf("%d", &n);
    for(i=0 ; i < n; i++){
        printf("\nIngrese la cadena %d: ", i+1);
        fflush(stdin);
        gets(strng[i]);
        strcpy(copy[i],strng[i]);
    }
    intercambio(strng, n);
    printf("\nCadenas Originales -> \n");
    for (i=0; i<n; i++)
    {
        printf("Cadena %d: ", i+1);
        puts(copy[i]);
    }
    printf("\n\nCadenas resultantes -> \n");
    for (i=0; i<n; i++)
    {
        printf(" Cadena %d: ", i+1);
        puts(strng[i]);
    }
}