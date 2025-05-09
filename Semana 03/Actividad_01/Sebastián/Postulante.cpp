#include "Postulante.h"
#include <iostream>

std::string Postulante::getNombre() {
    return _nombre;
}

void Postulante::setNombre(std::string nombre) {
    _nombre = nombre;
}

int Postulante::getEdad() {
    return _edad;
}

void Postulante::setEdad(int edad) {
    _edad = edad;
}

int Postulante::getExperiencia() {
    return _experiencia;
}

void Postulante::setExperiencia(int experiencia) {
    _experiencia = experiencia;
}

std::string Postulante::getPuesto() {
    return _puesto;
}

void Postulante::setPuesto(std::string puesto) {
    _puesto = puesto;
}

void Postulante::cargarDatos(std::string nombre, int edad, int experiencia, std::string puesto) {
    setNombre(nombre);
    setEdad(edad);
    setExperiencia(experiencia);
    setPuesto(puesto);
}

void Postulante::mostrarDatos() {
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Edad: " << getEdad() << std::endl;
    std::cout << "Experiencia: " << getExperiencia() << std::endl;
    std::cout << "Puesto: " << getPuesto() << std::endl;
}


