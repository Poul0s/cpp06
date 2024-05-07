#!/bin/bash

EXEC_NAME="../scalarConvert"
INPUT_FILE="./input.txt"

# if [ -v $1 ]; then
# 	EXEC_NAME=$1
# fi

# if [ -v $2 ]; then
# 	INPUT_FILE=$2
# fi

# echo "Executable: $EXEC_NAME"
# echo "Input file: $INPUT_FILE"

INPUT_DIR=$(dirname $INPUT_FILE)

test_nb=1

while read -r line; do
	# echo "Input: $line"
	valgrind --leak-check=full --track-fds=yes --error-exitcode=1 "$EXEC_NAME" "$line" > $INPUT_DIR/output_$test_nb.txt
	if [ ! $? -eq 0 ]; then
		echo "Test $test_nb: MKO"
		exit 2
	else
		diff $INPUT_DIR/output_$test_nb.txt $INPUT_DIR/res$test_nb.txt
		if [ $? -eq 0 ]; then
			echo "Test $test_nb: OK"
		else
			echo "Test $test_nb: KO"
			exit 1
		fi
	fi
	((test_nb++))
done < "$INPUT_FILE"