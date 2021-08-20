#!/bin/bash

# echo -n "message"#comprime el break line por defecto del echo
# echo -e "meassage"#habilita la interpretacion de caracteres especiales.
# \\,\a,\b,\c,\f,\n	,\r	,\t,\v

a=0
while [ $a -le 10 ]
do
    echo $a
    if [ $a -eq 5 ]
    then
        echo "Encontramos el cinco"
        break
    fi
    a=`expr $a + 1`
done

#break #n nested foor loops

for var1 in 1 2 3
do
    for var2 in 0 5
    do
        if [ $var1 -eq 2 -a $var2 -eq 0 ]
        then
            echo "$var1 -> $var2 find!"
            break 2 #es el break de toda la vida
        else
            echo "$var1-$var2"
        fi
    done
    
done

# continue

NUMS="1 2 3 4 5 6 7"
for NUM in $NUMS
do
    Q=`expr $NUM % 2`
    if [ $Q -eq 0 ]
    then
        echo "$Q is even number"
    fi
    echo "$Q is odd number"    
done