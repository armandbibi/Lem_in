
printf "${GREEN}maze that shall print not all the maze${NC}\n"
for file in tests/imcomplete_maze/*
do
	for ((i = 0; i < 1; i++))
	do
		name=${file##*/}
		echo $name
		./lem_in "$file"
		echo ""
	done
done
