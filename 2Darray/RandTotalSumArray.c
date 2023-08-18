#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/******************************************************************
 Descripción:
        Create an 3x4 array with integer numbers between 15 and 55
        to calc rows and columns totals.
********************************************************************/
#define N 12
#define M 13

//generating random number
int randNum(int min, int max){
    return min + rand() % (max - min + 1);
}
//init array with random nums
void randArrInit(int n, int m, int arr[n][m]){
    
    for (int i = 0; i < n*m; i++) {
        arr[i / m][i % m] = randNum(15, 50);
    }
}
//get rows array total sum 
void TotalSumArray(int n, int m, int arr[n][m]){
    int total = 0;
    printf("%*s   Total\n", m*4, "");

    //go to through 2D array
    for (int i = 0; i < n*m; i++) {

        total += arr[i / m][i % m];
        printf("%4d", arr[i / m][i % m]);
        
        //line jump + sum result
        if ((i+1) % m == 0) { 
            printf(" |%6d\n", total);
            total = 0; 
        }

    }
}


void main()
{
    //initializing arrays
    int array[N][M] = {0}; 
    int sumf[M] = {0};
    int sumc[M] = {0};
    char reset;

    //generatng truly rand numbers
    srand(time(NULL));

    do
    {
        
        printf("\n---RANDOM ARRAY GENERATED BETWEEN 15 AND 50---\n");
        //init rand array
        randArrInit(N, M, array);
        //calc total sum
        TotalSumArray(N, M, array);

        printf("Reset? [y]/[n]: ");
        scanf(" %c", &reset);
        system("CLS");

    } while (reset == 'y');

}
