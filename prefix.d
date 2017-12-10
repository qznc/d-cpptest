import core.runtime : Runtime;

extern(C++) {
    void d_init() {
        Runtime.initialize();
    }

    void d_term() {
        Runtime.terminate();
    }

    interface LineObserver(T) {
        void observeLine(const char* line, T payload);
    }

    class PrefixPrinter(T) : LineObserver!T {
        override extern(C++) void observeLine(const char* line, T payload) {
            import std.stdio;
            import std.conv : to;
            writefln("%d %s", payload, to!string(line));
        }
    }

    LineObserver!int from_d() {
        return new PrefixPrinter!int();
    }
}
