#include <stdio.h>
#include <stdlib.h>

/******************************************************************
 Descripción:
        Se almacenan hasta 100 pacientes de un hospital, se calcula el porcentaje de 
        Hombres y Mujeres, La cantidad de pacientes divididos por su estado de gravedad 
        entre 1 y 5, y la información de los pacientes con un grado de máxima gravedad
        se imprime, en específico nombre y telefono.
********************************************************************/

struct Domicilio
{
    char calle[51];
    int numero;
    char colonia[51];
    char cp[6];
    char ciudad[51];
};

struct Paciente
{
    char nombre[51];
    int edad;
    char sexo;
    int condicion;
    char telefono[12];
    struct Domicilio domicilio;
};

typedef struct
{
    struct Paciente pacientes[100];
}Hospital;



void main()
{
    int n, i, j;
    float porcentaje = 0;
    int cant[5] = {0};
    Hospital hosp;

    printf("\nCANTIDAD DE PACIENTES: \n");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        printf("\nNOMBRE DEL PACIENTE: \n");
        fflush(stdin);
        gets(hosp.pacientes[i].nombre);
        printf("EDAD DEL PACIENTE: \n");
        scanf("%d", &hosp.pacientes[i].edad);
        printf("SEXO DEL PACIENTE (H o M): \n");
        fflush(stdin);
        hosp.pacientes[i].sexo = getchar();
        if (hosp.pacientes[i].sexo == 'H')
        {
            porcentaje++;
        }
        printf("CONDICION DEL PACIENTE (1 a 5, 5 es ingreso de maxima gravedad): \n");
        scanf("%d", &hosp.pacientes[i].condicion);
        cant[hosp.pacientes[i].condicion-1] = cant[hosp.pacientes[i].condicion-1] + 1;
        printf("TELEFONO DEL PACIENTE: \n");
        fflush(stdin);
        gets(hosp.pacientes[i].telefono);
        printf("--DOMICILIO DEL PACIENTE-- \n");
        printf("Calle: ");
        gets(hosp.pacientes[i].domicilio.calle);
        printf("Numero: ");
        scanf("%d", &hosp.pacientes[i].domicilio.numero);
        printf("Colonia: ");
        fflush(stdin);
        gets(hosp.pacientes[i].domicilio.colonia);
        printf("Codigo Postal: ");
        gets(hosp.pacientes[i].domicilio.cp);
        printf("Ciudad: ");
        gets(hosp.pacientes[i].domicilio.ciudad);
    }

    porcentaje = porcentaje / n;
    printf("\n\n--- Porcentaje de Hombres y Mujeres --- ");
    printf("\nHombres = %.2f \nMujeres = %.2f ", porcentaje*100, (1 - porcentaje)*100);
    

    printf("\n\n--- Cantidad de pacientes por condicion --- ");
    printf("\nCondicion\t1\t2\t3\t4\t5 \n");
    printf("\t  ");
    for (i = 0; i < 5; i++)
    {
        printf("\t%d", cant[i]);
    }

    printf("\n\n--- PACIENTES CON UNA CONDICION DE MAXIMA GRAVEDAD --- ");
    printf("\n\tNOMBRE\t\t\t\t\tTELEFONO\n");
    for (i = 0; i < n; i++)
    {
        if (hosp.pacientes[i].condicion == 5)
        {
            printf("\t%s\t\t\t%s \n", hosp.pacientes[i].nombre, hosp.pacientes[i].telefono);
        }        
    }
    
    
    system("PAUSE");
}