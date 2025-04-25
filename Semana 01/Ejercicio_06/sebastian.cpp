using namespace std;
#include <iostream>
#include <locale>

// La mundialmente conocida hamburguesería Coco’s Burger desea registrar la información de las ventas de la primera semana de Agosto 2023 de su local ubicado en Canelones, Uruguay.

// Por cada venta se registra:
// •    Código de hamburguesa (entero de 1 a 5)
// •    Día (entero de 1 - Lunes a 7 - Domingo)
// •    Cantidad vendida (entero)
// •  Tipo de Acompañamiento ('B' – con batatas / 'P' – con papas / 'C' – Aros de cebolla / 'X' – sin acompañamiento)

// Pueden existir varios registros de ventas para la misma hamburguesa. El fin de la carga de datos se indica con un código de hamburguesa igual a 0.

// A este lote se le precede otro ordenado por número de hamburguesa con la siguiente información:
// •    Código de hamburguesa (1 a 5)
// •    Precio (float)
// •    Stock al comienzo de la semana (entero)

// Se pide determinar e informar:
// Por cada hamburguesa, la cantidad de unidades vendidas y el total recaudado.
// La hamburguesa más vendida el viernes.
// Los días que se vendieron hamburguesas acompañadas de Batatas pero no se vendieron hamburguesas acompañadas de Aros de Cebolla.
// Las hamburguesas que lograron un sold out (vendieron todo)
// Por cada día y acompañamiento, la cantidad de hamburguesas vendidas.

//Carga de la Matriz para cada día y acompañamiento, la cantidad de hamburguesas vendidas.


void cargaMatrizDiaMasAcompaniamiento(char tipoAcompaniamiento,int ventasPorDiaYAcomp[][4],int dia,int cantidadVendida){
   if(tipoAcompaniamiento == 'B'){
      ventasPorDiaYAcomp[dia-1][0] += cantidadVendida;
   }else if(tipoAcompaniamiento == 'P'){
      ventasPorDiaYAcomp[dia-1][1] += cantidadVendida;
}else if(tipoAcompaniamiento == 'C'){
      ventasPorDiaYAcomp[dia-1][2] += cantidadVendida;
   }else if(tipoAcompaniamiento == 'X'){
      ventasPorDiaYAcomp[dia-1][3] += cantidadVendida;
   }
}

//Carga de Stock y Precio de las hamburguesas.
void cargaStock(int tamanioHamburguesas, int ArrStock[],float ArrPrecio[]){
   float precio=0;
   int stock = 0;
   cout << "Carga de Stock" << endl;
   for (int i = 0; i < tamanioHamburguesas; i++)
   {
      cout << "Hamburguesa con Código: " << i + 1<< endl;
      cout << "Ingrese el precio: " << endl;
      cin >> precio;
      ArrPrecio[i] = precio;
      cout << "Ingrese el Stock: " << endl;
      cin >> stock; 
      ArrStock[i] = stock; 
   }
}

//Por cada hamburguesa, la cantidad de unidades vendidas y el total recaudado.
void cantVendidasCantRecaudado(int tamanioHamburguesas, int hamburguesa[], float ArrPrecio[]){
   // Por cada hamburguesa, la cantidad de unidades vendidas y el total recaudado.
   cout << "Cantidad de Ventas y Total recaudado por cada hamburgesa: " << endl;
   cout << "---------------------------------------------------------"  << endl;
   for (int i = 0; i < tamanioHamburguesas; i++)
   { 
      int auxCont = 0;
      cout << "Hamburguesa ( Código " << i + 1 << ")" << endl;
      cout << "Cantidad de ventas: " << hamburguesa[i] << endl;
      auxCont = hamburguesa[i] * ArrPrecio[i];
      cout << "Total Recaudado: " << auxCont << endl;
      cout << " " << endl;
   }
}

//Carga de Ventas
void cargaDeVentas(const int tamanioHamburguesas, int hamburguesa[], float ArrPrecio[],int ArrStock[],int dias[],int diaSieteMayorVenta,int indexDiaSieteMayor,int codHamburguesa,int dia,int cantidadVendida,char tipoAcompaniamiento,bool ArrDias[],int ventasPorDiaYAcomp[][4]){
   while(true){
      cout << "Ingrese el Código de la hamburguesa (1-5): " << endl;
      cin >> codHamburguesa;
      if(codHamburguesa == 0)break;
      cout << "Ingrese el Día (1-7): " << endl;
      cin >> dia;
      cout << "Ingrese la cantidad vendida: " << endl;
      cin >> cantidadVendida;
      hamburguesa[codHamburguesa-1] += cantidadVendida;
      ArrStock[codHamburguesa-1] -= cantidadVendida;
      //Mayor venta de hambuguesa el Día 7.
      if(dia == 7 && hamburguesa[codHamburguesa-1] > diaSieteMayorVenta){
         diaSieteMayorVenta = hamburguesa[codHamburguesa-1];
         indexDiaSieteMayor = codHamburguesa;
      }
      cout << "Ingrese el tipo de acompañiamiento: ('B' - con batatas / 'P' - con papas / 'C' - Aros de cebolla / 'X' - sin acompañamiento)" << endl;
      cin >> tipoAcompaniamiento;
      if(tipoAcompaniamiento == 'B'){
         ArrDias[dia-1] = true;
      }else if(tipoAcompaniamiento == 'C' && ArrDias[dia-1] == true){
         ArrDias[dia-1] = false;
      }
      cargaMatrizDiaMasAcompaniamiento(tipoAcompaniamiento,ventasPorDiaYAcomp,dia,cantidadVendida);
      
   }
}

