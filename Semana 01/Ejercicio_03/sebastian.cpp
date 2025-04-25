#include <iostream>
#include <locale>
using namespace std;
// Una persona desea registrar los gastos realizados durante un mes. 
// Ha definido que los gastos se pueden categorizar en:

// ┌────┬─────────────────┐
// │ ID │ Nombre Categoría│
// ├────┼─────────────────┤
// │  1 │ Servicios       │
// │  2 │ Alimentación    │
// │  3 │ Limpieza        │
// │  4 │ Transporte      │
// │  5 │ Educación       │
// │  6 │ Salud           │
// │  7 │ Ocio            │
// │  8 │ Impuestos       │
// │  9 │ Vestimenta      │
// │ 10 │ Inversiones     │
// └────┴─────────────────┘

// Por cada gasto registrado se ingresa el siguiente registro:
// - Día (número entero)
// - ID de Categoría de gasto (número entero entre 1 y 10)
// - Importe del gasto (número real)

// La información no se encuentra agrupada ni ordenada. No se sabe de antemano cuántos registros de gastos habrá. El fin de la carga de información se indica con un día igual a cero.

// Calcular e informar:
// A) La categoría de gasto que mayor dinero se haya destinado y cuál es dicha categoría.
// B) Por cada categoría de gasto, el nombre de la categoría y el total acumulado en concepto de gastos del mes.
// C) La cantidad de categorías de gasto que no hayan registrado movimientos.
// D) Por cada día, la cantidad de gastos que se hayan registrado. Sólo mostrar aquellos registros de días que hayan registrado gastos.

void puntoA(int acuCategoria[], string categorias[]){
   int mayor = acuCategoria[0];
   string categoriasMayor = categorias[0];
   for (int i = 1; i < 10 ; i++)
   {
      if(acuCategoria[i] > mayor){
         mayor = acuCategoria[i];
         categoriasMayor = categorias[i];
      }
   }
   cout << "La categoria con mayor gastos es " << categoriasMayor << " con un total de: $" << mayor << endl;
}
void puntoB(int acuCategoria[], string categorias[]){
   cout << "Total de Gastos por Categoria" << endl;
   for (int i = 0; i < 10; i++)
   {
      cout << categorias[i] << ": $" << acuCategoria[i] << endl;
   }
}
void puntoC(int acuCategoria[]){
   int contador = 0;
   for (int i = 0; i < 10; i++)
   {
      if(acuCategoria[i] == 0){
         contador++;
      }
   }
   cout << "Cantidad de categorias sin gastos: " << contador << endl;
}
void puntoD(int gastosPorDia[]){
   cout << "Cantidad de Gastos por Dia" << endl;
   for (int i = 0; i < 31; i++)
   {
      if(gastosPorDia[i] > 0){
         cout << "Dia " << i+1 << ": " << gastosPorDia[i] << endl;
      }
   }
}

int main()
{
   setlocale(LC_ALL, "es_ES.UTF-8");

   // - ID de Categoría de gasto (número entero entre 1 y 10)

   string categorias[10] = {"Servicios","Alimentación","Limpieza","Transporte","Educación","Salud","Ocio","Impuestos","Vestimenta","Inversiones"};
   int acuCategoria[10] = {};
   int gastosPorDia[31] = {};
   float monto = 0;
   int dia;
   while (true)
   {
      cout << "Ingrese el Número de Día(1-31)" << endl;
      cin >> dia ;
      if(dia >= 1 && dia <= 31){
         cout << "Ingrese el ID de la Categoria (1 - 10)";
         int auxCategoria;
         cin >> auxCategoria;
         if(auxCategoria >= 1 && auxCategoria <=10){
            cout << "Ingrese el Importe del Gasto" << endl;
            cin>>monto;
            if(monto > 0){
               gastosPorDia[dia-1]+=monto;
               acuCategoria[auxCategoria-1] += monto;
               }else{
               cout << "Monto Ingresado no puede ser negativo" << endl;
            }
         }else{
            cout << "Categoria Ingresada incorrecta" << endl;
         }
      }else if(dia == 0){
         break;
      }else{
         cout << "Día ingresado incorrecto" << endl;
      }
   }

   puntoA(acuCategoria, categorias);
   puntoB(acuCategoria, categorias);
   puntoC(acuCategoria);
   puntoD(gastosPorDia);
   return 0;
}