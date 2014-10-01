#include "CalendarBase.h"

using namespace std;

// The insertion operator just calls the print method.
// Since the print method is virtual, it'll call the
// print method from the derived class Calendar.

ostream &operator<<(ostream &os, const CalendarBase &rhs) {
    rhs.print(os);
    return os;
}
