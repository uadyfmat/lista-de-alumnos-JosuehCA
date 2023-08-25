#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* NombreCompleto;
    int creditos_aprobados;
    int semestre;
} alumno;

typedef struct nodo {
    alumno* alumno;
    struct nodo* enlace;
} nodo;

typedef nodo* nodoptr;
typedef alumno* alumnoptr;

alumnoptr crearAlumno(char*, int, int);
void imprimirAlumno(alumnoptr);
nodoptr crearNodo(alumnoptr);
void insertarNodoOrdenadoCreditos(nodoptr*, alumnoptr);
void imprimirLista(nodoptr*);

int main(){


    return 0;
}

alumnoptr crearAlumno(char* NombreCompleto, int creditos_aprobados, int semestre){
    alumnoptr nuevo;

    nuevo = (alumnoptr)malloc(sizeof(alumno));
    nuevo -> NombreCompleto = strdup(NombreCompleto);
    nuevo -> creditos_aprobados = creditos_aprobados;
    nuevo -> semestre = semestre;

    return nuevo;
};

nodoptr crearNodo(alumnoptr alumno){
    nodoptr nuevo;

    nuevo -> alumno = alumno;
    nuevo -> enlace = NULL;

    return nuevo;
};

void insertarNodoOrdenadoCreditos(nodoptr* cabecera, alumnoptr nuevo){
    nodoptr actual = *cabecera;

    while(actual != NULL){
        
    }
};

void imprimirAlumno(alumnoptr alumno){
    printf("Nombre completo: %s\n", alumno -> NombreCompleto);
    printf("Créditos aprobados: %d\n", alumno -> creditos_aprobados);
    printf("Semestre: %d\n", alumno -> semestre);
};

void imprimirLista(nodoptr* cabecera){
    nodoptr actual = *cabecera;

    if(actual == NULL){
        printf("Lista de alumnos vacía.\n");
    }
    else {
        while(actual != NULL){
            printf("Lista de alumnos:\n");
            imprimirAlumno(actual -> alumno);
            actual = actual -> enlace;
        }
    }
};