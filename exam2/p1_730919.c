#include <stdio.h>
#include <stdlib.h>


int pares(int num){
    int r, n;
    r = num%10;
    num = num / 10;
    if (r%2 == 0)
    {
        if (num == 0)
        {
            return num;
        }
        return pares(num);
    }
    else
    {
        return 1;
    }
    
    
}

void main()
{
    int num, par, op;
    do
    {
        system("CLS");
        printf("\n---------------------------- DIGITOS PARES -----------------------------\n\n");
        printf("1. Ingresar un valor.\n0. Salir.\n\nSeleccione una opcion:      ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            do
            {
                
                printf("\nIngrese un numero entero positiv0, para validar que sus digitos son pares:     ");
                scanf("%d", &num);

                if (num<0)
                {
                    system("CLS");
                    printf("\n\nERROR: Favor de ingresar un valor entero positivo...\n\n");
                    system("PAUSE");
                }
            } while (num<0);

            par = pares(num);
            if (par != 0)
            {
                printf("\n\nExiste un digito que no es par.\n\n");
                system("PAUSE");
            }else
            {
                printf("\n\nTodos los digitos son par.\n\n");
                system("PAUSE");
            }
            break;
        case 0:
            break;
        default:
            system("CLS");
            printf("\n\nOpción incorrecta...");
            system("PAUSE");
            break;
        }
        
    } while (op);

    system("PAUSE");
}
