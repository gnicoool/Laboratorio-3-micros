/* Problema 3
Jackelyn Giron 24737
*/
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

struct Persona {
    string nombre;
    char sexo;
    int edad;
    double estatura;
    double peso;

    double calcularGrasa() {
        switch (sexo) {
            case 'F':
                return (1.2 * (peso / (estatura * estatura))) + (0.23 * edad) - 5.4;
            case 'M':
                return (1.2 * (peso / (estatura * estatura))) + (0.23 * edad) - 16.2;
        }
        return -1;
    }
};

int main() {
    Persona persona;
    bool continuar = true;

    while (continuar) {
        cout << "\n----- MENU PORCENTAJE DE GRASA CORPORAL -----" << endl;
        cout << "1. Calcular porcentaje de grasa corporal" << endl;
        cout << "2. Salir" << endl;

        int opcion;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:{
                cout << "Ingrese su nombre: ";
                cin >> persona.nombre;
                cout << "Ingrese su edad en años: ";
                cin >> persona.edad;
                cout << "Ingrese su estatura en metros: ";
                cin >> persona.estatura;
                cout << "Ingrese su peso en kg: ";
                cin >> persona.peso;
                cout << "Ingrese su sexo (M/F): ";
                cin >> persona.sexo;
                persona.sexo = toupper(persona.sexo);

                if (persona.sexo != 'M' && persona.sexo != 'F') {
                    cout << "Sexo inválido. Ingrese 'M' para masculino o 'F' para femenino." << endl;
                } else {
                    cout << fixed << setprecision(2);
                    double grasa = persona.calcularGrasa();
                    cout << "\nEl porcentaje de grasa corporal de " << persona.nombre << " es: " << grasa << "%" << endl;
                }
                break;
            }   
            case 2:{
                cout << "Saliendo del programa..." << endl;
                continuar = false;
                break;
            }
            default:{
                cout << "Opción no válida, ingrese un número del 1 al 2." << endl;
                break;
            }
        }
    }

    return 0;
}
