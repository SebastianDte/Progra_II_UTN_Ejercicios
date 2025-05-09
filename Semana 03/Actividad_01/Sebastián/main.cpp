#include <iostream>
#include <locale>
#include <string>
#include "Postulante.h"
#include "Evaluador.h"

using namespace std;
// Actividad de Programación Orientada a Objetos
// Encapsulamiento con Constructores
// 🧾 Evaluación de Postulantes en una Empresa de Tecnología
// Una empresa de tecnología está diseñando un sistema para evaluar a las personas que se postulan a distintos puestos de trabajo. El sistema debe permitir registrar los datos de cada persona, evaluar si cumple ciertos requisitos mínimos y llevar un registro de las evaluaciones realizadas.

// 🧑‍💻 Historias de Usuario
// Como reclutador, quiero poder registrar la información de una persona que se postula, incluyendo su nombre, edad, puesto al que aplica y años de experiencia laboral.
// Como reclutador, quiero poder evaluar si una persona cumple con los requisitos mínimos para continuar en el proceso de selección.
// Como empresa, necesito que los criterios de evaluación sean:


// La persona debe tener entre 22 y 50 años inclusive.
// Debe contar con al menos 2 años de experiencia laboral.
// El puesto al que aplica debe ser uno de los aceptados (por ejemplo: Programador, Tester o Diseñador).


// Como reclutador, quiero que el sistema me indique con claridad si la persona pasó o no la evaluación, y que además me permita llevar un conteo total de personas evaluadas y cuántas fueron rechazadas.


// Como reclutador, quiero poder ver cuántas personas han sido evaluadas hasta el momento, y de ellas, cuántas no cumplieron los requisitos.
// EXTRA:
// Como reclutador quiero poder establecer los criterio de evaluación, edad mínima, edad máxima, experiencia mínima y puesto

#include <vector>


int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    Evaluador evaluador;
    vector<Postulante> postulantes; // Contenedor dinámico para los postulantes

    string nombre, puesto;
    int edad, experiencia;
    char continuar;

    do {
        cout << "Ingrese los datos del postulante:" << endl;

        cout << "Nombre: ";
        cin.ignore(); // Ignorar cualquier salto de línea pendiente
        getline(cin, nombre);

        cout << "Edad: ";
        cin >> edad;

        cout << "Años de experiencia: ";
        cin >> experiencia;

        cout << "Puesto al que aplica: ";
        cin.ignore(); // Ignorar salto de línea pendiente
        getline(cin, puesto);

        // Crear un nuevo objeto Postulante y cargar los datos
        Postulante nuevoPostulante;
        nuevoPostulante.cargarDatos(nombre, edad, experiencia, puesto);

        // Agregar el postulante al vector
        postulantes.push_back(nuevoPostulante);

        // Evaluar al postulante
        evaluador.evaluar(nuevoPostulante);

        cout << "¿Desea ingresar otro postulante? (s/n): ";
        cin >> continuar;

    } while (tolower(continuar) == 's'); // Continuar mientras el usuario diga 's'

    // Mostrar resultados
    cout << "\nCantidad de postulantes evaluados: " << evaluador.getCantidadEvaluados() << endl;
    cout << "Cantidad de postulantes rechazados: " << evaluador.getCantidadRechazados() << endl;

    // Mostrar los datos de todos los postulantes
    for (size_t i = 0; i < postulantes.size(); ++i) {
        cout << "\nPostulante " << i + 1 << ":" << endl;
        postulantes[i].mostrarDatos();
        cout << "Resultado: " << (evaluador.evaluar(postulantes[i]) ? "Aprobado" : "Rechazado") << endl;
    }

    return 0;
}