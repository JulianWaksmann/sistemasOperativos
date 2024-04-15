Objetivos:
 Adquirir conocimiento y práctica en los comandos más utilizados del sistema
GNU/Linux, mediante la práctica durante el desarrollo del trabajo práctico (TP).
 Reconocer la utilidad y relevancia de la adquisición de conocimientos y
habilidades en el uso de comandos de GNU/Linux, tanto en el contexto
académico como en el ámbito profesional.
 Analizar y comprender el concepto de proceso y sus estados, estableciendo una
conexión entre estos conceptos y el funcionamiento de un sistema operativo.
 Aplicar los conocimientos adquiridos sobre procesos y estados en la práctica con
el fin de mejorar la comprensión del funcionamiento de un sistema operativo y
su rendimiento.

Ejercicio 1: Shell y terminal
 Realicen un script de Shell Bash tal que realice las siguientes tareas:
o Debe recibir por parámetro una palabra y debe crear un directorio con
dicho nombre en tu home de usuario.
o Dentro de ese directorio debe crear un archivo .txt
o Debe agregar al archivo anterior el listado de todos los archivos de la
computadora que terminan con la extensión .txt (sino existen crear 4
archivos de ejemplos), y además de los nombres de los archivos se
tienen que ver los permisos de los mismos. Al final del archivo y del
listado debe agregar la fecha y la hora del sistema. Cuando el script
termine debe mostrar por pantalla el contenido del archivo.
● Pueden usar los siguientes operadores y comandos:
 pipe | ,
 redirección > ,
 redirección concatenando >>
 y los comandos
o grep
o ls
o cat
Ejercicio 2: Estados de un Proceso
En esta parte vamos a aplicar nuestros conocimientos de procesos y sus estados.
 Realizar un programa en C compuesto de instrucciones que realizan cálculos
(operaciones aritméticas) y operaciones de I/O (leer un input del usuario).
Compilar y ejecutar su programa y visualizar los estados por los que pasa.
Puede usar la herramienta htop.
 Ejecutar su programa y demostrar mediante capturas de pantalla del programa
htop que su programa efectivamente cambia de estados.
Sistemas Operativos y Redes
Ejemplo de una captura de htop
Ejercicio 3: Procesos y Fork
Fork es la llamada al sistema que permite crear nuevos procesos. Compilar,
ejecutar el siguiente programa. Describir y justificar el output. Dibujar el árbol de
proceso padre-hijo que se van generando para n=3
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
Int n=3;
for (i=0; i<n; i++){
fork();
printf("Soy un proceso!\n");
}
return 0;
}
Sistemas Operativos y Redes
Ejercicio 4: Threads
El siguiente programa ejecuta la función do_nothing() cinco veces. Esta función sólo
espera 2 segundos y continúa:
#include <stdio.h> //incluimos la libreria de estandar input/output
#include <unistd.h> //para hacer sleep
#include <time.h> //para inicializar el tiempo
void calculo_aritmetico(){
 int contador=0;
 while(contador < 2147483647){
 contador=contador+1;
 }
}
int main() {`1
 calculo_aritmetico();
 calculo_aritmetico();
 calculo_aritmetico();
 calculo_aritmetico();
 calculo_aritmetico();
 return 0;
}
Para compilar: gcc calculo_aritmetico.c -o ejecutable
Para ejecutar: ./ejecutable
 Con la función time, medir el tiempo que tarda el programa anterior.
 Modificar el programa anterior para que cada una de las 5 llamadas a la función
calculo_aritmetico() como un único hilo de ejecución.
 Medir el tiempo que tarda su nuevo programa. ¿Qué diferencias observa en el
tiempo? ¿Por qué es importante la cantidad de núcleos en el procesador?
