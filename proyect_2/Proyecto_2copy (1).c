/********************
    Materia: Estructura de Datos
    autores: Ricardo Guzm�n - 737080
            Ivan Rangel - 737680
            Ruben Vega - 730919
            Rodrigo Bohorquez - 733014
********************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>

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


//Muestra todas las boletas
void reporteBoletasCapturadas(struct Boleta b[], int n, int cont){
    for(int i=0; i<n; i++){
        printf("\nBoleta ID: %d  Numeros seleccionados: %d, %d, %d, %d, %d, %d",b[i].id,b[i].n1,b[i].n2,b[i].n3,b[i].n4,b[i].n5,b[i].n6);
    }
    Sleep(10);
}

//Muestra las boletas ganadoras
void reporteBoletasGanadores(int *melate,int *revancha,int *revanchita,struct Boleta b[]){
    int i,j,k;
    do{
    printf("1. melate");
    printf("2. revancha");
    printf("3. revanchita");
    printf("0. Salir");
    printf("Ingrese el numero del sorteo que quiere verificar");
    scanf("%d",&k);
    switch(k){
    case 1:
        for(i=0;i<6;i++){
            if(b[i].n1==melate[0] && b[i].n2==melate[1] && b[i].n3==melate[2] && b[i].n4==melate[3] && b[i].n5==melate[4] && b[i].n6==melate[5]){
            printf("\nBoleta Ganadora Melate ID: %d  Numeros seleccionados: %d, %d, %d, %d, %d, %d",b[i].id,b[i].n1,b[i].n2,b[i].n3,b[i].n4,b[i].n5,b[i].n6);}
        }
        break;
    case 2:
        for(i=0;i<6;i++){
            if(b[i].n1==revancha[0] && b[i].n2==revancha[1] && b[i].n3==revancha[2] && b[i].n4==revancha[3] && b[i].n5==revancha[4] && b[i].n6==revancha[5]){
            printf("\nBoleta Ganadora Melate ID: %d  Numeros seleccionados: %d, %d, %d, %d, %d, %d",b[i].id,b[i].n1,b[i].n2,b[i].n3,b[i].n4,b[i].n5,b[i].n6);}
        }
        break;
    case 3:
        for(i=0;i<6;i++){
            if(b[i].n1==revanchita[0] && b[i].n2==revanchita[1] && b[i].n3==revanchita[2] && b[i].n4==revanchita[3] && b[i].n5==revanchita[4] && b[i].n6==revanchita[5]){
            printf("\nBoleta Ganadora Melate ID: %d  Numeros seleccionados: %d, %d, %d, %d, %d, %d",b[i].id,b[i].n1,b[i].n2,b[i].n3,b[i].n4,b[i].n5,b[i].n6);}
        }
        break;
    }
    }while(k!=0);
}

void reinicioApp(){
    printf("\n      Hola mundo.");
}

void selectionSort(int *sort){
    int ind, aux, j, k;
    for (j = 0; j < 6; j++)
    {
        ind = j;
        for ( k = (j+1); k < 6 ; k++)
        {
            if (sort[k] < sort[ind])
            {
                ind = k;
            }

        }
        aux = sort[j];
        sort[j] = sort[ind];
        sort[ind] = aux;
    }

    for (j = 0; j < 6; j++)
        {
            Sleep(1000);
            printf("%d ", sort[j]);
        }

}

void ejecucionSorteo(int *sorteo){
    int i, j, rep=0;
    char *sort[] = {"Primero", "Segundo", "Tercero", "Cuarto", "Quinto", "Sexto"};
    srand(time(NULL));
    for (i = 0; i < 6; i++)
    {
        Sleep(1000);
        printf("\n%s numero:    ", sort[i]);
        *(sorteo+i) =  rand() % 54 + 1; //ENTRE 1 Y 56 = (N menor, M mayor -> %( M-N-1 ) + N )
        printf("%d", *(sorteo+i));
        if (i>0)
        {
            do
            {
                for (j = 0; j<i ; j++)
                {
                    rep = 0;
                    if (*(sorteo+i) == *(sorteo+j))
                    {
                        printf("\n\nNumero repetido, va de nuez...\n");
                        rep = 1;
                        Sleep(1000);
                        printf("\n%s numero:    ", sort[i]);
                        *(sorteo+i) =  rand() % 54 + 1; //ENTRE 1 Y 56 = (N menor, M mayor -> %( M-N-1 ) + N )
                        printf("%d", *(sorteo+i));
                    }
                }
            } while (rep==1);
            rep = 0;
        }
    }

}



void main(){
    int op, n, cont, melate[7], revancha[6], revanchita[6];

    srand(time(NULL));
    do{
        system("CLS");
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
            capturaBoleta(boleta, n, cont);
            break;
        case 2:
            printf("Sorteo Melate");
            ejecucionSorteo(melate);
            printf("\nNUMERO ADICIONAL: ");
            melate[6] = rand()%54 + 1;
            Sleep(1000);
            printf("%d", melate[6]);
            Sleep(1000);
            printf("\n\nNUMEROS GANADORES\n");
            printf("Ordenados: ");
            selectionSort(&melate[0]);

            printf("\nSorteo revancha");
            ejecucionSorteo(revancha);
            Sleep(1000);
            printf("\n\nNUMEROS GANADORES\n");
            printf("Ordenados: ");
            selectionSort(&revancha[0]);

            printf("\nSorteo revanchita");
            ejecucionSorteo(revanchita);
            Sleep(1000);
            printf("\n\nNUMEROS GANADORES\n");
            printf("Ordenados: ");
            selectionSort(&revanchita[0]);
            printf("\n");
            system("PAUSE");
            break;
        case 3:
            reporteBoletasCapturadas(boleta, n, cont);
            break;
        case 4:
            reporteBoletasGanadores(melate,revancha,revanchita,boleta);
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
