#include <iostream>
using namespace std;


int mcd(int a, int b) {
    if (b == 0)
        return a;
    return mcd(b, a % b);
}


int inversoModular(int e, int phi) {
    int phi0 = phi, y = 0, x = 1;
    if (phi == 1)
        return 0;
    while (e > 1) {
        int q = e / phi;
        int t = phi;
        phi = e % phi;
        e = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += phi0;
    return x;
}


void GeneraClave(int p, int q, int& e, int& d) {
    int n = p * q;               
    int phi = (p - 1) * (q - 1); 

   
    e = 2;
    while (e < phi) {
        if (mcd(e, phi) == 1)
            break;
        else
            e++;
    }

 
    d = inversoModular(e, phi);
}

int main() {
    int p = 19;
    int q = 61; 
    int e, d;


    GeneraClave(p, q, e, d);

    cout << "Clave pública (e): " << e << endl;
    cout << "Clave privada (d): " << d << endl;

    return 0;
}