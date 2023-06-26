#include <stdio.h>
#include<stdlib.h>

void main()
{
    int estacionamiento[5][8] = {0};
    int i, j, band;
    
    do
    {
        printf("\n------- CAJONES DISPONIBLES -------\n\n");
        printf("\t 1 \t 2 \t 3 \t 4 \t 5 \t 6 \t 7 \t 8\n");
        for ( i = 0; i < 5; i++)
        {
            printf("Fila %d" , i + 1);
            for ( j = 0; j < 8; j++)
            {
                printf("\t|%d|", estacionamiento[i][j]);
            }
            printf("\n"); 
        }

        printf("\n1. MARCAR UN CAJON\n2. DESMARCAR UN CAJON\n3. Salir");
        printf("\nIngrese la opcion que desee: ");
        scanf("%d", &band);
        switch (band)
        {
        case 1:
            printf("\nINGRESE LA FILA Y COLUMNA DEL CAJON A OCUPAR");
            printf("\nIngrese la fila: ");
            scanf("%d", &i); ;
            printf("\nIngrese la columna: ");
            scanf("%d", &j); ;
            estacionamiento[i-1][j-1] = 1;
            break;
        case 2:
            printf("\n INGRESE LA FILA Y COLUMNA DEL CAJON A VACIAR ");
            printf("\nIngrese la fila: ");
            scanf("%d", &i); ;
            printf("\nIngrese la columna: ");
            scanf("%d", &j); ;
            estacionamiento[i-1][j-1] = 0;
            break;
        case 3:
            system("PAUSE");
            break;

            default:
            break;
        }
        
    } while (band != 3);
    
}
