default: main

main: main.cpp main.h
	clang -g -I. -std=c++11 $< -o $@ -lstdc++
