#include <iostream>
#include <locale>
using namespace std;

// Escribe un programa que solicite al usuario ingresar una lista de 10 números enteros. Luego, el programa debe mostrar los números pares distintos que se ingresaron. Para resolver este ejercicio, deberás implementar una función que reciba un vector de enteros y su tamaño, y que devuelva un puntero a un vector dinámico que contenga solo los números pares distintos del vector recibido.

#include <iostream>
#include <locale>
using namespace std;

int* obtenerParesDistintos(int* vec, int tam, int& cantPares) {
    int* resultado = new int[tam]; 
    cantPares = 0;

    for (int i = 0; i < tam; ++i) {
        if (vec[i] % 2 == 0) {
            // Verificar si ya está
            bool repetido = false;
            for (int j = 0; j < cantPares; j++) {
                if (resultado[j] == vec[i]) {
                    repetido = true;
                    break;
                }
            }

            if (!repetido) {
                resultado[cantPares] = vec[i];
                cantPares++;
            }
        }
    }

    // Redimensionar manualmente (copiamos a uno nuevo del tamaño justo)
    int* paresFinal = new int[cantPares];
    for (int i = 0; i < cantPares; ++i) {
        paresFinal[i] = resultado[i];
    }

    delete[] resultado; // liberar el intermedio
    return paresFinal;
}

int main() {
    const int TAM = 10;
    int numeros[TAM];

    cout << "Ingrese " << TAM << " numeros enteros:" << endl;
    for (int i = 0; i < TAM; ++i) {
        cin >> numeros[i];
    }

    int cantidad = 0;
    int* pares = obtenerParesDistintos(numeros, TAM, cantidad);

    cout << "Numeros pares distintos:\n";
    for (int i = 0; i < cantidad; ++i) {
        cout << pares[i] << " ";
    }
    cout << endl;

    delete[] pares; // liberar memoria
    return 0;
}
