#include <iostream>
#include <locale>
using namespace std;

// Escribe un programa que solicite al usuario el tamaño de un array de enteros, lo cree dinámicamente utilizando new, el usuario debe poder cargar el array y mostrarlo, y luego libere la memoria con delete

int main() {
    setlocale(LC_ALL, ""); 
    int tamanio;
    cout << "Ingrese el tamaño del array: ";
    cin >> tamanio;
    //cargar el array
    int* array = new int[tamanio]; // Crear el array dinámicamente
    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> array[i];
    }
    // Mostrar el array
    cout << "El array es: ";
    for (int i = 0; i < tamanio; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    // Liberar la memoria
    delete[] array; // Liberar la memoria del array dinámico
    

    return 0;
}
