#ifndef EJEMPLO_H_INCLUDED
#define EJEMPLO_H_INCLUDED


struct EjemploE;

typedef struct EjemploE * Ejemplo;

Ejemplo cargarEjemplo();


void mostrarEjemplo(Ejemplo e);

int* getVector(Ejemplo e);
int* getMatriz(Ejemplo e);


#endif // EJEMPLO_H_INCLUDED
