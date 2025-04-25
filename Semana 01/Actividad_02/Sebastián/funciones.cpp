#include <iostream>
#include "funciones.h"
using namespace std;


void pausa() {
    cout << "Presione Enter para continuar...";
    cin.ignore(); // Ignora cualquier entrada previa en el buffer
    cin.get();    // Espera a que el usuario presione Enter
}

void cargarPuntos(int puntos [][4],int jugador1, int jugador2, int puntosJ1, int puntosJ2) {
    // Cargar los puntos en la matriz
    cout << "Cargando puntos..." << endl;
    cout << "Ingrese número del primer jugador (1-4): ";
    cin >> jugador1;
    cout << "Ingrese número del segundo jugador (1-4): ";
    cin >> jugador2;
    cout << "Ingrese puntos de J" << jugador1 << ": " << puntosJ1 << endl;
    cin >> puntosJ1;
    cout << "Ingrese puntos de J" << jugador2 << ": " << puntosJ2 << endl;
    cin >> puntosJ2;
    if(jugador1 < 1 || jugador1 > 4 || jugador2 < 1 || jugador2 > 4) {
        cout << "Error: Jugadores deben ser entre 1 y 4." << endl;
        pausa();
        system("cls");   
        return;
    }
    if(jugador1 == jugador2) {
        cout << "Error: Un jugador no puede enfrentarse a sí mismo." << endl;
        pausa(); 
        system("cls");   
        return;
    }
    puntos[jugador1 - 1][jugador2 - 1] += puntosJ1;
    puntos[jugador2 - 1][jugador1 - 1] += puntosJ2;
    cout << "Puntos cargados correctamente." << endl;
    pausa(); 
    system("cls");   
  
    
}

void reiniciarCampeonato(int puntos[][4]) {
    // Reiniciar la matriz a cero
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            puntos[i][j] = 0;
        }
    }
    cout << "Se han reiniciado todos los puntajes." << endl;
    pausa(); 
    system("cls");  
}

void mostrarTabla(int puntos[][4]) {
    // Mostrar la tabla de enfrentamientos
    system("cls");
    cout << "     J1  J2  J3  J4" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "J" << (i + 1) << "  ";
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                cout << " -   ";
            } else {
                cout << puntos[i][j] << "   ";
            }
        }
        cout << endl;
    }
    pausa(); 
    system("cls");
}

