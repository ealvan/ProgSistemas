#!/bin/bash
# comando para mostrar los usuarios conectados en este momento
# who | cut -d' ' -f1 | sort | uniq
#echo `who | cut -d' ' -f1 | sort | uniq`
#asi puedo ejecutar el comando para que llame al script
#$1 contedra elnombre del usuario
echo `bash usuarioconectado.sh $1`

