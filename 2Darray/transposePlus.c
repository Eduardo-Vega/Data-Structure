#include <stdio.h>
#include <stdlib.h>
/******************************************************************
 Description:
        Plus A array and fliped B array
********************************************************************/


//print 2D array function
void printArr(int n, int m, int arr[n][m]) {
    //go to through array
    for (int i = 0; i < n*m; i++) {

        printf("%2d\t", arr[i / m][i % m]);
        //line jump
        if ((i+1) % m == 0) { printf("\n"); }
    }
}
//flip MxN array to NxM function
void transposeArr(int arr[][2], int flipArr[][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            flipArr[j][i] = arr[i][j];
        }
    }
}
//plus function
void transposePlus(int A[][3], int B[][2], int C[][3]) {
    //getting B array transpose
    transposeArr(B, C);
    //print result
    printf("  Result\n");
    //point to first elem to go through arrays
    int *Ap = &A[0][0]; int *Cp = &C[0][0];
    //plus result calc and print
    for (int i = 0; i < 2*3; i++) {
        printf("%2d\t", Ap[i] + Cp[i]);
        //line jump
        if ((i+1) % 2 == 0){ printf("\n"); }
    }
    printf("\n  A array\n");                    //print A[N}[M] array
    printArr(3, 2, A);

    printf("\n  B array\n");                    //print B[M][N] array
    printArr(2, 3, B);

    printf("\nB transpose\n");                  //print B transpose
    printArr(3, 2, C);
}

void main()
{
    //initializing arrays
    int A[2][3] = {
        1, 2, 
        3, 4, 
        5, 6
    };
    int B[3][2] = {
         7, 8, 9,
        10,11,12
    };
    int C[2][3] = {0};
    //plus A array + B array transpose function call
    transposePlus(A, B, C);
    getchar();
}
