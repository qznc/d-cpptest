default: main

prefix.o: prefix.d
	ldc2 -g -c $<

main.o: main.cpp main.h
	clang -g -c -I. -std=c++11 $< -o $@

main: prefix.o main.o
	ldc2 $^ -L-lstdc++ -of=$@
