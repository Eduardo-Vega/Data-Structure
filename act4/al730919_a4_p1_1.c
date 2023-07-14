/********************
   Description: 
        
********************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int clave;
    char nombre[31];
    char cat[22];
    int lab;
    int inv;
    float precio;
    struct{
        int dia;
        int mes;
        int anio;
    };
}Farmacia;

void CaptFar(Farmacia far[], int N, int cont){
    for(int i=cont; i<(N+cont); i++){
        fflush(stdin);
        printf("     Clave:\t");
        scanf("%d", &far[i].clave);
        fflush(stdin);
        printf("\n     Nombre:\t");
        gets(far[i].nombre);
        fflush(stdin);
        printf("\n     Categoria:\t");
        gets(far[i].cat);
        printf("\n     Laboratorio:\t");
        scanf("%d", &far[i].lab);
        printf("\n     Inventario:\t");
        scanf("%d", &far[i].inv);
        printf("\n     Precio:\t");
        scanf("%f", &far[i].precio);
        printf("\n     Ingrese la fechas de caducidad:");
        printf("\n     Dia:\t");
        scanf("%d", &far[i].dia);
        printf("\n     Mes:\t");
        scanf("%d", &far[i].mes);
        printf("\n     Anio:\t");
        scanf("%d", &far[i].anio);
        printf("\n--------------------------------------------------------------------------------\n");
    }
}

void ImpFar(Farmacia far[], int cont){
    for(int i=0; i<cont; i++){
        printf("\nClave: %d || Nombre: %s || Categoria: %s || Laboratorio: %d || Inventario: %d || Precio: %.2f || Caducidad: %d/%d/%d",
           far[i].clave, far[i].nombre, far[i].cat, far[i].lab, far[i].inv, far[i].precio, far[i].dia, far[i].mes, far[i].anio);
        printf("\n");
    }
}

void main(){
    int N, opc, cont = 0;
    Farmacia far[50];
    do{
    printf("\n\tFARMACIA EQUIPO 5");
    printf("\n--------------------------------------------------------------------------------\n");
    printf("\t1.   CAPTURAR MEDICINA");
    printf("\n\t2.   IMPRIMIR MEDICINA");
    printf("\n\t3.   SALIR");
    printf("\n--------------------------------------------------------------------------------");
    printf("\n\tIngrese el numero de la accion que desea realizar:\t");
    scanf("%d", &opc);
        switch(opc){
        case 1:
            printf("\t Cuantos medicamentos ingresara?:\t");
            scanf("%d", &N);
            CaptFar(far, N, cont);
            cont = cont + N;
            break;
        case 2:
            ImpFar(far, cont);
            break;
        case 3:
            printf("\tEl programa finalizara. Presione una tecla para conttinuar.\n");
            system("pause");
        }
    }while(opc != 3);
}
