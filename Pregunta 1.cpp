#include <iostream>
using namespace std;


int PotenciaModulo(int Num, int E, int n) {
    int resultado = 1;          
    int base = Num % n;         

    while (E > 0) {
        if (E % 2 == 1) {
            
            resultado = (resultado * base) % n;
        }
       
        base = (base * base) % n;
        
        E = E / 2;
    }

    return resultado;
}

int main() {
    int Num = 327;
    int E = 128;
    int n = 1425;

    int R = PotenciaModulo(Num, E, n);

    cout << "R = " << R << endl; 
    return 0;
}