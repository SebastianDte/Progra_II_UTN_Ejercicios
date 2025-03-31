#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
using namespace std;

void mostrarMenu(int &opcion, int* &vec, int &numeroElementos); // aqui paso por referencia mi puntero porqu evoy a modificarlo en otras funciones
void cargarVector(int* &vec, int &numeroElementos);
void reservarMemoria(int* &vec, int numeroElementos);
void mostrarVector(int* vec, int numeroElementos);


#endif // FUNCIONES_H_INCLUDED
