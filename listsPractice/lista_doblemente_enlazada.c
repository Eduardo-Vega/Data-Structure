#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Nodo
{
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
}Nodo;
typedef struct Lista
{
    Nodo* cabeza;
    Nodo* cola;
}Lista;
Nodo* CrearNodo(Lista* lista, int dato){
    Nodo* nodo = (Nodo* )malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    nodo->anterior = NULL;
    return nodo;
}
void InsertarInicio(Lista* lista, int dato){
    Nodo* nodo = CrearNodo(nodo, dato);
    nodo->siguiente = lista->cabeza;
    if (lista->cabeza)
    {
        lista->cabeza->anterior = nodo;
    }
    lista->cabeza = nodo;
    if(lista->cola == NULL){
        lista->cola = nodo;
    }
}
void InsertarFinal(Lista* lista, int dato){
    
}