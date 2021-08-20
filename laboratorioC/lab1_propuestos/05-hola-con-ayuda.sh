#!/bin/bash

# if [ ! $# -ge 1 ]
# then
#     echo "ERROR: No tienes ningun parametro"
#     exit 0
# fi


# echo -n "Hola "
# for parametro in $@
# do
#     echo -n "$parametro, "
# done
# echo -n "!"
# echo

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

if test $# -le 0; then
    echo "Hay que introducir al mwnos unparametro"
    ayuda
    exit 1
fi

MENSAJE="Hola"
PRIMERO=1
#MIENTRAS HAYA PARAMENTROS
while [ -n $1 ];
do
    if [ $PRIMERO -eq 1 ]; then
        MENSAJE="$MENSAJE $1"
    else
        MENSAJE="$MENSAJE , $1"
    fi
    #oasamos al siguiente parametro
    shift
done

echo $MENSAJE