//Las hamburguesas que lograron un sold out (vendieron todo)
void souldOut(int ArrStock[],int hamburguesa[],int tamanioHamburguesas){
   //Las hamburguesas que lograron un sold out (vendieron todo)
   cout << "Las hamburguesas que lograron un sold out (vendieron todo): " << endl;
   for (int i = 0; i < tamanioHamburguesas; i++)
   {
      if(ArrStock[i] == 0){
         cout << "La hamburguesa con Código#: " << i + 1 << endl;
      }
   }
}

// Por cada día y acompañamiento, la cantidad de hamburguesas vendidas.
void cantVendidasPorDia(int ventasPorDiaYAcomp[][4],int){
   cout << "Por cada día y acompañamiento, la cantidad de hamburguesas vendidas: " << endl;
   cout << "---------------------------------------------------------"  << endl;
   for (int i = 0; i < 7; i++)
   {
      cout << "Día " << i + 1 << endl;
      cout << "Con Batatas: " << ventasPorDiaYAcomp[i][0] << endl;
      cout << "Con Papas: " << ventasPorDiaYAcomp[i][1] << endl;
      cout << "Aros de Cebolla: " << ventasPorDiaYAcomp[i][2] << endl;
      cout << "Sin Acompañamiento: " << ventasPorDiaYAcomp[i][3] << endl;
      cout << " " << endl;
   }
   cout << "---------------------------------------------------------"  << endl;
}

//Días que se vendieron hamburguesas acompañadas de Batatas pero no se vendieron hamburguesas acompañadas de Aros de Cebolla.
void diasConBatatasSinAros(bool ArrDias[]){
   cout << "Los días que se vendieron hamburguesas acompañadas de Batatas pero no se vendieron hamburguesas acompañadas de Aros de Cebolla: " << endl;
   cout << "---------------------------------------------------------"  << endl;
   for (int i = 0; i < 7; i++)
   {
      if(ArrDias[i]){
         cout << "El día " << i + 1 << " se vendieron hamburguesas acompañadas de Batatas pero no se vendieron hamburguesas acompañadas de Aros de Cebolla." << endl;
      }
   }
   cout << "---------------------------------------------------------"  << endl;
}

//Programa Principal
int main()
{
   setlocale(LC_ALL, "es_ES.UTF-8");
   
   //Constantes
   const int tamanioHamburguesas = 5;
   const int tamanioDias=7;
   //Declaración de arreglos
   int hamburguesa[tamanioHamburguesas]= {0};
   int dias[tamanioDias] = {};
   bool ArrDias[7] = {false};
   float ArrPrecio[tamanioHamburguesas] = {};
   int ArrStock[tamanioHamburguesas] = {};
   //Variables para la Carga de datos
   int codHamburguesa;
   int dia;
   int cantidadVendida;
   char tipoAcompaniamiento;
   int diaSieteMayorVenta = 0;
   int indexDiaSieteMayor = 0;
   int arr[tamanioDias] = {0};
   int ventasPorDiaYAcomp[7][4] = {0}; 
 
   cargaStock(tamanioHamburguesas,ArrStock,ArrPrecio);
   cargaDeVentas(tamanioHamburguesas,hamburguesa,ArrPrecio,ArrStock,dias,diaSieteMayorVenta,indexDiaSieteMayor,codHamburguesa,dia,cantidadVendida,tipoAcompaniamiento,ArrDias,ventasPorDiaYAcomp);

   cantVendidasCantRecaudado(tamanioHamburguesas,hamburguesa,ArrPrecio);
   souldOut(ArrStock,hamburguesa,tamanioHamburguesas);
   diasConBatatasSinAros(ArrDias);
   cantVendidasPorDia(ventasPorDiaYAcomp,tamanioDias);

   //Mayor venta de hamburguesa para el Día Viernes.
   cout << "La hamburguesa mas vendida el Viernes Fue la de Código: #" << indexDiaSieteMayor << endl; 

   return 0;
}