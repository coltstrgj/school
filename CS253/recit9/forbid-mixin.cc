#include <iostream>

class NoNewDelete {
   public:
   	static void *operator new(std::size_t);
   	static void operator delete(void *, std::size_t);
};

class Foo : public NoNewDelete {
};

using namespace std;

int main() {
	Foo bar;
	Foo *p = &bar;
	p = new Foo;
	cout << "done\n";
}
