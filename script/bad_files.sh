GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

printf "${GREEN}maze with error as output${NC}\n"
for file in tests/bad_tests/*
do
	for ((i = 0; i < 1; i++))
	do
		name=${file##*/}
		printf "${GREEN}$name -> ${RED}"
		./lem-in <  "$file"
		echo "${NC}"
	done
done

