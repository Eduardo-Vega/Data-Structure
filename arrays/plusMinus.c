#include <stdio.h>
#include <stdlib.h>
/******************************************************************
 Descripción:
    Calculate the ratios of elements that are +, - and  0
    in an array.
********************************************************************/

void plusMinus(int arr[], int n){
    int pos=0, neg=0, nul=0;
    float ratPos=0, ratNeg=0, ratNul=0;

    //loop over arr looking for +, - and 0
    for(int i = 0; i < n; i++){
        if (arr[i] > 0){ pos ++;}
        else if( arr[i] < 0){ neg++;}
        else{ nul++; }
    }
    // Ratio calc
    ratPos = (float)pos/n;
    ratNeg = (float)neg/n;
    ratNul = (float)nul/n;
    //printing result
    printf("Were found: \n%d positive(s).   Ratio %.5f", pos, ratPos); 
    printf("\n%d negative(s).   Ratio %.5f", neg, ratNeg);
    printf("\n%d null(s).       Ratio %.5f\n", nul, ratNul);

}

void main(){
    int n=9, pos=0, neg=0, nul=0;
    int arr[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4};

    plusMinus(arr, n);
    getchar();
}