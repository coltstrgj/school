#include "hset.h"
#include <cstdlib>			// for srand() and rand()
#include <iostream>
#include <time.h>			// for time() (duh)

using namespace std;

int main() {
    hset<int> h;
    cout<<h.empty()<<" <<<<<<<<<<<"<<endl;
    srand(time(0));			// Seed the random number generator

    for (int j=0; j<20; j++)		// Put some random numbers into the set
	h.insert(rand() % 100);		// Each number is 0-99
    h.dump();				// Let’s see what’s in there
    cout<< h.empty()<<"<<<<<<<<<<<<<<<<<<" << endl;
    cout << "size=" << h.size() << ':';
    for (hset<int>::iterator i=h.begin(); i!=h.end(); ++i)
	cout << ' ' << *i;
    cout << endl;
//////////////////////
    hset<double> hd;
    hd.insert(1.0);
    hd.insert(1.9);
    hd.insert(1.4);
    hd.insert(1.3);
    hd.insert(1.7);

    hd.dump();
    cout << "size=" << hd.size() << ':';
    for (hset<double>::iterator i=hd.begin(); i!=hd.end(); ++i)
	cout << ' ' << *i;
    cout << endl;
////////////////////////////
    hset<string> hs;
    hset<string, Hasher2> hs2;

    hs.insert("alpha");
    hs.insert("beta");
    hs.insert("gamma");
    hs.insert("delta");
    hs.insert("omega");
    hs.dump();

    hs2.insert("alpha");
    hs2.insert("beta");
    hs2.insert("gamma");
    hs2.insert("delta");
    hs2.insert("omega");
    hs2.dump();
    cout << "size=" << hs.size();
    for (hset<string>::iterator i=hs2.begin(); i!=hs2.end(); ++i)
	cout << ' ' << *i;
    cout << endl;
}
