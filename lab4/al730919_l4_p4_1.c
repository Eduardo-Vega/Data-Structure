#include <stdio.h>
#include <string.h>

/******************************************************************
 Descripcion:
    El programa es capaz de almacenar hasta 50 libros con su respectivo
    título, autor, editorial, año e isbn.
********************************************************************/

typedef struct {
    char titulo[51];
    char autor[51];
    char editorial[51];
    int year;
    int isbn;
} Libro;

void printLibro(Libro lib[], int n){
    for(int i=0; i <n; i++){
        printf("\n %s | %s | %s | %d | %d |", lib[i].titulo, lib[i].autor, lib[i].editorial, lib[i].year, lib[i].isbn);
    }
}

void scanLibro(Libro lib[], int n){
    for(int i=0; i <n; i++){
        printf("\nTitulo: ");
        fflush(stdin);
        gets(lib[i].titulo);
        printf("\nAutor: ");
        gets(lib[i].autor);
        printf("\nEditorial: ");
        gets(lib[i].editorial);
        printf("\nYear: ");
        scanf("%d", &lib[i].year);
        fflush(stdin);
        printf("\nISBN: ");
        scanf("%d", &lib[i].isbn);
    }
}

void main(){
    int n;
    Libro libros[50];
    printf("Ingrese la cantidad de libros: ");
    scanf("%d", &n);
    scanLibro(libros, n);
    printLibro(libros, n);
}