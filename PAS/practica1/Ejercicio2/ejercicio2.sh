#!/bin/bash
function imprimir(){
	

	echo -e "<ul>" >> "$1.html"
	for x in $(find $2 -maxdepth 1)
	do
		if [ $x != $2 ]
		then		
		if [ -d $x ]
		then
			echo -e "<strong><li>$x</li></strong>\n" >> "$1.html"
			imprimir $1 $x
			echo -e "</ul>\n">>"$1.html"
		else
				echo -e "<li>$x</li>\n" >> "$1.html"
		fi
		fi
	done


}

if [ $# -eq 1 ]
then
	if [ -d $1 ]
	then
		echo -e "<html>\n<head>\n<title>Ejercicio2</title>\n</head>\n<body>\n<h1>EJERCICIO2</h1>" >"$1.html"
		imprimir $1 $1
		echo -e	"</body>\n</html>">>"$1.html"	
		
	else	
		echo "No hay directorio."
	fi
else
	echo "Argumentos mal... $0 <carpeta>"
fi


