#include <fstream>
#include <iostream>
#include "calculos.hpp"
using namespace std;

const unsigned NUM_PRIMOS = 10000;
const string NOMBRE_FICHERO_PRIMOS = "primos.dat";


/*
 * Pre:  ---
 * Post: Crea un fichero denominado «nombreFichero» con los primeros «n» números primos.
 */
void crearFicheroPrimos(const string nombreFichero, const unsigned n) {
    ofstream f;
    f.open(nombreFichero, ios::binary);
    if (f.is_open()) {
        unsigned p = 2;
        f.write(reinterpret_cast<const char*>(&p), sizeof(p));  
        p = 3; 
        unsigned i = 1;             
        while (i < n) {
            if (esPrimo(p)) {
                f.write(reinterpret_cast<const char*>(&p), sizeof(p));  
                i++;
            }
            p += 2;
        }
        f.close();
    } else {
        cerr << "Error creando el fichero \"" << nombreFichero 
             << "\"." << endl;
    }
}


/*
 * Pre:  ---
 * Post: Si el fichero «nombreFichero» ya existe, escribe un mensaje
 *       indicándolo. En caso contrario, se crea un fichero denominado
 *       «nombreFichero» con los primeros «n» números primos. 
 */
void asegurarFicheroPrimos(const string nombreFichero, 
                           const unsigned numPrimos) {
    ifstream f(nombreFichero);
    if (f.is_open()) {
        f.close();
        cout << "\"" << nombreFichero << "\" ya existe. Nada que hacer." << endl;
    } else {
        crearFicheroPrimos(nombreFichero, numPrimos);
        cout << "Vector con los primeros " << numPrimos << " creado." << endl;
    }
}

