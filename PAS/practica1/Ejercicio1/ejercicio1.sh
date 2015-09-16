#!/bin/bash
if [ $# -ge 1 ] && [ $# -le 2 ]
then
	if [ -d $1 ]
	then
		mkdir "$1.tmp"
		for x in $(find $1)
		do
			if [ -d $x ]
			then
				mkdir "$1.tmp/$x"
			else
				var1=$(date +%s)
				var2=$(stat $x -c %Y)
				var3=$[$var1-$var2]	
				if [ $var3 -gt 20 ]
				then
					cp $x "$1.tmp/$x"
				fi
			fi
			
		done
			if [ $# -eq 1 ]
			then
				cd "$1.tmp/"
				tar -czvf "../$1.tar.gz" "$1"
				cd ..
			else
				cd "$1.tmp/"
				tar -czvf "../$2" "$1"
				cd ..
			fi
		rm -R "$1.tmp"
	else	
		echo "No hay directorio."
	fi
else
	echo "Argumentos mal... $0 <carpeta> <nombre.tar.gz (opcional)>"
fi
