/******************************************************************************\
 * Curso de Programación 1. Tema 16 (acceso directo y modo lectura/escritura)
 * Autores: Miguel Ángel Latre
 * Última revisión: 13 de diciembre de 2019
 * Resumen: Función que utiliza acceso directo en un fichero inicializado para
 *          lectura y escritura simultáneas
 * Nota: El código de este programa está repartido en varios módulos.
 *       Para compilarlo, hay que ejecutar el comando
 *           make lectura-escritura
 *       o, en Windows,
 *           mingw32-make lectura-escritura
 *       o ejecutar la tarea "Compilar «lectura-escritura»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           ./lectura-escritura
 *       o, en Windows,
 *           .\lectura-escritura.exe
 *       o ejecutar la tarea "Ejecutar «lectura-escritura»" de VSC.
\******************************************************************************/

#include <iostream>
#include <fstream>
#include "calculos.hpp"
#include "fichero-primos.hpp"
using namespace std;

/*
 * Pre:  El fichero de nombre «nombreFichero» contiene los primeros números
 *       primos, almacenados en orden ascendente. El fichero contiene al menos 
 *       dos primos.
 * Post: Ha añadido al fichero el número primo que sigue al último que tenía
 *       inicialmente almacenado. Si no ha podido, ha escrito un mensaje de error
 *       en «cerr».
 */
void agregarSiguientePrimo(const string nombreFichero) {
    fstream f;
    f.open(nombreFichero, ios::binary | ios::in | ios::out );
    if (f.is_open()) {
        f.seekg(-1 * int(sizeof(unsigned int)), ios_base::end);
        unsigned int primo;
        f.read(reinterpret_cast<char*>(&primo), sizeof(primo));
        cout << "Último primo del fichero: " << primo << endl;
        
        primo += 2;
        while (!esPrimo(primo)) {
            primo += 2;
        }
        
        f.seekp(0, ios_base::end);
        f.write(reinterpret_cast<const char*>(&primo), sizeof(primo));
        f.close();
        cout << "Agregado el siguiente primo: " << primo << endl;
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
    asegurarFicheroPrimos(NOMBRE_FICHERO_PRIMOS, NUM_PRIMOS);
    agregarSiguientePrimo(NOMBRE_FICHERO_PRIMOS);
    return 0;
}