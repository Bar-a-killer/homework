#!/bin/bash

g++ D.cpp -o std
g++ AC.cpp -o bf

cnt=0

while true
do
    cnt=$((cnt+1))

    python3 gen.py > in.txt

    ./std < in.txt > out1.txt
    ./bf < in.txt > out2.txt

    diff -q out1.txt out2.txt > /dev/null

    if [ $? -ne 0 ]; then
        echo "WA on test $cnt"

        echo "Input:"
        cat in.txt

        echo
        echo "std:"
        cat out1.txt

        echo
        echo "bf:"
        cat out2.txt

        break
    fi

    echo "AC $cnt"
done