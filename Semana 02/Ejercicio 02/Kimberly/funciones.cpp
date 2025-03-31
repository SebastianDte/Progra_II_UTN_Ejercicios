#include <iostream>
#include "funciones.h"
using namespace std;

void mostrarMenu(int &opcion, int* &vec, int &numeroElementos)
{
    do
    {
        system("cls");
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Cargar vector\n";
        cout << "2. Mostrar vector\n";
        cout << "3. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case 1:
            cargarVector(vec, numeroElementos);
            break;
        case 2:
            mostrarVector(vec, numeroElementos);
            break;
        case 3:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Intentalo de nuevo.\n";
        }
        cout << "\nPresiona Enter para continuar...";
        cin.ignore();
        cin.get();

    }
    while (opcion != 3);

    cout << "Hasta luego!\n";
}
void reservarMemoria(int* &vec, int numeroElementos)
{
    vec = new int[numeroElementos];
}

void cargarVector(int* &vec, int &numeroElementos)
{
    cout << "Ingrese el numero de elementos a cargar: ";
    cin >> numeroElementos;

    reservarMemoria(vec, numeroElementos);

    if (vec == nullptr)
    {
        cout << "\nNo hay memoria." << endl;
        return; // puedo hacer return para salir de la funcion, no retorno nada.
    }

    for (int i = 0; i < numeroElementos; ++i)
    {
        cout << "Ingrese el valor para el elemento #" << i + 1 << ": ";
        cin >> vec[i];
    }
    return;
}

void mostrarVector(int* vec, int numeroElementos)
{
    cout << "======== ELEMENTOS EN EL VECTOR ========\n";

    if (vec == nullptr)
    {
        cout << "Aun no hay datos cargados.\n";
        return;
    }

    for (int i = 0; i < numeroElementos; ++i)
    {
        cout << "Valor en la posicion #" << i+1 << ": " << vec[i] << endl;
    }
}
