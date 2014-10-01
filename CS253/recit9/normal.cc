#include <iostream>

using namespace std;

class Foo {
    public:
    	double datum;
};

int main() {
	cout << "sizeof(double) = " << sizeof(double) << endl;
	cout << "sizeof(Foo) = " << sizeof(Foo) << endl;
	Foo *p = new Foo;
	Foo *q = new Foo;
	cout << "p=" << p << endl;
	cout << "q=" << q << endl;
	delete p;
	delete q;
	return 0;
}
