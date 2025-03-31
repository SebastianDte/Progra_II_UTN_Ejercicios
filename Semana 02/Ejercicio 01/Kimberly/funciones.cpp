#include <iostream>
#include "funciones.h"
using namespace std;

void reservarMemoria(int* &vec, int numeroElementos)
{
    vec = new int[numeroElementos];
    if (vec == nullptr)
    {
        cout << "Error al asignar memoria." << endl;
        exit(1);
    }
}


void cargarVector(int* &vec, int &numeroElementos)
{
    cout << "Ingrese el numero de elementos a cargar: ";
    cin >> numeroElementos;
    system("cls");
    reservarMemoria(vec, numeroElementos);
    cout << "====== CARGA DEL VECTOR ======\n";
    for (int i = 0; i < numeroElementos; ++i)
    {
        cout << "Ingrese el valor para el elemento #" << i + 1 << ": ";
        cin >> vec[i];
    }
    return;
}


void mostrarVector(int* vec, int numeroElementos)
{
    cout << "====== DATOS DEL VECTOR ======\n";
    for(int i = 0; i < numeroElementos; ++i)
    {
        cout << vec[i] << endl;
    }
}
