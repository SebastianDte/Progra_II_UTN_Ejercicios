// Guía de Ejercicios de Memoria Dinámica
/*
Escribe un programa que solicite al usuario el tamaño de un array de enteros, lo cree dinámicamente utilizando new,
el usuario debe poder cargar el array y mostrarlo, y luego libere la memoria con delete

*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "funciones.h"
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int *vec = nullptr, numElementos;

    cargarVector(vec, numElementos);
    system("cls");
    mostrarVector(vec, numElementos);

    delete []vec;
    return 0;
}
