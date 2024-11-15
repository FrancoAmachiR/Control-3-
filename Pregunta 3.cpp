#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Función para calcular (base^exponente) mod n
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

// Función para cifrar un mensaje utilizando la clave pública (n, e)
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
    int p = 17; // Número primo
    int q = 23; // Número primo
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 15;


    vector<int> mensajeCifrado = CifradoRsa(mensaje, n, e);

    cout << "Mensaje cifrado: ";
    for (int c : mensajeCifrado) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
