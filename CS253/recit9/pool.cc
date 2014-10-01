#include <iostream>

using namespace std;

class Bar {
    public:
	static void *operator new(size_t);
	static void operator delete(void *);
	double datum;

};

struct Node {
    union {
	Node *next;
	char pad[sizeof(Bar)];
    };
};
static struct Node *freelist;

static void *Bar::operator new(size_t) {
    if (freelist == NULL) {				// Out of free nodes?
	const int NODES_PER_PAGE = 8192/sizeof(Node);	// A bunch of them
	Node *n = new Node[NODES_PER_PAGE];		// Allocate many
	// Link all the new free nodes into the freelist
	freelist = n;
	for (int i=0; i<NODES_PER_PAGE-1; i++, n++)
	    n->next = n+1;
	n->next = 0;
    }
    void *result = freelist;	// Get the first node
    freelist = freelist->next;	// Remove it from the free list
    return result;
}

static void Bar::operator delete(void *p) {
    if (!p) return;				// Pesky null pointer!
    // Return this node to the list of free nodes.
    Node *n = reinterpret_cast<Node *>(p);
    n->next = freelist;
    freelist = n;
}

int main() {
	cout << "sizeof(double) = " << sizeof(double) << endl;
	cout << "sizeof(Node) = " << sizeof(Node) << endl;
	cout << "sizeof(Bar) = " << sizeof(Bar) << endl;
	Bar *r = new Bar;
	Bar *s = new Bar;
	cout << "r=" << r << " " << sizeof(r) << endl;
	cout << "s=" << s << " "<< sizeof(s) << endl;
	delete r;
	delete s;
	return 0;
}
