
/////////////////////////////////
//Colt Darien
//CS253
//HW4
//03/25/2014
//////////////////////////////////

#ifndef Calendar_h_included
#define Calendar_h_included

#include <iostream>
#include <string>
#include <set>

#include "CalendarBase.h"


class Calendar : public CalendarBase{

    public:
        Calendar();
        ~Calendar();

        //copy constructor
        Calendar(const Calendar &); 
        
        //assignment opperator
        Calendar & operator=(const Calendar &); 
        
        // Insert an event. Return true if this new event overlapped another event, false otherwise, 
        // but insert it in either case. If the attempted insertion violates any of the following 
        // rules, throw an error and do not insert the event:
        bool insert(int year, int mon, int day, int hour, int length_in_hours, const std::string &title); 
       
        //Print the current calendar to the given stream, in ISO 8601 format, 
        //sorted primarily by beginning date/time, and secondarily by title. The format is: 
        void print(std::ostream &os) const;

        //Insert an event, returning the same value and throwing the same errors as the other version 
        //of .insert(). The string given as an argument will be in the same format as the strings that 
        //print() emits, though leading zeroes are optional.
            //2014-3-20T14/PT1H Right now
        bool insert(const std::string &specification); 
        
        //Return how many events are in the object.
        int size() const;

        //Empty the object. After this, size()==0.
        void clear();
        
        //this is the other operators that you asked for
        //this will combine two calendars and return the combo
        Calendar operator|(const Calendar &);

        //appends events to an existing callendar
        Calendar & operator|=(const Calendar &);


    private:
        std::multiset<std::string> events;
        void checkError(int year, int mon, int day, int hour, int length_in_hours);   
        bool checkDay(int year, int mon, int day);  
        bool checkOverlaps(int year, int mon, int day, int hour, int length_in_hours);
        int extractYear(std::string);
        int extractMonth(std::string);
        int extractDay(std::string);
        int extractHour(std::string);
        int extractPeriod(std::string);        
        std::string extractDesc(std::string);
        bool leap(int year);
        int days_per_month(int year, int month);


};

int stringToInt(std::string sNum);
std::string intToString(int iNum);
#endif /* Calendar_h_included */
