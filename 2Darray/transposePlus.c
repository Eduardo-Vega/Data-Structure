#include <stdio.h>
#include <stdlib.h>
/******************************************************************
 Description:
        Plus A array and fliped B array
********************************************************************/
#define N 3
#define M 2
//print any 2D array function
void printArr(int *arr,int n, int m) {
    //go to through array
    for (int i = 0; i < n*m; i++) {
        printf("%2d\t", arr[i]);
        //line jump
        if ((i+1) % m == 0) { printf("\n"); }
    }
}
//flip MxN array to NxM function
void transposeArr(int arr[][N], int flipArr[][M]){
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            flipArr[j][i] = arr[i][j];
        }
    }
}
//plus function
void transposePlus(int A[][M], int B[][N], int C[][M]) {
    //get B array transpose
    transposeArr(B, C);
    //print result
    printf("  Result\n");
    //point to first elem to go through arrays
    int *Ap = &A[0][0]; int *Cp = &C[0][0];
    //plus result calc n print it
    for (int i = 0; i < N*M; i++) {
        printf("%2d\t", Ap[i] + Cp[i]);
        //line jump
        if ((i+1) % M == 0){ printf("\n"); }
    }
    printf("\n  A array\n");                    //print A[N}[M] array
    printArr(&A[0][0], N, M);

    printf("\n  B array\n");                    //print B[M][N] array
    printArr(&B[0][0], M, N);

    printf("\nB transpose\n");                  //print B transpose
    printArr(&C[0][0], N, M);
}

void main()
{
    //initialize arrays
    int A[N][M] = {
        1, 2, 
        3, 4, 
        5, 6
    };
    int B[M][N] = {
         7, 8, 9,
        10,11,12
    };
    int C[N][M] = {0};
    //plus A array + B array transpose function call
    transposePlus(A, B, C);
    getchar();
}
