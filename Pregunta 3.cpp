#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Funci�n para calcular (base^exponente) mod n
int potenciaModular(int base, int exponente, int n) {
    int resultado = 1;
    base = base % n;
    while (exponente > 0) {
        if (exponente % 2 == 1)
            resultado = (resultado * base) % n;
        exponente = exponente / 2;
        base = (base * base) % n;
    }
    return resultado;
}

// Funci�n para cifrar un mensaje utilizando la clave p�blica (n, e)
vector<int> CifradoRsa(string mensaje, int n, int e) {
    vector<int> mensajeCifrado;
    for (char caracter : mensaje) {
        int m = (int)caracter;
        int c = potenciaModular(m, e, n);
        mensajeCifrado.push_back(c);
    }
    return mensajeCifrado;
}

int main() {
    string mensaje = "HOLA MUNDO";
    int p = 61; // N�mero primo
    int q = 53; // N�mero primo
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 17;


    vector<int> mensajeCifrado = CifradoRsa(mensaje, n, e);

    cout << "Mensaje cifrado: ";
    for (int c : mensajeCifrado) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}