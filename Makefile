main: Makefile main.o csci152_student.o
	g++ -std=c++17 -o main main.o csci152_student.o

main.o: Makefile main.cpp csci152_student.h
	g++ -c -std=c++17 -o main.o main.cpp

csci152_student.o: Makefile csci152_student.cpp csci152_student.h
	g++ -c -std=c++17 -o csci152_student.o csci152_student.cpp
