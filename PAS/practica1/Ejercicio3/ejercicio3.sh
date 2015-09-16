#!/bin/bash

var=0
for x in $(find *)
do
	if [ -f $x ]
	then
		((var++))
	fi
done
	echo "El número de archivos en la carpeta actual es $var"
echo "----------"
	echo "Esta sería la lista de usuarios conectados en este momento:"
	who | awk '{ print $1 }' | uniq -c
echo "----------"

if read -t5 -p "¿Qué caracter quieres contar?" caracter;
then
	echo "Buscando <$caracter>..."
else	
	caracter="a"
fi
var2=0
for x in $(find -name "*$caracter*")
do
		fichero=$(basename "$x")	
		num=$(echo $fichero | tr -cd $caracter | wc -c)
		var2=$(($var2+$num))
		
done
echo "El carácter <$caracter> aparece $var2 veces en nombres de ficheros o carpetas contenidos en la carpeta actual"
