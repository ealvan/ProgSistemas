#!/bin/bash
# comando para mostrar los usuarios conectados en este momento
# who | cut -d' ' -f1 | sort | uniq
#echo `who | cut -d' ' -f1 | sort | uniq`

function ayuda(){
    cat << DESCRIPCION_AYUDA
    SYNOPSIS
        $0 NOMBRE1 [NOMBRE2] ... [NOMBREN]
    descriptcion
        Muestra "Hola NOMBRE1, NOMBRE2, ...NOMBREN, por pantalla
    CODIGOS DE RETORNO
        1 si el numero de parametros es menor a 1

DESCRIPCION_AYUDA
}

if [ $# -le 0 ]; then
    echo "Hay que introducir al mwnos unparametro"
    ayuda
    exit 1
fi
MENSAJE="Hola"
PRIMERO=1
#MIENTRAS HAYA PARAMENTROS
while [ -n $1 ]
do
    ESTA_CONECTADO=´who | grep $1´
    if [ -z $ESTA_CONECTADO ]
    then
        echo "El usuario $1 no esta conectado"
        exit 2
    fi
    if [ $PRIMERO -eq 1 ]
    then
        MENSAJE="$MENSAJE $1"
        PRIMERO=0
    else
        MENSAJE="$MENSAJE, $1"
    fi

    shift
done

echo ${MENSAJE}"!"
