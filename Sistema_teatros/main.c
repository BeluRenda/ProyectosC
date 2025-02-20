#include <stdlib.h>
#include <string.h>
#include "teatros.c"
#include "teatros.h"

int main()
{

    int cantidad = 10;

    Teatro teatros[cantidad];

    iniciarLosTeatros(teatros, cantidad);

    //Agrego 4 teatros

    agregarTeatro(teatros, cantidad, 1111, "Colon", "Tucuman 1171", 9500);
    agregarTeatro(teatros,cantidad, 2222, "Gran Rex", "Av. Corrientes 857", 4500);
    agregarTeatro(teatros,cantidad, 3333, "Luna Park", "Av. Madero 420", 7000);
    agregarTeatro(teatros,cantidad, 4444, "Astros", "Av. Corrientes 750", 3000);

    //Muestro los teatros

    printf("\n-------LUEGO DE AGREGAR----------\n");
    mostrarTeatros(teatros, cantidad);

    //Elimino un teatro

    eliminarTeatro(teatros, cantidad, 2222);

    //Vuelvo a mostrar los teatros

    printf("\n-------LUEGO DE ELIMINAR----------\n");
    mostrarTeatros(teatros, cantidad);

    //Agrego un nuevo teatro y vuelvo a mostrar

    agregarTeatro(teatros, cantidad, 5555, "Espacio Abierto", "Carabelas 255", 13000);

    printf("\n-------LUEGO DE AGREGAR OTRO----------\n");
    mostrarTeatros(teatros, cantidad);

    //Guarda los teatros en un archivo teatros.txt
    guardarTeatros(teatros, cantidad);

    return 0;
}
