/********************
    Materia: Estructura de Datos
    autores: Ricardo Guzman - 737080
            Ivan Rangel - 737680
            Ruben Eduardo Vega Mayorga- 730919
            Rodrigo Bohorquez - 733014
********************/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 5
/*******************************
Description: 
    
*******************************/

int main()
{
    int arr[size],R=-1,F=0,te=0,ch,n,i,x;

    for(;;)
    {
        system("cls");
        printf("1. Agregar al final\n");
        printf("2. Eliminar del final\n");
        printf("3. Agregar al frente\n");
        printf("4. Eliminar del frente\n");
        printf("5. Mostrar\n");
        printf("6. Salir\n");
        printf("Elegir Opcion: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                if(te==size)
                {
                    printf("La cola esta llena");
                    getch();
                }
                else
                {
                    printf("Ingresa un numero ");
                    scanf("%d",&n);
                    R=(R+1)%size;
                    arr[R]=n;
                    te=te+1;
                }
                break;

            case 2:
                if(te==0)
                {
                    printf("La cola esta vacia");
                    getch();
                }
                else
                {
                    if(R==-1)
                    {
                        R=size-1;
                    }
                    printf("Numero borrado de final = %d",arr[R]);
                    R=R-1;
                    te=te-1;
                    getch();
                }
                break;

            case 3:
                if(te==size)
                {
                    printf("La cola esta llena");
                    getch();
                }
                else
                {
                    printf("Ingresa un numero ");
                    scanf("%d",&n);
                    if(F==0)
                    {
                        F=size-1;
                    }
                    else
                    {
                        F=F-1;
                    }
                    arr[F]=n;
                    te=te+1;
                }
                break;

            case 4:
                if(te==0)
                {
                    printf("La cola esta vacia");
                    getch();
                }
                else
                {
                    printf("Numero borrado de frente = %d",arr[F]);
                    F=(F+1)%size;
                    te=te-1;
                    getch();
                }
                break;

            case 5:
                if(te==0)
                {
                    printf("La cola esta vacia");
                    getch();
                }
                else
                {
                    x=F;
                    for(i=1; i<=te; i++)
                    {
                        printf("%d ",arr[x]);
                        x=(x+1)%size;
                    }
                    getch();
                }
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Opcion incorrecta");
                getch();
        }
    }
    return 0;
}
