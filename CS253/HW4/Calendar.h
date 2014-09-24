#ifndef _CALENDAR_H_INCLUDED_
#define _CALENDAR_H_INCLUDED_

#include "CalendarBase.h"
#include <string>
#include <set>

class Calendar : public CalendarBase  {
        public:
          Calendar();
          Calendar(const Calendar &);
          Calendar & operator=(const Calendar &);
          Calendar operator|(const Calendar &);
          Calendar & operator|=(const Calendar &);
          ~Calendar();
          bool insert(int year, int mon, int day, int hour, int length_in_hours, const std::string &title);
          bool insert(const std::string &specification);
          int size() const;
          void clear();
        private:
          std::multiset<std::string> calend;
          void print(std::ostream &os) const;

};

#endif /* _CALENDAR_H_INCLUDED_ */
