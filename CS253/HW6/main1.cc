    #include "DupliCon.h"
    #include <iostream>
    #include <string>

    using namespace std;

    int main() {
        const string s = "applesauce";
        DupliCon<char> dc(s.begin(), s.end());
        std::cout<<"doing dc2\n"; 
        DupliCon<char> dc2(dc);
        std::cout<<"Doing DC3\n";
        DupliCon<char> dc3;
        dc3=dc;
        
        dc.erase('c');
        cout << "Size should be 9: " << dc.size() << endl;
        cout << "Unique size should be 6: " << dc.unique_size() << endl;
        cout << "Should be aaeelppsu: ";
        for (char c : dc)
            cout << c;
        cout << endl;

        dc2.erase('s');
        cout << "Size should be 9: " << dc2.size() << endl;
        cout << "Unique size should be 6: " << dc2.unique_size() << endl;
        cout << "Should be aaeelppsu: ";
        for (char c : dc2)
            cout << c;
        cout << endl;

        
        cout << "Size should be 10: " << dc3.size() << endl;
        cout << "Unique size should be 7: " << dc3.unique_size() << endl;
        cout << "Should be aaeelppsu: ";
        for (char c : dc3)
            cout << c;
        cout << endl;
    }
