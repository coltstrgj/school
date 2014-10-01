#include <iostream>
#include <fstream>
#include <time.h>
#include <cassert>
#include <sstream>
using namespace std;

class Date {
    public:
        Date();
    // Default copy ctor is fine
    // Default assignment operator is fine
        Date(int year, int month, int day);

    int getday() const;
    int getmonth() const;
    int getyear() const;

    void setday(int);
    void setmonth(int);
    void setyear(int);

        Date &operator+=(int);
        int operator-(const Date &) const;

        Date operator+(int) const;
    const Date &operator++();   // prefix
    Date operator++(int);       // postfix

        Date operator-(int) const;
        Date &operator-=(int);
    const Date &operator--();   // prefix
    Date operator--(int);       // postfix

    bool operator<(const Date &) const;
    bool operator<=(const Date &) const;
    bool operator>(const Date &) const;
    bool operator>=(const Date &) const;
    bool operator==(const Date &) const;
    bool operator!=(const Date &) const;

    protected:
    static int ymd_to_daynum(int year, int month, int day);
        int daynum;             // 1 = January 1, year 1
};

Date operator+(int, const Date &);
ostream &operator<<(ostream &out, const Date &);    // YYYY-MM-DD
istream &operator>>(istream &in, Date &);       // YYYY-MM-DD

