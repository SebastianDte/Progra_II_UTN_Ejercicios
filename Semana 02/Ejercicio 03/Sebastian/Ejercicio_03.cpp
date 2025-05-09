#include <iostream>
#include <locale>
using namespace std;

// Hacer un programa que solicite al usuario 10 números y luego muestre primero los números positivos y luego los negativos.
// El programa debe crear dos arrays dinámicos con la cantidad exacta en cada caso: uno para almacenar los números positivos y otro para los números negativos. 


int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    int contadorPositivos = 0, contadorNegativos = 0;
    int numeros[10]; // Arreglo para almacenar los números ingresados
    int numero; // Variable para almacenar el número ingresado por el usuario
    int* positivos = nullptr; // Inicializamos el puntero a nullptr
    int* negativos = nullptr; // Inicializamos el puntero a nullptr

    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese un número;";
        cin >> numero;
        numeros[i] = numero; // Almacenamos el número en el arreglo
        if(numero > 0)
        {
            contadorPositivos++;
        }
        else if (numero < 0)
        {
            contadorNegativos++;
        }
    }

    positivos = new int[contadorPositivos]; // Creamos el arreglo dinámico para los positivos
    negativos = new int[contadorNegativos]; // Creamos el arreglo dinámico para los negativos

    for (int i = 0; i < 10; i++)
    {
        //operador ternario para mayores y menores que cero
        if(numeros[i] > 0)
        {
            positivos[contadorPositivos - 1] = numeros[i]; // Almacenamos el número positivo en el arreglo
            contadorPositivos--;
        }
        else if (numeros[i] < 0)
        {
            negativos[contadorNegativos - 1] = numeros[i]; // Almacenamos el número negativo en el arreglo
            contadorNegativos--;
        }
    }

    cout << "Números positivos:" << endl;
    for (int i = 0; i < contadorPositivos; i++)
    {
        cout << positivos[i] << " ";
    }
    cout << endl;
    cout << "Números negativos:" << endl;
    for (int i = 0; i < contadorNegativos; i++)
    {
        cout << negativos[i] << " ";
    }
    delete[] positivos; // Liberamos la memoria del arreglo dinámico de positivos
    delete[] negativos; // Liberamos la memoria del arreglo dinámico de negativos
    
    

    
    
    
    return 0;
}
