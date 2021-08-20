#!/bin/bash
# ${var:-default}//retorna default si var is unset or not exist
# ${var:=default}//retorna default si var is unset or not exist, and $var will be default 
# ${var:+default}//si existe $var, entonces se mostrara default

echo ${var:-"default"}  #exit : default
var="Origin"
echo ${var:+"default"}  #exit : default
unset var
echo ${var:="default"}  #exit : default, and var="default"
echo ${var}

# el que nos ayuda a manejar errores
${other:?"no existe esto"} #nos ayuda a verificar si existe, sino nos da un mensaje
                            #no altera para nada el $other value