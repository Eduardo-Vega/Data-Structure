/****************************************
   Description: Cuenta Caracteres
****************************************/
#include <stdio.h>

//Prototipo de la funci�n Cuenta()
int Cuenta(char *, char);

void main(void)
{
    // Declaraci�n de variables
    char Chr, Cadena[50];
    int Resultado;
    printf("\n -------------------------------------------");
    printf("\n            Conteo de Caracteres            ");
    printf("\n -------------------------------------------");

    // Lectura de valores
    printf("\n   Ingrese la Cadena: ");
    fflush(stdin);
    gets(Cadena);
    printf(" Ingrese el Caracter: ");
    Chr = getchar();
    // Invoca la funci�n que cuenta los carcateres
    Resultado = Cuenta(Cadena, Chr);
    printf("\n\n - %c se encuentra %d veces en la Cadena: %s ", Chr, Resultado, Cadena);
    printf("\n\n");
    system("pause");

}

// Funci�n para contar caracteres en una cadena
int Cuenta(char *Cadena, char Chr)
{

    int i = 0, r = 0;
    // El ciclo se repite hasta encontrar el caracter nulo
    while (Cadena[i] != '\0')
    {
        if (Cadena[i] == Chr)
            r++; // Contador de apariciones
        i++;     //Iterador del Ciclo
    }
    return (r);
}
