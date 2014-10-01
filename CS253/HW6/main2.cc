
     #include "DupliCon.h"
    #include <iostream>


    struct CompareByBits {          // A comparison functor
        int bitcount(int n) {       // From K&R’s C Programming Language
          int count;                // c accumulates the total bits set in v
          for (count = 0; n; count++) 
            n &= n - 1;             // clear the least significant bit set
          return count;
        }
        bool operator()(int a, int b) {
            return bitcount(a) < bitcount(b);   // Sort by number of bits
        }
    };

    int main() {

   DupliCon<int, CompareByBits> d; // ints sorted by number of bits
//        DupliCon<int> d; // ints sorted by number of bits

        d.insert(259);        // 3 bits set
        d.insert(15);         // 4 bits set
        d.insert(255);        // 8 bits set
        d.insert(0x80000000); // 1 bit set
        d.insert(259);
        d.insert(259);
        d.insert(0);          // 0 bits set
        auto iter2=d.begin();
        ++iter2;
        ++iter2;
        d.erase(iter2);
        for (auto iter=d.begin(); iter!=d.end(); ++iter){
            //for(auto iter2(iter); iter2!=d.end(); ++iter2)
              //  std::cout<<"\niterd"<<*iter2<<' ';

            std::cout <<*iter << ' ';
        }
        std::cout << "\n"<<d.max_size();
                    
        std::cout << "0 -2147483648 259 15 255"<<'\n';
        return 0;
    }


//Which produces this output, sorted by number of bits in each integer:

  //  0 -2147483648 259 15 255 


