#include <iostream>
#include <malloc.h>

using namespace std;

void *operator new(size_t size) throw(bad_alloc) {
	void *p = malloc(size);
	cout << "new(" << size << ") returns " << p << '\n';
	return p;
}



void operator delete(void *p) throw() {
	cout << "delete(" << p << ")\n";
	free(p);
}

class Foo {
	char zot[4000];
};

int main() {
	double *p = new double;
	Foo *q = new Foo;
	delete p;
	delete q;
	return 0;
}
