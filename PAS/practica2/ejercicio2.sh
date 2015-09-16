#!/bin/bash
if [ $# == 1 ];
then
	cat $1 | sed -e  "s/^\(.\{50\}\).*/\1.../" | sed -r "s/^\((2014|2015)\)[ ]*\[(.*.)\]/\1, \2/"
else
	echo "Mal argumentos <script><fichero>"
fi
