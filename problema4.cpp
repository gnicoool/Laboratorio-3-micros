/* Problema 4
Jackelyn Giron 24737
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Producto {
    string nombre;
    int stockInicial;
    int vendidos;
};

int calcularRestante(const Producto& p) {
    return p.stockInicial - p.vendidos;
}

bool estaAgotado(const Producto& p) {
    return calcularRestante(p) == 0;
}

void mostrarTabla(const vector<Producto>& productos) {
    cout << left << setw(15) << "Producto"
         << setw(10) << "Inicial"
         << setw(10) << "Vendidos"
         << setw(10) << "Restante"
         << setw(10) << "Agotado" << endl;

    for (const auto& p : productos) {
        cout << left << setw(15) << p.nombre
             << setw(10) << p.stockInicial
             << setw(10) << p.vendidos
             << setw(10) << calcularRestante(p)
             << setw(10) << (estaAgotado(p) ? "Sí" : "No") << endl;
    }
}

int main() {
    vector<Producto> productos;
    Producto temp;

    cout << "Ingrese los datos de 10 productos:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "\nProducto " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> temp.nombre;
        cout << "Stock inicial: ";
        cin >> temp.stockInicial;
        cout << "Vendidos: ";
        cin >> temp.vendidos;
        productos.push_back(temp);
    }

    cout << "\n--- Tabla de Productos ---";
    mostrarReporte(productos);

    return 0;
}
