#!/bin/bash
if [ "$#" == "1" ]
then
	if [ -f "$1" ]
	then
		cp $1 $1.bak_$(date +%d-%m-%y)
		echo "Perfecto."
	else
		echo "No existe el fichero"
		exit 1
	fi
else
	echo "El uso del programa es $0 nombreFichero"
	exit 1
fi
