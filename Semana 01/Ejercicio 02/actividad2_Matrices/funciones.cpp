#include "funciones.h"
#include <iostream>
using namespace std;

void cargarPuntos(int matriz[4][4]){

    int j1,j2,pJ1,pJ2;
    bool empate= false;
    bool mismoJugador = false;


    do
    {

        cout<<"****Carga de Puntos****"<<endl;
        cout<<endl;
        cout<<"Ingrese el numero del primer jugador (1-4): ";
        cin>>j1;
        cout<<endl;
        cout<<"Ingrese el numero del segundo jugador (1-4): ";
        cin>>j2;
        cout<<endl;
        mismoJugador = validacionMismoJ( matriz,j1,j2);

    }while( mismoJugador == true );

    do
    {

        cout<<endl;
        cout<<"Ingrese puntos del jugador "<<j1<<": ";
        cin>>pJ1;
        cout<<endl;
        cout<<"Ingrese puntos del jugador "<<j2<<": ";
        cin>>pJ2;
        empate = validacionEmpate( matriz,j1,j2,pJ1,pJ2 );

    }while( empate == true );





}

bool validacionMismoJ ( int matriz[4][4],int &j1,int &j2 ){

    if ( j1 == j2 ){
        cout<<endl;
        cout<<"Error. Los jugadores ingresados son iguales."<<endl;
        cout<<endl;

        return true;

    }else{

        return false;

    }

}

bool validacionEmpate ( int matriz[4][4], int &j1,int &j2,int &Pj1,int &Pj2 ){

    if ( Pj1 == Pj2 ){
        cout<<endl;
        cout<<"Error. Los jugadores no pueden empatar."<<endl;
        cout<<endl;

        return true;

    }else{

        matriz[j1][j2] = Pj1;
        matriz[j2][j1] = Pj2;
        return false;
    }

}

void mostrarTabla( int matriz[4][4]){

    cout<<"  ";
    for (int i = 0; i < 4; i++) {
        cout << " J" << (i + 1)<<" ";
    }
    cout <<endl;

   for (int f=0;f<4;f++){

        cout<<"J"<<f+1<<"  ";

        for(int c=0;c<4;c++){

            if( f == c){

                cout<<"-"<<"   ";

            }else{

                cout<<matriz[f][c]<<"   ";

            }

        }

        cout<<endl;
   }

}

void reiniciarCampeonato( int matriz[4][4]){

    for(int f=0;f<4;f++){

        for(int c=0;c<4;c++){

            if( matriz[f][c] != 0 ){

                matriz[f][c] = 0;

            }

        }

    }

    cout<<"Campeonato reiniciado"<<endl;
    cout<<endl;
}

void menu( int &opcion, int matriz[4][4] ){

    do
    {
        system("cls");

        cout<<endl;
        cout<<" Menu del Torneo."<<endl;
        cout<<endl;
        cout<<"1 - Cargar Puntos."<<endl;
        cout<<endl;
        cout<<"2 - Mostrar Tabla."<<endl;
        cout<<endl;
        cout<<"3 - Reiniciar Campeonato."<<endl;
        cout<<endl;
        cout<<"0 - Salir."<<endl;
        cout<<endl;

        cout<<"Ingrese una opcion"<<endl;
        cin>>opcion;

        switch (opcion)
        {
            case 1:
                system("cls");
                cargarPuntos(matriz);
                cout<<endl;
                system("pause");
                break;

            case 2:
                system("cls");
                mostrarTabla(matriz);
                cout<<endl;
                system("pause");
                break;

            case 3:
                system("cls");
                reiniciarCampeonato(matriz);
                system("pause");
                system("cls");
                mostrarTabla(matriz);
                cout<<endl;
                system("pause");
                break;


            case 0:
                system("cls");
                cout<<endl;
                cout<<"Gracias por jugar, adios!!";
                cout<<endl;
                break;
                system("pause");
            default:
            system("cls") ;
            cout<<"Ingreso Incorrecto"<<endl;
            cout<<endl;
            system("pause");
            cout<<endl;
            break;
        }

    }while( opcion != 0);

}



