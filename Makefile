default: main

main: main.cpp main.h
	gcc -I. -std=c++11 $< -o $@ -lstdc++
