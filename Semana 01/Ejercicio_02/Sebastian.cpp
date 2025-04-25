#include <iostream>
#include <locale>
using namespace std;
// Hacer una función llamada quitarRepetidos que reciba dos vectores de enteros de 10 elementos llamados vectorSinProcesar y vectorSinRepetidos. La función debe procesar el vectorSinProcesar de manera que en el vectorSinRepetidos queden todos los elementos distintos del vectorSinProcesar. La función debe devolver la cantidad de elementos asignados a vectorSinRepetidos.

// Ejemplo:
// vectorUno[10] = { 1, 2, 1, 2, 5, 5, 4, 4, 3, 3 }
// vectorDos[10];
// int elementos = quitarRepetidos(vectorUno, vectorDos);

// En elementos debe quedar el valor 5 ya que son 5 los elementos sin repetirse del vector. Además el vectorDos debe contener los valores 1, 2, 5, 4 y 3.

int quitarRepetidos(int vectorUno[], int vectorDos[], int tamanio) {
   int contador = 0;

   // Recorrer el vectorUno
   for (int i = 0; i < tamanio; i++) {
       bool yaExiste = false;

       // Comprobar si el valor ya existe en el vectorDos
       for (int j = 0; j < contador; j++) {
           if (vectorUno[i] == vectorDos[j]) {
               yaExiste = true;
               break;  // Salir del ciclo si ya existe
           }
       }

       // Si no existe, lo agregamos al vectorDos
       if (!yaExiste) {
           vectorDos[contador] = vectorUno[i];
           contador++;  // Incrementar el contador de elementos únicos
       }
   }

   return contador;  // Retorna la cantidad de elementos únicos
};
void mostrarVector(int vectorDos[],int elementos){
   for (int i = 0; i < elementos; i++)
   {
      cout << vectorDos[i] << endl;
   }
}
int main()
{
   setlocale(LC_ALL, "es_ES.UTF-8");

   int vectorUno[10] = {1, 2, 1, 2, 5, 5, 4, 4, 3, 3};
   int vectorDos[10];
   int elementos = quitarRepetidos(vectorUno, vectorDos,10);
   mostrarVector(vectorDos,elementos);
   
   return 0;
}