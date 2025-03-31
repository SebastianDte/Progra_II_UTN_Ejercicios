// Guía de Ejercicios de Memoria Dinámica
/*
Crear un programa que contenga un menú con las siguientes opciones:
1- Cargar Vector: El programa debe solicitar al usuario la cantidad de elementos que va a cargar,
 posteriormente se solicitara cuales son dichos números para almacenarlos en un vector utilizando asignación dinámica de memoria.
2- Mostrar Vector: En caso de tener cargado el vector, debe mostrarlo por pantalla.
3- Salir: Sale del programa (no olvidar liberar la memoria)
Pista: Recordar que se puede inicializar un puntero con el valor nullptr
*/
#include <iostream>
#include "funciones.h"
using namespace std;

int main()
{
    int opcion;
    int *vec = nullptr;
    int numeroElementos;

    mostrarMenu(opcion, vec, numeroElementos);

    delete []vec;
    vec = nullptr;
    return 0;
}
