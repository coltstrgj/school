#ifndef _CALENDARBASE_H_INCLUDED_
#define _CALENDARBASE_H_INCLUDED_

#include <iostream>
#include <string>

class CalendarBase {
  public:
    // Default ctor, copy ctor, dtor, and operator= are fine.
    virtual bool insert(int year, int mon, int day, int hour, int length, const std::string &title) = 0;
    virtual bool insert(const std::string &) = 0;
    virtual void clear() = 0;
    virtual int size() const = 0; 

  private:
    friend std::ostream &operator<<(std::ostream &, const CalendarBase &);
    virtual void print(std::ostream &) const = 0;
};

std::ostream &operator<<(std::ostream &, const CalendarBase &);

#endif /* _CALENDARBASE_H_INCLUDED_ */
