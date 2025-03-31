#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
using namespace std;

void cargarPuntos ( int matriz[4][4]);

bool validacionEmpate( int matriz[4][4],int &j1,int &j2,int &Pj1,int &Pj2);

bool validacionMismoJ( int matriz[4][4],int &j1,int &j2);

void mostrarTabla( int matriz[4][4]);

void reiniciarCampeonato( int matriz[4][4]);

void menu( int &opcion, int matriz[4][4] );




#endif // FUNCIONES_H_INCLUDED
