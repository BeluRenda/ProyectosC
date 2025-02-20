#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejemplo.h"


struct EjemploE{
    int vector[5];
    int matriz[3][4];
};


Ejemplo cargarEjemplo(){
    Ejemplo e = malloc(sizeof(struct EjemploE));
    //Cargo el vector con cualquier numero
    //3 4 5 6 7
    for (int i = 0; i<5; i++){
        e->vector[i] = i+3;
    }
    //Cargo la matriz con cualquier numero
    for (int i = 0; i<3; i++){
        for (int j = 0; j<4; j++){
            e->matriz[i][j] = i*j;
        }
    }
    return e;
}


int* getVector(Ejemplo e){
    return e->vector;

}


int* getMatriz(Ejemplo e){
    return e->matriz;
}



void mostrarEjemplo(Ejemplo e){
    printf("\nMuestro el array\n");
    for (int i =0; i<5; i++){
        printf("%d    ", e->vector[i]);
    }

     printf("\n\nMuestro la matriz\n\n");
    for (int i =0; i<3; i++){
            for (int j =0; j<4; j++){
                printf("%d    ", e->matriz[i][j]);
            }
        printf("\n");
    }

}
