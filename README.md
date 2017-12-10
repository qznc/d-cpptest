# C++ Test

Exploring a how well D can interact with C++.
D has [more potential than Rust](https://internals.rust-lang.org/t/interfacing-d-to-legacy-c-code-a-summary-of-a-competing-languages-capabilities/1406).

[Walter Bright says](http://www.walterbright.com/cppint.pdf)
that exceptions are still a problem though.

Basic idea of the example:
The program reads lines from stdin and does things with it.
There is an observer class declared in C++.
Can we also register a D class?
Yes, we can.

## Limitations

Using the STL does not really work.
The problem is that we must replicate the complete header files in D.
This is a lot of work and not portable between different compilers.

There is the [Calypso project](https://github.com/Syniurge/Calypso),
which tries to automate that by using Clang to parse the headers.
