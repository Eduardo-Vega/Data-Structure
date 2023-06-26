#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0, j = 0, k = 0;

struct Despachadores
{
    float tipoCombustible[3];
}; // HAY 3 DESPACHADORES PARA LOS 3 TIPOS DE COMBUSTIBLE


struct Isla
{
    struct Despachadores despachadorN;
}; // UNA ISLA TIENE DESPACHADORES

struct Semana
{
    char dia[12];
    struct Isla islaN[2];

}; //EN LA SEMANA SE DEFINE EL DÍA Y SE GUARDA EL CONSUMO DE LAS DOS ISLAS

typedef struct
{
    struct Semana diaSemana[7];
}Gasolinera; // LA GASOLINERA MIDE SU CONSUMO CADA DIA DE LA SEMANA


void capConsumo(Gasolinera *pgas, int dia){ //SE GUARDA EL CONSUMO DE UN TIPO DE COMBUSTIBLE EN LA ISLA SELECCIONADA
    char *combustible[] = {"Extra", "Supreme", "Diesel"};
    int isla, tipoCombustible;
    float monto;
    printf("Ingrese la isla actual(1 o 2): ");
    scanf("%d", &isla);
    // SE LEE EL TIPO DE COMBUSTIBLE A CAPTURAR, SOLO PUEDE INGRESAR 1, 2 O 3
    printf("\nUsted esta en la isla %d\n", isla);
    printf("\nTipos de combustible: \n1. Extra\n2. Supreme\n3. Diesel\n ");
    printf("Seleccione el tipo de combustible a capturar: ");
    scanf("%d", &tipoCombustible); // SE LEE EL TIPO DE COMBUSTIBLE SEGUN EL MENU
    printf("\nIngrese monto de la venta en la ISLA %d del COMBUSIBLE en LITROS: ", isla); //SE LEE EL MONTO EN LITROS DEL DESPACHADOR SELECCIONADO
    scanf("%f", &monto);
    //SE RESTA EL MONTO INGRESADO AL MONTO ACTUAL DEL DESPACHADOR ( 5000(o restante) - MONTO)
    pgas->diaSemana[dia].islaN[isla-1].despachadorN.tipoCombustible[tipoCombustible-1] = pgas->diaSemana[dia].islaN[isla-1].despachadorN.tipoCombustible[tipoCombustible-1] - monto;;
}

void reporteConsumoPorDia(Gasolinera gas){

    int dia;
    printf("1. Domingo\n 2. Lunes\n3. Martes\n4. Miercoles\n 5. Jueves\n 6. Viernes\n 7. Sabado\n");
    printf("Ingrese el dia de la semana a imprimir: ");
    scanf("%d", &dia);

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%s || Isla: %d || Despachador: %d ||  Monto Consumido %.2f L \n", gas.diaSemana[dia-1].dia, i+1, j+1, 5000 - gas.diaSemana[dia-1].islaN[i].despachadorN.tipoCombustible[j]);
        }
        printf("\n");
    }

}

void reporteConsumoPorComb(Gasolinera gas){
    int tipoCombustible;
    float montoConsumido[2];
    char *combustible[] = {"Extra", "Supreme", "Diesel"};

    printf("\nTipos de combustible: \n1. Extra\n2. Supreme\n3. Diesel\n");
    printf("\nIngrese el tipo de combustible para reportar su consumo: ");
    scanf("%d", &tipoCombustible);

    for ( i = 0; i < 7; i++)
    {
        for ( j = 0; j < 2; j++)
        {
            montoConsumido[j] = montoConsumido[j] + (5000 - gas.diaSemana[i].islaN[j].despachadorN.tipoCombustible[tipoCombustible-1]);
        }

    }

    for (i = 0; i < 2; i++)
    {
        printf("Isla: %d || Despachador: %d || Tipo de Combustible: %s || Monto Consumido: %.2f",
         i+1, tipoCombustible, combustible[tipoCombustible-1], montoConsumido[i]);
        printf("\n");
    }

}


int selecDiaSemana(Gasolinera gas){
    int dia;
    printf("1. Domingo\n 2. Lunes\n3. Martes\n4. Miercoles\n 5. Jueves\n 6. Viernes\n 7. Sabado\n");
    printf("\n Ingrese el dia para el sistema:  \n");
    scanf("%d",&dia);

    dia=dia-1;
    return dia;

}

int reinicioApp(Gasolinera gas){
    int dia;
    dia = 0;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 2; j++)
        {
            montoConsumido[j]=0;
            for (k = 0; k < 3; k++)
            {
                gas.diaSemana[i].islaN[j].despachadorN.tipoCombustible[k] = 5000;
                //SE INICIALIZAN LOS 3 DESPACHADORES DE LAS 2 ISLAS EN LOS 7 DÍAS EN 5000 LITROS
            }
        }
    }
    return dia;
}

void main()
{
    Gasolinera *pgas, gas = {
        .diaSemana[0].dia = "Domingo\0",
        .diaSemana[1].dia = "Lunes\0",
        .diaSemana[2].dia = "Martes\0",
        .diaSemana[3].dia = "Miercoles\0",
        .diaSemana[4].dia = "Jueves\0",
        .diaSemana[5].dia = "Viernes\0",
        .diaSemana[6].dia = "Sabado\0",
    };
    pgas = &gas;

    int dia = 0, opc; // EL PRIMER DIA DE LA SEMANA ES EL DOMINGO EN EL ARREGLO ES 0

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 3; k++)
            {
                gas.diaSemana[i].islaN[j].despachadorN.tipoCombustible[k] = 5000;
                //SE INICIALIZAN LOS 3 DESPACHADORES DE LAS 2 ISLAS EN LOS 7 DÍAS EN 5000 LITROS
            }
        }
    }

    do
    {
        printf("DIA DE LA SEMANA: %s", gas.diaSemana[dia].dia);
        printf("\n------------------\n");
        printf("1.Captura de Consumo\n");
        printf("2.Reporte de Consumo por dia\n");
        printf("3.Reporte de Consumo por Combustible\n");
        printf("4.Seleccion de dia de la semana\n");
        printf("5.Reinicio de Aplicacion\n");
        printf("6.Salir\n");
        printf("\nIngrese la opcion que desea ejecutar: ");

        scanf("%d",&opc);
        switch(opc){
        case 1:
            printf("\n-----Captura de Consumo-----\n");
            capConsumo(pgas, dia);
            break;
        case 2:
            printf("\n-----Reporte de Consumo por dia-----\n");
            reporteConsumoPorDia(gas);
            break;
        case 3:
            printf("\n-----Reporte de Consumo por Combustible-----\n");
            reporteConsumoPorComb(gas);
            break;
        case 4:
            printf("\n-----Seleccion de dia de la semana-----\n");
            dia = selecDiaSemana(gas);
            break;
        case 5:
            printf("\n-----Reinicio de aplicacion-----\n");
            dia = reinicioApp(gas);
            break;
        case 6:
            printf("\n-----Saliendo-----\n");

        }
    } while (opc != 6);
     system("pause");




}
