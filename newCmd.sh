#!/bin/bash

#touch infile
pno="10"
echo $pno
make
./simplechain 4 >file1.out 2>file1.out
export i=0
true > infile

input="file1.out"
while IFS= read -r line
do
	echo "$line" | awk -F ' ' '{if($5=="ID:972") {print($5);};}' | tr ',' '\n' | tee -a infile 
done < "$input"

input="infile"
while IFS= read -r line
do
	i=$(($i+1));
done < "$input"

bc -l <<< $i/$pno


