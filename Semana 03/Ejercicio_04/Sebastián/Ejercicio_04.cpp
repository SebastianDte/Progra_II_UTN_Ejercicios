#include <iostream>
#include <locale>
using namespace std;
// Crea una clase llamada Triangulo que represente un triángulo. La clase debe contener un vector de 3 elementos, donde cada elemento corresponde a la longitud de un lado del triángulo. Implementa los siguientes métodos:
// getLado(int numero): Devuelve la longitud del valor del lado correspondiente al número proporcionado (1, 2, o 3). Si el número es incorrecto (fuera del rango 1-3), devuelve cero.
// setLado(int numero, float valor): Establece el valor del lado correspondiente al número proporcionado (1, 2, o 3). Si el número es incorrecto (fuera del rango 1-3), no realiza ninguna acción.
// getTipo(): Devuelve el tipo de triángulo según sus lados:
// 1 para un triángulo equilátero (todos los lados iguales).
// 2 para un triángulo isósceles (dos lados iguales).
// 3 para un triángulo escaleno (todos los lados diferentes).
// isEscaleno(): Devuelve true si el triángulo es escaleno, false en caso contrario.
// isIsosceles(): Devuelve true si el triángulo es isósceles, false en caso contrario.
// isEquilatero(): Devuelve true si el triángulo es equilátero, false en caso contrario.

class Triangulo{
    private:
    float lados[3];
    public:
    float getLado(int numero){
        if(numero > 0 && numero <=3)
        return lados[numero-1];
        return 0;
    }
    void setLado(int numero,float valor){
        if(numero>0&&numero<=3)
        lados[numero-1] = valor;
    }
    int getTipo(){
        if(lados[0] == lados [1] && lados[1] == lados[2])return 1;
        if(lados[0] != lados [1] && lados[1] != lados[2])return 3;
        return 2;
    }
    bool isEscaleno() {
    return getTipo() == 3;  
}

bool isIsosceles() {
    return getTipo() == 2;  
}

bool isEquilatero() {
    return getTipo() == 1;  
}

};


int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    Triangulo t1;
    t1.setLado(1,30);
    t1.setLado(2,20);
    t1.setLado(3,10);
    cout<<"Tipo: " << t1.getTipo()<<endl;
    cout<< "Es equilatero? "<< t1.isEquilatero()<<endl;
    cout<< "Es escaleno? " << t1.isEscaleno()<<endl;
    cout<<"Es isosceles? " << t1.isIsosceles()<<endl;
    
    
    return 0;
}