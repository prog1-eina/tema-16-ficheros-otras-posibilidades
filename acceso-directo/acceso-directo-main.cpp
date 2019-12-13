/********************************************************************************\
 * Curso de Programación 1. Tema 16 (acceso directo)
 * Autores: Miguel Ángel Latre
 * Última revisión: 13 de diciembre de 2019
 * Resumen: Función que utiliza acceso directo en un fichero en lugar de acceso
 *          secuancial (se presenta también una versión que usa acceso secuencial)
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;


/*
 * Pre:  El fichero de nombre «nombreFichero» almacena al menos los primeros
 *       «i» números primos, almacenados en orden ascendente.
 * Post: Ha devuelto el «i»-ésimo (comenzando a contar por 1) número primo, 
 *       según el contenido del fichero. Si no se ha podido abrir el fichero, ha
 *       escrito un mensaje de error en «cerr» y ha devuelto un valor negativo.
 * Nota: Versión secuencial de la función
 */
int leerUnPrimo_secuencial(const char nombreFichero[], int i) {
    ifstream f(nombreFichero, ios::binary);
    if (f.is_open()) {
        int primo;
        for(int j = 1; j <= i; j++) {
            f.read(reinterpret_cast<char*>(&primo), sizeof(primo));
        }
        f.close();
        return primo;
    }
    else {
        // Escritura de un mensaje de error si no se ha podido abrir el fichero
        cerr << "No se ha podido leer el fichero \""
             << nombreFichero << "\"" << endl;
        return -1;
    }
}


/*
 * Pre:  El fichero de nombre «nombreFichero» almacena al menos los primeros
 *       «i» números primos, almacenados en orden ascendente.
 * Post: Ha devuelto el «i»-ésimo (comenzando a contar por 1) número primo, 
 *       según el contenido del fichero. Si no se ha podido abrir el fichero, ha
 *       escrito un mensaje de error en «cerr» y ha devuelto un valor negativo.
 * Nota: Versión de la función que utiliza acceso directo.
 */
int leerUnPrimo(const char nombreFichero[], int i) {
    ifstream f(nombreFichero, ios::binary);
    if (f.is_open()) {
        f.seekg((i - 1) * sizeof(int));
        int primo;
        f.read(reinterpret_cast<char*>(&primo), sizeof(primo));
        f.close();
        return primo;
    }
    else {
        // Escritura de un mensaje de error si no se ha podido abrir el fichero
        cerr << "No se ha podido leer el fichero \""
             << nombreFichero << "\"" << endl;
        return -1;
    }
}

/*
 * Programa de prueba de la función «leerUnPrimo», que escribe el valor del
 * milésimo número primo (7919).
 */
int main() {
    const char NOMBRE_FICHERO[] = "../../../tema-15-ficheros-binarios/creacion-fichero-primos/primos.dat";
    cout << leerUnPrimo(NOMBRE_FICHERO, 1000) << endl;
    return 0;
}

