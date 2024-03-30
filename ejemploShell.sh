#!/bin/bash

#Aca verificamos que haya pasado el argumento, puesto que si es 0 no se paso nada e imprimira mensaje.
if [ $# -eq 0 ]; then
    echo "Error: Uso $0 <nombre_directorio>"
    exit 1
fi

#Almacenamos el nombre pasado y generamos el path
nombre_dir="$HOME/$1"
archivo_txt="$nombre_dir/lista_archivos.txt"

# Crear el directorio en el home del usuario
mkdir -p "$nombre_dir"

# Crear el archivo .txt dentro del directorio
touch "$archivo_txt"

# Buscar archivos .txt en todo el sistema. Si no encuentra, crea archivos de ejemplo y busca de nuevo
find / -name "*.txt" 2>/dev/null > /tmp/lista_temp.txt
if [ ! -s /tmp/lista_temp.txt ]; then
  # Crear archivos de ejemplo y buscar de nuevo
  for i in {1..4}; do
    touch "$nombre_dir/ejemplo$i.txt"
  done
  find / -name "*.txt" 2>/dev/null > /tmp/lista_temp.txt
fi

# Listar los archivos encontrados con sus permisos y agregarlos al archivo
while IFS= read -r archivo; do
  ls -l "$archivo" 2>/dev/null >> "$archivo_txt"
done < /tmp/lista_temp.txt

# Agregar la fecha y hora del sistema al final del archivo
echo "Fecha y hora del sistema: $(date)" >> "$archivo_txt"

# Mostrar el contenido del archivo en pantalla
cat "$archivo_txt"
