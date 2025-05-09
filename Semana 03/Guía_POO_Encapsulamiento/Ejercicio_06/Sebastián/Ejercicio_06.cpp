#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

// Crea una clase llamada Punto que represente un punto en un plano cartesiano. La clase debe contener los siguientes atributos:
// x (float): Almacena la coordenada en el eje X.
// y (float): Almacena la coordenada en el eje Y.
// Implementa los siguientes métodos públicos:
// Punto(float xInicial, float yInicial): Constructor que inicializa las coordenadas x y y del punto.
// Getters y Setters para cada atributo.
// calcularDistancia(Punto otroPunto): Devuelve la distancia entre el punto actual y otro punto dado. La fórmula para calcular la distancia entre dos puntos (x1, y1) y (x2, y2) es: sqrt((x2 - x1)^2 + (y2 - y1)^2).
// mover(float deltaX, float deltaY): Mueve el punto sumando deltaX a x y deltaY a y.

class Punto{
private:
    float x;
    float y;
    public:
    //Constructor
    Punto(float xInicial, float yInicial) : x(xInicial), y(yInicial) {}
    //Getters
    float getX() const { return x; }
    float getY() const { return y; }
    //Setters
    void setX(float xNuevo) { x = xNuevo; }
    void setY(float yNuevo) { y = yNuevo; }
    //Método para calcular la distancia entre dos puntos
    float calcularDistancia(const Punto& otroPunto) const {
        return sqrt(pow(otroPunto.x - x, 2) + pow(otroPunto.y - y, 2));
    }
    //Método para mover el punto
    void mover(float deltaX, float deltaY) {
        x += deltaX;
        y += deltaY;
    }

};

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    
    // Crear dos puntos
    Punto punto1(3.0, 4.0);
    Punto punto2(6.0, 8.0);

    // Mostrar las coordenadas iniciales
    cout << "Punto 1: (" << punto1.getX() << ", " << punto1.getY() << ")" << endl;
    cout << "Punto 2: (" << punto2.getX() << ", " << punto2.getY() << ")" << endl;

    // Calcular y mostrar la distancia entre los puntos
    cout << "Distancia entre punto 1 y punto 2: " << punto1.calcularDistancia(punto2) << endl;

    // Mover el punto 1 y mostrar las nuevas coordenadas
    punto1.mover(2.0, 3.0);
    cout << "Punto 1 después de moverlo: (" << punto1.getX() << ", " << punto1.getY() << ")" << endl;

    // Calcular y mostrar la nueva distancia
    cout << "Nueva distancia entre punto 1 y punto 2: " << punto1.calcularDistancia(punto2) << endl;
    return 0;
}