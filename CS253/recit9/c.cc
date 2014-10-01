#include <iostream>
#include <malloc.h>

using namespace std;

void *operator new(size_t size) throw(bad_alloc) {
	void *p = malloc(size);
	// cout << "new(" << size << ") returns " << p << '\n';
	return p;
}



void operator delete(void *p) throw() {
	// cout << "delete(" << p << ")\n";
	free(p);
}

class Foo {
	char zot[4000];
};

int main() {
	for (int size=1; size<1000; size++) {
		char *p = new char[size];
		long *ip = (long *) p;
		cout << "bytesize=" << size*sizeof(*p) << " ip[-1]=" << ip[-1] << endl;
		delete[] p;
	}
	return 0;
}
