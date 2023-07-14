#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
/********************
Description:
    
********************/

int prioridad(char simbolo);
void main(){
    int tope, pos, tamexp, i;
    char pila[20], exposfija[20];
    char expinfija[20], simbolo;
    
    printf("\n--------CONVERSION DE UNA EXPRESION INFIJA A POSTFIJA---------\n");
    printf("Ingrese la expresion en notacion Infija(SIN ESPACIONS): \n");
    scanf("%s", &expinfija);

    tamexp = strlen(expinfija);
    tope = -1;
    pos = -1;
    for ( i = 0; i < tamexp; i++)
    {
        simbolo = expinfija[i];
        
        if (simbolo == '(')
        {
            tope = tope + 1;
            pila[tope] = simbolo;
        }
        else if(simbolo == ')')
        {
            while (pila[tope] != '('){
                pos = pos + 1;
                exposfija[pos] = pila[tope];
                tope = tope - 1;
            }
            tope = tope - 1;            
        }
        else if ((simbolo >= 'a') && (simbolo <= 'z')||(simbolo >= 'A') && (simbolo <= 'Z'))
        {
            pos = pos + 1;
            exposfija[pos] = simbolo;
        }
        else
        {
            while (tope > -1 && ( prioridad(simbolo) <= prioridad(pila[tope]) )){
                pos = pos +1;
                exposfija[pos] = pila[tope];
                tope = tope - 1;
            } 
            
            tope = tope + 1;
            pila[tope] = simbolo;

        }
    }
     while (tope > -1){
        pos = pos + 1;
        exposfija[pos] = pila[tope];
        tope = tope - 1;
    }

    printf("----------------EXPRESION TRANSFORMADA A POSFIJA--------------\n");
    for (i = 0; i <= pos ; i++)
    {
        printf("%c", exposfija[i]);
    }
    printf("\n");
    system("PAUSE");
    
}

int prioridad(char simbolo){
    int priori;
    switch (simbolo){
    case '^': priori = 3; break;
    case '/': priori = 2; break;
    case '*': priori = 2; break;
    case '-': priori = 1; break;
    case '+': priori = 1; break;
    case ')': priori = 0; break;
    case '(': priori = 0; break;
    }
    return priori;
}

