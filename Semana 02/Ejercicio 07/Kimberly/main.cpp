// Guía de Ejercicios de Memoria Dinámica

/*
Escribe un programa que simule la gestión de un club de lectura.
El programa debe solicitar al usuario la cantidad de libros que desea cargar y posteriormente pedir los nombres de dichos libros. Una vez cargados los libros se debe mostrar un menú  con las siguientes opciones:
1- Listado: Debe listar los libros en el orden en que fueron cargados.
2- Tiempo de lectura: Se solicita el nombre del libro. Si no existe debe mostrar un mensaje aclaratorio. Si el libro existe, ingresar la cantidad de minutos que le llevó su lectura.
3- Ranking: Mostrar los libros ordenados por tiempo de lectura de Mayor a Menor.
4- Salir: el programa debe salir del programa
*/

#include <iostream>
using namespace std;


struct Libro
{
    string titulo;
    int tiempoLectura;
};


void mostrarMenu(int &opcion, Libro* &vec, int &numeroElementos);
void reservarMemoria(Libro* &vec, int numeroElementos);
void cargarVector(Libro* &vec, int &numeroElementos, string mensajeCarga = "Ingrese la cantidad de elementos a cargar: ", string mensajeElemento = "Ingrese el valor para el elemento #");
void listarLibros(Libro* libros, int numeroLibros);
void cargarTiempoLectura(Libro* &libros, int numeroLibros);
Libro* ordenarVector(Libro* libros, int numeroLibros);
void mostrarRanking(Libro* libros, int numeroLibros);


int main()
{

    int opcion;
    Libro* vecLibros = nullptr;
    int numeroElementos;

    cargarVector(vecLibros, numeroElementos, "Ingrese la cantidad de libros a cargar: ", "Ingrese el nombre del libro #");

    mostrarMenu(opcion, vecLibros, numeroElementos);

    delete []vecLibros;
    vecLibros = nullptr;

    return 0;
}


void mostrarMenu(int &opcion, Libro* &vec, int &numeroElementos)
{
    do
    {
        system("cls");
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Listado\n";
        cout << "2. Tiempo de lectura\n";
        cout << "3. Ranking\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case 1:
            listarLibros(vec, numeroElementos);
            break;
        case 2:
            cargarTiempoLectura(vec, numeroElementos);
            break;
        case 3:
            mostrarRanking(vec, numeroElementos);
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Intentalo de nuevo.\n";
        }
        cout << "\nPresiona Enter para continuar...";
        cin.ignore();
        cin.get();

    }
    while (opcion != 4);

    cout << "Hasta luego!\n";
}


void reservarMemoria(Libro* &vec, int numeroElementos)
{
    vec = new Libro[numeroElementos];
    if (vec == nullptr)
    {
        cout << "Error al asignar memoria." << endl;
        exit(1);
    }
}


void cargarVector(Libro* &vec, int &numeroElementos, string mensajeCarga, string mensajeElemento)
{
    cout << mensajeCarga;
    cin >> numeroElementos;
    cin.ignore(); //limpiamos el buffer

    reservarMemoria(vec, numeroElementos);

    for (int i = 0; i < numeroElementos; ++i)
    {
        cout << mensajeElemento << i + 1 << ": ";
        getline(cin, vec[i].titulo); // utilizamos getline para poder obtener nombres con espacios.
        vec[i].tiempoLectura = 0; // inicializo en 0 paraevitar errores mas adelante.
    }
    return;
}


void listarLibros(Libro* libros, int numeroLibros)
{
    for (int i = 0; i < numeroLibros; ++i)
    {
        cout << i + 1 << ". " << libros[i].titulo << endl;;
    }
}



void cargarTiempoLectura(Libro* &libros, int numeroLibros)
{

    string titulo;
    bool existe= false;
    cin.ignore();
    cout << "Ingrese el nombre del libro: ";
    getline(cin, titulo);

    for (int i = 0; i < numeroLibros; ++i)
    {
        if(libros[i].titulo == titulo)
        {
            cout << "Ingrese el tiempo de lectura: ";
            cin >> libros[i].tiempoLectura;
            cin.ignore();
            existe = true;
            cout << "Tiempo de lectura registrado correctamente." << endl;
            break;
        }
    }

    if (!existe)
    {
        cout << "El libro indicado no se encuentra en la lista" << endl;
    }
}


Libro* ordenarVector(Libro* libros, int numeroLibros)
{
    Libro aux;
    Libro* auxLibros = nullptr;

    reservarMemoria(auxLibros, numeroLibros);

    for (int i = 0; i < numeroLibros; ++i)
    {
        auxLibros[i] = libros[i];
    }

    for (int i = 0; i < numeroLibros - 1; ++i)
    {
        //cout << "Posicion de i: " << i << " Valor de i: " << vecAux[i] << endl;

        for (int j = i + 1; j < numeroLibros; ++j)
        {
            //cout << "Posicion de j: " << j << " Valor de j: " << vecAux[j] << endl;

            if((auxLibros[i].tiempoLectura < auxLibros[j].tiempoLectura))
            {
                aux = auxLibros[i];
                auxLibros[i] = auxLibros[j];
                auxLibros[j] = aux;
            }
        }
    }

    return auxLibros;
}


void mostrarRanking(Libro* libros, int numeroLibros)
{
    Libro* librosOrdenados = ordenarVector(libros, numeroLibros);
    cout << "============RANKING============"<< endl;
    for (int i = 0; i < numeroLibros; ++i)
    {
        cout << i + 1 << ": " << librosOrdenados[i].titulo << "\t Tiempo de lectura: " << librosOrdenados[i].tiempoLectura << endl;
    }

    delete []librosOrdenados;
    librosOrdenados = nullptr;
}
