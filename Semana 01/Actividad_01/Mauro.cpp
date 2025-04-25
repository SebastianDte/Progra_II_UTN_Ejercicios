#include <iostream>

using namespace std;

//DECLARACION

void mostrarMatrizFecha(int matrizFecha[12][31]);
void mostrarDiasconEmpleados(int matrizFecha[12][31]);
void mostrarDiasnoTrabajados(int matrizFecha[12][31]);
void mostrarHsEmpleado(int matriz[30][1]);


int main()

{

/*
    Una empresa lleva un registro de asistencia de sus 30 empleados. Cada vez que un empleado asiste al trabajo,
    se registra la siguiente información:
    Número de empleado (100 a 129)
    Mes (1 a 12)
    Día (1 a 31)
    Horas trabajadas en el día
    Los registros finalizan cuando se ingresa un número de empleado igual a 0.

    Al finalizar la carga de datos, se debe calcular:

    1)Para cada mes del año, mostrar cuántos días tuvieron al menos un empleado presente.
    2)Listar los días del año en los que ningún empleado trabajó.
    3)Por cada empleado, indicar el número de empleado y la cantidad de horas trabajadas en total en el año.

    RTA: una matriz 30x3--> numEmpleado
*/

    int numEpleado,mes,dia,hs;
    int matrizFecha[12][31] = {};
    int matrizHorasEmpleado[30][1] = {};

    cout<<"Ingrese el numero de empleado: ";
    cin>>numEpleado;
    cout<<endl;

    while( numEpleado !=0){

        cout<<"Ingrese el mes: ";
        cin>>mes;
        cout<<endl;
        cout<<"Ingrese el dia: ";
        cin>>dia;
        cout<<endl;
        cout<<"Ingrese las horas: ";
        cin>>hs;
        cout<<endl;

        matrizFecha[mes-1][dia-1] += 1;

        matrizHorasEmpleado[numEpleado-1][0]+= hs;


        cout<<"Ingrese el numero de empleado: ";
        cin>>numEpleado;
        cout<<endl;
    }

   /*
    mostrarMatrizFecha(matrizFecha);
   */

    // Punto 1

    cout<<"******Punto 1**********"<<endl;
    cout<<endl;
    mostrarDiasconEmpleados(matrizFecha);
    cout<<endl;

    // Punto 2

    cout<<"******Punto 2**********"<<endl;
    cout<<endl;
    mostrarDiasnoTrabajados(matrizFecha);
    cout<<endl;



  //Punto 3

    cout<<"*****Punto 3***********"<<endl;
    cout<<endl;
    mostrarHsEmpleado(matrizHorasEmpleado);
    cout<<endl;

    return 0;
}

// DEFINICION

void mostrarMatrizFecha(int matrizFecha[12][31]){

    for(int f=0;f<12;f++){

        for(int c=0;c<31;c++){

            cout<<matrizFecha[f][c]<<" ";

        }
        cout<<endl;
    }

}

void mostrarDiasconEmpleados(int matrizFecha[12][31]){

    for(int f=0;f<12;f++){

        int acu=0;
        bool bandSinEmpleados= true;

        for(int c=0;c<31;c++){

            if ( matrizFecha[f][c] != 0){

                bandSinEmpleados= false;

                acu += matrizFecha[f][c];
            }
        }

        if (bandSinEmpleados== false){

           cout<<"El mes "<<f+1<<" tuvieron "<<acu<<" empleados."<<endl;

        }

    }

}

void mostrarDiasnoTrabajados(int matrizFecha[12][31]){


    for (int f=0;f<12;f++){

        for (int c=0;c<31;c++){

            if( matrizFecha[f][c] == 0){

                cout<<"El dia "<<c+1<<" del mes "<<f+1<<" ningun empleado trabajo."<<endl;

            }

        }
    }


}

void mostrarHsEmpleado(int matrizHorasEmpleado[30][1]){

    for(int f=0;f<30;f++){

        for(int c=0;c<1;c++){

            cout<<"El empleado: "<<f+1<<" trabajo "<<matrizHorasEmpleado[f][c]<<" horas en el año."<<endl;

        }
        cout<<endl;
    }

}









