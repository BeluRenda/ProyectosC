#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 100

struct TeatroE{

	char nombre[50];
	char dir[50];
	int capacidad;
	int identificador;

};
struct TeatrosE{
	struct TeatroE teatros[100];
	int contarT;

};

struct TeatroE crearTeatroPorParametro(int iden,char n[50],char dire[50],int cap);
void mostrarTeatro(struct TeatroE a);
void mostrarTeatros(struct TeatroE a[],int t);
struct TeatrosE agregarTeatros();
void mostrarAgregados(struct TeatrosE b);
struct TeatrosE agregarTeatro(struct TeatrosE b, struct TeatroE a);
struct TeatrosE eliminarTeatro(struct TeatrosE b, int idenBuscado);
int buscarI(struct TeatroE a[],int t,int idenBuscado);
void GuardarEnArchivo(struct TeatrosE b,int t);
void orderIdenti(struct TeatroE a[],int t);


int main(){

struct TeatrosE t1 = agregarTeatros();

struct TeatroE teatross[CANTIDAD];
int cont=0;
 printf("\nExamen_42778410_Franco_Ponce\n");

// AGREGO 4 TEATROS;
teatross[cont] = crearTeatroPorParametro(1111,"Colon","Tucuman 1171",9500); // cargo un teatro
t1 = agregarTeatro(t1,teatross[cont]); // lo agrego
cont++; // se  cargo un teatro por ende incremento el contador


teatross[cont] = crearTeatroPorParametro(2222,"Gran Rex","Av. Corrientes 875",4500); // cargo un teatro
t1 = agregarTeatro(t1,teatross[cont]); // lo agrego
cont++; // se  cargo un teatro por ende incremento el contador



teatross[cont] = crearTeatroPorParametro(3333,"Luna Park","Av. Madero 420",7000); // cargo un teatro
t1 = agregarTeatro(t1,teatross[cont]); // lo agrego
cont++; // se  cargo un teatro por ende incremento el contador



teatross[cont] = crearTeatroPorParametro(4444,"Astros","Av. Corrientes 750",3000); // cargo un teatro
t1 = agregarTeatro(t1,teatross[cont]); // lo agrego
cont++; // se  cargo un teatro por ende incremento el contador



// MUESTRO LOS 4 TEATROS
printf("\n--------LUEGO DE AGREGAR---------------\n");
mostrarAgregados(t1);

// ELIMINO 1 TEATRO
t1 = eliminarTeatro(t1,2222);

// MUESTRO LOS Teatros
printf("\n--------LUEGO DE ELININAR---------------\n");
mostrarAgregados(t1);

//agrego un nuevo teatro y vuelvo a mostrar
teatross[cont] = crearTeatroPorParametro(5555,"Espacio Abierto","Carabelas 255",13000); // cargo un teatro
t1 = agregarTeatro(t1,teatross[cont]); // lo agrego
cont++; // se  cargo un teatro por ende incremento el contador

printf("\n--------LUEGO DE AGREGAR OTRO---------------\n");
orderIdenti(t1.teatros,CANTIDAD); // esto no hace falta pero bueno, ya que estamos los ordeno tambien
mostrarAgregados(t1);

//guardar en archivo Teatro.txt

GuardarEnArchivo(t1,CANTIDAD);

}

struct TeatrosE agregarTeatros(){

	struct TeatrosE b;

	b.contarT=0;


	for(int i=0;i<CANTIDAD;i++){


		b.teatros[i].identificador = -1;


	}



	return b;


}

void mostrarAgregados(struct TeatrosE b){


mostrarTeatros(b.teatros,CANTIDAD);

}

struct TeatroE crearTeatroPorParametro(int iden,char n[50],char dire[50],int cap){

struct TeatroE a2;

a2.identificador = iden;
strcpy(a2.nombre,n);
strcpy(a2.dir,dire);
a2.capacidad = cap;

return a2;

}

void mostrarTeatro(struct TeatroE a){

 printf("\nCOD: %d   NOMBRE: %s    DIRECCION: %s  CAP: %d \n",a.identificador,a.nombre,a.dir,a.capacidad);

}

void mostrarTeatros(struct TeatroE a[],int t){


     for ( int i = 0; i<t; i++){

        if(a[i].identificador !=-1){
        mostrarTeatro(a[i]);
        }

    }


}

struct TeatrosE agregarTeatro(struct TeatrosE b, struct TeatroE a){

int j = b.contarT;

	b.teatros[j] = a;

	b.contarT++;

return b;

}

struct TeatrosE eliminarTeatro(struct TeatrosE b, int idenBuscado){

int i = buscarI(b.teatros,CANTIDAD,idenBuscado);

	if(i != -1){

		b.teatros[i].identificador = -1;
		orderIdenti(b.teatros,CANTIDAD);
		b.contarT--;
	}

return b;
}

int buscarI(struct TeatroE a[],int t,int idenBuscado){

	int flag = -1;

	for(int i=0;i<t;i++){

		if(a[i].identificador == idenBuscado){
			flag = i;
		}
	}
	return flag;
}

void GuardarEnArchivo(struct TeatrosE b,int t){

 FILE * Teatros = fopen("Teatros.txt","w");

for(int i=0;i<t;i++){

	if(b.teatros[i].identificador != -1){

		fprintf(Teatros,"%d;%s;%s;%d\n",b.teatros[i].identificador,b.teatros[i].nombre,b.teatros[i].dir,b.teatros[i].capacidad);
	}

}

	fclose(Teatros);

}

void orderIdenti(struct TeatroE a[],int t){

struct TeatroE aux;

    for (int i=0;i<t;i++){
        for(int k=0;k<t-1;k++){
            if(a[k].identificador>a[k+1].identificador){
                aux = a[k];
                a[k]=a[k+1];
                a[k+1]=aux;

            }
        }
    }
}
