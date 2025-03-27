#include <iostream>
#include <string>
#include <cctype>
#include "funciones.h"
using namespace std;


void CargarDatos(int Asistencias[30][31][12], int diasPorMes[], int VAcuEmpleados[], bool &datosCargados)
{
    int numeroEmpleado, dia, mes, horasTrabajadas;
    string entrada;
    
    cout << "=== CARGA DE DATOS ===" << endl;

    cout << "Ingrese el numero de empleado (100 a 129), o 0 para salir: ";
    cin >> entrada;

    if(!ValidarNumeroEmpleado(numeroEmpleado,entrada,datosCargados)) return;
    
    while (numeroEmpleado != 0)
    {
        // Validación del mes
        while (true)
        {
            cout << "Ingrese el mes (1 a 12): ";
            cin >> entrada;

            if (EsUnNumero(entrada))
            {
                mes = stoi(entrada);
                if (mes >= 1 && mes <= 12)
                {
                    break;
                }
                else
                {
                    cout << "Mes ingresado incorrecto. Ingrese un mes entre 1 y 12." << endl;
                }
            }
            else
            {
                cout << "Por favor ingrese un número válido para el mes." << endl;
            }
        }

        // Validación del día con respecto al mes ingresado
        while (true)
        {
            cout << "Ingrese el día (1 a " << diasPorMes[mes - 1] << "): ";
            cin >> entrada;

            if (EsUnNumero(entrada))
            {
                dia = stoi(entrada);
                if (dia >= 1 && dia <= diasPorMes[mes - 1])
                {
                    break;
                }
                else
                {
                    cout << "Día ingresado incorrecto. Ingrese un día entre 1 y " << diasPorMes[mes - 1] << "." << endl;
                }
            }
            else
            {
                cout << "Por favor ingrese un número válido para el día." << endl;
            }
        }

        // Ingreso de horas trabajadas
        while (true)
        {
            cout << "Ingrese las horas trabajadas en el día (4hs - 8hs): ";
            cin >> entrada;

            if (EsUnNumero(entrada))
            {
                horasTrabajadas = stoi(entrada);
                if (horasTrabajadas >= 4 && horasTrabajadas <=8)
                {
                    break;
                }
                else
                {
                    cout << "Las horas trabajadas no pueden ser negativas o superar las 8hs." << endl;
                }
            }
            else
            {
                cout << "Por favor ingrese un número válido para las horas trabajadas." << endl;
            }
        }

        // Carga de datos en la matriz
        Asistencias[numeroEmpleado - 100][dia - 1][mes - 1] = horasTrabajadas;

        // Acumulador de horas para el punto C
        VAcuEmpleados[numeroEmpleado - 100] += horasTrabajadas;

        cout << "Ingrese el numero de empleado (100 a 129), o 0 para salir: ";
        cin >> entrada;
        if(!ValidarNumeroEmpleado(numeroEmpleado,entrada))return;


    }
}

// Función Inicial contiene la lógica para el  Punto A y B.
void cargarInformacion(int Asistencias[30][31][12], int MTamanio, int DTamanio, int ETamanio, int diasPorMes[], int vectorPuntoA[], int totalDiasAlAnio, bool VDiasNoWork[])
{

    int indiceDia = 0; // Indice para cargar el vector de Dias que no se trabajaron.

    // For para recorrer los meses.
    for (int m = 0; m < MTamanio; m++)
    {
        int contador = 0;
        // For para recorrer los días.
        for (int d = 0; d < diasPorMes[m]; d++)
        {
            bool diaConEmpleado = false;
            // For para recorrer los empleados.
            for (int e = 0; e < ETamanio; e++)
            {
                if (Asistencias[e][d][m] != 0)
                {
                    diaConEmpleado = true;
                    break;
                }
            }
            // Validación para verificar si hubo un empleado presente en el día o no.
            if (diaConEmpleado)
            {
                contador++;
            }
            else
            {
                VDiasNoWork[indiceDia] = true;
            }
            indiceDia++;
        }
        vectorPuntoA[m] = contador;
    }
}

// Punto A
void PuntoA(int vectorPuntoA[])
{
    cout << "\n====================================" << endl;
    cout << "Días con empleados presentes por mes" << endl;
    cout << "\n" << endl;

    for (int i = 0; i < 12; i++)
    {
        if (vectorPuntoA[i] != 0)
        {
            cout << "MES: " << i + 1 << endl;
            cout << "En " << vectorPuntoA[i] << " Días hubo empleados presentes" << endl;
        }
    }
}

// Punto B
void PuntoB(bool VDiasNoWork[], int diasPorMes[], int MTamanio)
{

    cout << "\n====================================" << endl;
    cout << "DÍAS SIN TRABAJO EN EL AÑO" << endl;
    cout << "\n"
         << endl;

    int indiceDia = 0;
    string nombresMes[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    for (int m = 0; m < MTamanio; m++)
    {
        for (int d = 0; d < diasPorMes[m]; d++)
        {
            if (VDiasNoWork[indiceDia])
            {
                cout << "Día " << (d + 1) << " de " << nombresMes[m] << endl;
            }
            indiceDia++;
        }
    }
}

// Punto C
void PuntoC(int VAcuEmpleados[], int tamanio)
{
    cout << "\n=================================================" << endl;
    cout << "Total de HS trabajadas en el año por cada Empleado" << endl;
    cout << "\n"
         << endl;

    for (int i = 0; i < tamanio; i++)
    {
        if (VAcuEmpleados[i] != 0)
        {
            cout << "Empleado " << i + 100 << ": ";
            cout << "Horas trabajadas en el año: " << VAcuEmpleados[i] << " hs." << endl;
        }
    }
}

bool ValidarNumeroEmpleado(int& numeroEmpleado, string& entrada,bool& datosCargados)
{
    while (true)
    {
        if (EsUnNumero(entrada))
        {
            numeroEmpleado = stoi(entrada);
            if (numeroEmpleado == 0)
            {
                cout << "Volviendo al menú principal..." << endl;
                return false;
            }
            else if (numeroEmpleado < 100 || numeroEmpleado > 129)
            {   
                cout << "Número de empleado inválido." << endl;
                cout << "Ingrese el numero de empleado (100 a 129), o 0 para salir: ";
                cin >> entrada;
            }else{
                datosCargados = true;
                return true;
            }
               
        }
        else
        {
            cout << "Número de empleado inválido." << endl;
            cout << "Ingrese el numero de empleado (100 a 129), o 0 para salir: ";
            cin >> entrada;
        }
    }
}

//Sobrecarga de la función validar( no recibe el valor booleano) Simplificada para seguir validando una vez
//que ya se ingresaron datos al menos 1 vez.
bool ValidarNumeroEmpleado(int& numeroEmpleado, string& entrada){
    while (true)
    {
        if (EsUnNumero(entrada))
        {
            numeroEmpleado = stoi(entrada);
            if (numeroEmpleado == 0)
            {
                cout << "Volviendo al menú principal..." << endl;
                return false;
            }
            else if (numeroEmpleado < 100 || numeroEmpleado > 129)
            {   
                cout << "Número de empleado inválido." << endl;
                cout << "Ingrese el numero de empleado (100 a 129), o 0 para salir: ";
                cin >> entrada;
            }else{
                return true;
            }
               
        }
        else
        {
            cout << "Número de empleado inválido." << endl;
            cout << "Ingrese el numero de empleado (100 a 129), o 0 para salir: ";
            cin >> entrada;
        }
    }
}

// Función para validar solo números.
bool EsUnNumero(const string &entrada)
{
    for (char c : entrada)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}