#include <iostream>
#include <locale>
using namespace std;
// Crea una clase llamada Termometro que represente un termómetro digital. La clase debe contener los siguientes atributos:
// temperatura (float): Almacena la temperatura actual medida por el termómetro.
// unidad (char): Almacena la unidad de medida de la temperatura ('C' para Celsius, 'F' para Fahrenheit).
// Implementa los siguientes métodos:
// Termometro(float tempInicial, char unidadInicial): Constructor que inicializa la temperatura y la unidad de medida.
// get y set de temperatura.
// cambiarUnidad(char nuevaUnidad): Cambia la unidad de medida entre Celsius y Fahrenheit. Si la nueva unidad es diferente de la actual, convierte la temperatura a la nueva unidad.
// Fórmula de conversión de Celsius a Fahrenheit: (C * 9/5) + 32
// Fórmula de conversión de Fahrenheit a Celsius: (F - 32) * 5/9
// getUnidad(): Devuelve la unidad actual de medida.

class Termometro
{
private:
    float _temperatura;
    char _unidad;

public:
    Termometro(float tempInicial, char unidadInicial)
    {
        _temperatura = tempInicial;
        _unidad = unidadInicial;
    }
    float getTemperatura()
    {
        return _temperatura;
    }
    void setTemperatura(float temperatura)
    {
        _temperatura = temperatura;
    }
    void cambiarUnidad(char nuevaUnidad)
    {
        if (_unidad != nuevaUnidad)
        {
            if (nuevaUnidad == 'F')
            {
                _temperatura = _temperatura * 9.0 / 5.0 + 32;
            }
            else if (nuevaUnidad == 'C')
            {
                _temperatura = (_temperatura - 32) * 5.0 / 9.0;
            }
            _unidad = nuevaUnidad;
        }
    }

    char getUnidad()
    {
        return _unidad;
    }
};

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    Termometro t(25.0, 'C');
    cout << "Temperatura: " << t.getTemperatura() << "°" << t.getUnidad() << endl;

    t.cambiarUnidad('F');
    cout << "Convertido a Fahrenheit: " << t.getTemperatura() << "°" << t.getUnidad() << endl;

    t.cambiarUnidad('C');
    cout << "Vuelto a Celsius: " << t.getTemperatura() << "°" << t.getUnidad() << endl;
    return 0;
}