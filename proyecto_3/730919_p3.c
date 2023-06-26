#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct viaje{
    char vuelo[6];
    char transporte[20];
    char equipamiento[8];
    char origen[5];
    char destino[5];
    char estado[12];
    struct viaje *sig;
} viaje;

typedef viaje *apuntador;

int tam = 0;

void agregarVuelo(apuntador *V, char vuelo[], char transporte[], char equipamiento[], char origen[], char destino[], char estado[]){
    apuntador nuevo = NULL;//, aux = NULL;
    //aux = *V;
    //while(aux->sig != NULL)
        //aux = aux->sig;
    nuevo = (viaje*)malloc(sizeof(viaje));
    strncpy(nuevo->vuelo, vuelo, 6);
    strncpy(nuevo->transporte, transporte, 20);
    strncpy(nuevo->equipamiento, equipamiento, 8);
    strncpy(nuevo->origen, origen, 5);
    strncpy(nuevo->destino, destino, 12);
    strncpy(nuevo->estado, estado, 12);
    nuevo->sig = *V;

    //aux->sig = nuevo;
    *V = nuevo;
    tam++;
}

void recorreFirst(apuntador V){
    if(V != NULL){
        printf("\n  - %s  %s", V->vuelo, V->origen);
        recorreFirst(V->sig);
    }
}

void consultar(apuntador V){
    if(V != NULL){
        printf("\n  VUELO %s || TRANSPORTE %s || EQUIPAMIENTO %s || ORIGEN %s || DESTINO %s || ESTADO %s ||", V->vuelo, V->transporte, V->equipamiento, V->origen, V->destino, V->estado);
        consultar(V->sig);
        
    }
}

void despegarVuelo(apuntador Vdespege, apuntador Vsalida, char vuelo[]){
    apuntador puntero = Vdespege;

    while (puntero->sig && strcmp(puntero->sig->vuelo, vuelo) != 0)
    {
        puntero = puntero->sig;
    }
    if (strcmp(puntero->vuelo, vuelo) == 0)
    {
        if (Vsalida == NULL)
        {
            Vsalida = (viaje *)malloc(sizeof(viaje));
        }
        strncpy(puntero->sig->estado, "EN RUTA", 12);
        apuntador eliminado = puntero->sig;
        puntero->sig = puntero->sig->sig;
        *Vsalida = *eliminado;
        free(eliminado);
        printf("\nSe movio el vuelo de Control de Despegues a Control de Salidas\n");
    }
    else if (strcmp(puntero->vuelo, vuelo) != 0)
    {
        printf("\nNo se ha encontrado el vuelo\n");
    }
}



