#include <stdio.h>
#include <stdbool.h>
struct Boleto{
    int id;
    int numeros[6];
    int aciertos;
    int melate;
    int revancha;
    int revanchita;
};
// variables de GANADORES
struct Boleto ganadoresMelate[200];
int total_ganadoresMeltate = 0;
struct Boleto ganadoresRevancha[200];
int total_ganadoresRevancha = 0;
struct Boleto ganadoresRevanchita[200];
int total_ganadoresRevanchita = 0;
// VAR GLOBALES
// base de datos de boletos
struct Boleto boletos[200];
// variable para llevar el conteo y el ID de boletos
int boletoActualCapturar = 0;
// flag para saber si repitieron numerosIngresados se usa en Case 1 y 2
int flag = 0;

// CASE 2 variables
// Array para guardar numeros y comparar
int oldNumbers[7];
// Array para numeros de GANADOR melate
int gMelate[7];
// Array para GANADOR de revancha
int gRevancha[6];
// Array para GANADOR de revanchita
int gRevanchita[6];
// Ordenamiento
int * shell(int a[], int n){
    int ints, i, aux;
    bool band;

    ints = n;
    while(ints >1){
        ints = (ints/2);
        band = true;
        while(band == true){
            band = false;
            i = 0;
            while(i+ints <= n){
                if(a[i] > a[i+ints]){
                    aux = a[i];
                    a[i] = a[i+ints];
                    a[i+ints] = aux;
                    band = true;
                }
                i++;
            }
        }
    }

    return a;
}
// Operaciones con boletos
void setNumeroAciertos(struct Boleto verificar, int comparar[6]){
    for(int i = 0; i < 6; i++){
        for(int e = 0; e < 6; ){
            if(verificar.numeros[i] == comparar[e]){
                // si no funciona usar verificar.aciertos = verificar.aciertos + 1;
                verificar.aciertos++;
            }
        }
    }
}
void deleteBoleto(struct Boleto boleto){
    for(int i = 0; i < 6; i++){
        boleto.numeros[i] = 0;
    }
}
void capturaBoleto(){
    for(int i = 0; i < 6; i++){
        int dato;
        printf("\n - Ingrese el #%d numero a capturar que sea menor a 56: ", i+1);
        scanf("%d", &dato);
        if(dato <= 56){
            // validacion si se repite numero
            for(int e = 0; e <= i; e++){
                if(boletos[boletoActualCapturar].numeros[e] == dato){
                    flag = 1;
                }
            }
            if(flag == 0){
                boletos[boletoActualCapturar].numeros[i] = dato;
            }
            else{
                printf("\n + El numero %d esta repetido favor de intentar otro", dato);
                flag = 0;
                i--;
            }
        }
        else{
            i--;
        }
    }
}
int compara(int J[],int K[], int m){
    int coincidencias =0;
    for (int x = 0; x<=6; x++){
                    for (int y = 0; y<=6 ; y++){
                        if (J[x]==K[y]){
                            coincidencias++;

                        }
                    }
    }
    return coincidencias;
}
void imprime(int V[], int N){
    printf("\n");
    printf(" ");
    for (int i=1; i<N; i++)
         printf(" \t [%d] ",V[i]);
}
void getReporte(struct Boleto t_boletos[200], int boletos_vendidos){
    for(int i = 0; i < boletos_vendidos; i++){
        printf("\n ID: %d", t_boletos[i].id);
        printf("\n Numeros: %d - %d - %d - %d - %d - %d",
            t_boletos[i].numeros[0],
            t_boletos[i].numeros[1],
            t_boletos[i].numeros[2],
            t_boletos[i].numeros[3],
            t_boletos[i].numeros[4],
            t_boletos[i].numeros[5]);
        printf("\n");
    }
}
void printWinners(struct Boleto winners[], int total){
    for(int i = 0; i < total; i++){
        printf("\n ID: %d", winners[i].id);
        printf("\n Numeros: %d - %d - %d - %d - %d - %d",
            winners[i].numeros[0],
            winners[i].numeros[1],
            winners[i].numeros[2],
            winners[i].numeros[3],
            winners[i].numeros[4],
            winners[i].numeros[5]);
        if(winners[i].aciertos == 6){
            printf("\n Primer lugar");
        }
        if(winners[i].aciertos == 5){
            printf("\n Segundo lugar");
        }
        if(winners[i].aciertos == 4){
            printf("\n Tercer lugar");
        }
    }
}
// Verificar ganadores
void verifyWinnerMelate(struct Boleto boletos[200], int total_boletos_vendios){
    // ciclo para el total de boletos
    for(int i = 0; i < total_boletos_vendios; i++){
        if(boletos[i].aciertos == 6){
            boletos[i].aciertos = 0;
            ganadoresMelate[total_ganadoresMeltate] = boletos[i];
            total_ganadoresMeltate++;
        }
        if(boletos[i].aciertos == 5){
            boletos[i].aciertos = 0;
            ganadoresMelate[total_ganadoresMeltate] = boletos[i];
            total_ganadoresMeltate++;
        }
        if(boletos[i].aciertos == 4){
            boletos[i].aciertos = 0;
            ganadoresMelate[total_ganadoresMeltate] = boletos[i];
            total_ganadoresMeltate++;
        }
    }
}
void verifyWinnerRevancha(struct Boleto boletos[200], int total_boletos_vendios){
    // ciclo para el total de boletos
    for(int i = 0; i < total_boletos_vendios; i++){
        if(boletos[i].aciertos == 6){
            boletos[i].aciertos = 0;
            ganadoresRevancha[total_ganadoresRevancha] = boletos[i];
            total_ganadoresRevancha++;
        }
        if(boletos[i].aciertos == 5){
            boletos[i].aciertos = 0;
            ganadoresRevancha[total_ganadoresRevancha] = boletos[i];
            total_ganadoresRevancha++;
        }
        if(boletos[i].aciertos == 4){
            boletos[i].aciertos = 0;
            ganadoresRevancha[total_ganadoresRevancha] = boletos[i];
            total_ganadoresRevancha++;
        }
    }
}
void verifyWinnerRevanchita(struct Boleto boletos[200], int total_boletos_vendios){
    for(int i = 0; i < total_boletos_vendios; i++){
        if(boletos[i].aciertos == 6){
            boletos[i].aciertos = 0;
            ganadoresRevanchita[total_ganadoresRevanchita] = boletos[i];
            total_ganadoresRevanchita++;
        }
        if(boletos[i].aciertos == 5){
            boletos[i].aciertos = 0;
            ganadoresRevanchita[total_ganadoresRevanchita] = boletos[i];
            total_ganadoresRevanchita++;
        }
        if(boletos[i].aciertos == 4){
            boletos[i].aciertos = 0;
            ganadoresRevanchita[total_ganadoresRevanchita] = boletos[i];
            total_ganadoresRevanchita++;
        }
    }
}
// Generar Tombola
void generateWinnerNumbers(){
    for(int i = 0; i < 7; i++){
        int newNumber = rand()%((56+1)-1) + 1;

        if(i == 0){
            oldNumbers[i] = newNumber;
        }
        else{
            for(int e = 0; e < i; e++){
                if(newNumber == oldNumbers[e]){
                    flag = 1;
                }
            }
            if(flag == 1){
                i--;
            }
            else{
                oldNumbers[i] = newNumber;
            }
        }
    }
}
// borrar variables gobales y de estado
void resetApp(){
    for(int i = 0; i <= boletoActualCapturar; i++){
        for(int e = 0; e < 6; e++){
            boletos[i].numeros[e] = 0;
        }
        boletos[i].id = 0;
    }
    // BORRAR boletos ganadores
    for(int i = 0; i <= 6; i++){
        if(i != 6){
            gRevanchita[i] = 0;
            gRevancha[i] = 0;
        }
        gMelate[i] = 0;
    }
    boletoActualCapturar = 0;
    flag = 0;
}
int main(){
    // variable para elegir opcion de menu
    int opc;
    // Ciclo del menu
    do{
        // elegir opcion
        printf("\n ======================== Melate, Revancha, Revanchita ========================");
        printf("\n\n   1. Capturar boleta");
        printf("\n\n   2. Realizar Sorteo");
        printf("\n\n   3. Reporte de Boletas Capturadas");
        printf("\n\n   4. Reporte de Boletas Ganadores");
        printf("\n\n   5. Reinicio de la app");
        printf("\n\n   6. Salir");
        printf("\n\n - Ingresa la opcion que deseas: ");
        scanf ("\n\n %d", &opc);
        switch (opc){
            // Captura de boleta
            case 1:
                printf("\nCaptura de Boleta\n");
                capturaBoleto();
                shell(boletos[boletoActualCapturar].numeros, 5);
                boletos[boletoActualCapturar].id = boletoActualCapturar;
                boletos[boletoActualCapturar].aciertos = 0;
                boletos[boletoActualCapturar].melate = 0;
                boletos[boletoActualCapturar].revancha = 0;
                boletos[boletoActualCapturar].revanchita = 0;
                boletoActualCapturar++;
                break;

            // Realizar sorteo
            case 2:
                // GANADOR melate y ordenar
                // Genera 7 numeros aleatorios no repetidos del 1 al 56
                generateWinnerNumbers();
                for(int i = 0; i < 7; i++){
                    gMelate[i] = oldNumbers[i];
                    oldNumbers[i] = 0;
                }
                shell(gMelate,7); // Ordena numeros ganadores
                // GANADOR revancha y ordenar
                // Genera 6 numeros aleatorios no repetidos del 1 al 56
                generateWinnerNumbers();
                for(int i = 0; i < 6; i++){
                    gRevancha[i] = oldNumbers[i];
                    oldNumbers[i] = 0;

                }
                shell(gRevancha,6); // Ordena numeros ganadores
                // GANADOR revanchita y ordenar
                // Genera 6 numeros aleatorios no repetidos del 1 al 56
                generateWinnerNumbers();
                for(int i = 0; i < 6; i++){
                    gRevanchita[i] = oldNumbers[i];
                    oldNumbers[i] = 0;
                }
                shell(gRevanchita,6);
                printf("\n ======================== Numeros ganadores ========================\n");
                printf("\n ======================== Melate : ========================\t \n");
                imprime(gMelate,8);
                printf("\n ========================Revancha : ========================\t \n");
                imprime(gRevancha, 7);
                printf("\n ========================Revanchita : ========================\t \n");
                imprime(gRevanchita, 7);

                break;
            case 3:
                getReporte(boletos, boletoActualCapturar);
                break;

            case 4:
                printf("\n ======================== Ganador melate ========================\n");
                for(int i = 0; i < boletoActualCapturar; i++){
                    setNumeroAciertos(boletos[i], gMelate);
                }
                verifyWinnerMelate(boletos, boletoActualCapturar);
                printf("\n ======================== Ganador Revancha ========================\n");
                for(int i = 0; i < boletoActualCapturar; i++){
                    setNumeroAciertos(boletos[i], gRevancha);
                }
                verifyWinnerRevancha(boletos, boletoActualCapturar);
                printf("\n ======================== Ganador Revanchita ========================\n");
                for(int i = 0; i < boletoActualCapturar; i++){
                    setNumeroAciertos(boletos[i], gRevanchita);
                }
                verifyWinnerRevanchita(boletos, boletoActualCapturar);
                printf("\n Ganadores Melate");
                printWinners(ganadoresMelate, total_ganadoresMeltate);
                printf("\n Ganadores Revancha");
                printWinners(ganadoresRevancha, total_ganadoresRevancha);
                printf("\n Ganadores Revanchita");
                printWinners(ganadoresRevanchita, total_ganadoresRevanchita);
            break;

            case 5:
                printf("\n\n Reinicio de la app");
                resetApp();
                break;
        }
    } while (opc != 6);
    printf("Programa finalizado");
    return 0;
}
