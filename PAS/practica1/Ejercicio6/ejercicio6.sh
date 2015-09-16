#!/bin/bash

function recorreCarpeta(){
	
	for x in $(find "$1" -name "lib*")
      do
          cp -i $x $librerias
      done

      for x in $(find "$1" -name "*.h")
      do
          cp -i $x $cabeceras
      done

      for x in $(find "$1" -name "*.c*")
      do
          cp -i $x $fuentes
      done

      for x in $(find "$1")
      do
        if [ -x $x ]
          then
          cp -i $x $ejecutables
        fi
      done

	for x in $(find "$1" -name "*.c")
      do
        ejecutable="$(echo "$(basename "$x")" | tr -d '.c' )"
        if ! gcc $x -o $ejecutable 2>>ejercicio6.log;
	then
		echo "Error al compilar $x"
	fi
        mv $ejecutable $ejecutables

      done

      for x in $(find "$1" -name "*.cpp")
      do
        ejecutable="$(echo "$(basename "$x")" | tr -d '.cpp' )"
        if ! g++ $x -o $ejecutable 2>>ejercicio6.log;
	then
		echo "Error al compilar $x"
	fi
        mv $ejecutable $ejecutables
      done

}

function crearFich(){
	if ! read -t5 -p "Introduce nombre para fichero ejecutables: " ejecutables;
	then
		ejecutables="$HOME/bin"
	fi
	if ! read -t5 -p "Introduce nombre para fichero librerias: " librerias;
	then
		librerias="$HOME/lib"
	fi
	if ! read -t5 -p "Introduce nombre para fichero codigos fuentes: " fuentes;
	then
		fuentes="$HOME/src"
	fi
	if ! read -t5 -p "Introduce nombre para fichero cabeceras: " cabeceras;
	then
		cabeceras="$HOME/include"
	fi

	mkdir $ejecutables
	mkdir $librerias
	mkdir $fuentes
	mkdir $cabeceras
}

if [ $# -ge 1 ]
then
	crearFich
	#Carpetas introducidas
	for x in $*
	do
		echo "hola"
		recorreCarpeta $x
	done
else
	#Carpeta actual
	crearFich
	recorreCarpeta *
fi
