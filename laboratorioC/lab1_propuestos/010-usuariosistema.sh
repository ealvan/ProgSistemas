#!/bin/bash

function ayuda(){
    cat << DESCRIPCION_AYUDA
    SYNOPSIS
        $0 NOMBRE1 [NOMBRE2] ... [NOMBREN]
    descriptcion
        Muestra "Hola NOMBRE1, NOMBRE2, ...NOMBREN, por pantalla
    CODIGOS DE RETORNO
        Devuelve:
            SI si NOOMBRE_USUARIO coincide con algun usario del sistema o
            NO si NOOMBRE_USUARIO no coincide con algun usuario del sistema 

DESCRIPCION_AYUDA
}

if [ $# -ne 1 ] 
then
    echo "El #nro de parametros debe ser igual a 1"
    ayuda
    exit 1
fi

ESTA_EN_SISTEMA=´grep -E ^$1: /etc/passwd´
if [ -z "$ESTA_EN_SISTEMA" ]
then
    echo "NO"
else
    echo "SI"
fi


