#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* NombreCompleto;
    int creditos_aprobados;
    int semestre;
} alumno;

typedef alumno* alumnoptr;

typedef struct nodo {
    alumnoptr alumno;
    struct nodo* enlace;
} nodo;

typedef nodo* nodoptr;

alumnoptr crearAlumno(char*, int, int);
void imprimirAlumno(alumnoptr);
nodoptr crearNodo(alumnoptr);
void insertarNodoOrdenadoCreditos(nodoptr*, nodoptr);
void imprimirLista(nodoptr*);

int main(){
    nodoptr cabecera = NULL;

    alumnoptr alumno1 = crearAlumno("Josueh", 35, 6);
    alumnoptr alumno2 = crearAlumno("Ricardo", 20, 3);
    alumnoptr alumno3 = crearAlumno("Deco", 25, 8);
    alumnoptr alumno4 = crearAlumno("Andrea", 40, 2);
    alumnoptr alumno5 = crearAlumno("Mariano", 38, 9);

    puts("");

    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(alumno1));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(alumno2));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(alumno3));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(alumno4));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(alumno5));

    puts("");

    imprimirLista(&cabecera);

    return 0;
}

alumnoptr crearAlumno(char* NombreCompleto, int creditos_aprobados, int semestre){
    alumnoptr nuevo;

    nuevo = (alumnoptr)malloc(sizeof(alumno));
    nuevo -> NombreCompleto = strdup(NombreCompleto);
    nuevo -> creditos_aprobados = creditos_aprobados;
    nuevo -> semestre = semestre;

    printf("Se ha creado una estructura Alumno en la dirección %p\n", nuevo);

    return nuevo;
};

nodoptr crearNodo(alumnoptr alumno){
    nodoptr nuevo;

    nuevo = (nodoptr)malloc(sizeof(nodo));
    nuevo -> alumno = alumno;
    nuevo -> enlace = NULL;

    printf("Se ha creado un nodo en la lista de Alumnos en %p\n", nuevo);

    return nuevo;
};

void insertarNodoOrdenadoCreditos(nodoptr* cabecera, nodoptr nuevo){
    nodoptr anterior = NULL;
    nodoptr actual = *cabecera;

    if(*cabecera == NULL){      // Si la lista está vacía
        *cabecera = nuevo;
    }
    else {
        while(actual != NULL && ((nuevo -> alumno -> creditos_aprobados) < (actual -> alumno -> creditos_aprobados))){
            anterior = actual;
            actual = actual -> enlace;
        }

        if(anterior == NULL){       // Si es el primer elemento
        nuevo -> enlace = *cabecera;
        *cabecera = nuevo;         //(???)
        }  
        else {      // Si está en medio o al final
            anterior -> enlace = nuevo;
            nuevo -> enlace = actual;
        }
    }
};

void imprimirAlumno(alumnoptr alumno){
    printf("Nombre completo: %s\n", alumno -> NombreCompleto);
    printf("Créditos aprobados: %d\n", alumno -> creditos_aprobados);
    printf("Semestre: %d\n\n", alumno -> semestre);
};

void imprimirLista(nodoptr* cabecera){
    nodoptr actual = *cabecera;

    if(actual == NULL){
        printf("Lista de alumnos vacía.\n\n");
    }
    else {
        printf("Lista de alumnos:\n\n");
        while(actual != NULL){
            imprimirAlumno(actual -> alumno);
            actual = actual -> enlace;
        }
    }
};