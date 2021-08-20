#!/bin/bash

#dcir si un usario esta conectado o no

function ayuda(){
    cat << DESCRIPCION_AYUDA
    SYNOPSIS
        $0 NOMBRE_USUARIO
    descriptcion
        devuelve:
            SI si $1 coincide con algun usuario conectado
            NO si $1 no coincide con algunusario conectado
        Muestra "Hola NOMBRE1, NOMBRE2, ...NOMBREN, por pantalla
    CODIGOS DE RETORNO
        1 si el numero de parametros es distinto de 1

DESCRIPCION_AYUDA
}

if [ $# -le 0 ]; then
    echo "Hay que introducir al mwnos unparametro"
    ayuda
    exit 1
fi

ESTA_CONECTADO=´who | grep $1´
if [ -z $ESTA_CONECTADO ] 
then
    echo "NO"
else
    echo "SI"
fi
