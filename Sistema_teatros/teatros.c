#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teatros.h"

//---Cuerpo de la struct---

struct TeatroA{

    int identificador;
    char nombre[20];
    char direccion[30];
    int capacidad;
};

//---Funciones---

void iniciarLosTeatros(Teatro t[], int cant){

    for (int i = 0; i < cant; i++){
         t[i] = teatrosVacios();
    }

}

Teatro teatrosVacios(){

    Teatro tv = malloc(sizeof(struct TeatroA));

    char aux[40] = "XXX";

    tv -> identificador = -1;
    strcpy(tv -> nombre, aux);
    strcpy(tv -> direccion, aux);
    tv -> capacidad = -1;

    return tv;
}

int buscarPosicion(Teatro t[], int cant){

    int pos = -9;
    int i = 0;

    while(pos == -9 && i < cant){
        if(t[i] -> identificador == -1){
            pos = i;
        }
        i++;
    }

    return pos;

}

void agregarTeatro(Teatro t[], int cant, int id, char n[20], char d[30], int c){

    int i = buscarPosicion(t, cant);

    //printf("\nLa posicion encontrada para el %s es: %d\n", n, i);

    t[i] = construirTeatro(id, n, d, c);

}

Teatro construirTeatro(int id, char n[20], char d[30], int c){

    Teatro tn = malloc(sizeof(struct TeatroA));

    tn -> identificador = id;
    strcpy(tn -> nombre, n);
    strcpy(tn -> direccion, d);
    tn -> capacidad = c;

    return tn;
}

void mostrarTeatros(Teatro t[], int cant){

    for (int i = 0; i < cant; i++){
        if (t[i] -> identificador != -1){
            mostrarTeatroParticular(t[i]);
        }
    }
}

void mostrarTeatroParticular(Teatro p){

    printf("----> Identificador: %d, Nombre: %s, Direccion: %s, Capacidad: %d\n", p -> identificador, p -> nombre, p -> direccion, p -> capacidad);

}

int busquedaTeatro(Teatro t[], int cant, int idBuscada){

    int resultado = -1;
    int comparacion = -10;

    for (int i = 0; i < cant; i++){
        comparacion = t[i] -> identificador;
        if (comparacion == idBuscada){
            resultado = i;
            return resultado;
        }
    }

    return resultado;
}

void eliminarTeatro(Teatro t[], int cant, int id){

    printf("----> ATENCION: Se procede a demoler el teatro con la ideniticacion %d\n", id);

    int i = busquedaTeatro(t, cant, id);

    t[i] -> identificador = -1;

}

void guardarTeatros(Teatro t[], int cant){

    FILE * teatritos = fopen("Teatros.txt", "a");

    for (int i = 0; i < cant; i++){
        if (t[i] -> identificador != -1){
            fprintf(teatritos, "%d+%s+%s+%d\n", t[i] -> identificador, t[i] -> nombre, t[i] -> direccion, t[i] -> capacidad);
        }
    }

    fclose(teatritos);

    destructorDeTeatros(t, cant);
}

void destructorDeTeatroParticular(Teatro t){
    free(t);
}

void destructorDeTeatros(Teatro t[], int cant){

    for (int i = 0; i < cant; i++){
            destructorDeTeatroParticular(t[i]);
    }
}
