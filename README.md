# Ficheros: otras posibilidades

Código de las transparencias del tema 16 (otras posibilidades con ficheros) de la asignatura [Programación 1](https://github.com/prog1-eina) ([Grado en Ingeniería Informática](https://webdiis.unizar.es/~silarri/coordinadorGrado/), [Escuela de Ingeniería y Arquitectura](https://eina.unizar.es/), [Universidad de Zaragoza](https://www.unizar.es/)).

## Compilación y ejecución

### ``1-linea-adicional.cpp``

El programa ``linea-adicional`` puede compilarse y ejecutarse con la extensión Code Runner de Visual Studio Code.

También puede compilarse desde la terminal través de la orden

```shell
    g++ -Wall -Wextra 1-linea-adicional.cpp -o 1-linea-adicional
```

Puede ejecutarse en Windows, después de ser compilado, a través de la orden

```shell
    .\1-linea-adicional.exe
```

y en Linux o macOS, a través de la orden

```shell
    ./1-linea-adicional
```

### ``2-acceso-directo.cpp`` y ``3-lectura-escritura.cpp``

Los programas `acceso-directo` y `lectura-escritura` necesitan de un fichero denominado `primos.dat` que se crea a través de la función ``asegurarFicheroPrimos`` del módulo `fichero-primos`.

El módulo `fichero-primos` necesita del módulo «calculos» del proyecto `calculadora` de la [práctica 3](https://github.com/prog1-eina/practica3). El fichero ``Makefile`` ha sido configurado suponiendo que el directorio de la práctica 3 se encuentra en un directorio denominado `practica3` ubicado en la misma carpeta que el directorio de este repositorio.

#### ``2-acceso-directo.cpp``

Para compilarlo, hay que ejecutar el comando

```shell
    make acceso-directo
```

o, en Windows,

```shell
    mingw32-make acceso-directo
```

o ejecutar la tarea ``Compilar «acceso-directo»`` de VSC.

Para ejecutarlo, una vez compilado, hay que ejecutar el comando

```shell
    ./acceso-directo
```

o, en Windows,

```shell
    .\acceso-directo.exe
```

o ejecutar la tarea ``Ejecutar «acceso-directo»`` de VSC.

#### ``3-lectura-escritura.cpp``

Para compilarlo, hay que ejecutar el comando

```shell
    make lectura-escritura
```

o, en Windows,

```shell
    mingw32-make lectura-escritura
```

o ejecutar la tarea ``Compilar «lectura-escritura»`` de VSC.

Para ejecutarlo, una vez compilado, hay que ejecutar el comando

```shell
    ./lectura-escritura
```

o, en Windows,

```shell
    .\lectura-escritura.exe
```

o ejecutar la tarea ``Ejecutar «lectura-escritura»`` de VSC.
