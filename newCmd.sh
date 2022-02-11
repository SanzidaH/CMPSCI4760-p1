#!/bin/bash

#touch infile
pno="100"
st="2"
iter="2"
char="2"

echo "Number of Process: $pno"
make
./simplechain -s $st -p $pno -i $iter -c $char >file1.out 2>file1.out
export i=0
true > infile

input="file1.out"
while IFS= read -r line
do
	echo "$line" | awk -F ' ' '{if($5=="ID:1" || $5=="ID:972") {print($5);};}' | tr ',' '\n' | tee -a infile 
done < "$input"

input="infile"
while IFS= read -r line
do
	i=$(($i+1));
done < "$input"

echo "fraction that are adopted by init:"
bc -l <<< $i/$pno


