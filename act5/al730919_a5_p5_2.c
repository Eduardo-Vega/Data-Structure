/********************
    Description:
        
********************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i, j, k;

typedef struct {
    char clave[11];
    char nombre[31];
    float precio;
}Articulo;

void printList(Articulo art[]){

    for ( i = 0; i < 10; i++){
        printf("\t%s      %s          %.2f\n", art[i].clave, art[i].nombre, art[i].precio);
    }    
}

void linearSearch(Articulo art[]){
    char key[31], realkey[31];
    int band = 0, len;
    printf("\n----------------------------------------------------------\n");
    printf("Ingrese el nombre del articulo a buscar: ");
    gets(key);
    len = strlen(key);
    for (i = 0; i < len; i++)
    {
        if (key[i] != ' ')
        {
            realkey[i] = key[i];
        }
    }
    len = strlen(realkey);
    for ( i = 0; i < 10; i++)
    {
        if (strnicmp(art[i].nombre, realkey, len) == 0 )
        {
            printf("\n----------------------------------------------------------\n");
            printf("Articulo encontrado: \n");
            printf("\tCLAVE      NOMBRE             PRECIO\n");
            printf("\t%s      %s          %.2f\n", art[i].clave, art[i].nombre, art[i].precio);
            band = 1; 
        } 
    }
    if (!band)
    {
        printf("\n El articulo no se encuntra en la lista.\n");
    }   
}

void selectionSort(Articulo art[], Articulo aux){
    int ind;
    for (j = 0; j <= 9; j++)
    {
        ind = j;
        for ( k = (j+1); k <= 9 ; k++)
        {
            if (atoi(art[k].clave) < atoi(art[ind].clave))
            {
                ind = k;
            }
            
        }   
        aux = art[j];  
        art[j] = art[ind];
        art[ind] = aux;

    }

    printf("\n---------------------Lista Ordenada----------------------\n");
    printf("\tCLAVE      NOMBRE             PRECIO\n");
    
    printList(art);
    linearSearch(art);
}

void main()
{
     
    Articulo articulos[10] = { 
        {"003", "Monitor   ", 3850.70},
        {"006", "Laptop    ", 8699.99},
        {"010", "Procesador", 599.50},
        {"001", "RAM       ", 279.80},
        {"008", "HDMI      ", 199.40},
        {"005", "Teclado   ", 399.90},
        {"002", "Mause     ", 259.60},
        {"007", "Consola   ", 4799.99},
        {"004", "Audifonos ", 160.40},
        {"009", "Bocinas   ", 3499.70},
    }, articulosAux;
    

    printf("\n----------------Lista Original de Ariculos---------------\n");
    printf("\tCLAVE      NOMBRE             PRECIO\n");

    printList(articulos);

    selectionSort(articulos, articulosAux);
    system("pause");
}


