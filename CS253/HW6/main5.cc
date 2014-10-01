


    // This C++11 program tests a comparison functor and use of const.

    #include "DupliCon.h"
    #include <iostream>
    #include <string>

    using namespace std;

    // Compare two strings by length: short strings go first.
    class CompareSize {
      public:
        bool operator()(const string &a, const string &b) const {
            return a.size() < b.size();
        }
    };

    int main() {
        const string strs[] = {"alpha","beta","gamma","delta","epsilon","zeta"};
        const DupliCon<string, CompareSize> d(strs, strs+6);

        // Should produce: beta beta alpha alpha alpha epsilon 
        for (const auto s : d)
            cout << s << ' ';
        cout << '\n';
    }

