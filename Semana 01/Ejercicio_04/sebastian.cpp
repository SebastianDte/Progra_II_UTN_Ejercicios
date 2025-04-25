#include <iostream>
#include <locale>
using namespace std;

// Una fundación que se dedica a fomentar la adopción de mascotas dispone de los registros de adopciones del año 2024. Por cada adopción que se haya efectuado se registró:
// Mes de la adopción (entero entre 1 y 12)
// Tipo de animal adoptado (entero entre 10 y 15)
// Edad del adoptante responsable
// Tipo de vivienda del adoptante responsable (entero entre 1 y 5)

// La información no se encuentra agrupada ni ordenada bajo ningún criterio. Para indicar el fin de la carga de datos se ingresa un mes de adopción igual a cero.

// Se pide calcular e informar
// El tipo de animal más adoptado en general.
// El promedio de edad de los adoptantes de cada tipo de animal.
// Por cada tipo de animal y tipo de vivienda la cantidad total de adopciones registradas.

// Aclaración:
// Los tipos de animales son:
// 10 - Perro, 11 - Gato, 12 - Conejo, 13 - Hurón, 14 - Caballo, 15 - Oveja

// Los tipos de vivienda son:
// 1 - Casa, 2 - Departamento, 3 - Casa Quinta, 4 - Finca, 5 - Duplex

void animalMasAdoptado(int tipoAnimal[], string tipoAnimalString[], int tamanio) {
   cout << "=========================================" << endl;
   cout << "         TIPO DE ANIMAL MÁS ADOPTADO     " << endl;
   cout << "=========================================" << endl;

   int maximo = tipoAnimal[0];
   int indiceMaximo = 0;
   for (int i = 0; i < tamanio; i++) {
       if (tipoAnimal[i] > maximo) {
           maximo = tipoAnimal[i];
           indiceMaximo = i;
       }
   }
   cout << "Animal: " << tipoAnimalString[indiceMaximo] << endl;
   cout << "Cantidad de adopciones: " << tipoAnimal[indiceMaximo] << endl;
   cout << "=========================================" << endl << endl;
}

void promedioEdadAdoptantes(int cantidadAdopciones[], int promedioEdad[], string tipoAnimalString[]) {
   cout << "=========================================" << endl;
   cout << "       PROMEDIO DE EDAD POR ANIMAL       " << endl;
   cout << "=========================================" << endl;

   for (int i = 0; i < 6; i++) {
       if (cantidadAdopciones[i] > 0) {
           int promedio = promedioEdad[i] / cantidadAdopciones[i];
           cout << tipoAnimalString[i] << ": " << promedio << " años" << endl;
       } else {
           cout << tipoAnimalString[i] << ": No se registraron adopciones" << endl;
       }
   }
   cout << "=========================================" << endl << endl;
}

void cantidadTotalAdopciones(int cantidadAdopcionesTipoViviendayTipoAnimal[][6], string tipoAnimalString[], string tipoViviendaString[]) {
   cout << "=========================================" << endl;
   cout << " CANTIDAD DE ADOPCIONES POR ANIMAL Y VIVIENDA " << endl;
   cout << "=========================================" << endl;

   for (int i = 0; i < 5; i++) {
       cout << "-----------------------------------------" << endl;
       cout << "Tipo de vivienda: " << tipoViviendaString[i] << endl;
       cout << "-----------------------------------------" << endl;

       for (int j = 0; j < 6; j++) {
           cout << tipoAnimalString[j] << ": " << cantidadAdopcionesTipoViviendayTipoAnimal[i][j] << " adopciones" << endl;
       }
       cout << "-----------------------------------------" << endl << endl;
   }
   cout << "=========================================" << endl << endl;
}

void cargarDatos(int tipoAnimal[],int tipoVivienda[],string tipoAnimalString[],string tipoViviendaString[],int promedioEdad[],int cantidadAdopciones[],int cantAdopcionesPorTipos[][6]){

   int mesAdopcion,edadAdoptante;
   //Carga de Datos
   while (true)
   {
      //Entrada Datos mes de adopción.
      cout << "Ingrese el mes de adopcion (0 para salir): ";
      cin >> mesAdopcion;
      //Validar mes de adopción.
      if(mesAdopcion >= 1 && mesAdopcion <= 12)
      {  //Entrada Datos tipo de animal adoptado.
         cout << "Ingrese el tipo de animal adoptado (10-15): ";
         int auxTipoAnimal;
         cin >> auxTipoAnimal;
         //Validar tipo de animal adoptado.
         if(auxTipoAnimal >= 10 && auxTipoAnimal <= 15){
            //Entrada Datos edad del adoptante responsable.
            cout << "Ingrese la edad del adoptante responsable: ";
            cin >> edadAdoptante;
            //Validar edad del adoptante responsable.
            if(edadAdoptante > 0){
               cout << "Ingrese el tipo de vivienda del adoptante responsable (1-5): ";
               int auxTipoVivienda;
               cin >> auxTipoVivienda;
               if(auxTipoVivienda >= 1 && auxTipoVivienda <= 5){
                  tipoAnimal[auxTipoAnimal-10]++;
                  promedioEdad[auxTipoAnimal-10] += edadAdoptante;
                  cantidadAdopciones[auxTipoAnimal-10]++;
                  cantAdopcionesPorTipos[auxTipoVivienda-1][auxTipoAnimal-10]++;
                  cout << "Adopcion registrada con exito!" << endl;
               }else{
                  cout << "Tipo de vivienda invalido. Intente nuevamente." << endl;
               }
            }else{
               cout << "Edad invalida. Intente nuevamente." << endl;
            }
         }else{
            cout << "Tipo de animal invalido. Intente nuevamente." << endl;
         }
      }else if(mesAdopcion == 0)break;  //Mes igual a 0, salir del bucle.
      else{
         cout << "Mes invalido. Intente nuevamente." << endl;
      }
   }
}

int main()
{
   setlocale(LC_ALL, "es_ES.UTF-8");
   //Declaración de Variables
   int tipoAnimal[6] ={};
   int tipoVivienda[6] = {1, 2, 3, 4, 5};
   string tipoAnimalString[6] = {"Perro", "Gato", "Conejo", "Hurón", "Caballo", "Oveja"};
   string tipoViviendaString[6] = {"Casa", "Departamento", "Casa Quinta", "Finca", "Duplex"};
   int promedioEdad[6] = {0};
   int cantidadAdopciones[6] = {0};
   int cantAdopcionesPorTipos[5][6] = {0};
   //Carga de Datos
   cargarDatos(tipoAnimal,tipoVivienda,tipoAnimalString,tipoViviendaString,promedioEdad,cantidadAdopciones,cantAdopcionesPorTipos);
   
   // Salida de Datos
   animalMasAdoptado(tipoAnimal, tipoAnimalString, 6);
   promedioEdadAdoptantes(cantidadAdopciones, promedioEdad, tipoAnimalString);
   cantidadTotalAdopciones(cantAdopcionesPorTipos, tipoAnimalString, tipoViviendaString);

   cout << "=========================================" << endl;
   cout << "             FIN DEL PROGRAMA            " << endl;
   cout << "=========================================" << endl;

   return 0;
}