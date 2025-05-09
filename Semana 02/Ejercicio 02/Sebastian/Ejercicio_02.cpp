#include <iostream>
#include <locale>
using namespace std;

// Crear un programa que contenga un menú con las siguientes opciones:
// 1- Cargar Vector: El programa debe solicitar al usuario la cantidad de elementos que va a cargar, posteriormente se solicitara cuales son dichos números para almacenarlos en un vector utilizando asignación dinámica de memoria.
// 2- Mostrar Vector: En caso de tener cargado el vector, debe mostrarlo por pantalla.
// 3- Salir: Sale del programa (no olvidar liberar la memoria)
// Pista: Recordar que se puede inicializar un puntero con el valor nullptr

void cargarVector(int *&vector, int &cantidad)
{
    cout << "Ingrese la cantidad de elementos: ";
    cin >> cantidad;
    vector = new int[cantidad];
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> vector[i];
    }
}

void mostrarVector(int *vector, int cantidad)
{
    cout << "Los elementos del vector son: ";
    for (int i = 0; i < cantidad; i++)
    {
        cout << vector[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    int *vector = nullptr;
    int cantidad = 0;
    int opcion = 0;
    while (true)
    {
        cout << "Ingrese una opción (1-3): " << endl;
        cout << "1- Cargar Vector" << endl;
        cout << "2- Mostrar Vector" << endl;
        cout << "3- Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cargarVector(vector, cantidad);
            break;
        case 2:
            mostrarVector(vector, cantidad);
            break;
        case 3:
            delete[] vector;
            vector = nullptr;
            return 0;
            break;

        default:
            cout << "Ingrese una opción válida (1-3): ";
            break;
        }
    }

    return 0;
}




