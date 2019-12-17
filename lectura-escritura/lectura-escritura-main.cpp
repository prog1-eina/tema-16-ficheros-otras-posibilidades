/********************************************************************************\
 * Curso de Programación 1. Tema 16 (acceso directo y modo lectura/escritura)
 * Autores: Miguel Ángel Latre
 * Última revisión: 13 de diciembre de 2019
 * Resumen: Función que utiliza acceso directo en un fichero inicializado para
 *          lectura y escritura simultáneas
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <iostream>
#include <fstream>
#include "calculos.h"
using namespace std;

/*
 * Pre:  El fichero de nombre «nombreFichero» contiene los primeros números
 *       primos, almacenados en orden ascendente. El fichero contiene al menos 
 *       dos primos.
 * Post: Ha añadido al fichero el número primo que sigue al último que tenía
 *       inicialmente almacenado. Si no ha podido, ha escrito un mensaje de error
 *       en «cerr».
 */
void agregarSiguientePrimo(const char nombreFichero[]) {
    fstream f;
    f.open(nombreFichero, ios::binary | ios::in | ios::out );
    if (f.is_open()) {
        f.seekg(-1 * sizeof(int), ios_base::end);
        int primo;
        f.read(reinterpret_cast<char*>(&primo), sizeof(primo));
        
        primo += 2;
        while (!esPrimo(primo)) {
            primo += 2;
        }
        
        f.seekp(0, ios_base::end);
        f.write(reinterpret_cast<const char*>(&primo), sizeof(primo));
        f.close();
    }
    else {
        // Escritura de un mensaje de error si no se ha podido abrir el fichero
        cerr << "No se ha podido abrir el fichero \""
             << nombreFichero << "\"" << endl;
    }
}


/*
 * Prueba la función «agregarSiguientePrimo».
 */
int main() {
    const char NOMBRE_FICHERO[] = "../../../tema-15-ficheros-binarios/creacion-fichero-primos/primos.dat";
    agregarSiguientePrimo(NOMBRE_FICHERO);
    return 0;
}