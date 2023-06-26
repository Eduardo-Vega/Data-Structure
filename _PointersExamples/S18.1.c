/****************************************
       Materia: Estructura de Datos
     #Programa: Ejemplo S18.1
   Descripción: Punteros
****************************************/
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *P, D = 123;
    P = &D;
    printf ("..............................\n");
    printf (" Direccion de Memoria D: %p   \n",&D);
    printf ("             Valor en D: %d   \n",D);
    printf ("..............................\n");
    printf ("             Valor en P: %d   \n",P);
    printf (" Direccion de Memoria P: %p   \n",&P);
    printf ("    Valor en puntero *P: %d \n\n",*P);
    system("Pause");
}

