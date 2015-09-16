#!/bin/bash
if [ $# -eq 2 ]
then
	while read direccion;
	do 
	tiempo=$(ping -c1  $direccion -w $2 | grep 'time=.* ' -o | sed 's/time=//')
	if [ "$tiempo" == "" ]
	then
		echo "La IP $direccion no respondió tras $2 segundos">>fichero.tmp
	else
		echo "La IP $direccion respondió , en $tiempo milisegundos">>fichero.tmp
	fi
	done < <(cat $1)
	cat fichero.tmp |sort -k7
	rm fichero.tmp
else
	echo "Mal argumentos <script><fichero><segundos>"
fi