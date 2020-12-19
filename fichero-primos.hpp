#include <string>
using namespace std;

const unsigned int NUM_PRIMOS = 1000;
const string NOMBRE_FICHERO_PRIMOS = "primos.dat";

/*
 * Pre:  ---
 * Post: Si el fichero «nombreFichero» ya existe, escribe un mensaje
 *       indicándolo. En caso contrario, se crea un fichero denominado
 *       «nombreFichero» con los primeros «n» números primos. 
 */
void asegurarFicheroPrimos(const string nombreFichero, 
                           const unsigned int numPrimos);
