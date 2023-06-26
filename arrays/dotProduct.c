#include <stdio.h>
#include <stdlib.h>
/******************************************************************
 Description:
        Multiplying two arrays.
        Input: n(size), arr1, arr2
        Output: arr3 (product result)
********************************************************************/

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++){ 
        printf("%d ", arr[i]); 
    }printf("\n");
}

//dot product function
void dotProduct(int n, int arr1[], int arr2[], int arr3[]){
    for (int i = 0; i < n; i++) { 
        arr3[i] = arr1[i] * arr2[i]; 
    }
}
//difference between dot product arr
void diffBetweenElements(int diffArr[], int arr3[], int n){
    int j = 0;
    for (int i = 0; i < n ; i++){
        if (i%2 == 0){
           diffArr[j] = arr3[i+1] - arr3[i];
           j++; 
        }
    }
}

void main()
{
    //initializing test arrays of same len
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int	arr2[] = {10, 11, 12, 13, 14, 15, 16, 17, 18};
    int arr3[9] = {0}, diffArr[4] = {0};
    dotProduct(9, arr1, arr2, arr3);
    //printing result
    printf("\nResults: \n");
    printf("Array1: "); printArr(arr1, 9);
    printf("\nArray2: "); printArr(arr2, 9);
    printf("\nResultant array is: "); printArr(arr3, 9);
    diffBetweenElements(diffArr, arr3, 9);
    printf("\nThe different between resultant elements: "); printArr(diffArr, 4);
    getchar();
}