/////////////////////////////////
//Colt Darien
//CS253
//HW4
//03/25/2014
//////////////////////////////////



/*
year is 1900–2100, inclusive.
mon is 1–12.
day is 1–31, but the range is smaller for some months.
hour is 0–23; noon is 12.
length_in_hours must not go past midnight.

void print(std::ostream &os) const
Print the current calendar to the given stream, in ISO 8601 format, sorted primarily by beginning date/time, and secondarily by title. The format is: 

<year>-<month>-<day>T<hour>/PT<duration>H 

All numbers in the time specification are displayed with at least two digits.
    1976-07-04T00/PT24H Bicentennial
    2013-12-31T18/PT06H New Year's Eve!
    2014-03-03T10/PT01H CS253
    2014-03-03T13/PT01H CS156
    2014-03-04T10/PT02H Office Hours
*/

//$default ctor
#include <string>
#include "Calendar.h"
#include <sstream>
#include <set>
#include <cassert>
#include <stdlib.h>

using namespace std;



Calendar::Calendar() {}

//$Calendar dtor
Calendar::~Calendar() {
    events.clear();
}

//$
Calendar::Calendar(const Calendar &rhs): events(rhs.events) {}

//$
Calendar & Calendar::operator=(const Calendar &rhs){
    this->events = rhs.events;
    //may need to be *this
    return *this; 
}

//$Insert an event. Return true if this new event overlapped another event, false otherwise, but insert it in either case. If the attempted insertion violates any of the following rules, throw an error and do not insert the event:
//year is 1900–2100, inclusive.
//mon is 1–12.
//day is 1–31, but the range is smaller for some months.
//hour is 0–23; noon is 12.
//length_in_hours must not go past midnight.
//this will insert the date into the multiset
bool Calendar::insert(int year, int mon, int day, int hour, int length_in_hours, const string &title){
    //2014-03-24T21/PT02H A two-hour meeting
    string tmp;
    checkError(year, mon, day, hour, length_in_hours);
    
    string y = (intToString(year));
    string m = (intToString(mon));
    string d = (intToString(day));
    string h = (intToString(hour));
    string l = (intToString(length_in_hours));

    tmp.append(y);
    tmp.append("-");
    tmp.append(m);
    tmp.append("-");
    tmp.append(d);
    tmp.append("T");
    tmp.append(h);
    tmp.append("/PT");
    tmp.append(l);
    tmp.append("H ");
    tmp.append(title);
    bool ovr = checkOverlaps(year, mon, day, hour, length_in_hours);
    events.insert(tmp);
    return ovr;
}



//$Print the current calendar to the given stream, in ISO 8601 format, 
//sorted primarily by beginning date/time, and secondarily by title. The format is: 
void Calendar::print(ostream &os) const{
    for(multiset<string>::iterator it=events.begin(); it!=events.end(); it++){
        os<<(*it)<<endl;
    }
    
}

//$Insert an event, returning the same value and throwing the same errors as the other version 
//of .insert(). The string given as an argument will be in the same format as the strings that 
//print() emits, though leading zeroes are optional.
    //2014-3-20T14/PT1H Right now
bool Calendar::insert(const string &specification){
    int year, mon, day, hour, length_in_hours;
    year = extractYear(specification);
    mon = extractMonth(specification);
    day = extractDay(specification);
    hour = extractHour(specification);
    length_in_hours = extractPeriod(specification);


    string title = extractDesc(specification); 
    try{
    return insert(year, mon, day, hour, length_in_hours, title);
    }catch(string gone){
        throw 2.71828182846;
    }
}

//$Return how many events are in the object.
int Calendar::size() const{
    return events.size();
}

//$Empty the object. After this, size()==0.
void Calendar::clear(){
    events.clear();
}

//$this is the other operators that you asked for
//this will combine two calendars and return the combo
Calendar Calendar::operator|(const Calendar &rhs){
    Calendar tmp;
    tmp.events.insert(events.begin(), events.end());
    tmp.events.insert(rhs.events.begin(), rhs.events.end());
    return tmp;
}
//$appends events to an existing callendar
Calendar & Calendar::operator|=(const Calendar &rhs){
    events.insert(rhs.events.begin(), rhs.events.end());
    return *this;
}












////////////////this is private stuff
//$converts a string to an int     
int stringToInt(string sNum) {
   int number=0; 
   for(unsigned int i=0; i<sNum.size(); i++){
           number*=10;
           number+=sNum.at(i)-48;//ascii to int
   }
   return number;

}

