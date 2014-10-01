#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <string.h>
#include <limits>

using namespace std;

template <class T>
class BarGraph {
    typedef map<T, unsigned> Con;
    Con data;
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
    void dump(std::ostream& os) {
	for (typename Con::iterator it=data.begin(); it!=data.end(); ++it)
	    os << right << setw(10) << it->first << ' '
		 << string(it->second, '*') << '\n';
        os << '\n';
    }
    friend std::ostream& operator<<(std::ostream& os, BarGraph& obj){
        obj.dump(os);
        return os;    
    }




};

template<>
class BarGraph<char> {
    int *count;
    unsigned int minChar, maxChar;
  public:
    BarGraph() : minChar(std::numeric_limits<char>::min()),
                 maxChar(std::numeric_limits<char>::max())
    {
        count = new int [maxChar-minChar+1];
        memset(count, 0, maxChar-minChar+1); 
    }
    ~BarGraph(){
    delete[] count;
    }
    void operator+=(bool datum) {
        count[datum - minChar]++;
    }
    void operator+=(string datumS) {
        for(int i=0; i<datumS.length(); i++)
            count[datumS[i]-minChar]++;    
    }

    void dump() {
        for(int i=minChar; i<=maxChar; i++)
            if(count[i-minChar])
                cout<< right <<setw(10)<<char(i)<<' '<<string(count[i-minChar], '*')<<endl;    
    }

};



template <>
class BarGraph<bool> {
    unsigned false_count, true_count;
  public:
    BarGraph() : false_count(0), true_count(0) {
    }
    void operator+=(bool datum) {
	datum ? true_count++ : false_count++;
    }
    void dump() {
        cout << "     false " << string(false_count, '*') << "\n"
                "      true " << string(true_count,  '*') << "\n\n";
    }
};

int main() {
	BarGraph<int> alpha;
	alpha += 12;
	alpha += 6;
	alpha += 4;
	alpha += 6;
    cout<<alpha;
	BarGraph<double> beta;
	beta += 3.14;
	beta += 2.71828;
	beta += 6.023e23;
	beta += 2.71828;
    cout<<alpha;

	BarGraph<bool> gamma;
	gamma += false;
	gamma += true;
	gamma += false;
	gamma += true;
	gamma += true;

	BarGraph<char> delta;
	delta += 'G';
	delta += 'e';
	delta += 'o';
	delta += 'f';
	delta += 'f';
}
