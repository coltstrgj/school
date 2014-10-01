#include <string>

// Some horrible hash functions

class Hasher {
  public:
    unsigned operator()(int n) {
	return n % 8;
    }
    
    unsigned operator()(double n) {
        int tmp=n*11111;
        return tmp % 8;
    }
    unsigned operator()(const std::string &s) {
	unsigned sum = 42;
	for (unsigned i=0; i<s.size(); i++)
	    sum += s[i];
	return sum;
    }
};

