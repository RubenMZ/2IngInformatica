#!/bin/bash
function imprimeFic(){
	if [ -f $x ]
	then
		if [ -x $x ]
		then
			echo "$x; $(stat -c %s $x); $(stat -c %h $x); $(stat -c %A $x); 1;"
		else
			echo "$x; $(stat -c %s $x); $(stat -c %h $x); $(stat -c %A $x); 0;"
		fi
	fi

}

if [ $# -eq 1 ] || [ $# -eq 2 ]
then
	if [ -d $1 ]
	then
		echo "Ruta;Tamanio;ReferenciaInodo;Permisos;Ejecutable"
		if [ $#==2 ]
		then
			for x in $(find $1 -name "*$2*" -ls)
			do
			#y=$(awk '{print 11}')
			imprimeFic $x
			done
		else
			for x in $(find $1 -ls)
			do
			#y=$(awk '{print 11}')
			imprimeFic $x
			done	
		fi	
	else
		echo "El primer arg no es un directorio"
	fi
else
	echo "Argumentos mal <$0><directorio><cadena>"
fi
