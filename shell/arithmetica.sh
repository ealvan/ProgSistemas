#!/bin/bash

val=`expr 2 + 2`
echo "a + b  : $val"

val1=`expr 2 - 2`
echo "a - b : $val1"

val2=`expr 2 \* 2`
echo "a * b : $val2"

val3=`expr 2 / 2`
echo "a / b : $val3"

val4=`expr 2 % 2`
echo "a % b: $val4"

echo "el print de 12345: "
array=(1 2 3 4 5)
for TOKEN in ${array[@]}
do
	echo $TOKEN
done

echo "a = 2"
echo "b = 3"
a=2
b=3
if [ $a == $b ]
then
	echo "a y b son iguales"
else
	echo "a y b son diferentes"
fi


if [ $a != $b ]
then
	echo "Somos diferentes a y b"
else
	echo "somos iguales"
fi


