//$convert int to string number
string intToString(int iNum){
    string number = "";
    while(iNum>0){
        number.insert(number.begin(),static_cast<char>(iNum%10+48));
        iNum/=10; 
    }
    while(number.size()<4){
        number.insert(number.begin(),'0');
    }
    if(number.at(0)=='0')
       number=number.substr(2); 
    return number;
}
//this will get the year out of the string
int Calendar::extractYear(string specification){
    return atoi(specification.substr(0,specification.find("-")).c_str());
}
//this will get the month our of the string
int Calendar::extractMonth(string specification){
    return atoi((specification.substr(specification.find("-")+1,5)).c_str());
}
//day out of string
int Calendar::extractDay(string specification){
    return atoi((specification.substr(specification.find("T")-2,specification.find("T")-1)).c_str());
}
//gets hour out of string
int Calendar::extractHour(string specification){
    return atoi((specification.substr(specification.find("/PT")-2,specification.find("/PT")-1)).c_str());
}
//gets length_in_hours out of string
int Calendar::extractPeriod(string specification){
    return atoi((specification.substr(specification.find("/PT")+3,specification.find("H")-1)).c_str());
}
//gets the title out of the string
string Calendar::extractDesc(string specification){
    return specification.substr(specification.find("H")+2);
}




//check for overlaps in events that are being added
bool Calendar::checkOverlaps(int year, int mon, int day, int hour, int length_in_hours){
    if(length_in_hours==0)
        return false;
    

    for(multiset<string>::iterator it=events.begin(); it!=events.end(); it++){
        int y, m, d, h, l;
        y=extractYear(*it);        
        m=extractMonth(*it);
        d=extractDay(*it);
        h=extractHour(*it);
        l=extractPeriod(*it);
        if(l==0)
           return false;
        if(year==y && day==d && mon==m){
            //check if the edges of new event are during an old one
            if((h>hour && h<hour+length_in_hours)||(h+l>hour && h+l<hour+length_in_hours))
                return true;
            //check if the edges of old events are in the new one
            if((hour>h && hour<h+l)||(hour+length_in_hours>h && hour+length_in_hours<h+l))
                return true;
        } 
    }
    return false;
}

//$check for an error in the formating of the event and the existance of dates
void Calendar::checkError(int year, int mon, int day, int hour, int length_in_hours){
    if(year>2100 || year < 1900) {
        string tmp;
        tmp.append("The year ");
        tmp.append(intToString(year));
        tmp.append(" is not in the allowed range 1900-2100");
        throw(tmp);        
    }
    if(hour>23 || hour<0){
        string tmp;
        tmp.append("The hour ");
        tmp.append(intToString(hour));
        tmp.append(" is not in the allowed range");
        throw(tmp);
    } 
    if((hour + length_in_hours)>24 || length_in_hours<0){
        string tmp;
        tmp.append("The event of duration ");
        tmp.append(intToString(length_in_hours));
        tmp.append(" will go past midnight, and that will make you tired. Please do not do that.");
        throw(tmp);        
    }
    if(mon>12 || mon<0){
        string tmp;
        tmp.append("The month ");
        tmp.append(intToString(mon));
        tmp.append(" is not in the allowed range 1-12");
        throw(tmp);        
    }
    if(checkDay(year, mon, day)){ 
        string tmp;
        tmp.append("The day ");
        tmp.append(intToString(day));
        tmp.append(" is not in contained in month ");
        tmp.append(intToString(mon));
        throw(tmp);        
    }
} 

//$this checks for the existance of the day in specified month
bool Calendar::checkDay(int year, int mon, int day){
    int tmp = days_per_month(year, mon);
    return (day>tmp || day<0);
}  

//$this checks for leap years obviously
bool Calendar::leap(int year) {
    assert(1 <= year && year <= 9999);
    //check this out to be sure that it works.
    if(year%4 == 0){
        if (year % 100 ==0 && year % 400!= 0){
            return false;
        }
        return true;
    }
    return false;
}

//this is the number of days in the specified month
int Calendar::days_per_month(int year, int month) {
    assert(1 <= year && year <= 9999);
    assert(1 <= month && month <= 12);
    static int days[] = {00,31,28,31,30,31,30,31,31,30,31,30,31};
    if (month==2 && leap(year))
        return 29;
    return days[month];
}



































