// Guía de Ejercicios de Memoria Dinámica
/*
Escribe un programa que solicite al usuario el tamaño de un array de enteros, lo cree dinámicamente utilizando new,
el usuario debe poder cargar el array y mostrarlo, y luego libere la memoria con delete

*/
#include <iostream>
using namespace std;



int main(){

    int *vec = nullptr, numElementos;

    cout << "Ingrese el numero de elementos a cargar: ";
    cin >> numElementos;

    vec = new int[numElementos];

    if (vec == nullptr){
        cout << "\nNo hay memoria." << endl;
        return -1;
    }

    for (int i = 0; i < numElementos; ++i){
        cout << "\nIngrese un valor para el elemento #" << i+1 << ": ";
        cin >> vec[i];
    }

    for(int i = 0; i < numElementos; ++i){
        cout << "\nElemento en posicion #"  << i+1 << ": " << vec[i] << endl;
    }

    delete []vec;


	return 0;
}
