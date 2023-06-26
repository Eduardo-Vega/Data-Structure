#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char nombre[31];
    char apellidos[31];
    float promedio;
    char genero;
}alumno;

int i, n;

void ImpAlumno(alumno *alu){
    printf("\n\n Impreson Alumnos");
    printf("\n --------------------------------------------------------------");
    for (i = 0; i < n; i++)
    {
        printf("\n %d | %d | %s %s \t | %.2f | %c", i+1, alu[i].matricula, alu[i].nombre,
                                                    alu[i].apellidos, alu[i].promedio, alu[i].genero);
    }
    printf("\n");
}

void LeerAlumno(alumno *alu){
    printf("\n.......................................................................................");
    for ( i = 0; i < n; i++)
    {
        printf("\n\nDatos del alumno %d", i+1);
        printf("\n.......................................................................................");
        printf("\n              Matricula: ");
        scanf("%d", &alu[i].matricula);
        fflush(stdin);
        printf("                Nombre: ");
        gets(alu[i].nombre);
        printf("                Apellido: ");
        gets(alu[i].apellidos);
        printf("\n              Promedio: ");
        scanf("%f", &alu[i].promedio);
        fflush(stdin);
        printf("                Genero(F/M): ");
        alu[i].genero = getchar();
    }
    printf("\n");
}



void main(){
    printf("\n      Conjunto de Estructuras         ");
    printf("\n -------------------------------------");
    printf("\n Cunatos alumnos desea: ");
    scanf("%d", &n);

    alumno *palumno;
    // palumno = (alumno *)malloc(10*sizeof(alumno));
    palumno = (alumno *)malloc(10*sizeof(alumno));

    // LeerAlumno(palumno);
    // ImpAlumno(palumno);

    
    free(palumno);
    printf("\n\n");
    system("pause");

}