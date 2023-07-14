#include <stdio.h>

/******************************************************************
 Description:
        CONTEO DE VOTOS PARA 5 CANDIDATOS.
********************************************************************/

void main()
{
    int votos[5]= {};
    int voto, i;
    i = 1;
    printf("Ingrese su voto (1-5) y 0 para concluir.\n");
    do{
        printf("Voto: ");
        scanf("%d",&voto);
        switch(voto)
        {
            case 1:
                    votos[0]++;
                    break;

            case 2:
                    votos[1]++;
                    break;

            case 3:
                    votos[2]++;
                    break;

            case 4:
                    votos[3]++;
                    break;

            case 5:
                    votos[4]++;
                    break;

            case 0:
                    i = 0;
                    break;

            default:
                     break;
        }
    }while(i);
    printf("\n Conteo de votos: \n");
    for (i=0;i<5;i++) {
        printf("Candidato %d = %d \n",i+1,votos[i]);
    }
}
