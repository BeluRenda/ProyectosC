#include <stdio.h>
#include <stdlib.h>
#include "ejemplo.h"

int main()
{
    Ejemplo e1 = cargarEjemplo();

    mostrarEjemplo(e1);

    //Recorro el vector con el get:
    printf("\n\nRecorro el vector con el get!\n");
    for( int i = 0 ; i<5; i++){
        printf("-----> %d\n", getVector(e1)[i]);
    }

    //La matriz se accede con posiciones consecutivas
    //Esto se puede mejorar con int* getMatrizColuma1(Ejemple e){ return e->matriz[1]}
    //En el peor de los casos se puede definir en el .h a la matriz y listo, se evita el get.

    printf("\n\nRecorro la  matriz con el get\n");
    for( int i = 0 ; i<(4*3)-1; i++){
        printf("-----> %d\n", getMatriz(e1)[i]);
    }
    return 0;
}
