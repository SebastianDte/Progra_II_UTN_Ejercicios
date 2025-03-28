#include <iostream>
/*
Una empresa lleva un registro de asistencia de sus 30 empleados. Cada vez que un empleado asiste al trabajo, se registra la siguiente informaci¢n:
  -Numero de empleado (100 a 129)
  -Mes (1 a 12)
  -Dia (1 a 31)
  -Horas trabajadas en el d¡a

Los registros finalizan cuando se ingresa un numero de empleado igual a 0.
Al finalizar la carga de datos, se debe calcular:

  A-Para cada mes del a¤o, mostrar cuantos dias tuvieron al menos un empleado presente.
  B-Listar los dias del a¤o en los que ningun empleado trabajo.
  C-Por cada empleado, indicar el numero de empleado y la cantidad de horas trabajadas en total en el a¤o.

*/
using namespace std;

void puntoA(bool matPresentes[][31], int filas, int columnas);
void puntoB(bool matPresentes[][31], int filas, int columnas);
void puntoC(float vecEmpleados[], int filas);


int main()
{
    int numeroEmpleado, mes, dia;
    float horas = 0;
    bool presentes[12][31] = {};
    float empleados[30] = {};

    cout << "Para cortar el ingreso de datos, ingresar 0 en numero de empleado"<<endl;
    cout << "-------------------------------------------------------------------------------------------------------------"<<endl;
    cout << endl;
    cout << "Ingresar numero de empleado (100 a 129): ";
    cin >> numeroEmpleado;

    while (numeroEmpleado != 0)
    {
        cout << "Ingresar mes: ";
        cin >> mes;
        cout << "Ingresar dia: ";
        cin >> dia;
        cout << "Ingresar cantidad de horas trabajadas: ";
        cin >> horas;

        presentes[mes - 1][dia - 1] = true;
        empleados[numeroEmpleado-100] += horas;

        cout << "Ingresar numero de empleado (100 a 129): ";
        cin >> numeroEmpleado;
    }

    puntoA(presentes, 12, 31);
    puntoB(presentes, 12, 31);
    puntoC(empleados, 30);
    return 0;
}


/// A-Para cada mes del a¤o, mostrar cuantos dias tuvieron al menos un empleado presente.
void puntoA(bool matPresentes[][31], int filas, int columnas)
{
    cout << endl << "--- Punto A: D¡as con empleados presentes por mes ---" << endl;
    cout << endl;
    cout << endl;
    string nombresMeses[] =
    {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };
    for (int mes = 0; mes < filas; mes++)
    {
        cout << "Mes " << nombresMeses[mes]<< ": ";
        int cantPresentes = 0;
        for (int dia = 0; dia < columnas; dia++)
        {
            if (matPresentes[mes][dia])
            {
                cantPresentes++;
            }
        }
        cout << cantPresentes << " d¡as con empleados presentes." << endl;
    }
}

/// B-Listar los dias del a¤o en los que ningun empleado trabajo.
void puntoB(bool matPresentes[][31], int filas, int columnas)
{
    cout << endl << "--- Punto B: D¡as del a¤o sin empleados presentes ---" << endl;
    cout << endl;
    cout << endl;
    string nombresMeses[] =
    {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    for (int mes = 0; mes < filas; mes++)
    {
        cout << "Mes de " << nombresMeses[mes] << ":" << endl;
        for (int dia = 0; dia < columnas; dia++)
        {
            if (!matPresentes[mes][dia])
            {
                cout << "  D¡a " << dia + 1 << endl;
            }
        }
    }
}

void puntoC(float vecEmpleados[], int filas)
{
     cout << endl << "--- Punto C: Horas trabajadas por cada empleado ---" << endl;
    cout << endl;
    cout << endl;
    for(int empleado = 0; empleado < filas; empleado++)
    {
        if(vecEmpleados[empleado] > 0){
        cout << "Empleado #"<< empleado+100 <<":  "<<vecEmpleados[empleado]<< " horas."<<endl;
        }
    }

}
