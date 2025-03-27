//FUNCIONES Y ARRAYS
//Actividad: Torneo Relámpago

/*
Un grupo de 4 jugadores se enfrenta en un torneo donde todos juegan contra todos una vez. Después de cada partido, se anotan los puntos obtenidos.
📌 Tu misión:
Debes programar un sistema con un menú que permita gestionar el torneo con las siguientes opciones:
📋 Menú del Torneo
1 - Cargar Puntos
Pide el número de dos jugadores que se enfrentaron y sus respectivos puntos
2 - Mostrar Tabla
Muestra la tabla de enfrentamientos
3 - Reiniciar Campeonato
Borra los resultados y deja todo en cero
0 - Salir
	Cierra el programa

📖 Reglas:
Cada partido tiene un ganador. No hay empates.
Se registran los puntos de ambos jugadores en la tabla [A][B] y [B][A].
No se permiten partidos contra uno mismo (si ingresan el mismo número dos veces, se debe mostrar un error).
La tabla debe mostrarse como una matriz de 4x4 donde la diagonal principal no se usa.
*/

#include <iostream>
using namespace std;

void mostrarMenu(int &opcion, int tablaPuntajes[][4], int filas = 4, int columnas = 4);
void cargarPuntos(int tablaPuntajes[][4], int filas = 4, int columnas = 4);
void validarNumeroJugador(int &numeroJugador);
void controlarJugadores(int &primerJugador, int &segundoJugador);
void mostrarTablaPuntaje(int tablaPuntajes[][4], int filas = 4, int columnas = 4);
void reiniciarCampeonato(int tablaPuntajes[][4], int filas = 4, int columnas = 4);
void validarEmpate(int &puntajePrimerJugador, int &PuntajeSegundoJugador);

int main()
{
    int opcion;
    int tablaPuntajes[4][4] = {};
    mostrarMenu(opcion, tablaPuntajes);

    return 0;
}

void mostrarMenu(int &opcion, int tablaPuntajes[][4], int filas, int columnas)
{
    do
    {
        system("cls");
        cout << "===== MENU PRINCIPAL =====\n";
        cout << "1 - Cargar Puntos\n";
        cout << "2 - Mostrar Tabla\n";
        cout << "3 - Reiniciar Campeonato\n";
        cout << "0 - Salir\n";
        cout << "\nElige una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            cargarPuntos(tablaPuntajes);
            break;
        case 2:
            mostrarTablaPuntaje(tablaPuntajes);
            break;
        case 3:
            reiniciarCampeonato(tablaPuntajes);
            cout << "Se han reiniciado los resultados de la tabla.\n";
            break;
        case 0:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Intentalo de nuevo.\n";
        }
        cout << "\nPresiona Enter para continuar...";
        cin.ignore();
        cin.get();
    }
    while(opcion != 0);
    cout << "Hasta luego!\n";
}

void cargarPuntos(int tablaPuntajes[][4], int filas, int columnas)
{

    bool cargarPuntos = false;
    int numeroPrimerJugador;
    int numeroSegundoJugador;
    int puntosPrimerJugador;
    int puntosSegundoJugador;
    char opcion;
    while(!cargarPuntos)
    {
        system("cls");
        cout << "Ingrese numero del primer jugador (1-4): ";
        cin >> numeroPrimerJugador;
        validarNumeroJugador(numeroPrimerJugador);
        cout << endl;

        cout << "Ingrese numero del segundo jugador (1-4): ";
        cin >> numeroSegundoJugador;

        validarNumeroJugador(numeroSegundoJugador);
        controlarJugadores(numeroPrimerJugador, numeroSegundoJugador);
        cout << endl;

        cout << "Ingrese puntos de J1: ";
        cin >> puntosPrimerJugador;
        cout << endl;
        cout << "Ingrese puntos de J2: ";
        cin >> puntosSegundoJugador;
        cout << endl;

        validarEmpate(puntosPrimerJugador, puntosSegundoJugador);

        // puntaje jugador 1
        tablaPuntajes[numeroPrimerJugador - 1 ][numeroSegundoJugador - 1] = puntosPrimerJugador;

        //puntaje jugador 2
        tablaPuntajes[numeroSegundoJugador - 1][numeroPrimerJugador - 1] = puntosSegundoJugador;

        cout << "Presione S para seguir cargando puntaje o N para salir: ";
        cin >> opcion;

        if (opcion == 'N' || opcion == 'n')
        {
            break;
        }
    }
}


void validarNumeroJugador(int &numeroJugador)
{
    while(numeroJugador < 1 || numeroJugador > 4)
    {
        cout << "Numero de jugador invalido. Ingrese un rango valido entre 1 y 4: ";
        cin >> numeroJugador;
    }
}


void controlarJugadores(int &primerJugador, int &segundoJugador)
{
    while (primerJugador == segundoJugador)
    {
        cout << "Los jugadores no pueden ser iguales. Ingrese el segundo jugador nuevamente: ";
        cin >> segundoJugador;
    }
}


void mostrarTablaPuntaje(int tablaPuntajes[][4], int filas, int columnas)
{
    cout << "\tJ1 \tJ2 \tJ3 \tJ4\n";
    for (int fila = 0; fila < filas; ++fila)
    {
        cout << "J" << fila + 1 << "\t";
        for (int col = 0; col < columnas; ++col)
        {
            if(fila == col)
            {
                cout << "-" << "\t";
            }
            else
            {
                cout << tablaPuntajes[fila][col] << "\t";
            }
        }
        cout << endl;
    }
}


void reiniciarCampeonato(int tablaPuntajes[][4], int filas, int columnas){
    for (int fila = 0; fila < filas; ++fila)
    {
        for (int col = 0; col < columnas; ++col)
        {
            if(fila == col)
            {
               tablaPuntajes[fila][col] = '-';
            }
            else
            {
                tablaPuntajes[fila][col] = 0;
            }
        }
    }
}


void validarEmpate(int &puntajePrimerJugador, int &PuntajeSegundoJugador){
    while(puntajePrimerJugador == PuntajeSegundoJugador){
        cout << "Cada partido solo puede tener un ganador. No se permite el empate. Vuelve a cargar los puntajes correctos.\n";
        cout << "Ingrese puntos de J1: ";
        cin >> puntajePrimerJugador;
        cout << endl;
        cout << "Ingrese puntos de J2: ";
        cin >> PuntajeSegundoJugador;
        cout << endl;
    }
}
