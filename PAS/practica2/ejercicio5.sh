#!/bin/bash
echo "Descargando la web https://twitter.com/GeoPortalMityc..."
wget https://twitter.com/GeoPortalMityc &>fichero.tmp
echo "Listado de precios de GeoPortalMityc ordenados por precio del Combustible: "
cat GeoPortalMityc | grep -E -o "EcoPrecio.*<" | sed -n -r 's/^EcoPrecio[ ]([^ ]*[ ][^ ]*)[ ](.*)[ ]es[ ](.*)[ ]en[ ](.*)</Precio: "\3" Ciudad: "\2" Combustible: "\1" Direccion: "\4"/p' |sort -k2
rm GeoPortalMityc
rm fichero.tmp