/********************
   Description:
        
********************/
#include<stdio.h>
#include<stdlib.h>

int i, j, k;

void impA(int vec[], int N){
    printf("\n");
    printf("     Arreglo: ");
    for(i=0; i<N; i++){
        printf(" %d ", vec[i]);
    }
}

void ordenShell(int vec[], int N){
    int skip, aux, end, acum =1;
    skip = N;
    while(skip>0){
        skip = skip/2;
        do{
            end = 1;
            k = N-skip;
            for(i=0; i<k; i++){
                j = i+skip;
                if(vec[i] < vec[j]){
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                    end = 0;
                }
            }
        }while(!end);
    }

    impA(vec, N);
}

void busBin(int vec[], int N, int num){
    int s, f, ind, band, mid;
    s = 0;
    f = N-1;
    ind = 0;
    band = 0;
    while(band==0 && ind<=f){
        mid = (ind+f)/2;
        if(num == vec[mid]){
            band=1;
        }
        else{
            if(num>vec[mid]){
                f = mid-1;
            }
            else{
                ind = mid+1;
            }   
        }
    }

    if(band){
        printf("\n El elemento %d esta en la aposicion [%d]: ", num, mid+1);
    }else{
        printf("\n El elemento %d no fue encontrado.", num);
    }
}

void main(){
    int ARRE[10]={8, 43, 17, 6, 40, 16, 18, 97, 11, 7};
    int num;
    printf("\n     Actividad 5 || Equipo 5");
    printf("\n     Problema 5.1 || Ordenamiento SHELL");
    printf("\n--------------------------------------------------");
    printf("\n Arreglo Original: ");
    impA(ARRE, 10);
    printf("\n--------------------------------------------------");
    printf("\n\n Arreglo ordenado: ");
    ordenShell(ARRE, 10);
    printf("\n--------------------------------------------------");
    printf("\n Elemento a buscar: ");
    scanf("%d", &num);
    printf("\n--------------------------------------------------");
    busBin(ARRE,10,num);
    printf("\n\n");
    system("pause");
}
