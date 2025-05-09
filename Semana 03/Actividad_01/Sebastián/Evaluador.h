#pragma once
#include "Postulante.h"

class Evaluador
{
private:
    int _cantidadEvaluados;
    int _cantidadRechazados;
public:
    Evaluador(); // Constructor para inicializar los contadores
    bool evaluar(Postulante postulante);
    int getCantidadEvaluados() ;
    int getCantidadRechazados() ;
};


