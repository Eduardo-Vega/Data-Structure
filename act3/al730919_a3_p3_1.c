#include <stdio.h>
#include <stdlib.h>

/******************************************************************
 Nombre: Ruben Eduardo Vega Mayorga
 Matricula: 730919
 Fecha: 7 de octubre del 2022
 Problema 3.1 Actividad 3
 Descripción:
        Se guarda un arreglo unidimensional de tpo estructura Alumno para 
        determinar Su promedio en la 4ta materia y su promedio general,
        también los alumnos con calificación mayor a 9 en la 3er materia.
********************************************************************/
struct Materias
{
    char mat[51];
};

struct Promedios
{
    float prom;
};

typedef struct
{
    int matricula;
    char nombres[51];
    char apellidos[51];
    struct Materias materia[4];
    struct Promedios promedio[5];

}Alumno;

void main()
{
    int i, j, n;
    float promf = 0.0;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);
    Alumno alu[n];
    for (i = 0; i < n; i++){
        printf("\n\nIngrese la matricula del alumno %d: ", i + 1);
        scanf("%d", &alu[i].matricula);
        fflush(stdin);
        printf("Ingrese los nombres del alumno %d: ", i + 1);
        gets(alu[i].nombres);
        printf("Ingrese los apellidos del alumno %d: ", i + 1);
        gets(alu[i].apellidos);

        for ( j = 0; j < 4; j++)
        {
            printf("\nIngrese el nombre de la materia %d: ", j + 1);
            fflush(stdin);
            gets(alu[i].materia[j].mat);
            printf("Ingrese la calificacion de la materia %s: ", alu[i].materia[j].mat);
            scanf("%f", &alu[i].promedio[j].prom);
            promf = promf + alu[i].promedio[j].prom;
        }
        alu[i].promedio[4].prom = promf / 4;
        promf = 0;
    }
    
    printf("\n\n\t\t ------------------ INFORMACION DE LOS ALUMNOS ------------------");
    printf("\n\n\tMatricula \t\t\t Promedio Materia 4 \t\t\t Promedio General\n");
    for ( i = 0; i < n; i++)
    {
        printf("\t %d \t\t\t\t %.2f \t\t\t\t\t %.2f \n", alu[i].matricula, alu[i].promedio[3].prom, alu[i].promedio[4].prom);
    }
    printf("\n\n\t\t\t   ------ ALUMNOS CON CALIFICACION MAYOR A 9 EN LA MATERIA 3 -------");
    printf("\n\tMatricula\n");
    for ( i = 0; i < n; i++)
    {
        if (alu[i].promedio[2].prom > 9) 
        {
            printf("\t %d \n", alu[i].matricula);
        }
        
    }
    
    printf("\n\n");
    system("PAUSE");
}
