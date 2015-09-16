#!/bin/bash
if [ $# == 1 ]
then
while read line;
do
  		conectado=0
      echo $line | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/==========\nLogname: \1 \n->UID:\3/p'
      logname=$(echo $line | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\1/p')
      idgrupo=$(echo -n $line | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\4/p')
      if [ "$idgrupo" == "" ]
      then
            echo "->Grupo: Sin grupo"
      else
        while read grupo;
        do
          numgrupo=$(echo $grupo |sed -r -n 's/(.*):(.*):(.*):(.*)/\3/p')
          gnombre=$(echo $grupo |sed -r -n 's/(.*):(.*):(.*):(.*)/\1/p')
          if [ "$numgrupo" == "$idgrupo" ]
            then
              echo "->Grupo: $gnombre"
          fi
        done < <(cat /etc/group)
      fi 
      echo $line | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/->GID: \4 \n->gecos: \5 \n->Home: \6 \n->Shell por defecto: \7/p'
      while read user;
      do
        if [ "$logname" == "$user" ]
          then
          conectado=1
        fi
      done < <(who |sed -r -n 's/([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)/\1/p')
      echo "->Conectado: $conectado"
done < <(cat /etc/passwd | grep "$1" )
else
	echo "Mal argumentos <script> <shell>" 
fi