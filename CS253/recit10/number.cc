#include <iostream>
#include <sstream>
#include <map>


using namespace std;

class Number {
    public:
	Number() : value(0) {}
	Number(int v) : value(v) {}
	Number &operator=(int n) { value = n; return *this; }
	operator int() const { return value; }
    private:
    	int value;
};

istream &operator>>(istream &is, Number &rhs) {
	string str;
    is>>str;
    if(is_digits(str)){
        istringstream buffer(str);
        int n;  
        buffer >> n;
        rhs = n;
    }else if(m.count(str)){//if it is "one" "two" ...
        rhs = m[str];
    }else{
        is.setstate(std::ios::badbit);//set the badbit and stop
    }

	return is;
}


int main() {
	Number n = 666;
	istringstream ss("12 34 three 789 five");

	while (ss >> n)
		cout << n << ' ';
	cout << endl;
}
