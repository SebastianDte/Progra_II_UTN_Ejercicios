#include <iostream>
#include <locale>
using namespace std;

// Crea una clase llamada Usuario que represente a un usuario en un sistema. La clase debe tener los siguientes atributos:
// Nombre (string)
// Clave (string)
// Rol (string): Puede ser "admin" o "user".
// Implementa los siguientes métodos:
// Usuario(string nombre, string clave, string rol): Constructor que inicializa los atributos.
// getter y setter de cada atributo
// Desarrolla un programa que realice lo siguiente:
// Cargar en el sistema una lista de 5 usuarios utilizando un array de objetos Usuario (esto debe estar hardcodeado en el programa).
// Solicitar al usuario que ingrese su nombre y contraseña al iniciar el programa.
// Verificar si las credenciales ingresadas coinciden con alguno de los usuarios cargados en el sistema utilizando una función que reciba el array de usuarios, la cantidad de usuarios, el nombre y la contraseña. Esta función debe devolver el índice donde se encuentra el usuario en el array, o -1 si el usuario no existe.
// Si se encuentra un usuario con las credenciales correctas, permitir el acceso al sistema mostrando el rol al que pertenece con un saludo amigable. Utiliza una función que reciba un objeto Usuario y muestre el saludo con el rol específico.
// Si el usuario ingresa credenciales incorrectas, permitir un máximo de 3 intentos. Si se agotan los intentos, el programa debe finalizar indicando que se han agotado los intentos.

class Usuario
{
private:
    string nombre;
    string clave;
    string rol;

public:
    // Constructor
    Usuario(string nombre, string clase, string rol) : nombre(nombre), clave(clase), rol(rol) {}
    // Getters
    string getNombre() const { return nombre; }
    string getClave() const { return clave; }
    string getRol() const { return rol; }
    // Setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setClave(string clase) { this->clave = clase; }
    void setRol(string rol) { this->rol = rol; }
};

// Función para verificar las credenciales
int verificarCredenciales(Usuario usuarios[], int cantidadUsuarios, string nombre, string clave)
{
    for (int i = 0; i < cantidadUsuarios; i++)
    {
        if (usuarios[i].getNombre() == nombre && usuarios[i].getClave() == clave)
        {
            return i;
        }
    }
    return -1;
}
// Función para mostrar el saludo
void mostrarSaludo(Usuario usuario)
{
    cout << "¡Bienvenido " << usuario.getNombre() << "! Tu rol es: " << usuario.getRol() << endl;
}

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    // Variables
    string nombreIngresado;
    string claveIngresada;
    const int tamanio = 5;
    int intentos = 0;
    // Crear un array de 5 usuarios
    Usuario usuarios[tamanio] = {
        Usuario("Juan", "1234", "admin"),
        Usuario("Maria", "5678", "user"),
        Usuario("Pedro", "abcd", "admin"),
        Usuario("Ana", "efgh", "user"),
        Usuario("Luis", "ijkl", "admin")};

        
    cout << "Bienvenido al sistema. Por favor, ingrese su nombre y contraseña." << endl;
    while (intentos < 3)
    {
        cout << "Nombre: ";
        cin >> nombreIngresado;
        cout << "Contraseña: ";
        cin >> claveIngresada;
        // Verificar credenciales
        int indiceUsuario = verificarCredenciales(usuarios, tamanio, nombreIngresado, claveIngresada);
        if (indiceUsuario != -1)
        {
            // Si las credenciales son correctas, mostrar saludo
            mostrarSaludo(usuarios[indiceUsuario]);
            break;
        }
        else
        {
            // Si las credenciales son incorrectas, incrementar intentos
            intentos++;
            cout << "Credenciales incorrectas. Intento " << intentos << " de 3." << endl;
        }
    }

    return 0;
}