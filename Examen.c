#include <stdio.h>
#include <stdlib.h>

#define Nombre 50
#define Materia 50

typedef struct
{
    char nombre[Nombre];
    char materia[Materia];
    float nota1;
    float nota2;
    float nota3;
} Estudiante;
void G_estudiante(Estudiante estudiante, int numero)
{
    FILE *archivo;
    archivo = fopen("estudiantes.txt", "a");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "%d;%s;%s;%.2f;%.2f;%.2f\n", numero, estudiante.nombre, estudiante.materia, estudiante.nota1, estudiante.nota2, estudiante.nota3);

    fclose(archivo);
}
void C_estudiante()
{
    FILE *archivo;
    archivo = fopen("estudiantes.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    Estudiante estudiante;
    int numero = 1;
    while (fscanf(archivo, "%*[^;];%[^;];%[^;];%f;%f;%f\n", estudiante.nombre, estudiante.materia, &estudiante.nota1, &estudiante.nota2, &estudiante.nota3) == 5)
    {
        printf("%d;%s;%s;%.2f;%.2f;%.2f\n", numero, estudiante.nombre, estudiante.materia, estudiante.nota1, estudiante.nota2, estudiante.nota3);
        numero++;
    }

    fclose(archivo);
}
