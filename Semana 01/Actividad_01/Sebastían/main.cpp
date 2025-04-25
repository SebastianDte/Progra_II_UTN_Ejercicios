#include <iostream>
#include <locale>
#include "funciones.h"
using namespace std;


// 📋 Actividad: Control de Asistencias en la Empresa 🏢
// Una empresa lleva un registro de asistencia de sus 30 empleados. Cada vez que un empleado asiste al trabajo, se registra la siguiente información:
// Número de empleado (100 a 129)
// Mes (1 a 12)
// Día (1 a 31)
// Horas trabajadas en el día
// Los registros finalizan cuando se ingresa un número de empleado igual a 0.
// Al finalizar la carga de datos, se debe calcular:
// Para cada mes del año, mostrar cuántos días tuvieron al menos un empleado presente.
// Listar los días del año en los que ningún empleado trabajó.
// Por cada empleado, indicar el número de empleado y la cantidad de horas trabajadas en total en el año.

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");

    // DECLARACIÓN DE VARIABLES CONSTANTES.
    int const DIAS = 31;
    int const MESES = 12;
    int const EMPLEADOS = 30;
    // Días definidos de cada mes para un año no bisiesto.
    int diasPorMes[MESES] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // MATRIZ 3X3.
    int Asistencias[EMPLEADOS][DIAS][MESES] = {};
    // Variables locales.
    int numeroEmpleado = 0, dia = 0, mes = 0, horasTrabajadas;
    // Vector para el punto A.
    const int VecPuntoA = 12;
    int vectorPuntoA[VecPuntoA] = {};
    // Vector para el punto B.
    const int totalDiasAlAnio = 365;
    bool VDiasNoWork[totalDiasAlAnio] = {false};
    // Vector para el punto C.
    int VAcuEmpleados[EMPLEADOS] = {};

    int opcion;
    bool datosCargados = false; // Bandera para saber si se cargaron datos

    do
    {
        cout << "\n===== MENU PRINCIPAL =====" << endl;
        cout << "1. Cargar datos de asistencias" << endl;
        cout << "2. Mostrar dias con al menos un empleado presente" << endl;
        cout << "3. Listar dias sin trabajo" << endl;
        cout << "4. Mostrar horas trabajadas por empleado" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            CargarDatos(Asistencias,diasPorMes,VAcuEmpleados,datosCargados);
            if(datosCargados){
                cargarInformacion(Asistencias,MESES,DIAS, EMPLEADOS, diasPorMes,vectorPuntoA, totalDiasAlAnio,VDiasNoWork);
            }
            break;
        case 2:
            if (datosCargados)
                PuntoA(vectorPuntoA);
            else cout << "Debe cargar los datos primero." << endl;
            break;
        case 3:
            if (datosCargados)
                PuntoB(VDiasNoWork, diasPorMes, MESES);
            else cout << "Debe cargar los datos primero." << endl;
            break;
        case 4:
            if (datosCargados)
                PuntoC(VAcuEmpleados, EMPLEADOS);
            else
                cout << "Debe cargar los datos primero." << endl;
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 5);

    return 0;
}
