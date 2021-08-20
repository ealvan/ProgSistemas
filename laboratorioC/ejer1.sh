total=1
for var in "$*";do
    echo "\$* ========> #$total=$var"
    total=$(($total + 1))
done

total=1
for var in "$@";do
    echo "\$@ =======> #$total=$var"
    total=$(($total + 1))
done

#$bash myscript.sh 1 2 3 4



















