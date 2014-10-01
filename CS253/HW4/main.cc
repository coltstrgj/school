

#include "Calendar.h"

using namespace std;

int main(){

	Calendar a, b;
    try{
    a.insert(2023,12,24,18,5,"Christmas Eve");
    b.insert("1993-2-12T19/PT01H Groundhog Day");
    Calendar c=a;
    cout<<c.insert("2023-12-24T17/PT01H Lunch");
    cout << a;	// one events
    cout << c;	// two events
    cout << b;
    cout << a.size()<<endl;
	a.clear();
    cout << a.size()<<endl;
    }catch (string name){
        cout << name<<endl;
    }


	return 0;
}
