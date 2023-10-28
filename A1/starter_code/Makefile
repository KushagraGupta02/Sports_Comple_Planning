all: main.cpp SportsLayout.cpp
	g++ -o main main.cpp SportsLayout.cpp

clean:
	rm main

run: all
	./main ../test_cases/$(in) ../outputs/$(out)

test: all
	./main ../test_cases/input1.txt ../outputs/output1.txt
	./main ../test_cases/input2.txt ../outputs/output2.txt
	./main ../test_cases/input3.txt ../outputs/output3.txt
	./main ../test_cases/input4.txt ../outputs/output4.txt
	./main ../test_cases/input5.txt ../outputs/output5.txt

rishit: all
	./main ../Rishit\ TC/input0.txt ../Rishit\ TC/output0.txt
	./main ../Rishit\ TC/input1.txt ../Rishit\ TC/output1.txt
	./main ../Rishit\ TC/input2.txt ../Rishit\ TC/output2.txt
	./main ../Rishit\ TC/input3.txt ../Rishit\ TC/output3.txt
	./main ../Rishit\ TC/input4.txt ../Rishit\ TC/output4.txt
	./main ../Rishit\ TC/input5.txt ../Rishit\ TC/output5.txt
	./main ../Rishit\ TC/input6.txt ../Rishit\ TC/output6.txt
	./main ../Rishit\ TC/input7.txt ../Rishit\ TC/output7.txt
	./main ../Rishit\ TC/input8.txt ../Rishit\ TC/output8.txt
	./main ../Rishit\ TC/input9.txt ../Rishit\ TC/output9.txt
	./main ../Rishit\ TC/input10.txt ../Rishit\ TC/output10.txt