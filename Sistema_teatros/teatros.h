#ifndef TEATROS_H_INCLUDED
#define TEATROS_H_INCLUDED

//----Estructura----
struct TeatroA;

typedef struct TeatroA * Teatro;

//---Funciones---

//Pre: No se pide ningun parametro
//Post: Se devuelve un teatro particular con basura absurda
Teatro teatrosVacios();

//Pre: Se pide el array de teatros y la cantidad establecida en el main
//Post: Todos los teatros terminan siendo establecidos con basura absurda
void iniciarLosTeatros(Teatro t[], int cant);

//Pre: Se pide el array de teatros y la cantidad establecida en el main
//Post: Se devuelve la posicion libre (marcada con el -1 en el identificador)
int buscarPosicion(Teatro t[], int cant);

//Pre: Se pide el array de teatros, la cantidad de los mismos, y los parametros para constuir los teatros
//Post: Se construye el teatro
void agregarTeatro(Teatro t[], int cant, int id, char n[20], char d[30], int c);

//Pre: Se piden los parametros para construir el teatro
//Post: Se devuelve el teatro construido
Teatro construirTeatro(int id, char n[20], char d[30], int c);

//Pre: Se pide el array de teatros y la cantidad de estos
//Post: Se muestran los teatros actuales
void mostrarTeatros(Teatro t[], int cant);

//Pre: Se pide el teatro particular a mostrar
//Post: Se muestra ese teatro
void mostrarTeatroParticular(Teatro p);

//Pre: Se pide el array de teatros, la cantidad de estos, y el identificador del teatro que se necesita
//Post: Se devuelve la posicion del teatro buscado
int busquedaTeatro(Teatro t[], int cant, int idBuscada);

//Pre: Se pide el array de teatros, su cantidad, y el identificador del teatro a demoler
//Post: Se borra el teatro especificado
void eliminarTeatro(Teatro t[], int cant, int id);

//Pre: Se pide el array de teatros y la cantidad de estos (Escribi esto mil veces, ya se. Disculpe)
//Post: Se guardan los datos en un archivo y se libera la memoria usada
void guardarTeatros(Teatro t[], int cant);

//Pre: Se recibe un teatro a destruir
//Post: Se destruye el teatro
void destructorDeTeatroParticular(Teatro t);

//Pre: Se pide el array de teatros y la cantidad de los mismos
//Post: Se libera la memoria de todos los teatros
void destructorDeTeatros(Teatro t[], int cant);

#endif // TEATROS_H_INCLUDED