void main(){
    int op, op2;
    char vuelo[6],transporte[20],equipamiento[8],origen[5],destino[5],estado[12];
    apuntador gndd=NULL, dep=NULL, acc=NULL, app=NULL, gndl=NULL;

    do
    {
        system("cls");
        printf("\n\n  Aeropuerto-Equipo 5");
        printf("\n -------------------------------");
        printf("\n 1. Control de Despegues (GNDD)");
        printf("\n 2. Control de Salidas (DEP)");
        printf("\n 3. Control de Ruta A�rea (ACC)");
        printf("\n 4. Control de Aproximaci�n (APP)");
        printf("\n 5. Control de Aterrizajes (GNDL)");
        printf("\n 6. Salir");
        printf("\n -------------------------------");
        printf("\n Porfavor ingrese la accion que desea realizar:\t");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            do{
                system("cls");
                printf("\n\tControl de Despegues\n");
                printf("\n**************************************************");
                recorreFirst(gndd);
                printf("\n\n\n\n\n");
                printf("\n 1. Agregar vuelo | 2. Consultar vuelo | 3. Despegar vuelo | 4. Salir");
                printf("\n\n    Porfavor ingrese la accion que desea realizar:\t");
                scanf("%d",&op2);
                switch(op2){
                case 1:
                    system("cls");
                    fflush(stdin);
                    printf("\n    Porfavor ingresa la clave de vuelo:\t");
                    scanf("%6[^\n]", vuelo);
                    fflush(stdin);
                    printf("\n    Porfavor ingresa el nombre de la linea aerea:\t");
                    scanf("%20[^\n]", transporte);
                    fflush(stdin);
                    printf("\n    Porfavor ingresa el modelo de la aeronave:\t");
                    scanf("%8[^\n]", equipamiento);
                    fflush(stdin);
                    printf("\n    Porfavor ingresa el punto de partida del vuelo:\t");
                    scanf("%5[^\n]", origen);
                    fflush(stdin);
                    printf("\n    Porfavor ingresa el punto de llegada del vuelo:\t");
                    scanf("%5[^\n]", destino);
                    fflush(stdin);
                    // printf("\n    Porfavor ingresa la situacion actual del vuelo:\t");
                    // scanf("%12[^\n]", estado);
                    fflush(stdin);
                    agregarVuelo(&gndd, vuelo, transporte, equipamiento, origen, destino, "POR DESPEGAR");
                    printf("\n\n     Cantidad actual de vuelos: %d \n\n", tam);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    fflush(stdin);
                    consultar(gndd);
                    printf("\n");
                    system("PAUSE");
                    break;
                case 3:
                    system("CLS");  
                    fflush(stdin);
                    printf("\n    Porfavor ingresa la clave de vuelo a despegar:\t");
                    scanf("%s", vuelo);
                    despegarVuelo(gndd, dep, vuelo);
                    printf("\n\n     Cantidad actual de vuelos: %d \n\n", tam);
                    system("PAUSE");
                    break;
                }
            }while(op2!=4);
            break;
        case 2:
            do{
            printf("\nControl de Salidas");
            printf("\n**************************************************");
            recorreFirst(dep);
            printf("\n\n\n\n\n");
            printf("\n 1. Consultar vuelo | 2. Pasar Vuelo a centro | 3. Regreso de Emergencia | 4. Salir");
            scanf("%d",&op2);
            switch(op2){
            case 1:
                //consultar();
                break;
            case 2:
                //pasarCentro();
                break;
            case 3:
                //regresoEmergencia();
                break;
            }
            }while(op2!=4);
            break;
        case 3:
            do{
            printf("\nControl de Ruta A�rea");
            //mostrarEnRuta();
            printf("\n\n\n\n\n");
            printf("\n 1. Agregar vuelo | 2. Consultar vuelo | 3. Pasar vuelo a aproximacion | 4. Salir");
            scanf("%d",&op2);
            switch(op2){
            case 1:
                //agregar();
                break;
            case 2:
                //consultar();
                break;
            case 3:
                //pasarAprox();
                break;
            }
            }while(op2!=4);
            break;
        case 4:
            do{
            printf("\nControl de Aproximaci�n");
            //mostrarAprox();
            printf("\n\n\n\n\n");
            printf("\n 1. Consultar vuelo | 2. Aterrizar vuelo | 3. Salir");
            scanf("%d",&op2);
            switch(op2){
            case 1:
                //consultar();
                break;
            case 2:
                //aterrizar(); --Puede ser eliminar
                break;
            }
            }while(op2!=3);
            break;
        case 5:
            do{
            printf("\nControl de Aterrizajes");
            //mostrarAterrizar();
            printf("\n\n\n\n\n");
            printf("\n 1. Consultar vuelo | 2. En terminal | 3. Por Despegar | 4. Eliminar | 5. Salir");
            printf("\n ");
            scanf("%d",&op2);
            switch(op2){
            case 1:
                //consultar();
                break;
            case 2:
                //terminal();
                break;
            case 3:
                //pordespegar();
                break;
            case 4:
                //eliminar();
                break;
            }
            }while(op2!=5);
            break;
        }
    }
    while(op != 6);
}
