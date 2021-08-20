#!/bin/bash
echo "Hola $*!"
if [ $# -ge 1 ]
then
    echo "Exitos, tienes al menos un parametro"
else
    echo "Lo lamento no tienes ni un parametro"
fi


