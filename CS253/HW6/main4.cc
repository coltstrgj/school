


    #include "DupliCon.h"
    #include <iostream>

    using namespace std;

    // This class counts its instances.
    class Counter {
      public:
        Counter(int n=0) : value(n) { counter++; }
        Counter(const Counter &rhs) : value(rhs.value) { counter++; }
        ~Counter() { counter--; }
        bool operator<(const Counter &rhs) const { return value < rhs.value; }
        static int get_counter() { return counter; }
      private:
        int value;
        static int counter;
    };

    int Counter::counter=0;

    int main() {
        DupliCon<Counter> d;
        for (int i=0; i<1000; i++) {
            Counter c1(1), c2(2);
            d.insert(c1);
            d.insert(c2);
        }
        cout << d.size() << '\n'                // Must be 2000
             << d.unique_size() << '\n'         // Must be 2
             << Counter::get_counter() << '\n'; // 2 or just a few more
    }


