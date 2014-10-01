
#include <iostream>
#include <malloc.h>
#include <string.h>

using namespace std;

void *operator new(size_t size) throw(bad_alloc) {
	void *p = malloc(size);
	cout << "new(" << size << ") returns " << p << '\n';

	// Fill that memory with the letter 'q'
	memset(p, 'q', size);
	
	return p;
}

void operator delete(void *p) throw() {
	cout << "delete(" << p << ")\n";
	free(p);
}

// Really, we should be filling the memory with nonsense during
// delete, not new.  However, it's harder to figure out what the
// size is when delete is called, so we compromise.

int main() {
	int *p = new int;
	cout << "Our int is: " << *p << '\n';
	cout << "new(" << size << ") returns " << p << '\n';
	delete p;
	return 0;
}
