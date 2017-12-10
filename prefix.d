import std.stdio;
import core.runtime : Runtime;

extern (C++) void d_init() {
    Runtime.initialize();
}

extern (C++) void d_term() {
    Runtime.terminate();
}

extern (C++) void registering()
{
    writefln("registering yeah!");
}
