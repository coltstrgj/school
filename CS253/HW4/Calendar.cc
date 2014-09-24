#include <string>
#include "Calendar.h"
#include <sstream>
#include <set>

using std::cout;
using std::cerr;
using std::string;

//DONE... LOL
Calendar::Calendar(){ }

//DONE
string tostr(int conv){
        std::stringstream ss;
        ss << conv;
        return ss.str();
}

//TODO
bool Calendar::insert(int year, int mon, int day, int hour, int length_in_hours, const std::string &title){

        //if(year <
        string event = tostr(year) + "-" + tostr(mon) + "-" + tostr(day) + "T" + tostr(hour) + "/PT" + tostr(length_in_hours) + "H " + title;
        //cout << event << "\n";
        calend.insert(event);
        return 0;
}

//DONE
void Calendar::print(std::ostream &os) const{
        std::multiset<string>::iterator it;
        for(it=calend.begin(); it!=calend.end(); it++){
                cout << (*it) << "\n";
        }
}

//TODO
bool Calendar::insert(const std::string &specification){ return 0;}

//DONE
int Calendar::size() const{ return calend.size();}

//DONE
void Calendar::clear(){ calend.clear(); }

//DONE
Calendar Calendar::operator|(const Calendar &rhs){
  Calendar temp;
  temp.calend = calend;
  //temp = this;
  temp.calend.insert(rhs.calend.begin(), rhs.calend.end());
  return temp;
}

//DONE
Calendar &Calendar::operator|=(const Calendar &rhs){
  calend.insert(rhs.calend.begin(), rhs.calend.end());
  return *this;
}
//DONE
Calendar &Calendar::operator=(const Calendar &rhs){
        calend = rhs.calend;
        return *this;
}
//DONE
Calendar::Calendar(const Calendar &rhs) : calend(rhs.calend) {}
//DONE
Calendar::~Calendar(){ calend.clear(); }
