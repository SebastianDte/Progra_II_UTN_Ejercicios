#include <iostream>
#include <locale>
using namespace std;

// Crea una clase llamada Rectangulo que represente un rectángulo. La clase debe tener dos atributos correspondientes a la base y altura. Implementa las siguientes metodos:
// Getters y Setter de cada atributo.
// calcularArea(): Devuelve el área del rectángulo.
// calcularPerimetro(): Devuelve el perímetro del rectángulo.

class Rectangulo{
private:
    float base;
    float altura;
public:
void setBase(float b){
        base = b;
    }
float getBase(){
        return  base;
    }
void setAltura(float a){
        altura = a;
    }
float getAltura(){
        return altura;
    }

float calcularArea(){
        return base * altura;
    }
float calcularPerimetro(){
        return 2 * (base + altura);
    }
// Constructor
Rectangulo(float b, float a){
        base = b;
        altura = a;
    }
// Destructor
~Rectangulo(){
        cout << "Destructor de Rectangulo llamado" << endl;
    }
};



int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    // Crear un objeto de la clase Rectangulo
    Rectangulo rectangulo(5.0, 3.0);
    
    
    return 0;
}