// Postulante.h
#pragma once
#include <string>



// Clase que representa a un postulante para un puesto de trabajo.
class Postulante {
private:
    // Atributo que almacena el nombre del postulante.
    std::string _nombre;

    // Atributo que almacena la edad del postulante.
    int _edad;

    // Atributo que almacena los años de experiencia laboral del postulante.
    int _experiencia;

    // Atributo que almacena el puesto al que aplica el postulante.
    std::string _puesto;

public:
    // Método para obtener el nombre del postulante.
    std::string getNombre();

    // Método para establecer el nombre del postulante.
    void setNombre(std::string nombre);

    // Método para obtener la edad del postulante.
    int getEdad();

    // Método para establecer la edad del postulante.
    void setEdad(int edad);

    // Método para obtener los años de experiencia del postulante.
    int getExperiencia();

    // Método para establecer los años de experiencia del postulante.
    void setExperiencia(int experiencia);

    // Método para obtener el puesto al que aplica el postulante.
    std::string getPuesto();

    // Método para establecer el puesto al que aplica el postulante.
    void setPuesto(std::string puesto);

    // Método para cargar los datos del postulante.
    void cargarDatos(std::string nombre, int edad, int experiencia, std::string puesto);

    // Método para mostrar los datos del postulante.
    void mostrarDatos();

};
