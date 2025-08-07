/* Decodificador Binario
Jackelyn Giron 24737
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int suma(int a, int b) { return a + b; }
int and_op(int a, int b) { return a & b; }
int or_op(int a, int b) { return a | b; }
int xor_op(int a, int b) { return a ^ b; }

// Convierte dos bits a numeros, se relaciona con las instrucciones binarias
int bitsToNum(char a, char b) {
    return ((a - '0') << 1) | (b - '0');
}

// Verifica la paridad de la instrucción
bool verificarParidad(const string& instr) {
    int count = 0;
    for (int i = 1; i < 8; ++i) {
        if (instr[i] == '1') count++;
    }
    return ((count % 2 == 0 && instr[0] == '0') || (count % 2 == 1 && instr[0] == '1'));
}

string getOpcodeDesc(int opcode) {
    switch (opcode) {
        case 0: return "Suma";
        case 1: return "AND";
        case 2: return "OR";
        case 3: return "XOR";
        default: return "Desconocido";
    }
}

string getModDesc(int mod) {
    switch (mod) {
        case 0: return "Directo";
        case 1: return "Negar resultado";
        case 2: return "Doble operando A";
        case 3: return "Intercambio de operandos";
        default: return "Desconocido";
    }
}

int getOperando(int bits) {
    switch (bits) {
        case 0: return 1;
        case 1: return 2;
        case 2: return 3;
        case 3: return 4;
        default: return 0;
    }
}

void procesarInstruccion(const string& instr, int index) {
    cout << "• Instrucción " << index + 1 << ": ";

    if (instr.length() != 8 || instr.find_first_not_of("01") != string::npos) {
        cout << "instrucción mal formada → error." << endl;
        return;
    }

    if (!verificarParidad(instr)) {
        cout << "paridad incorrecta → error." << endl;
        return;
    }

    int opcode = bitsToNum(instr[1], instr[2]);
    int mod = bitsToNum(instr[3], instr[4]);
    bool bandera = instr[5] == '1';
    int operand_bits = bitsToNum(instr[6], instr[7]);

    int A = getOperando(operand_bits);
    int B = getOperando(operand_bits);

    cout << "paridad correcta, operación " << getOpcodeDesc(opcode)
         << ", modificación: " << getModDesc(mod)
         << ", bandera " << (bandera ? "activada" : "desactivada") << ", ";

    if (bandera) {
        A = (~A) & 0x03;
        B = (~B) & 0x03;
    }

    int resultado = 0;
    switch (opcode) {
        case 0: resultado = suma(A, B); break;
        case 1: resultado = and_op(A, B); break;
        case 2: resultado = or_op(A, B); break;
        case 3: resultado = xor_op(A, B); break;
    }

    switch (mod) {
        case 1: resultado = (~resultado) & 0xFF; break;
        case 2: resultado = A * 2; break;
        case 3: swap(A, B); resultado = suma(A, B); break;
    }

    cout << "resultado binario: ";
    for (int i = 7; i >= 0; --i)
        cout << ((resultado >> i) & 1);
    cout << endl;
}

int main() {
    string input;
    cout << "Ingrese instrucciones binarias separadas por espacio: ";
    getline(cin, input);

    vector<string> instrucciones;
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        instrucciones.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    instrucciones.push_back(input);

    for (size_t i = 0; i < instrucciones.size(); ++i) {
        procesarInstruccion(instrucciones[i], i);
    }

    return 0;
}
