#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/******************************************************************
 Descripción:
        Create an 3x4 array with integer numbers between 20 n 50
        to calc rows n columns totals.
********************************************************************/

void main()
{
    int array[3][4] = {0}; 
    int sumf[4] = {0};
    int sumc[4] = {0};
    int i, j;
    srand(time(NULL));

    for ( i = 0; i < 3; i++)
    {

        for ( j = 0; j < 4; j++)
        {
            array[i][j] = rand() % 31 + 20; //ENTRE 20 Y 50 = (N menor, M mayor -> %( M-N-1 ) + N )
            sumf[i] = sumf[i] + array[i][j];
            sumc[j] = sumc[j] + array[i][j];
        }
        
    }
    printf("\n---RANDOM ARRAY GENERATED BETWEEN 20 N 50---\n");
    printf("\n\t ---------------------------    Total=\n");
    for ( i = 0; i < 3; i++)
    {
        printf("\t ");
        for ( j = 0; j < 4; j++)
        {
            printf("| %d | ", array[i][j]);
        }
        printf("    %d", sumf[i]);
        printf("\n\t ---------------------------");
        printf("\n");
    }
    printf("\n");
    printf("Total=     ");
    for (i = 0; i < 4; i++)
    {
        printf("%d    ", sumc[i]);
    }
    printf("\n");
    getchar();
}
