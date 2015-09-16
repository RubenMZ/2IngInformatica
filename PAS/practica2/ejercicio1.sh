#!/bin/bash
if [ $# == 1 ];
then
	echo "*******"
	echo "1) Líneas con la duración de las películas: "
	cat $1 | grep '[0-9]* min.'
	echo "*******"
	echo "2) Líneas con el país de las películas: "
	cat $1 | grep '\[.*.\]'
	echo "*******"
	echo "3) Solo el país de las películas: "
	cat $1 | sed -r -n -e 's/.*\[(.*.)\]/\1/p'
	echo "*******"
	echo "4) Hay películas $(cat $1 | grep -c '\(2014\)') del 2014 y $(cat $1 | grep -c '\(2015\)') películas del 2015."
	echo "*******"
	echo "5) Eliminar líneas vacías: "
	cat $1 | sed -r -n -e 's/(.*.)/\1/p'
	echo "*******"
	echo "6) Lineas que empiezan la letra C (con o sin espacios antes):"
	cat $1 | grep -E '^C|^[ ]*C'
	echo "*******"
	echo "7) Lineas que contienen d, l o t, una vocal y la misma letra: "
	cat $1 | grep -E '([dlt])[aeiou]\1'
	echo "*******"
	echo "8) Lineas que contienen 8 aes o mas: "
	cat $1 | sed -r -n 's/([aA].*[aA].*[aA].*[aA].*[aA].*[aA].*[aA].*[aA].*)/\1/p' 
	echo "*******"
	echo "9) Lineas que terminan con tres puntos y no empiezan por espacio: "
	cat $1 | grep -E '^[[:alpha:]].*(\.\.\.)$'
	echo "*******"
	echo "10) Mostrar entre comillas las vocales con tilde: "
	cat $1 | sed -r  -e 's/([áéíóúÁÉÍÓÚ])/"\1"/'
else
	echo "Mal argumentos <script><fichero>"
fi
 