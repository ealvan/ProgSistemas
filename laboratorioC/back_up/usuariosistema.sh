#!/bin/bash
VAR1=$(cut -d: -f1 /etc/passwd)
dec="NO"
for usr in $VAR1
do
    if [ $usr = $1 ]
        then
            dec="SI"
            break
    else
        continue
    fi
done
echo $dec
