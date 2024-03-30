#include <stdio.h> // Incluimos la librería de entrada/salida estándar
#include <unistd.h> // Para hacer sleep (aunque no se usa en este fragmento)
#include <time.h> // Para inicializar el tiempo (aunque no se usa en este fragmento)

//la biblioteca que se utiliza para gestionar hilos en linux que vimos en clase se llama pthreads, la importamos para gestionar ese caso:
#include <pthread.h>

void calculo_aritmetico() {
    int contador = 0;
    while (contador < 2147483647) {
        contador = contador + 1;
    }
}

//Esta funcion wrapper o envoltorio nos permite llamar a nuestra funcion original de calculo aritmetico y es necesaria para la creacion de hilos.
void* calculo_aritmetico_wrapper(void* arg) {
    calculo_aritmetico();
    return NULL; // Retorna NULL ya que la función no necesita devolver nada.
}

int main() {
    pthread_t hilos[5]; // Array para almacenar los identificadores de los hilos.

    // Crear 5 hilos para ejecutar `calculo_aritmetico` de forma concurrente.
    for (int i = 0; i < 5; i++) {
        pthread_create(&hilos[i], NULL, calculo_aritmetico_wrapper, NULL);
    }

    // Esperar a que cada uno de los hilos termine.
    for (int i = 0; i < 5; i++) {
        pthread_join(hilos[i], NULL);
    }

    return 0;
}
