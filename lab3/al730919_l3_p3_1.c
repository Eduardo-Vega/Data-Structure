#include <stdio.h>
/******************************************************************
 Nombre: Ruben Eduardo Vega Mayorga
 Matricula: 730919
 Fecha: 1 de octubre del 2022
 Problema 3.1 Laboratorio 3
 Descripcion:
    Se ingresa una cadena de caracteres y un caracter, se cuentan las veces
    que el caracter se encuentra en la cadena.
********************************************************************/
int count(char *strng, char chr){
    int i=0, times=0;
    while (strng[i] != '\0'){
        if (strng[i] == chr){
            times++;
        }
        i++;
    }

    return(times);
}

void main(){
    int times;
    char chr, strng[51];
    printf("Ingrese una cadena de caracteres: ");
    fflush(stdin);
    gets(strng);
    printf("Ingrese el caracter a contar en la cadena: ");
    chr = getchar();
    times = count(strng, chr);
    if (times == 1){
        printf("\nEl caracter %c esta %d vez en la cadena.", chr, times);
    } else{
        printf("\nEl caracter %c esta %d veces en la cadena.", chr, times);
    }
}