#!/bin/bash

a=0
#while loop
while [ $a -le 10 ]
do
    echo $a
    a=`expr $a + 1`
done

#for loop
for var in 0 1 2 3 4 5
do  
    if [ `expr $var % 2` -eq 0 ]
    then
        echo "$var es par"
    else
        echo "$var es impar"
    fi
done

#until loop
p=0
until [ ! $p -lt 5 ]
do
    echo $p
    p=`expr $p + 1`
done

#select loop
#no funciona muy bien siempre se va al caso *)
# select DRINK in tea cofee water juice appe all none
# do
#     case $DRINK in
#         tea|cofee|water|all)
#             echo "Go to canteen"
#             ;;
#         juice|appe)
#             echo "Avaible at home"
#             ;;
#         none)
#             break
#             ;;
#         *)
#             echo "ERROR: Invalid selection"
#             ;;
#     esac
# done


