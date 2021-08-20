#!/bin/bash
#Simple array
array=(1 2 3 4 5)

echo ${array[*]}

otro=("A" "B" "C")

for token in ${otro[@]}
do
echo $token
done
echo "Misiono completada!!"

