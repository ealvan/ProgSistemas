#!/bin/bash
#echo "Hola $*!"
echo -n "Hola "
for parametro in $@
do
    echo -n "$parametro, "
done
echo -n "!"
echo
if [ $# -ge 1 ]
then
    echo "Exitos, tienes al menos un parametro"
else
    echo "Lo lamento no tienes ni un parametro"
fi
