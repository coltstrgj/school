    #include "PNum.h"
    #include <iostream>
    #include <set>
    #include <cassert>

    using namespace std;

    // These three methods attempt to construct a PNum with the given arguments.
    // We expect that the ctor should fail.
    void should_throw(const string &arg) {
        try {
            PNum zulu(arg);
        }
        catch (const char *msg) {
            cout << "Good, PNum(\"" << arg << "\") threw \"" << msg << "\"\n";
            return;
        }
        cerr << "Error: expected PNum(\"" << arg << "\") to throw\n";
    }

    void should_throw(const string &a, const string &b, const string &c) {
        try {
            PNum zulu(a, b, c);
        }
        catch (const char *msg) {
            cout << "Good, PNum(\"" << a << "\",\"" << b << "\",\"" << c << "\")"
                    " threw \"" << msg << "\"\n";
            return;
        }
        cerr << "Error: expected PNum(\"" << a << "\",\"" << b << "\",\"" << c << "\")"
                " to throw\n";
    }

    void should_throw(int a, int b, int c) {
        try {
            PNum zulu(a, b, c);
        }
        catch (const char *msg) {
            cout << "Good, PNum(" << a << ',' << b << ',' << c << ")"
                    " threw \"" << msg << "\"\n";
            return;
        }
        cerr << "Error: expected PNum(" << a << ',' << b << ',' << c << ")"
                " to throw\n";
    }


    int main() {
        // PNum z;                          // must not compile

      PNum p(313, 987, 6543);
      assert(p.get_phone_number() == "313-987-6543");
      p.set_area_code("586");
      assert(p.get_phone_number() == "586-987-6543");
//      p.set_exchange(777);
//      assert(p.get_phone_number() == "586-777-6543");
//      const string s = "5393";
//      p.set_subscriber(s);
//      assert(p.get_phone_number() == "586-777-5393");
//      assert(p.get_area_code() == "586");
//      assert(p.get_exchange() == "777");
//      assert(p.get_subscriber() == "5393");

//      // Try some things that should throw errors
//      should_throw(0,0,0);                // Invalid area code & exchange
//      should_throw(911,123,4567);         // Invalid area code
//      should_throw("123","653","4567");   // Invalid area code
//      should_throw(970,142,4567);         // Invalid exchange
//      should_throw(970,711,4567);         // Invalid exchange
//      should_throw("911");                // Too short
//      should_throw("970","111","8712");   // Invalid exchange
//      should_throw("970","555","123");    // Invalid subscriber
//      should_throw("(777) 555-1212");     // Parentheses?
//      should_throw("777 555 1212");       // Spaces?
//      should_throw("777.555.1212");       // Dots?
//      should_throw("7775551212");         // Omitting delimiters not allowed
//      should_throw(" 777-555-1212");      // Extra spaces?
//      should_throw("777-5*5-1212");       // What a strange character!
//      should_throw("777-555-121½");       // What a strange character!
//      should_throw("7©7-555-1212");       // What a strange character!
//      should_throw("777-555-1212");       // Not really

//      set<PNum> nums;
//      nums.insert(p);
//      nums.insert(PNum("586", "321", "4567"));
//      nums.insert(PNum("586-777-7777"));
//      nums.insert(PNum(999,999,9999));
//      nums.insert(PNum("586-777-7777"));      // Duplicate should be rejected
//      nums.insert(PNum("246-888-8888"));

     //   for (set<PNum>::iterator it=nums.begin(); it!=nums.end(); ++it)
    //        cout << *it << endl;
    };
