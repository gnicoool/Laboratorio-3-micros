/* Problema2
Jackelyn Giron 24737
*/
#include <iostream>

using namespace std;

int main() {
    int numero = 0;
    char letra;
    bool continuar = true;

    while (continuar)
    {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Ver tabla ASCII completa" << endl;
        cout << "2. Convertir numero" << endl;
        cout << "3. Salir" << endl;

        int opcion;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Tabla ASCII completa:" << endl;
            for (int i = 0; i < 128; i++) {
                cout << i << " -> " << static_cast<char>(i) << endl;
            }
            break;
        case 2:
            cout << "Ingrese un numero: ";
            cin >> numero;
            if (numero >= 0 && numero <=127) {
                if (numero >=0 && numero <= 32){
                    cout << "\nEl numero " << numero << " es un caracter de control ASCII y no se puede mostrar"<< endl;
                }else{
                 letra = static_cast<char>(numero);
                    cout << "\nEl caracter ASCII correspondiente al numero " << numero << " es: " << letra << endl;   
                }

            }else{
                cout << "\nNumero fuera de rango ingrese un numero entre 0 y 127" << endl;
            }
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            continuar = false;
            return 0;
        default:
            cout << "Opción no válida, ingrese un numero del 1 al 3" << endl;
            break;
        }
    }
    
    
}