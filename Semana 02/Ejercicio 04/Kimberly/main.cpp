// Guía de Ejercicios de Memoria Dinámica
/*
Hacer una función que reciba un vector de enteros y su tamaño y devuelva la cantidad de números distintos 
que se repiten en el vector.
*/

#include <iostream>
using namespace std;

void mostrarMenu(int &opcion, int* &vec, int &numeroElementos);
void cargarVector(int* &vec, int &numeroElementos);
void reservarMemoria(int* &vec, int numeroElementos);
int contarNumerosDistintosRepetidos(int* &vec, int &numeroElementos);
void inicializarVectorDinamico(int* &vec, int numeroElementos);
bool validarSiYaExiste(int numero, int vec[], int numeroElementos);

int main()
{

    int *vec = nullptr;
    int numeroElementos;
    int opcion;

    mostrarMenu(opcion, vec, numeroElementos);

    delete []vec;
    vec = nullptr;

    return 0;
}

void mostrarMenu(int &opcion, int* &vec, int &numeroElementos)
{
    do
    {
        system("cls");
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Cargar vector\n";
        cout << "2. Mostrar numeros distintos repetidos\n";
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
            contarNumerosDistintosRepetidos(vec, numeroElementos);
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

void cargarVector(int* &vec, int &numeroElementos)
{
    cout << "Ingrese el numero de elementos a cargar: ";
    cin >> numeroElementos;

    reservarMemoria(vec, numeroElementos);

    for (int i = 0; i < numeroElementos; ++i)
    {
        cout << "Ingrese el valor para el elemento #" << i + 1 << ": ";
        cin >> vec[i];
    }
    return;

}

void inicializarVectorDinamico(int* &vec, int numeroElementos)
{
    for (int i = 0; i < numeroElementos; ++i)
    {
        vec[i] = 0;
    }
}

bool validarSiYaExiste(int numero, int vec[], int numeroElementos)
{
    bool yaExiste = false;

    for (int i = 0; i < numeroElementos; ++i)
    {
        if (numero == vec[i])
        {
            yaExiste = true;
            break;
        }
    }
    return yaExiste;
}


int contarNumerosDistintosRepetidos(int* &vec, int &numeroElementos)
{
    int *vecAuxiliar = nullptr; //para rastrear los valores distintos, inicializo en 0.
    reservarMemoria(vecAuxiliar, numeroElementos);
    inicializarVectorDinamico(vecAuxiliar, numeroElementos);

    int index = 0;
    int repetidos = 0;

    for (int i = 0; i < numeroElementos; ++i)
    {
        //cout << "Posicion de i: " << i << " Valor de i: " << vec[i] << endl;

        bool existe = validarSiYaExiste(vec[i], vecAuxiliar, numeroElementos);

        //cout << "Existe el valor de i en vecAuxiliar: " << existe << endl;

        for (int j = i + 1; j < numeroElementos; ++j)
        {
            //cout << "Posicion de j: " << j << " Valor de j: " << vec[j] << endl;

            if((vec[i] == vec[j]) && !existe)
            {
                repetidos++;
                vecAuxiliar[index] = vec[i];
                index++;
                break;
            }
        }
    }
    cout << "=======CANTIDAD DE REPETIDOS======="<< endl;
    cout << "La cantidad de repetidos es de: " << repetidos << endl;
    delete []vecAuxiliar;
    vecAuxiliar = nullptr;
    return repetidos;
}
