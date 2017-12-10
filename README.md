# C++ Test

Exploring a how well D can interact with C++.
Basic idea: The program reads lines from stdin and does things with it.
There is an observer class declared in C++.
Can we also register a D class?
Yes, we can.

## Limitations

Using the STL does not really work.
The problem is that we must replicate the complete header files in D.
This is a lot of work and not portable between different compilers.

There is the [Calypso project](https://github.com/Syniurge/Calypso),
which tries to automate that by using Clang to parse the headers.
