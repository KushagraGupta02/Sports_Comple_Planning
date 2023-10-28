for n in {0..10}
	do
		input_file="../Rishit\ TC/input${n}.txt"
		
		# Check if the input file exists before running the program
		if [ -e "$input_file" ]
		then
			echo "Running my_program on $input_file"
			./main $input_file ./Rishit\TC/out.txt  # Replace with the actual command to run your program
		else
			echo "$input_file does not exist."
		fi
	done
