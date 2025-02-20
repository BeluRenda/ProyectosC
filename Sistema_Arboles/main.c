#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanio 100

struct Arbol{
    char especie[20];
    int edad;
    float altura;
};

void cargarArbol(struct Arbol vec[],char esp[20],int age,float alt);
void mostrarArbol(struct Arbol variableArbol);
void mostrarArboles(struct Arbol vec[],int tam);
struct Arbol vaciarArboles(struct Arbol vec[],int tam);
struct Arbol eliminarArbol(struct Arbol vec[],int tam,char especieBuscada[]);
void modificarArbol(struct Arbol vec[],int tam,char especieBuscada[]);
struct Arbol charAArbol(char c[], int n);
void agregarArbol(struct Arbol v[], int n, struct Arbol m);
int busquedaArbol(struct Arbol vec[],int tam,char especieBuscada[]);
void cargarAbolTXT(struct Arbol v[], int n);

int main() {

    struct Arbol vector[tamanio];

    cargarAbolTXT(vector,tamanio);
    cargarArbol(vector,"Laurel",210,2.55);
    cargarArbol(vector,"Secuoya Caucho",150,1.99);
    cargarArbol(vector,"Gikgo biloba",90,1.88);
    mostrarArboles(vector,tamanio);
    modificarArbol(vector,tamanio,"Laurel");
    system("cls");

    printf("\n\n-----------2da muestra----------\n\n");
    mostrarArboles(vector,tamanio);
    eliminarArbol(vector,tamanio,"Cocotero");
    eliminarArbol(vector,tamanio,"Falsa Acacia");

    printf("\n\n-----------FINAL----------\n\n");
    mostrarArboles(vector,tamanio);

    vaciarArboles(vector,tamanio);

return 0;
}

void cargarArbol(struct Arbol vec[],char esp[20],int age,float alt){
    struct Arbol nuevoArbol;
    strcpy(nuevoArbol.especie,esp);
    nuevoArbol.edad=age;
    nuevoArbol.altura=alt;
    agregarArbol(vec,tamanio,nuevoArbol);
}

void mostrarArbol(struct Arbol variableArbol){
    printf ("\n--------------ARBOL---------------\n");
    printf("\n ESPECIE:%s \n EDAD:%d \n ALTURA:%f",variableArbol.especie,variableArbol.edad,variableArbol.altura);
}

void mostrarArboles(struct Arbol vec[],int tam){
    for(int i=0;i<tam;i++){
        if(vec[i].edad!=-1 ){
            mostrarArbol(vec[i]);
        }
    }
}

struct Arbol vaciarArboles(struct Arbol vec[],int tam){
    struct Arbol resultado;

    for (int i;i<tam;i++){
        vec[i].edad=-1;
    }
    return resultado;
};

int busquedaArbol(struct Arbol vec[],int tam,char especieBuscada[]){
  int resultado=-1;

  for(int i=0;i<tam;i++){
    if((strcmp(especieBuscada,vec[i].especie))==0){
        resultado=i;
    }
  }
return resultado;
}

void modificarArbol(struct Arbol vec[],int tam,char especieBuscada[]){
      int aux;
      float aux1;
      int i= busquedaArbol(vec,tam,especieBuscada);
        printf("\nINGRESE LA NUEVA ALTURA\n");
        scanf("%f",&aux1);
        printf("\nINGRESE LA NUEVA EDAD\n");
        scanf("%d",&aux);
        vec[i].edad=aux;
        vec[i].altura=aux1;

}

struct Arbol eliminarArbol(struct Arbol vec[],int tam,char especieBuscada[]){
    int i=busquedaArbol(vec,tam,especieBuscada);
    if(i!=-1){
        vec[i].edad=-1;
    }
    return vec[i];
}

struct Arbol charAArbol(char c[], int n){
    int pos1 = -1;
    int pos2 = -1;
    char auxEspecie[40]=" ";
    char auxEdad[40]=" ";
    char auxAltura[40]=" ";
    struct Arbol v;

    for ( int i = 0; i<n; i++){
        if(c[i]=='+'){
            pos1 = i;
            i = n;
        }
    }
     for ( int i = pos1+1; i<n; i++){
        if(c[i]=='+'){
            pos2 = i;
        }
    }
    for ( int i = 0; i<pos1; i++){
        auxEspecie[i]= c[i];
    }
    for ( int i = pos1+1; i<pos2; i++){
        auxEdad[i-pos1-1]= c[i];
    }
     for ( int i = pos2+1; i<n; i++){
        auxAltura[i-pos2-1]= c[i];
    }
    strcpy(v.especie, auxEspecie);
    v.edad = atoi(auxEdad);
    v.altura = atof(auxAltura);
    return v;
};

void cargarAbolTXT(struct Arbol v[], int n){
    vaciarArboles(v,n);
    FILE * puntero = fopen("arboles.txt", "r");

    while(!feof(puntero)){
        char aux[40] = " ";
        fgets(aux, 40, puntero);
        struct Arbol m = charAArbol(aux, 40);
        agregarArbol(v,n,m);
    }
    fclose(puntero);
}

int buscarPosicionDisponible(struct Arbol v[], int n){
    int posicion = -9;
    int i = 0;

    while(posicion==-9&&i<n){
        if(v[i].edad==-1){
            posicion = i;
        }
        i++;
    }
    return posicion;
}

void agregarArbol(struct Arbol v[], int n, struct Arbol m){
    int i = buscarPosicionDisponible(v,  n);

    if(i!=-9){
        v[i] = m;
    }else{
    printf("\nYa no hay espacio para agregar!!!\n");
    }
}

void guardarArbol(struct Arbol v[], int n){
    FILE * puntero = fopen("arboles.txt", "w");

    for ( int i = 0; i<n; i++){
        if(v[i].edad!=-1){
            fprintf(puntero, "%s;%d;%f\n", v[i].especie, v[i].edad, v[i].altura);
        }
    }
    fclose(puntero);
}
