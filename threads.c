#include <stdio.h> // Incluimos la librería de entrada/salida estándar
#include <unistd.h> // Para hacer sleep (aunque no se usa en este fragmento)
#include <time.h> // Para inicializar el tiempo (aunque no se usa en este fragmento)

void calculo_aritmetico() {
    int contador = 0;
    while (contador < 2147483647) {
        contador = contador + 1;
    }
}

int main() {
    calculo_aritmetico();
    calculo_aritmetico();
    calculo_aritmetico();
    calculo_aritmetico();
    calculo_aritmetico();
    return 0;
}
