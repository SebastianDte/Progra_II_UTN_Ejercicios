#include <iostream>
#include <locale>
using namespace std;
// Hacer una función que reciba un vector de enteros y su tamaño y luego muestre el vector ordenado de forma ascendente, tener en cuenta que el vector enviado como argumento no debe ser modificado.

void vectorOrdenado(int* vector,int tamanio){
 int* vectorOrdenado = nullptr;
   vectorOrdenado = new int[tamanio];
   int aux = 0;
   //Copia del vector
   for (int i = 0; i < tamanio; i++)
   {
      vectorOrdenado[i] = vector[i];
   }
   //Ordenar el vector
   for(int x = 0; x < tamanio; x++){
      for(int y = 0; y < tamanio-1; y++){
         if(vectorOrdenado[y] > vectorOrdenado[y+1]){
            aux = vectorOrdenado[y];
            vectorOrdenado[y] = vectorOrdenado[y+1];
            vectorOrdenado[y+1] = aux;
         }
      }
   }
   //Mostrar el vector ordenado
   for (int i = 0; i < tamanio; i++)
   {
      cout << vectorOrdenado[i] << " ";
   }
   delete[] vectorOrdenado; 
   
}
int main()
{
   setlocale(LC_ALL, "es_ES.UTF-8");
   int tamanio = 0;
   cout << "Ingrese el tamaño del vector: ";
   cin >> tamanio;
   int* vector = nullptr;
   vector = new int[tamanio];
   //Llenar el vector
   for (int i = 0; i < tamanio; i++)
   {
      cout << "Ingrese el elemento " << i + 1 << ": ";
      cin >> vector[i];
   }
   //llamar a la funcion ordenar
   cout << "El vector ordenado es: ";
   vectorOrdenado(vector, tamanio);
   delete[] vector;  
   return 0;
}