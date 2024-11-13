#include <iostream>
#include <vector>
#include <string>
using namespace std;


int inversoModular(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        
        q = a / m;
        t = m;

        
        m = a % m, a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    
    if (x1 < 0)
        x1 += m0;

    return x1;
}

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

string DescifradoRsa(vector<int> mensajeCifrado, int n, int d) {
    string mensajeDescifrado;
    for (int c : mensajeCifrado) {
        // Ajustar c si es mayor que n
        if (c >= n) {
            c = c % n;
        }
        int m = potenciaModular(c, d, n); 
        char caracter = (char)m; 
        mensajeDescifrado += caracter;
    }
    return mensajeDescifrado;
}

int main() {
    
    vector<int> mensajeCifrado = { 1722, 666, 666, 1722, 2044, 2490 };

    
    int p = 43; // Número primo
    int q = 59; // Número primo
    int n = p * q; 
    int phi = (p - 1) * (q - 1); 
    int e = 13; 

   
    int d = inversoModular(e, phi);

    if ((e * d) % phi != 1) {
        cout << "Error: e y d no son inversos modulares." << endl;
        return 1;
    }

    string mensajeDescifrado = DescifradoRsa(mensajeCifrado, n, d);

    cout << "Mensaje descifrado: " << mensajeDescifrado << endl;

    return 0;
}