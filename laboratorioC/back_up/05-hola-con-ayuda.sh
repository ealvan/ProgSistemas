#!/bin/bash

if [ ! $# -ge 1 ]
then
    echo "ERROR: No tienes ningun parametro"
    exit 0
fi
echo -n "Hola "
for parametro in $@
do
    echo -n "$parametro, "
done
echo -n "!"
echo