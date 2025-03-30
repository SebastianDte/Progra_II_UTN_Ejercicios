// Guía de Ejercicios de Memoria Dinámica
/*
Hacer un programa que solicite al usuario 10 números y luego muestre primero los números positivos y luego los negativos.
El programa debe crear dos arrays dinámicos con la cantidad exacta en cada caso: uno para almacenar los números positivos y otro para los números negativos.
*/

#include <iostream>
using namespace std;

void mostrarMenu(int &opcion, int* &ptrVecPositivos, int* &ptrVecNegativos, int numeroElementos);
void cargarVector(int* &ptrVecPositivos, int* &ptrVecNegativos, int numeroElementos);
void reservarMemoria(int* &vec, int numeroElementos);
void mostrarVector(int* ptrVecPositivos, int* ptrVecNegativos, int numeroElementos);

void inicializarVectorDinamico(int* &vec, int numeroElementos);
void mostrarElementosVector(int* vec, int numeroElementos);

int main()
{
    int opcion;
    const int NUMERO_ELEMENTOS = 10;
    int *ptrVecPositivos = nullptr, *ptrVecNegativos = nullptr;

    mostrarMenu(opcion, ptrVecPositivos, ptrVecNegativos, NUMERO_ELEMENTOS);

    delete []ptrVecPositivos;
    delete []ptrVecNegativos;

    ptrVecPositivos = nullptr;
    ptrVecNegativos = nullptr;
    return 0;
}


void mostrarMenu(int &opcion, int* &ptrVecPositivos, int* &ptrVecNegativos, int numeroElementos)
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
            cargarVector(ptrVecPositivos, ptrVecNegativos, numeroElementos);
            break;
        case 2:
            mostrarVector(ptrVecPositivos, ptrVecNegativos, numeroElementos);
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
    if (vec == nullptr)
    {
        cout << "Error al asignar memoria." << endl;
        exit(1);
    }
}

void inicializarVectorDinamico(int* &vec, int numeroElementos)
{
    for (int i = 0; i < numeroElementos; ++i)
    {
        vec[i] = 0;
    }
}

void cargarVector(int* &ptrVecPositivos, int* &ptrVecNegativos, int numeroElementos)
{
    reservarMemoria(ptrVecPositivos, numeroElementos);
    reservarMemoria(ptrVecNegativos, numeroElementos);
    inicializarVectorDinamico(ptrVecPositivos, numeroElementos);
    inicializarVectorDinamico(ptrVecNegativos, numeroElementos);

    int numero;
    int indexPos = 0, indexNeg = 0;
    for (int i = 0; i < numeroElementos; ++i)
    {
        cout << "Ingrese el valor para el elemento #" << i + 1 << ": ";
        cin >> numero;

        if (numero < 0)
        {
            ptrVecNegativos[indexNeg++] = numero;
        }
        else
        {
            ptrVecPositivos[indexPos++] = numero;
        }
    }
    return;
}

void mostrarElementosVector(int* vec, int numeroElementos)
{
    for (int i = 0; i < numeroElementos; ++i)
    {
        cout << vec[i] << endl;;
    }
}

void mostrarVector(int* ptrVecPositivos, int* ptrVecNegativos, int numeroElementos)
{
    cout << "======== ELEMENTOS EN EL VECTOR ========\n";

    if (ptrVecPositivos == nullptr && ptrVecNegativos == nullptr)
    {
        cout << "Aun no hay datos cargados.\n";
        return;
    }
    cout << "======== NUMEROS POSITIVOS ========\n";
    mostrarElementosVector(ptrVecPositivos, numeroElementos);

    cout << "======== NUMEROS NEGATIVOS ========\n";
    mostrarElementosVector(ptrVecNegativos, numeroElementos);
}