static bool leap(int year) {
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

static int days_per_year(int year) {
    assert(1 <= year && year <= 9999);
    return leap(year) ? 366 : 365;
}

static int days_per_month(int year, int month) {
    assert(1 <= year && year <= 9999);
    assert(1 <= month && month <= 12);
    static int days[] = {00,31,28,31,30,31,30,31,31,30,31,30,31};
    if (month==2 && leap(year))
        return 29;
    return days[month];
}

int Date::ymd_to_daynum(int year, int month, int day) {
    assert(1 <= year && year <= 9999);
    assert(1 <= month && month <= 12);
    assert(1 <= day && day <= 31);

    // Start at Jan 1, 0001, and increment until we get to what we want
    int daynum=1;

    for (int y=1; y < year; y++) 
        daynum += days_per_year(y);

    for (int m=1; m < month; m++)
        daynum += days_per_month(year, m);

    // We're now poised at the first day of that month
    daynum += day-1;

    assert(1 <= daynum && daynum <= 10000 * 366);
    return daynum;
}

static void daynum_to_ymd(int daynum, int &year, int &month, int &day) {
    assert(1 <= daynum && daynum <= 10000 * 366);

    int y=1, m=1, d=1;

    while(daynum>365){
        daynum-=365;
        y++;
        if(leap(y-1)){
            daynum--;
        }    
    }
    for (; daynum>1; daynum--) {
        // Increment y-m-d
        d++;
        if (d > days_per_month(y, m)) {
            m++;
            d=1;
            if (m > 12) {
                y++;
                m=1;
            }
        }
    }

    year = y;
    month = m;
    day = d;

    assert(1 <= year && year <= 9999);
    assert(1 <= month && month <= 12);
    assert(1 <= day && day <= 31);
}

Date::Date(int year, int month, int day) 
    : daynum(ymd_to_daynum(year, month, day)) {
    assert(1 <= year && year <= 9999);
    assert(1 <= month && month <= 12);
    assert(1 <= day && day <= 31);
    assert(1 <= daynum && daynum <= 10000 * 366);
}

Date::Date() {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    daynum = ymd_to_daynum(tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday);
}

int Date::getday() const {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    return day;
}

int Date::getmonth() const {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    return month;
}

int Date::getyear() const {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    return year;
}

void Date::setday(int new_day) {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    daynum = ymd_to_daynum(year, month, new_day);
}

void Date::setmonth(int new_month) {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    daynum = ymd_to_daynum(year, new_month, day);
}

void Date::setyear(int new_year) {
    int year, month, day;
    daynum_to_ymd(daynum, year, month, day);
    daynum = ymd_to_daynum(new_year, month, day);
}

// This one stands alone

int Date::operator-(const Date &rhs) const {
    return daynum - rhs.daynum;
}

// This does the real work of all numeric operations.
// All other operators (+, -, ++, -=, etc) should invoke this.

Date &Date::operator+=(int value) {
    daynum += value;
    return *this;
}

Date Date::operator+(int value) const {
    Date result = *this;
    return result += value;
}

const Date &Date::operator++() {            // prefix
    *this += 1;
    return *this;
}

Date Date::operator++(int /* dummy */) {        // postfix
    Date before = *this;
    *this += 1;
    return before;
}

Date Date::operator-(int value) const {
    return *this + -value;
}

Date &Date::operator-=(int value) {
    return *this += -value;
}

const Date &Date::operator--() {            // prefix
    *this -= 1;
    return *this;
}

Date Date::operator--(int /* dummy */) {        // postfix
    Date before = *this;
    *this -= 1;
    return before;
}


bool Date::operator<(const Date &rhs) const {
    return daynum < rhs.daynum;
}

bool Date::operator<=(const Date &rhs) const {
    return daynum <= rhs.daynum;
}

bool Date::operator>(const Date &rhs) const {
    return daynum > rhs.daynum;
}

bool Date::operator>=(const Date &rhs) const {
    return daynum >= rhs.daynum;
}

bool Date::operator==(const Date &rhs) const {
    return daynum == rhs.daynum;
}

bool Date::operator!=(const Date &rhs) const {
    return daynum != rhs.daynum;
}

Date operator+(int value, const Date &rhs) {
    return rhs + value;
}

ostream &operator<<(ostream &out, const Date &d) {
    return out << d.getyear() << '-' << d.getmonth() << '-' << d.getday();
}

#include <iomanip>

istream &operator>>(istream &in, Date &d) {
    int year, month, day;
    char c1, c2;
    if (in >> year  >> c1 && c1=='-'
     && in >> month >> c2 && c2=='-'
     && in >> day)
        d = Date(year, month, day);
    else
        in.setstate(ios::failbit);
    return in;
}


int main() {
    // Read & display some dates
    ifstream data("data");
    Date d;
    // Read each line, try to convert it to a date, complain if it fails.
    for (string s; getline(data, s); ) {
        istringstream iss(s);   // Initialize stream with string
        if (iss >> d)       // Try to convert to a date
        cout << d << endl;
        else
        cerr << "Bad date \"" << s << "\"\n";
    }

    const Date a(2009,3,4);
    cout << a << endl;      // Wed Mar 4 2009

    const Date b(a);
    cout << b << endl;      // Wed Mar 4 2009

    Date c; c=a;
    cout << c << endl;      // Wed Mar 4 2009

    c = c+1;
    cout << c << endl;      // Thu Mar 5 2009
    c += 9;
    cout << c << endl;      // Sat Mar 14 2009
    d = ++c;
    cout << c << endl;      // Sun Mar 15 2009
    cout << d << endl;      // Sun Mar 15 2009

    d = c++;
    cout << c << endl;      // Mon Mar 16 2009
    cout << d << endl;      // Sun Mar 15 2009

    Date e = d-1;
    cout << e << endl;      // Sat Mar 14 2009
    d = e--;
    cout << d << endl;      // Sat Mar 14 2009
    cout << e << endl;      // Fri Mar 13 2009
    d = --e;
    cout << d << endl;      // Thu Mar 12 2009
    cout << e << endl;      // Thu Mar 12 2009
    e -= 5;
    cout << e << endl;      // Sat Mar 7 2009
    e -= -2;
    cout << e << endl;      // Mon Mar 9 2009
    cout << d-e << endl;        // 3
    cout << e-d << endl;        // -3

    // a==b, a<c
    cout << ((a==b) ? "== good\n" : "== bad\n");
    cout << ((a==c) ? "== bad\n"  : "== good\n");
    cout << ((a!=c) ? "!= good\n" : "!= bad\n");
    cout << ((a!=b) ? "!= bad\n"  : "!= good\n");
    cout << ((a<c)  ? "<  good\n" : "<  bad\n");
    cout << ((a<b)  ? "<  bad\n"  : "<  good\n");
    cout << ((c>a)  ? ">  good\n" : ">  bad\n");
    cout << ((b>a)  ? ">  bad\n"  : ">  good\n");
    cout << ((a<=b) ? "<= good\n" : "<= bad\n");
    cout << ((a<=c) ? "<= good\n" : "<= bad\n");
    cout << ((c<=a) ? "<= bad\n"  : "<= good\n");
    cout << ((a>=b) ? ">= good\n" : ">= bad\n");
    cout << ((c>=a) ? ">= good\n" : ">= bad\n");
    cout << ((a>=c) ? ">= bad\n"  : ">= good\n");
    
    //stuff that I have inserted myself
    d.setday(12);
    d.setmonth(4);
    d.setyear(2012);
    d = 1+d;
    cout<<"April 13 2012? "<<d<<endl;

    return 0;
}
