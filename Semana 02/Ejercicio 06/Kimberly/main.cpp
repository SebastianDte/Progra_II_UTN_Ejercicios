// Guía de Ejercicios de Memoria Dinámica
/*
Escribe un programa que solicite al usuario ingresar una lista de 10 números enteros.
Luego, el programa debe mostrar los números pares distintos que se ingresaron.
Para resolver este ejercicio, deberás implementar una función que reciba un vector de enteros y su tamaño,
y que devuelva un puntero a un vector dinámico que contenga solo los números pares distintos del vector recibido.
*/
#include <iostream>
using namespace std;

void reservarMemoria(int* &vec, int numeroElementos);
void cargarVector(int* &vec, int numeroElementos);
int* vectorParesDistintos(int* vec, int numeroElementos);
void mostrarVector(int* vec, int numeroElementos);
void inicializarVectorDinamico(int* &vec, int numeroElementos);
bool validarSiYaExiste(int numero, int vec[], int numeroElementos);


int main()
{

    int* vec = nullptr;
    const int NUMERO_ELEMENTOS = 10;

    cargarVector(vec, NUMERO_ELEMENTOS);
    int* vectorPares = vectorParesDistintos(vec, NUMERO_ELEMENTOS);
    mostrarVector(vectorPares, NUMERO_ELEMENTOS);

    delete []vec;
    delete []vectorPares;
    vec = nullptr;
    vectorPares = nullptr;

    return 0;
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


void cargarVector(int* &vec, int numeroElementos)
{
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

int* vectorParesDistintos(int* vec, int numeroElementos)
{

    int *vecAuxiliar = nullptr; //para rastrear los valores distintos, inicializo en 0.
    reservarMemoria(vecAuxiliar, numeroElementos);
    inicializarVectorDinamico(vecAuxiliar, numeroElementos);

    int index = 0;

    for (int i = 0; i < numeroElementos; ++i)
    {
       // cout << "Posicion de i: " << i << " Valor de i: " << vec[i] << endl;

        if(vec[i] %2 == 0)
        {
            bool existe = validarSiYaExiste(vec[i], vecAuxiliar, numeroElementos);
            //cout << "Existe el valor de i en vecAuxiliar: " << existe << endl;
            if(!existe)
            {
                vecAuxiliar[index] = vec[i];
                index++;
            }

        }

    }
    return vecAuxiliar;
}

void mostrarVector(int* vec, int numeroElementos)
{
    cout << "=======VECTOR PARES DISTINTOS=======" << endl;
    for(int i = 0; i < numeroElementos; ++i)
    {
        cout << vec[i] << endl;
    }
}
