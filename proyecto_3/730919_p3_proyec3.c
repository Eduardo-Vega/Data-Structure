#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// RUBEN EDUARDO VEG AMAYORGA  730919  7 DE DICIEMBRE DEL 2022

typedef struct Viaje{
    char vuelo[6],transporte[20],equipamiento[8],origen[5],destino[5],estado[12];
}Viaje;

typedef struct Nodo
{
    Viaje viaje;
    struct Nodo* siguiente;
}Nodo;

typedef struct Lista
{
    Nodo* cabeza;
    int longitud;
}Lista;

Nodo* CrearNodo(Viaje* viaje){
    Nodo* nodo = (Nodo *)malloc(sizeof(Nodo));
    strncpy(nodo->viaje.vuelo, viaje->vuelo, 6);
    strncpy(nodo->viaje.transporte, viaje->transporte, 20);
    strncpy(nodo->viaje.equipamiento, viaje->equipamiento, 8);
    strncpy(nodo->viaje.origen, viaje->origen, 5);
    strncpy(nodo->viaje.destino, viaje->destino, 5);
    strncpy(nodo->viaje.estado, viaje->estado, 12);
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo){
    free(nodo);
}

void IngresarViaje(Viaje* viaje, char estado[]){
    char vuelo[6],transporte[20],equipamiento[8],origen[5],destino[5];
    printf("\n    Porfavor ingresa la clave de vuelo:\t");
    scanf("%s", vuelo);
    printf("\n    Porfavor ingresa el nombre de la linea aerea:\t");
    scanf("%s", transporte);
    printf("\n    Porfavor ingresa el modelo de la aeronave:\t");
    scanf("%s", equipamiento);
    printf("\n    Porfavor ingresa el punto de partida del vuelo:\t");
    scanf("%s", origen);
    printf("\n    Porfavor ingresa el punto de llegada del vuelo:\t");
    scanf("%s", destino);
    strncpy(viaje->vuelo, vuelo, 6);
    strncpy(viaje->transporte, transporte, 20);
    strncpy(viaje->equipamiento, equipamiento, 8);
    strncpy(viaje->origen, origen, 5);
    strncpy(viaje->destino, destino, 12);
    strcpy(viaje->estado, estado);
}

