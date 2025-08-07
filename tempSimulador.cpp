/* Promedio de Temperaturas
Jackelyn Giron 24737
*/
#include <iostream>

using namespace std;

double calcularPromedio(double temp[], int size) {
    double suma = 0;
    for (int i = 0; i < size; i++) {
        suma += temp[i];
    }
    return suma /size;
}

double encontrarMaximo(double temp[], int size) {
    double maxTemp = temp[0];
    for (int i = 1; i < size; i++) {
        if (temp[i] > maxTemp) {
            maxTemp = temp[i];
        }
    }
    return maxTemp;
}

double encontrarMinimo(double temp[], int size) {
    double minTemp = temp[0];
    for (int i = 1; i < size; i++) {
        if (temp[i] < minTemp) {
            minTemp = temp[i];
        }
    }
    return minTemp;
}

int main() {
    const int maxDias = 5;
    double temperaturas[maxDias];
    
    cout << "Ingrese las temperaturas de 5 dias en grados Celsius:" << endl;
    for (int i = 0; i < maxDias; i++) {
        cout << "Día " << (i + 1) << ": ";
        cin >> temperaturas[i];
    }
    
    double promedio = calcularPromedio(temperaturas, maxDias);
    double maximo = encontrarMaximo(temperaturas, maxDias);
    double minimo = encontrarMinimo(temperaturas, maxDias);
    
    cout << "El promedio de las temperaturas es: " << promedio << " grados Celsius." << endl;
    cout << "La temperatura máxima es: " << maximo << " grados Celsius." << endl;
    cout << "La temperatura mínima es: " << minimo << " grados Celsius." << endl;

    
}