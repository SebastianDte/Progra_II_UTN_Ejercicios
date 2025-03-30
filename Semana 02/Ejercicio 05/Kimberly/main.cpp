// Guía de Ejercicios de Memoria Dinámica
/*
Hacer una función que reciba un vector de enteros y su tamaño y luego muestre el vector ordenado de forma ascendente,
tener en cuenta que el vector enviado como argumento no debe ser modificado.
*/
#include <iostream>
using namespace std;

int* ordenarVector(int* vec, int numeroElementos); // retorna un puntero usando memoria dinamica
void reservarMemoria(int* &vec, int numeroElementos);
void cargarVector(int* &vec, int &numeroElementos);
void mostrarVectorOrdenado(int* vec, int numeroElementos);

int main()
{
    int* vec = nullptr;
    int numeroElementos;

    cargarVector(vec, numeroElementos);

    int* vectorOrdenado = ordenarVector(vec, numeroElementos);

    mostrarVectorOrdenado(vectorOrdenado, numeroElementos);


    delete []vec;
    delete []vectorOrdenado;
    vec = nullptr;

    vectorOrdenado = nullptr;

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

int* ordenarVector(int* vec, int numeroElementos)
{
    int aux;
    int* vecAux = nullptr;

    reservarMemoria(vecAux, numeroElementos);

    for (int i = 0; i < numeroElementos; ++i)
    {
        vecAux[i] = vec[i];
    }

    for (int i = 0; i < numeroElementos - 1; ++i)
    {
        //cout << "Posicion de i: " << i << " Valor de i: " << vecAux[i] << endl;

        for (int j = i + 1; j < numeroElementos; ++j)
        {
            //cout << "Posicion de j: " << j << " Valor de j: " << vecAux[j] << endl;

            if((vecAux[i] > vecAux[j]))
            {
                aux = vecAux[i];
                vecAux[i] = vecAux[j];
                vecAux[j] = aux;
            }
        }
    }

    return vecAux;
}


void mostrarVectorOrdenado(int* vec, int numeroElementos)
{
    cout << "=======VECTOR ORDENADO=======" << endl;
    for(int i = 0; i < numeroElementos; ++i)
    {
        cout << vec[i] << endl;
    }
}
