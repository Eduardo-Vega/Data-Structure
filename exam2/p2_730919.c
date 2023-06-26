#include<stdio.h>
#include<stdlib.h>

int pila_llena(int tope, int max)
{
    if(tope==max){
        return 1;
    }
    else{
        return 0;
    }
        
}

int pila_vacia(int tope)
{
    if(tope==0){
        return 1;
    }
    else{
        return 0;
    }
        
}

void insertar(int *pila, int *tope, int max, int num)
{
    int t;
    t=*tope;
    if(pila_llena(t,max))
    {
        printf("\n\n ERROR: Desbordamiento, la pila esta llena!!! ");
        system("PAUSE");
    }
    else
    {
        pila[t]=num;
        t++;
        *tope=t;

    }
}

void eliminar(int *pila, int *tope, int *tope1)
{
    int t, tm, tm1, t1, i;
    t=*tope;
    tm = t;
    t1=*tope1;
    tm1 = t1;
    if(pila_vacia(t))
    {
        printf("\n\n ERROR: La pila esta vacia!!!");
        system("PAUSE");
    }
    else
    {
        for (i = 0; i < t; i++)
        {
            tm--;
            *tope=tm;

        }
        for (i = 0; i < t1; i++)
        {
            tm1--;
            *tope1=tm1;

        }
    }
}




void imprimir(int *pila, int tope)
{
    int i;
    system("CLS");
    printf("\n\n Elementos de la Pila  ");
    printf("\n -------------------------------");
    for(i=0; i<tope; i++){
        printf("\n Elemento [%d] : %d",i+1,pila[i]);
    }

}

void positivosFuncion(int *pila, int *tope, int max, int *positivos, int *tope1, int max1){
    int i, t1, t;
    for (i = 0; i < *tope; i++)
    {
        if (pila[i] > 0)
        {
            t1 = *tope1;
            pila[i] = positivos[t1];
            t1++;
            t--;
            *tope1 = t1;
            *tope = t;
        }
    }
}

void main()
{
    int pila[50], positivos[50], tope=0, max=50, tope1=0, max1=50, i, band, num, op;
    do
    {
        system("CLS");
        printf("\n\n  Lista de Enteros ");
        printf("\n -------------------------------");
        printf("\n 1. Insertar lista de elementos");
        printf("\n 2. Vaciar");
        printf("\n 3. Imprimir Pila");
        printf("\n 0. Salir");
        printf("\n\n Seleccione una opcion: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            do
            {
                system("cls");
                printf("\n\n Agregar Elementos (Apilar) ");
                printf("\n -------------------------------");
                printf("\n  Elemento: ");
                scanf("%d",&num);
                insertar(pila,&tope,max,num);
                printf("\n  Deseas agregar otro elemento (1=SI|0=NO): ");
                scanf("%d",&band);
            }
            while(band && tope<max);
            break;
        case 2:
            band=1;
            system("cls");
            printf("\n\n Vaciar Pila");
            printf("\n -------------------------------");
            if (tope1 == 0)
            {
                positivosFuncion(pila,&tope,max,positivos,&tope1,max1);

            }
            printf("\n\nPILA CON VALORES POSITIVOS\n");
            imprimir(positivos,tope1);
            printf("\n\nPILA CON VALORES Negativos\n");
            imprimir(pila,tope);
            system("PAUSE");
            eliminar(pila, &tope, &tope1);
            break;
        case 3:
            if(pila_vacia(tope))
            {
                printf("\n\n ERROR: La pila esta vacia!!!");
                system("PAUSE");
            }
            else
                if (tope1 == 0)
                {
                    positivosFuncion(pila,&tope,max,positivos,&tope1,max1);

                }
                printf("\n\nPILA CON VALORES POSITIVOS\n");
                imprimir(positivos,tope1);
                printf("\n\nPILA CON VALORES Negativos\n");
                imprimir(pila,tope);
                system("PAUSE");
            break;
        }
    }
    while(op);
}





