/********************
Description:
    
********************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Arreglo de estructura para las boletas.
struct Boleta{
    int id;
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int n6;
}boleta[5];

//Capturacion de datos de boleta.
void capturaBoleta(struct Boleta b[], int n, int cont){
    for(int i=0; i<n; i++){
        cont++;
        printf("\n         Comenzando con la capturacion de numeros de la boleta:\t%d", cont);
        printf("\n           Porfavor ingrese el ID de la boleta:\t");
        scanf("%d", &b[i].id);
        printf("\nIngrese el primer numero deseado del 1 al 56 \n ");
        scanf("%d",&b[i].n1);
        printf("\nIngrese el segundo numero deseado del 1 al 56 \n ");
        scanf("%d",&b[i].n2);
        printf("\nIngrese el tercer numero deseado del 1 al 56 \n ");
        scanf("%d",&b[i].n3);
        printf("\nIngrese el cuarto numero deseado del 1 al 56 \n ");
        scanf("%d",&b[i].n4);
        printf("\nIngrese el quinto numero deseado del 1 al 56 \n ");
        scanf("%d",&b[i].n5);
        printf("\nIngrese el sexto numero deseado del 1 al 56 \n ");
        scanf("%d",&b[i].n6);
    }
    system("pause");
}


//Ejecucion de sorteo Melate, Revancha y Revanchita
void ejecucionSorteo(){

}

//Muestra todas las boletas
void reporteBoletasCapturadas(struct Boleta b[], int n, int cont){
    for(int i=0; i<n; i++){
        printf("\nBoleta ID: %d  Numeros seleccionados: %d, %d, %d, %d, %d, %d",b[i].id,b[i].n1,b[i].n2,b[i].n3,b[i].n4,b[i].n5,b[i].n6);
    }
}

//Muestra las boletas ganadoras
void reporteBoletasGanadores(){

}

void reinicioApp(){
    printf("\n      Hola mundo.");
}

void main(){
    int op, n=0, cont;
    do{

        printf("\n\n     Proyecto 2do Parcial-Equipo 5");
        printf("\n--------------------------------------------------");
        printf("\n Eliqe una de las siguientes opciones.");
        printf("\n    [1] CAPTURA DE BOLETA.");
        printf("\n    [2] EJECUCION DE SORTEO.");
        printf("\n    [3] REPORTE DE BOLETAS CAPTURADAS.");
        printf("\n    [4] REPORTE DE BOLETAS GANADORES.");
        printf("\n    [5] REINICIO DE APLICACIONES.");
        printf("\n    [6] SALIR.");
        printf("\n    Ingrese el numero de la accion que desea realizar:\t");
        scanf("%d", &op);
        switch(op){
        case 1:
            printf("\n      Cuantas boletas registrara?\t");
            scanf("%d", &n);
            n+=n;
            capturaBoleta(boleta, n, cont);
            break;
        case 2:
            ejecucionSorteo();
            break;
        case 3:
            reporteBoletasCapturadas(boleta, n, cont);
            break;
        case 4:
            reporteBoletasGanadores();
            break;
        case 5:
            reinicioApp();
            break;
        case 6:
            printf("\n       El programa finalizara.\n\n\t");
            system("pause");
            break;
        }
    }while(op != 6);
}
