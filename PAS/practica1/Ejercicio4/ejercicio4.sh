#!/bin/bash
if [ $# -eq 2 -a -f $1 ]
then 
	ind=1
	for x in $(grep -n $2 < $1 | cut -d ":" -f1 )
	do
		echo "---------------------------"
		echo "Emparejamiento número: $ind"
		i=0
		while read linea
		do 
			((i++))
			if [ $x -eq $((i-1)) -o $x -eq $i -o $x -eq $((i+1)) ]
			then
				echo $linea
			fi
		done < $1
		#echo "$x" | cut -d " " -f 2 esta malito
		((ind++))
	done
else
	echo "Argumentos mal <ejecutable><fichero><caracteres>"
fi
