
    #include "DupliCon.h"
    #include <iostream>

    // A thin wrapper around a double.  You can’t compare these using <.
    class Foo {
      public:
        Foo(double d=0.0) : value(d) {}
        double value;
    };

    // A functor that compares two objects of type Foo.
    struct Functor {
        bool operator()(const Foo &a, const Foo &b) {
            return b.value < a.value;   // Sort by value, high to low
        }
    };

    int main() {
        DupliCon<Foo, Functor> dc;
        Foo a(1.234), b(12.5), c(-12);
        dc.insert(a);
        dc.insert(b);
        dc.insert(c);

        for (auto v : dc)
            std::cout << v.value << ' ';
        std::cout << '\n';
    }

//Which produces this output:

  //  12.5 1.234 -12 


