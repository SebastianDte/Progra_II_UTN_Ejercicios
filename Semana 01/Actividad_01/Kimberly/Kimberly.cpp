//FUNCIONES Y ARRAYS
/*
📋 Actividad: Control de Asistencias en la Empresa 🏢
Una empresa lleva un registro de asistencia de sus 30 empleados. Cada vez que un empleado asiste al trabajo, se registra la siguiente información:
● Número de empleado (100 a 130)
● Mes (1 a 12)
● Día (1 a 31)
● Horas trabajadas en el día
Los registros fi nalizan cuando se ingresa un número de empleado igual a 0.
Al fi nalizar la carga de datos, se debe calcular:
1. Para cada mes del año, mostrar cuántos días tuvieron al menos un empleado presente.
2. Listar los días del año en los que ningún empleado trabajó.
3. Por cada empleado, indicar el número de empleado y la cantidad de horas trabajadas en total en el año.
*/
#include <iostream>
using namespace std;

void validarNumeroEmpleado(int &numeroEmpleado);
void validarDia(int &dia);
void validarMes(int &mes);
void mostrarAsistenciaPorMes(int controlAsistencia[][31], int meses = 12, int dias = 31); // parametros por default solo una vez al declarar la funcion
void listarDiasSinTrabajar(int controlAsistencia[][31], int meses = 12, int dias = 31);
void mostrarHorasTrabajadasEmpleados(float horasTrabajadasEmpleados[], int tam);

int main()
{
    const int CANTIDAD_EMPLEADOS = 30;
    int numeroEmpleado, dia, mes;
    int controlAsistencia[12][31] = {};
    float horasTrabajadas;
    float horasTrabajadasEmpleados[CANTIDAD_EMPLEADOS] = {};

    cout<<"Ingrese el numero de empleado (101 - 130) "<< endl;
    cin>>numeroEmpleado;

    while(numeroEmpleado!=0)
    {
        cout<<"ingresa el mes: "<<endl;
        cin>> mes;
        validarMes(mes);

        cout<<"ingresa el dia: "<<endl;
        cin>> dia;
        validarDia(dia);

        cout << "Ingresar hora trabajadas" << endl;
        cin >> horasTrabajadas;

        controlAsistencia[mes-1][dia-1]++; // por cada empleado sumamos una asistencia en el dia y mes indicado.
        horasTrabajadasEmpleados[numeroEmpleado - 101] += horasTrabajadas;

        cout<<"Ingresa el numero de empleado (101 - 130)"<<endl;
        cin>>numeroEmpleado;

        validarNumeroEmpleado(numeroEmpleado);
    }

    mostrarAsistenciaPorMes(controlAsistencia);
    listarDiasSinTrabajar(controlAsistencia);
    mostrarHorasTrabajadasEmpleados(horasTrabajadasEmpleados, CANTIDAD_EMPLEADOS);

    return 0;
}


void validarNumeroEmpleado(int &numeroEmpleado)
{
    while ((numeroEmpleado < 101 || numeroEmpleado > 130)&& numeroEmpleado != 0)
    {
        cout << "Ingrese un numero de empleado valido entre 101 y 130: ";
        cin >> numeroEmpleado;
    }
}

void validarMes(int &mes)
{
    while (mes < 1 || mes > 12)
    {
        cout << "Ingrese un mes valido entre 1 y 12: ";
        cin >> mes;
    }
}

void validarDia(int &dia)
{
    while (dia < 1 || dia > 31)
    {
        cout << "Ingrese un dia valido entre 1 y 31: ";
        cin >> dia;
    }
}


void mostrarAsistenciaPorMes(int controlAsistencia[][31], int meses, int dias) // parametros por default solo una vez al declarar la funcion
{

    for (int mes = 0; mes < meses; ++mes )
    {
        int diasPresentismo = 0;
        cout << "====== MES #" << mes + 1 << "======\n";
        for (int dia = 0; dia < dias; ++dia)
        {
            if(controlAsistencia[mes][dia] != 0)
            {
                diasPresentismo++;
            }
        }
        cout << "La cantidad de dias con al menos un empleado presente fue de: " <<  diasPresentismo << endl;
        cout << endl;
    }
}

void listarDiasSinTrabajar(int controlAsistencia[][31], int meses, int dias){

for (int mes = 0; mes < meses; ++mes )
    {
        cout << "====== DIAS QUE NO SE TRABAJO" << "======\n";
        cout << "====== MES #" << mes + 1 << "======\n";
        for (int dia = 0; dia < dias; ++dia)
        {
            if(controlAsistencia[mes][dia] == 0)
            {
                cout << "Dia: " <<  dia + 1<< endl;
            }
        }
        cout << endl;
    }
}

void mostrarHorasTrabajadasEmpleados(float horasTrabajadasEmpleados[], int tam){

    for (int empleado = 0; empleado < tam; ++empleado){
        cout << "El empleado con el ID #" << empleado + 101 << " tiene un total de horas trabajadas de: " << horasTrabajadasEmpleados[empleado] << endl;
    }

}



