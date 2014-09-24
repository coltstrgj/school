

#include "Calendar.h"

using namespace std;

int main(){

	Calendar a, b;
    a.insert(2023,12,24,18,5,"Christmas Eve");
    b.insert("1993-2-2T9/PT01H Groundhog Day");
    c.insert(2023,12,24,18,6,"Christmas Eve");
    Calendar c=a;
    cout << a;	// one events
    cout << c;	// two events
    cout << b;
	cout << a.size();
	a.clear();
	cout << a.size();


	return 0;
}
