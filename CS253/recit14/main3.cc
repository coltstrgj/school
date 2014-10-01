#include "fix2.h"		// This is fix2.h, not fix.h
#include <iostream>

int main() {
    fix<int, 3> f;
    fix<int,3>::iterator it;
    it = f.begin();		// now points to f[0]
    ++it;			// now points to f[1]
    ++it;			// now points to f[2]
    ++it;			// now points to f[3], the same as f.end()
    ++it;			// now points past f.end()!
    std::cout << *it << '\n';
}
