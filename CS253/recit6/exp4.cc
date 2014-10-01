#include <iostream>
using namespace std;

void foo(int x) {
    if (x < 10)
        cout << "x is less than 10\n";
}

int main() {
    int y=1;
    foo(y);
    return 0;
}
