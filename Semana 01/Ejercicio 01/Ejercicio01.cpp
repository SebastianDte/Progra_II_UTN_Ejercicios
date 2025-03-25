#include <iostream>
#include <locale>
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

//Firma de Función | Para el punto A Y B.
void PuntoAB(int Asistencias[30][31][12],int MTamanio,int DTamanio,int ETamanio);
//Firma de Función | Para el punto C.
void PuntoC(int VAcuEmpleados[], int tamanio);
//Validaciones.
void Validaciones(int &numeroEmpleado, int &mes, int &dia);

int main()
{
   setlocale(LC_ALL, "es_ES.UTF-8");

   //DECLARACIÓN DE VARIABLES CONSTANTES.
   int const DIAS = 31;
   int const MESES = 12;
   int const EMPLEADOS = 30;
    //MATRIZ 3X3.
   int Asistencias[EMPLEADOS][DIAS][MESES]={};
   //Variables locales.
    int numeroEmpleado = 0, dia = 0, mes = 0, horasTrabajadas;
    //Vector para acumular las horas trabajadas para cada empleado - Punto C.
    int  VAcuEmpleados[EMPLEADOS] = {};

    //Lote pincipal
   do
   {
    //Carga de datos
    cout <<  "Ingrese el numero de empleado (100 a 129): "<<endl;
    cin >> numeroEmpleado;
    if(numeroEmpleado==0)break;
    cout << "Ingrese el Mes(1 a 12): " << endl;
    cin >> mes;
    cout << "Ingrese el Día (1 a 31): " << endl;
    cin >> dia;

    // Validación de los datos ingresados
    Validaciones(numeroEmpleado, mes, dia);

    cout << "Ingrese las horas trabajadas en el día: " << endl;
    cin >> horasTrabajadas;

    //ACUMULADOR DE HORAS PARA EL PUNTO C.
    VAcuEmpleados[numeroEmpleado-100]+=horasTrabajadas;

    //Carga de datos en la matriz:
    Asistencias[numeroEmpleado-100][dia-1][mes-1]=horasTrabajadas;

   } while (numeroEmpleado!=0);
   
   PuntoAB(Asistencias,MESES,DIAS,EMPLEADOS);
   PuntoC(VAcuEmpleados,EMPLEADOS);

   return 0;
}

//Función Punto A + Punto B
void PuntoAB(int Asistencias[30][31][12],int MTamanio,int DTamanio,int ETamanio){

    const int totalDiasAlAno = 372; 
    bool VDiasNoWork[totalDiasAlAno] = {false}; // Inicializamos todos los días a false

    //Mensajes para diferenciar las partes.
    cout << "\n====================================" << endl;
    cout << "Cuántos días tuvieron al menos un empleado presente " << endl;
    cout << "Filtrado por cada mes del año " << endl;
    cout << "\n" << endl;
     
    for (int m = 0; m < MTamanio; m++)
    {
       //Contador para cuántos días tuvieron al menos un empleado presente.
        int contador = 0;
        for (int d = 0; d < DTamanio; d++)
        {
            //Bandera para contador de Días.
            bool diaConEmpleado = false;
            for (int e = 0; e < ETamanio; e++)
            {
                if(Asistencias[e][d][m] != 0)
                {
                    diaConEmpleado = true;
                    break;
                }
            }

            //En el día actual trabajó alguien ?
            if (diaConEmpleado) {
                contador++;    
            }else{
               // Si es falso, no se trabajó.
               VDiasNoWork[m * DTamanio + d] = true; // Mapeo del vector.
            }
        }
        if(contador!=0){
            
            cout << "MES: " << m + 1 << endl;
             cout << "En " << contador << " Días hubo empleados presentes" << endl;
        }
       
    }

   
    // Mostrar los días en los que no se trabajó.
    cout << "\n====================================" << endl;
    cout << "DÍAS SIN TRABAJO EN EL AÑO" << endl;
    cout << "\n" << endl;

   for (int i = 0; i < totalDiasAlAno; i++) {
       if (VDiasNoWork[i]) {
          
            //Cálculo del Día.
           int dia = (i % DTamanio) + 1; 
           int mes = i / DTamanio; 
           
           // Meses
           string nombresMes[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
           
           cout << "Día " << dia << " de " << nombresMes[mes] << endl;
       }
   }   
  
}

//Función Punto C - Cantidad de horas trabajadas en total en el año de cada empleado.
void PuntoC(int VAcuEmpleados[], int tamanio) {
    cout << "\n=================================================" << endl;
    cout << "Total de HS trabajadas en el año por cada Empleado" << endl;
    cout << "\n" << endl;

    for (int i = 0; i < tamanio; i++) {
        if(VAcuEmpleados[i] != 0){
        cout << "Empleado " << i + 100 << ": ";
        cout << "Horas trabajadas en el año: " << VAcuEmpleados[i] << " hs." << endl;
        }
    }
}

void Validaciones(int &numeroEmpleado, int &mes, int &dia) {
    bool Validacion = false;
    
    // Validación del número de empleado
    do {
        if (numeroEmpleado < 100 || numeroEmpleado > 129) {
            cout << "Numero de empleado invalido. Ingrese un numero entre 100 y 129: ";
            cin >> numeroEmpleado;
        } else {
            Validacion = true;
        }
    } while (!Validacion);
    
    // Validación del mes
    Validacion = false;  
    do {
        if (mes < 1 || mes > 12) {
            cout << "Mes ingresado incorrecto. Ingrese un mes entre 1 y 12: ";
            cin >> mes;
        } else {
            Validacion = true;
        }
    } while (!Validacion);
    
    // Validación del día
    Validacion = false;
    do {
        if (dia < 1 || dia > 31) {
            cout << "Día ingresado incorrecto. Ingrese un día entre 1 y 31: ";
            cin >> dia;
        } else {
            Validacion = true;
        }
    } while (!Validacion);
}
