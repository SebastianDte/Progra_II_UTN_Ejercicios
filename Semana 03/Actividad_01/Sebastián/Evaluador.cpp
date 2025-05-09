#include "Evaluador.h"
#include <iostream>
#include <string>
#include "Postulante.h"

//Constructor para inicializar los contadores
Evaluador::Evaluador() {
    _cantidadEvaluados = 0;
    _cantidadRechazados = 0;
}

bool Evaluador::evaluar(Postulante postulante) {
    
    // Verificar si la edad está dentro del rango permitido
    if (postulante.getEdad() < 22 || postulante.getEdad() > 50) {
        _cantidadRechazados++;
        return false;
    }

    // Verificar si la experiencia es suficiente
    if (postulante.getExperiencia() < 2) {
        _cantidadRechazados++;
        return false;
    }

    // Verificar si el puesto es aceptado
    if (postulante.getPuesto() != "Programador" && postulante.getPuesto() != "Tester" && postulante.getPuesto() != "Diseñador") {
        _cantidadRechazados++;
        return false;
    }

    _cantidadEvaluados++;
    return true;
}
int Evaluador::getCantidadEvaluados(){
    return _cantidadEvaluados;
}

int Evaluador::getCantidadRechazados(){
    return _cantidadRechazados;
}