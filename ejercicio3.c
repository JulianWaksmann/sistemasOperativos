#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int n = 3;
    int i;
    for (i = 0; i < n; i++) {
        fork();
        // Imprimir el PID del proceso actual junto con el mensaje.
        printf("Soy un proceso! Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
    }
    // Agregar un pequeño delay usando sleep para evitar que la salida se mezcle debido a la planificación del sistema operativo.
    sleep(1); 
    return 0;
}
