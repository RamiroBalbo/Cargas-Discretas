#include <iostream>
#include <cmath>

using namespace std;

const int dim = 2;
const long double Kc = 9 * pow(10, 9);

struct carga {
    long double valor;
    char signo;
    long double posicion[dim];
};

void distancia(carga q1, carga q2, long double *r) { // en q2 tenes que escribir el valor sobre el que estas trabajando
    if (q1.signo == q2.signo) {
        for (int i = 0; i < dim; i++) {
            r[i] = q2.posicion[i] - q1.posicion[i];
        }
    } else {
        for (int i = 0; i < dim; i++) {
            r[i] = q1.posicion[i] - q2.posicion[i];
        }
    }
}

void coulomb(long double *Ft, carga q1, carga q2, long double *r) {
    Ft[0] = ((Kc*q1.valor*q2.valor)/pow(pow(r[0], 2) + pow(r[1], 2), 1.5)) * r[0];
    Ft[1] = ((Kc*q1.valor*q2.valor)/pow(pow(r[0], 2) + pow(r[1], 2), 1.5)) * r[1];
}

int main(int argc, char *argv[]) 
{
    carga q1, q2;
    long double r[dim]{};
    long double Ft[dim]{};

    cout << "Ingrese el valor de la primera carga" << endl;
    cin >> q1.valor; cout << endl;
    cout << "Ingrese las dos posiciones seguidas en x e y, de la primera carga" << endl;
    cin >> q1.posicion[0] >> q1.posicion[1]; cout << endl;
    cout << "Ingrese el signo de la primera carga" << endl;
    cin >> q1.signo; cout << endl;

    cout << "Ingrese el valor de la segunda carga, sobre la cual quiere analizar" << endl;
    cin >> q2.valor; cout << endl;
    cout << "Ingrese las dos posiciones seguidas en x e y, de la segunda carga" << endl;
    cin >> q2.posicion[0] >> q2.posicion[1]; cout << endl;
    cout << "Ingrese el signo de la segunda carga, sobre la cual quiere analizar" << endl;
    cin >> q2.signo; cout << endl;

    distancia(q1, q2, r);
    coulomb(Ft, q1, q2, r);

    cout << "Ft = (" << Ft[0] << ", " << Ft[1] << ")N" << endl;

    return 0;
}