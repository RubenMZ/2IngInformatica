#!/bin/bash
function imprime(){
          echo $1 | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/==========\nLogname: \1 \n->UID:\3/p'
        logname=$(echo $1 | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\1/p')
        idgrupo=$(echo -n $1 | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\4/p')
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
        echo $1 | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/->GID: \4 \n->gecos: \5 \n->Home: \6 \n->Shell por defecto: \7/p'
        while read user;
        do
          if [ "$logname" == "$user" ]
            then
            conectado=1
          fi
        done < <(who |sed -r -n 's/([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)/\1/p')
        echo "->Conectado: $conectado"
}

if [ $# == 1 ]
then
while read line;
do
  		conectado=0
      uid=$(echo $line | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\3/p')
      if [ $uid -ge 1000 -a $1 -eq 1 ]
        then
        imprime $line
      fi

      if [ $1 -eq 0 ]
        then
        imprime $line
      fi
done < <(cat /etc/passwd )
else
	echo "Mal argumentos <script> <uid 0/1>" 
fi