#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/*
RUBÉN EDUARDO VEGA MAYORGA 
730919
ITC
3 DE DICIEMBRE DEL 2022
*/
typedef struct Vehiculo{
    char placas[10];
    char marca[10];
    char modelo[10];
    int tipo;
    int year;
}Vehiculo;

typedef struct Nodo
{
    Vehiculo vehiculo;
    struct Nodo* siguiente;
}Nodo;

typedef struct Lista
{
    Nodo* cabeza;
    int longitud;
}Lista;

Nodo* CrearNodo(Vehiculo* vehiculo){
    Nodo* nodo = (Nodo *)malloc(sizeof(Nodo));
    strncpy(nodo->vehiculo.placas, vehiculo->placas, 10);
    strncpy(nodo->vehiculo.marca, vehiculo->marca, 10);
    strncpy(nodo->vehiculo.modelo, vehiculo->modelo, 10);
    nodo->vehiculo.tipo = vehiculo->tipo;
    nodo->vehiculo.year = vehiculo->year;
    nodo->siguiente = NULL;
    return nodo; 
}

void InsertarPrincipio(Lista* lista, Vehiculo* vehiculo){
    Nodo* nodo = CrearNodo(vehiculo); 
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void InsertarDespues(char placas[], Lista* lista, Vehiculo* vehiculo){
    Nodo* nodo = CrearNodo(vehiculo);
    if (lista->cabeza == NULL)
    {
        lista->cabeza = nodo;
        lista->longitud++;
        printf("Se ha agregado el vehiculo\n");
    }
    else
    {
        Nodo* puntero = lista->cabeza;
        while (strcmp(placas, puntero->vehiculo.placas) != 0 && puntero->siguiente) 
        {
            puntero = puntero->siguiente;
        }
        if (strcmp(placas, puntero->vehiculo.placas) == 0)
        {
            nodo->siguiente = puntero->siguiente; 
            puntero->siguiente = nodo;
            lista->longitud++;
            printf("Se ha agregado el vehiculo\n");
        }
        else
        {
            printf("\nNo se encontro el vehiculo!\n");
        }
    }
}

void ImprimirLista(Lista* lista){
    if(lista->cabeza == NULL)
    {
        printf("\nLa lista esta vacia!\n");
        system("PAUSE");
    }
    else
    {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        printf("\nPLACAS | MARCA | MODELO | A%cO | TIPO DE SERVICIO |\n\n", 165);
        while (posicion < lista->longitud)
        {
            printf("%s | %s | %s | %d | %d\n", puntero->vehiculo.placas, puntero->vehiculo.marca, puntero->vehiculo.modelo, puntero->vehiculo.year, puntero->vehiculo.tipo);
            puntero = puntero->siguiente;
            posicion++;
        }
        printf("\n");
        system("PAUSE");
    }
}

Vehiculo* Obtener(char placas[], Lista* lista){
    if (lista->cabeza == NULL)
    {
        printf("No hay Vehiculos!\n");
        Sleep(1500);
        return NULL;
    }
    else
    {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while (strncmp(placas, puntero->vehiculo.placas, 10) != 0 && posicion < lista->longitud && puntero->siguiente)
        {
            puntero = puntero->siguiente;
            posicion++;
        }
        if (strcmp(placas, puntero->vehiculo.placas) != 0)
        {
            printf("\nNo se encontro el vehiculo!\n");
            Sleep(1500);
            return &puntero->vehiculo;
        }
        else
        {
            return &puntero->vehiculo;
        }   
    }
}

void AtenderVehiculo(Lista* lista){
    if (lista->cabeza)
    {
        Nodo* eliminado = lista->cabeza;
        printf("\nPlacas | Marca | Modelo | A%cO| TIPO DE SERVICIO |\n", 165);
        printf("%s | %s | %s | %d | %d\n", eliminado->vehiculo.placas, eliminado->vehiculo.marca, eliminado->vehiculo.modelo, eliminado->vehiculo.year, eliminado->vehiculo.tipo);
        lista->cabeza = lista->cabeza->siguiente;
        free(eliminado);
        lista->longitud--;
        printf("\nSe ha eliminado el vehiculo.\n");
        system("PAUSE");
    }
    else
    {
        printf("\nLa lista esta vacia!!\n");
        system("PAUSE");
    }
    
}

void RegistrarVehiculo(Vehiculo* vehiculo){
    char placas[10], marca[10], modelo[10];
    int tipo, year;
    printf("\nIngrese las placas del vehiculo: ");
    scanf("%s", placas);
    printf("Ingrese la marca del vehiculo: ");
    scanf("%s", marca);
    printf("Ingrese el modelo del vehiculo: ");
    scanf("%s", modelo);
    printf("Tipos de servicio: \n1. Cambio de Aceite y Filtro.\n2. Hojalateria y Pintura.\n3. Frenos y Clutch.");
    printf("\nIngrese el tipo de servicio: ");
    scanf("%d", &tipo);
    printf("\nIngrese el a%co del vehiculo: ", 164);
    scanf("%d", &year);

    strncpy(vehiculo->placas, placas, 10);
    strncpy(vehiculo->marca, marca, 10);
    strncpy(vehiculo->modelo, modelo, 10);
    vehiculo->tipo = tipo;
    vehiculo->year = year;
}

void main()
{
    Vehiculo* vehiculo = (Vehiculo*)malloc(sizeof(Vehiculo));
    Lista lista;
    lista.cabeza = NULL;
    lista.longitud = 0;
    int op = 0, n = 0;
    char placas[10];
    do
    {
        system("CLS");
        printf("----------------------------------------------------------------------\n");
        printf("---------------LISTA DE VEHICULOS EN TALLER AUTOMOTRIZ----------------\n");
        printf("----------------------------------------------------------------------\n");
        printf("1. Agregar Vehiculo.\n2. Agregar Vehiculo en Medio.\n3. Imprimir Lista.\n4. Buscar en la Lista.\n5. Atender Vehiculo.\n0. SALIR \n\n");
        printf("Seleccione una de las opciones anteriores:  ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                RegistrarVehiculo(vehiculo);
                InsertarPrincipio(&lista, vehiculo);
                break;
            case 2:
                RegistrarVehiculo(vehiculo);
                printf("\n!!Se buscan las placas de un vehiculo y el nuevo vehiculo se coloca despues de el: \n\n");
                printf("Ingrese las placas de dicho vehiculo: ");
                scanf("%s", placas);
                InsertarDespues(placas, &lista, vehiculo);
                system("PAUSE");
                break;
            case 3:
                ImprimirLista(&lista);
                break;
            case 4:
                printf("\nIngrese las palcas del vehiculo a buscar: ");
                scanf("%s", placas);
                vehiculo = Obtener(placas, &lista);
                printf("\nPLACAS | MARCA | MODELO | A%cO | TIPO DE SERVICIO |\n\n", 165);
                printf("%s | %s | %s | %d | %d\n", vehiculo->placas, vehiculo->marca, vehiculo->modelo, vehiculo->year, vehiculo->tipo);
                system("PAUSE");
                break;
            case 5:
                AtenderVehiculo(&lista);
                break;
            case 0:
                break;
            default:
                printf("\nSeleccione otra opcion.\n");
                system("PAUSE");
                break;
        }
    } while (op);
    printf("\nSaliendo...\n\n");
    system("PAUSE");   
}