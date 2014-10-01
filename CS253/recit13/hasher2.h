#include <string>

// Some horrible hash functions

class Hasher2 {
  public:
    unsigned operator()(int n) {
	   return n*3.456789;
    
    }
    
    unsigned operator()(double n) {
        return n*123456;
    }
    unsigned operator()(const std::string &s) {
	unsigned sum = 42;
	for (unsigned i=0; i<s.size(); i++)
	    sum += s[i];
	return sum;
    }
};

