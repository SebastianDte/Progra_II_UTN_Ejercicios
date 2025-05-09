#include <iostream>
#include <locale>
using namespace std;
// Crea una clase llamada Dado que simule el comportamiento de un dado de seis caras. La clase debe contener los siguientes atributos:
// valor (int): Almacena el valor actual del dado (un número entre 1 y 6).
// Implementa los siguientes métodos públicos:
// Dado(): Constructor que inicializa el dado con un valor aleatorio entre 1 y 6.
// lanzar(): Simula el lanzamiento del dado, asignando un nuevo valor aleatorio entre 1 y 6 al atributo valor.
// getValor(): Devuelve el valor actual del dado.
// esMaximo(): Devuelve true si el valor del dado es 6, y false en caso contrario.
// esMinimo(): Devuelve true si el valor del dado es 1, y false en caso contrario.

class Dado{
    private:
    int valor;
    public:
    Dado(){
        valor = rand() % 6 + 1; // Inicializa el dado con un valor aleatorio entre 1 y 6
    }
    int getValor(){
        return valor;
    }
    void lanzar(){
        valor = rand() % 6 + 1; // Asigna un nuevo valor aleatorio entre 1 y 6
    }
    bool esMaximo(){
        return valor == 6;
    }
    bool esMinimo(){
        return valor == 1;
    }
};

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    srand(time(NULL));
    Dado dado1;
    cout << "Valor inicial del dado: " << dado1.getValor() << endl;
    dado1.lanzar();
    cout << "Valor después de lanzar: " << dado1.getValor() << endl;
    cout << "¿Es máximo? " << (dado1.esMaximo() ? "Sí" : "No") << endl;
    cout << "¿Es mínimo? " << (dado1.esMinimo() ? "Sí" : "No") << endl;

    
    
    return 0;
}