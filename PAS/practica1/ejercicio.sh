#!/bin/bash

#find /etc/rc?.d/ -name "S*"

for f in $(find /etc/rc?.d "S*")
do
	echo "Carpeta $(dirname $f) Fichero $(basename $f)"
done

#Sin directorios
#for f in $(ls /etc/rc?.d/ | grep ^S)
#do
#	echo "Carpeta $(dirname $f) Fichero $(basename $f)"
#done

