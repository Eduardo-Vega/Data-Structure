#include<stdio.h>
#include<stdlib.h>
/******************************************************************
 Description:
            Draw the number 1 in principal diagonal of Array[NxN]
********************************************************************/
#define N 20

//diafonal function
void drawDiagonal(int arr[][N]){
    //set "1" diagonal looking for i =+ j
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) { arr[i][j] = 1; }
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    //initialize 2D array
    int arr[N][N] = {0}; 

    drawDiagonal(arr);
    getchar(); 
}