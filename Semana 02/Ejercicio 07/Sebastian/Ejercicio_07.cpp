#include <iostream>
#include <locale>
using namespace std;

// Escribe un programa que simule la gestión de un club de lectura. 
// El programa debe solicitar al usuario la cantidad de libros que desea cargar y posteriormente pedir los nombres de dichos libros. Una vez cargados los libros se debe mostrar un menú  con las siguientes opciones:
// 1- Listado: Debe listar los libros en el orden en que fueron cargados.
// 2- Tiempo de lectura: Se solicita el nombre del libro. Si no existe debe mostrar un mensaje aclaratorio. Si el libro existe, ingresar la cantidad de minutos que le llevó su lectura.
// 3- Ranking: Mostrar los libros ordenados por tiempo de lectura de Mayor a Menor.
// 4- Salir: el programa debe salir del programa

//Listado de libros
void listadoLibros(string *libros, int cantidadLibros)
{
   cout << "Listado de libros: " << endl;
   for (int i = 0; i < cantidadLibros; i++)
   {
      cout << i + 1 << ". " << libros[i] << endl;
   }
}
// Tiempo de lectura
void FunciontiempoLectura(string *libros, int cantidadLibros,float tiempoLectura[])
{
   string libroBuscado;
   cout << "Ingrese el nombre del libro que desea buscar: ";
   cin >> libroBuscado;
   bool encontrado = false;
   float minutos;
   for (int i = 0; i < cantidadLibros; i++)
   {
      minutos = 0;

      if (libros[i] == libroBuscado)
      {
         encontrado = true;
         cout << "Ingrese la cantidad de minutos que le llevó su lectura: ";
         cin >> minutos;
         cout << "Tiempo de lectura registrado para el libro " << libros[i] << ": " << minutos << " minutos." << endl;
         tiempoLectura[i] = minutos;
         break;
      }
   }
   if (!encontrado)
   {
      cout << "El libro no existe en la lista." << endl;
   }
}
//Mostrar libros ordenados por tiempo de lectura
void rankingLibros(string *libros, int cantidadLibros,float tiempoLectura[])
{
   float tempTiempo;
   string tempLibro;
   //Ordenar los libros por tiempo de lectura de mayor a menor
   for (int i = 0; i < cantidadLibros; i++)
   {
      for (int j = 0; j < cantidadLibros - 1; j++)
      {
         if (tiempoLectura[j] < tiempoLectura[j + 1])
         {
            
            tempTiempo = tiempoLectura[j];
            tiempoLectura[j] = tiempoLectura[j + 1];
            tiempoLectura[j + 1] = tempTiempo;

            // Intercambiar libros
            tempLibro = libros[j];
            libros[j] = libros[j + 1];
            libros[j + 1] = tempLibro;
         }
      }
   }

   cout << "Ranking de libros por tiempo de lectura: " << endl;
   for (int i = 0; i < cantidadLibros; i++)
   {
      cout << i + 1 << ". " << libros[i] << " - " << tiempoLectura[i] << " minutos." << endl;
   }
}
void menu(string *libros, float tiempoLectura[],int& cantidadLibros){
   int opcion;
   cout << "Seleccione una opción del menú: " << endl;
   cout << "1. Listado de libros" << endl;
   cout << "2. Tiempo de lectura" << endl;
   cout << "3. Ranking de libros" << endl;
   cout << "4. Salir" << endl;
   cin >> opcion;
   switch (opcion)
   {
   case 1:
      cout << "Listado de libros: " << endl;
      listadoLibros(libros, cantidadLibros);
      break;
   case 2:
      cout << "Tiempo de lectura: " << endl;
      FunciontiempoLectura(libros, cantidadLibros,tiempoLectura);
      break;
   case 3:
      cout << "Ranking de libros: " << endl;
      rankingLibros(libros, cantidadLibros,tiempoLectura);
      break;
   case 4:
      cout << "Saliendo del programa..." << endl;
      break;
   default:
      cout << "Opción no válida." << endl;
      break;
   }
}
int main()
{
   setlocale(LC_ALL, "es_ES.UTF-8");
   //carga de libros
   int cantidadLibros;
   string *libros = nullptr;
   cout << "Ingrese la cantidad de libros que desea cargar: ";
   cin >> cantidadLibros;
   libros = new string[cantidadLibros];
   float *tiempoLectura = new float[cantidadLibros];
   
   
   //Carga de libros
   for (int i = 0; i < cantidadLibros; i++)
   {
      cout << "Ingrese el nombre del libro " << i + 1 << ": ";
      cin >> libros[i];
   }

   //menu
   menu(libros,tiempoLectura,cantidadLibros);
   //Liberar memoria
   delete[] libros;
   delete[] tiempoLectura;
   libros = nullptr;
   tiempoLectura = nullptr;
   return 0;
}