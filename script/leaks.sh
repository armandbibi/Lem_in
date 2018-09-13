#!/bin/bash

RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
BASE=$(tput sgr0)
GOOD_MAPS=./tests/good_tests/*
BAD_MAPS=./tests/bad_tests/*

printf ">> LEAK MANAGEMENT\n"
WHAT="lost"
for f in $BAD_MAPS
do
	printf "\n>> testing ${f##*/}:\n"
	WHERE="$(valgrind --track-origins=yes --show-leak-kinds=definite ./lem_in < $f | grep $WHAT)"
	res=$(echo "$WHERE" | grep -E 'directly|definitely' | cut -c 14-)
	echo "${res}"
done
printf "\n>> 2. GOOD MAPS\n"
for f in $GOOD_MAPS
do
	printf "\n>> testing ${f##*/}:\n"
	WHERE="$(valgrind --tool=memcheck --leak-check=full ./lem-in 2>&1 < $f | grep $WHAT)"
	res=$(echo "$WHERE" | grep -E 'directly|definitely' | cut -c 14-)
	echo "${res}"
done
