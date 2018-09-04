for file in tests/bad_tests/*
do
	for ((i = 0; i < 1; i++))
	do
		name=${file##*/}
		echo $name
		./lem_in "$file"
		echo ""
	done
done
