#include <iostream>
#include <locale>
using namespace std;

// Crea una clase llamada CuentaBancaria que represente una cuenta bancaria. La clase debe tener los siguientes atributos:
// Número de cuenta (entero)
// Saldo actual (float)
// Implementa los siguientes métodos:
// Un constructor que me permita establecer el número de cuenta y el saldo.
// Un método depositar(float monto) que incremente el saldo.
// Un método retirar(float monto) que disminuya el saldo si hay fondos suficientes, caso contrario no hace nada.
// Un método obtenerSaldo() que devuelva el saldo actual.

class CuentaBancaria{
    private:
    int numeroCuenta;
    float saldoActual;
    public:
    CuentaBancaria(int numero, float saldo){
        numeroCuenta = numero;
        saldoActual = saldo;
    }
    void Depositar(float monto){
        saldoActual += monto;
    }
    void Retirar(float monto){
        if (monto <= saldoActual){
            saldoActual -= monto;
        }else{
            cout << "Monto Insuficiente" << endl;
        }
    }
    float ObtenerSaldo(){
        return saldoActual;
    }
};



int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    float retiro;
    CuentaBancaria sujeto1(35248,100120);
    cout << "Su saldo actual es de: " << sujeto1.ObtenerSaldo() << endl;
    cout << "Retirando 50.000" << endl;
    sujeto1.Retirar(50000);
    cout << "Su saldo actual es de: " << sujeto1.ObtenerSaldo() << endl;

    cout << "Retirando 70.000" << endl;
    sujeto1.Retirar(70000);
    cout << "Su saldo actual es de: " << sujeto1.ObtenerSaldo() << endl;

    return 0;
}