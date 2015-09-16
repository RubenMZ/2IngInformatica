#!/bin/bash
read -p "Introduzca un primer numero: " var1
read -p "Introduzca un segundo numero: " var2
echo "Suma: $[var1+var2]"
echo "Resta: $[var1-var2]"
echo "Multiplicacion: $[var1*var2]"
echo "Division: $[var1/var2]"
echo "Modulo: $[var1%var2]"
