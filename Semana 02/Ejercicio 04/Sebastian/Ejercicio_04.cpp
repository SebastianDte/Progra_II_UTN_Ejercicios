#include <iostream>
#include <locale>
using namespace std;
// Hacer una función que reciba un vector de enteros y su tamaño y devuelva la cantidad de números distintos que se repiten en el vector.

int contarRepetidos(int vec[],int tamanio){
    int contador = 0;
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vec[i] == vec[j]) {
                contador++;
                break; 
            }
        }
    }
    return contador;
}
int main() {
    setlocale(LC_ALL, ""); 
    int tamanio;
    int *vector = nullptr; 

    cout << "Ingrese el tamaño del vector: " << endl;
    cin >> tamanio;
    vector = new int[tamanio]; 
    cout << "Ingrese los elementos del vector: " << endl;   
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Elemento " << i + 1 << ": " << endl;
        cin >> vector[i]; 
    }

    int cantidadRepetidos = contarRepetidos(vector, tamanio);
    cout << "La cantidad de números distintos que se repiten en el vector es: " << cantidadRepetidos << endl;
    
    delete[] vector;
    
    return 0;
}