void InsertarViaje(Lista* lista, Viaje* viaje){
    Nodo* nodo = CrearNodo(viaje);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void ImprimirViajes(Lista* lista, char opcion[]){//IMPRIME INFORMACION PRINCIPAL
    Nodo* puntero = lista->cabeza;
    int posicion = 0;
    if(puntero != NULL)
    {
        while (posicion < lista->longitud)
        {
            if (strcmp(opcion, "origen") == 0)
            {
                printf("\n- %s  %s", puntero->viaje.vuelo, puntero->viaje.origen);
            }else if (strcmp(opcion, "destino") == 0)
            {
                printf("\n- %s  %s", puntero->viaje.vuelo, puntero->viaje.destino);
            }
            puntero = puntero->siguiente;
            posicion++;
        }
    }else
    {
        printf("\n.......");
    }
    
}

Viaje* BuscarViaje(Lista* lista, char viaje[]){

    if (lista->cabeza == NULL)
    {
        printf("No hay Viajes\n");
        Sleep(1500);
        return NULL;
    }else
    {
        Nodo* puntero = lista->cabeza;
        while (strcmp(viaje, puntero->viaje.vuelo) != 0  && puntero->siguiente ) 
        {
            puntero = puntero->siguiente;
        }
        if ((viaje, puntero->viaje.vuelo) != 0)
        {
            printf("\nNo se encontro el viaje\n");
            Sleep(1500);
            return &puntero->viaje;
        }
        else
        {
            return &puntero->viaje;
        }
    }
}

void ConsultarViaje(Lista* lista, char vuelo[]){//IMPRIME INFORMACION A DETALLE DE UN SOLO VUELO
    Nodo* puntero = lista->cabeza;
    while (puntero->siguiente && strcmp(puntero->viaje.vuelo, vuelo) != 0)//SE AVANZA EN LA LISTA HASTA LLEGAR AL FINAL O ENCONTRAR EL VUELO
    {
        puntero = puntero->siguiente;
    }
    if (strcmp(puntero->viaje.vuelo, vuelo) == 0)
    {
        printf("\nVUELO: %s || TRANSPORTE: %s || EQUIPAMIENTO: %s || ORIGEN: %s || DESTINO: %s || ESTADO: %s\n", puntero->viaje.vuelo, puntero->viaje.transporte, puntero->viaje.equipamiento, puntero->viaje.origen, puntero->viaje.destino, puntero->viaje.estado);
        system("PAUSE");
    }else if (strcmp(puntero->viaje.vuelo, vuelo) != 0)
    {
        printf("\nNo se ha encontrado el vuelo\n");
        system("PAUSE");
    }
}

void DespegarVuelo(Lista* listaD, Lista* listaS, char vuelo[]){
    Nodo* puntero = listaD->cabeza;
    Nodo* eliminado;
    Viaje viajenull;
    if (puntero != NULL)
    {
        if (strcmp(puntero->viaje.vuelo, vuelo) == 0)
        {
            if (listaS->cabeza == NULL)
            {
                InsertarViaje(listaS, &viajenull);
                listaS->longitud--;
            }
            strcpy(puntero->viaje.estado, "En Ruta");
            eliminado = puntero;
            if (listaD->longitud = 1)
            {
                eliminado = puntero;
                listaD->cabeza = NULL;
            }else
            {
                listaD->cabeza = puntero->siguiente;
            }
            listaD->longitud--;
            if (listaS->cabeza == NULL)
            {
                listaS->cabeza = eliminado;
            }
            else
            {
                eliminado->siguiente = listaS->cabeza;
                listaS->cabeza = eliminado;
            }
            listaS->longitud++;

            printf("\nSe movio el vuelo de Control de Despegues a Control de Salidas");
        }
        else
        {    
            while (puntero->siguiente && strcmp(puntero->siguiente->viaje.vuelo, vuelo) != 0 )
            {
                puntero = puntero->siguiente;
            }
            if (strcmp(puntero->siguiente->viaje.vuelo, vuelo) == 0)
            {
                if (listaS->cabeza == NULL)
                {
                    InsertarViaje(listaS, &viajenull);
                    listaS->longitud--;
                }
                strcpy(puntero->siguiente->viaje.estado, "En Ruta");
                eliminado = puntero->siguiente;
                puntero->siguiente = puntero->siguiente->siguiente;
                if (listaS->longitud < 2)
                {
                    eliminado->siguiente = NULL;
                    listaS->cabeza = eliminado;
                }
                else
                {
                    eliminado->siguiente = listaS->cabeza;
                    listaS->cabeza = eliminado;
                }
                listaS->longitud++;
                listaD->longitud--;
                
                printf("\nSe movio el vuelo de Control de Despegues a Control de Salidas");
            }
            else if (strcmp(puntero->siguiente->viaje.vuelo, vuelo) != 0)
            {
                printf("\nNo se ha encontrado el vuelo.");
            }
            else if (strcmp(puntero->viaje.vuelo, vuelo) != 0)
            {
                printf("\nNo se ha encontrado el vuelo.");
            }
            
        }
        
    }
    else
    {
        printf("\nNo hay vuelos.");
    }
    
}

void EliminarVuelo(Lista* lista, char vuelo[]){
    if (lista->cabeza)
    {
        if (strcmp(lista->cabeza->viaje.vuelo, vuelo) == 0) 
        {
            Nodo* eliminado = lista->cabeza; 
            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
            printf("\nSe ha eliminado el primer nodo!\n");
            system("PAUSE");
        }
        else
        {
            Nodo* puntero = lista->cabeza;
        }
    }else
    {
        printf("\nLista vacia!!\n");
        system("PAUSE");
    }
}


void main(){
    Lista gndd, dep, acc, app, gndl;

    gndd.cabeza = NULL;
    gndd.longitud = 0;
    dep.cabeza = NULL;
    dep.longitud = 0;
    acc.cabeza = NULL;
    acc.longitud = 0;
    app.cabeza = NULL;
    app.longitud = 0;
    gndl.cabeza = NULL;
    gndl.longitud = 0;

    Viaje viaje;
    
    int op,op2;
    char vuelo[6];

    do
    {
        system("cls");
        printf("\n\n  Aeropuerto ");
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
            ImprimirViajes(&gndd, "origen");
            printf("\n\n\n\n\n");
            printf("\n 1. Agregar vuelo | 2. Consultar vuelo | 3. Despegar vuelo | 4. Salir\n");
            printf("\n\n    Porfavor ingrese la accion que desea realizar:\t");
            scanf("%d",&op2);
            switch(op2){
            case 1:
                system("cls");
                IngresarViaje(&viaje, "En Espera");
                InsertarViaje(&gndd, &viaje);
                printf("\n");
                printf("\n\n     Cantidad actual de vuelos: %d \n\n", gndd.longitud);
                system("PAUSE");
                break;
            case 2:
                system("cls");
                printf("\n    Porfavor ingresa la clave de vuelo a consultar:\t");
                scanf("%s", vuelo);
                ConsultarViaje(&gndd, vuelo);
                break;
            case 3:
                system("cls");
                printf("\n    Porfavor ingresa la clave de vuelo que esta despegando:\t");
                scanf("%s", vuelo);
                DespegarVuelo(&gndd, &dep, vuelo);
                printf("\n\n     Cantidad actual de vuelos: %d \n\n", gndd.longitud);
                system("PAUSE");
                break;
            }
            }while(op2!=4);
            break;
        case 2:
            do{
            printf("\nControl de Salidas");
            printf("\n**************************************************");
            ImprimirViajes(&dep, "destino");
            printf("\n\n\n\n\n");
            printf("\n 1. Consultar vuelo | 2. Pasar Vuelo a centro | 3. Regreso de Emergencia | 4. Salir");
            printf("\n\n    Porfavor ingrese la accion que desea realizar:\t");
            scanf("%d",&op2);
            switch(op2){
            case 1:
                system("cls");
                printf("\n    Porfavor ingresa la clave de vuelo a consultar:\t");
                scanf("%s", vuelo);
                ConsultarViaje(&dep, vuelo);
                break;
            case 2:
                system("cls");
                printf("\n    Porfavor ingresa la clave de vuelo a transferir a Conrolador Cento:\t");
                scanf("%s", vuelo);

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
            }while(op2 != 3);
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
            }while(op2 != 5);
            break;
        }
    }
    while(op != 6);
}
