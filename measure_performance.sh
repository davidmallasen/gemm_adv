#!/bin/bash

EXEC=$1
OUT=$2

for i in `seq 10 10 1000`;
do
    echo $i
    ./$EXEC $i >> $OUT
done
