/* Problema1
Jackelyn Giron 24737
*/
#include <iostream>
using namespace std;

struct Alumno {
    string nombre;
    double zona;
    double examenFinal;
    double notafinal ;
    bool aprobado;
};

double calcularNotaFinal(double zona, double examenFinal) {
    return (zona * 0.4) + (examenFinal * 0.6);
}

int main() {
    Alumno alumno;

    bool continuar = true;
    while (continuar)
    {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Calcular nota final" << endl;
        cout << "2. Salir" << endl;

        int opcion;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "----- Calculo de Nota Final -----" << endl;
                cout << "Ingrese el nombre del alumno: " << endl;
                cin >> alumno.nombre;
                cout << "Ingrese la nota de la zona de 0 a 100: " << endl;
                cin >> alumno.zona;
                cout << "Ingrese la nota del examen final de 0 a 100: " << endl;
                cin >> alumno.examenFinal;

                alumno.notafinal = calcularNotaFinal(alumno.zona, alumno.examenFinal);
                alumno.aprobado = alumno.notafinal >= 61;

                cout << (alumno.aprobado ? "El alumno ha aprobado." : "El alumno ha reprobado.") << endl;
                cout << "La nota final del alumno " << alumno.nombre << " es: " << alumno.notafinal << endl;


                break;
            case 2:
                cout << "Saliendo del programa..." << endl;
                continuar = false;
                break;
            default:
                cout << "Opción no válida, ingrese un número del 1 al 2." << endl;
                break;
            
        }
    }
    return 0;
}
