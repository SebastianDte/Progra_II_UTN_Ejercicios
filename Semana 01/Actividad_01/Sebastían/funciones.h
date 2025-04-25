// funciones.h
#ifndef FUNCIONES_H  
#define FUNCIONES_H
using namespace std;
#include <string>
#include <cctype>

//Funciónes bases del programa.
void cargarInformacion(int Asistencias[30][31][12], int MTamanio, int DTamanio, int ETamanio, int diasPorMes[],int vectorPuntoA[],int totalDiasAlAnio,bool VDiasNoWork[]);
void CargarDatos(int Asistencias[30][31][12], int diasPorMes[], int VAcuEmpleados[],bool& datosCargados);

//Funciones para mostrar la información solicitada en cada punto del ejercicio.
void PuntoA(int vectorPuntoA[]);
void PuntoB(bool VDiasNoWork[], int diasPorMes[],int MTamanio);
void PuntoC(int VAcuEmpleados[], int tamanio);

//Validaciones
bool EsUnNumero(const string &entrada);
bool ValidarNumeroEmpleado(int& numeroEmpleado, string& entrada,bool& datosCargados);
//Sobrecarga de la función ValidarNumeroEmpleado.
bool ValidarNumeroEmpleado(int& numeroEmpleado, string& entrada);

#endif
