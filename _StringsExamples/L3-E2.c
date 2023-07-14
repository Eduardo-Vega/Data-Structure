/****************************************
Description: 
Invierte Orden de Cadenas
****************************************/

#include <stdio.h>
#include <string.h>

//Prototipo de la funci�n Cambia()
void Cambia(char Cadena[][50], int);


void main(void)
{
    // Declaraci�n de variables
    int i, n;
    // Declaraci�n de arreglo
    char Cadena[20][50];
    printf("\n -------------------------------------------");
    printf("\n   Invertir Orden de Cadenas de Caracter    ");
    printf("\n -------------------------------------------");

    // Lee la cantidad de cadenas a almacenar
    printf("\n  Numero de cadenas a ingresar: ");
    scanf("%d", &n);

    // Llenado de arreglo
    printf("\n   captura de Cadenas                         ");
    printf("\n -------------------------------------------\n");
    for (i=0; i<n; i++)
    {
        printf(" Cadena [%d] : ", i+1);
        fflush(stdin);
        gets(Cadena[i]);
    }

    printf("\n\n");
    //Invoca la funci�n que intercambia las cadenas
    Cambia(Cadena, n);

    // Impresion de Arreglo
    printf("\n   Impresion de Arreglo Resultante         ");
    printf("\n -------------------------------------------\n");
    for (i=0; i<n; i++)
    {
        printf(" Cadena [%d] : ", i+1);
        puts(Cadena[i]);
    }
    printf("\n\n");
    system("pause");
}

// Funci�n para intercambiar cadenas
void Cambia(char Cadena[][50], int n)
{
    //Declaraci�n de variables
    int i, j;
    //Ultima posici�n
    j = n - 1;
    char Temp[50];
    // Ciclo para intercambiar valores
    for (i=0; i < (n/2); i++)
    {
        strcpy(Temp, Cadena[i]);       // Copia cadena actual a temp
        strcpy(Cadena[i], Cadena[j]);  // Copia �ltima cadena a actual
        strcpy(Cadena[j], Temp);       // Copia temp a �ltima cadena
        j--;
    }
}
