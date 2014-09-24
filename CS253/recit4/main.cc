#include <iostream>
#include "ll.h" 

using namespace std;

int main() {

    LinkedList list;
    bool done = false;

//    list.Initialize ();

    while (!done) {
	unsigned int i;
	int option;

	cout << "Choose your operation:\n"
	     << "1. insert\t2. delete\t3. exit\t4. Print\n";

	cin >> option;

	switch (option) {
	    case 1:
		cout << "Enter the number to insert\n";
		cin >> i;
		list.Insert (i);
		break;
	    case 2:
		if (list.Delete (i))
		    cout << "Deleted " << i << '\n';
		else
		    cout << "No numbers in the list\n";
		break;
	    case 3:
		done = true;
		break;
	
		case 4:
			list.Print(cout);
			break;
		
		
	}
    }

    return 0;
} 
