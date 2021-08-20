#!/bin/sh
echo "current filename $0"
echo "parametro nro 1 del comand prompt $1"
echo "parametro nro 2 $2"
echo "el nro de agumentos de un script $#"
echo "uno equivale a dos, todos en un string:"
echo $*
echo "cada uno es un sttring, uno equivale a dos"
echo $@
echo "estado de salida del ultimo comando ejecutado!:"
echo $?
echo "Process ID de este proceso que estas ejecutando:"
echo $$
echo "el numero de proceso del ultimo comando ejecutado"
echo $!
