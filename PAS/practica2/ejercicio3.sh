#!/bin/bash
echo "Lista de usuarios conectados, juntos con el número de horas, minutos y segundos que llevan conectados:"
while read usuario;
do
 nombre=$(echo $usuario | sed -r -n 's/([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)/\1/p')
 fecha=$(echo $usuario | sed -r -n 's/([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*[ ]*[^ ]*)[ ]*([^ ]*)/\3/p')
  segundosAct=$(date +%s)
  segundosUser=$(date -d "$fecha" +%s)
  segundosConectado=$[$segundosAct-$segundosUser]
  horas=$[$segundosConectado/3600]
  minutos=$[$[$segundosConectado/60]%60]
  segundos=$[$segundosConectado-$horas*3600-$minutos*60]
  echo "El usuario $nombre lleva $horas horas, $minutos minutos , $segundos segundos conectado"

done < <(who | sort)
