#include <stdio.h>
#include <stdlib.h>

struct Mercaderia{

    char nombre[20];
    int codigo;
    float precio;


};

//------------------Mercaderia----------------------------
//Pre:Ninguna
//Post:Pide los datos por teclado y retorna una Mecaderia
struct Mercaderia crearMercaderiaPorTeclado();
//Pre: La mercaderia tiene que estar creada
//post: Muestra los datos de la mercaderia
void mostrarMercaderia(struct Mercaderia m);


//------------------Archivo.txt----------------------------
//Pre: El archivo tiene que estar creado con el siguiente formato
//nombre;codigo;precio
//Post: Carga el array v, con las mercaderias que estan en el archivo
void cargarMercaderias(struct Mercaderia v[], int n);
//Pre: El array c[] tiene que tener el formato nombre;codigo;precio
//Post: Transforma ese array en un elemento mercaderia y lo retorna
struct Mercaderia charAMercaderia(char c[], int n);
//Pre: El array v tiene que estar iniciado
//Post: Guarda los datos en el archivo
void guardarMercaderias(struct Mercaderia v[], int n);


//------------------ARRAY de Mercaderia----------------------------
//pre: n debe ser mayor a cero, el array tiene que estar declarado
//post: En cada elemento, marca con precio = -1 los elementos "vacios"
//En esas posiciones se podran guardar nuevos datos
void iniciarMercaderias(struct Mercaderia v[], int n);
//Pre: Se tiene que iniciar la mercaderia inicialmente con precio= -1
//Post: nos devuelve en que posicion podemos escribir una nueva mercaderia
int buscarPosicionDisponible(struct Mercaderia v[], int n);
//Pre: la mercaderia tiene que existir, y el array tiene que estar iniciado correctamente
//post: agrega esa mercaderia a alguna posicion del array
void agregarMercaderia(struct Mercaderia v[], int n, struct Mercaderia m);
//Pre: El array tiene que estar iniciado/cargado
//Post: Muestra por consola el estado de las mercaderias
void mostrarMercaderias(struct Mercaderia v[], int n);


//--------------Para que agreguen y mejoren---------------------
//Modifica solo el precio de la mercaderia con el codigo indicado
void modificarMercaderia(struct Mercaderia v[], int n, int codigo);
void eliminarMercaderia(struct Mercaderia v[], int n, int codigo);
//Crear un menu que nos de las opciones de ver, cargar, modificar, eliminar
//guardar, etc
//en vez de borrar todo el archivo y escribirlo con w, podrian ir
//agregando cada vez que se crea una nueva mercaderia y usar a, generen
//esa modificación




int main()
{
    printf("Ejemplo Integrador ABMs - Archivos\n");

    int cantidad = 100;
    struct Mercaderia mercaderias[cantidad];

    cargarMercaderias(mercaderias, cantidad);
    mostrarMercaderias(mercaderias, cantidad);

    struct Mercaderia m1 = crearMercaderiaPorTeclado();
    struct Mercaderia m2 = crearMercaderiaPorTeclado();

    agregarMercaderia(mercaderias, cantidad, m1);
    agregarMercaderia(mercaderias, cantidad, m2);

    mostrarMercaderias(mercaderias, cantidad);

    guardarMercaderias(mercaderias, cantidad);


    return 0;
}


struct Mercaderia crearMercaderiaPorTeclado(){

    struct Mercaderia m;
    char aux[20]= " ";

    printf("\n\n\nCreando mercaderia Nueva\n") ;
    printf("\nIngrese el nombre:\n") ;
    fflush(stdin);
    gets(aux);
    strcpy(m.nombre, aux);

    printf("Ingrese el precio:\n");
    scanf("%f", &m.precio);

    printf("Ingrese el codigo:\n");
    scanf("%d", &m.codigo);


    printf("\nCreada!!!  :)\n") ;
    system("cls");//borro la consola


    return m;

};

void mostrarMercaderia(struct Mercaderia m){

    printf("\n-----------------------------------------\n");
    printf("Mercaderia: %s -- Codigo: %d -- Precio: $ %.2f",
           m.nombre, m.codigo, m.precio);


}

void iniciarMercaderias(struct Mercaderia v[], int n){

    //inicio el array para que no tenga basura
    for ( int i = 0; i<n; i++){

        v[i].precio = -1;

    }

}

void agregarMercaderia(struct Mercaderia v[], int n, struct Mercaderia m){


    int i = buscarPosicionDisponible(v,  n);

    if(i!=-9){
        v[i] = m;
    }else{
    printf("\nYa no hay espacio para agregar!!!\n");
    }

}

void mostrarMercaderias(struct Mercaderia v[], int n){

    for ( int i = 0; i<n; i++){

        if (v[i].precio!=-1){


            mostrarMercaderia(v[i]);
        }
    }

}

int buscarPosicionDisponible(struct Mercaderia v[], int n){


    int posicion = -9;
    int i = 0;

    while(posicion==-9&&i<n){

        if(v[i].precio==-1){
            posicion = i;
        }

        i++;
    }

    return posicion;

}

void cargarMercaderias(struct Mercaderia v[], int n){

    iniciarMercaderias(v, n);

    FILE * puntero = fopen("archivoMercaderias.txt", "r");

    while(!feof(puntero)){


        char aux[40] = " ";

        fgets(aux, 40, puntero);

        struct Mercaderia m = charAMercaderia(aux, 40);

        agregarMercaderia(v,n,m);

    }

    fclose(puntero);


}

struct Mercaderia charAMercaderia(char c[], int n){

    //El formato es nombre;codigo;precio

    int pos1 = -1;
    int pos2 = -1;



    char auxNombre[40]=" ";
    char auxCodigo[40]=" ";
    char auxPrecio[40]=" ";

    struct Mercaderia m;

    for ( int i = 0; i<n; i++){

        if(c[i]==';'){
            pos1 = i;
            i = n; //Así termino el for
        }
    }

     for ( int i = pos1+1; i<n; i++){

        if(c[i]==';'){
            pos2 = i;
        }
    }




    for ( int i = 0; i<pos1; i++){

        auxNombre[i]= c[i];


    }



    for ( int i = pos1+1; i<pos2; i++){

        auxCodigo[i-pos1-1]= c[i];


    }

     for ( int i = pos2+1; i<n; i++){

        auxPrecio[i-pos2-1]= c[i];


    }

    strcpy(m.nombre, auxNombre);
    m.codigo = atoi(auxCodigo);
    m.precio = atof(auxPrecio);


    return m;

};

void guardarMercaderias(struct Mercaderia v[], int n){


    FILE * puntero = fopen("archivoMercaderias.txt", "w");


    for ( int i = 0; i<n; i++){

        if(v[i].precio!=-1){

            fprintf(puntero, "%s;%d;%f\n", v[i].nombre, v[i].codigo, v[i].precio);

        }

    }


    fclose(puntero);


}
