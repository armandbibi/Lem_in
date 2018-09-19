#!/bin/bash

if [ -e trace ]
then
	rm trace
fi

for file in ./tests/_maps/*
do
	echo "Run ./lem-in $1 < $file"
	echo "\nFile: $file" >> trace
	valgrind ./lem-in $1 < $file >> trace 2>&1
done
