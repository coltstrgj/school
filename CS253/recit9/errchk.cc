#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

class Foo {
    public:
	static void *operator new(size_t size) throw(bad_alloc) {
		void *p = new char[size];
		if (min==NULL || p < min)
			min = p;
		if (max==NULL || p > max)
			max = p;
		cout << "new(" << size << ") returns " << p << '\n';
		return p;
	}

	static void operator delete(void *p) throw() {
		cout << "delete(" << p << ")\n";
		if (p == NULL)			// It's ok to delete NULL.
			return;

		if (min == NULL) {
			cerr << "ERROR: attempt to delete a Foo, "
			     << "but no Foo was ever allocated.\n";
			exit(1);
		}
		else if (p < min || p > max) {
			cerr << "ERROR: attempt to delete a Foo, "
			     << "but " << p << " is out of range.\n";
			exit(1);
		}
		// Non-portable code:
		else if (long(p) & 07) {
			cerr << "ERROR: attempt to delete a Foo, "
			     << "but " << p << " has bad alignment.\n";
			exit(1);
		}

		delete[] static_cast<char *>(p);
	}

	static void *min, *max;
	char zot[4000];
};

void *Foo::min, *Foo::max;

int main() {
	double *p = new double;
	Foo *q = new Foo;
	int z;
	Foo *r = (Foo *) &z;
	delete p;
	delete q;
	delete r;
	return 0;
}
