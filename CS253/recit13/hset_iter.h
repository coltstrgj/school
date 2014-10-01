#include <list>
#include <vector>

template <class T>
class hset_iter {
  private:
    typedef typename std::list<T> list_t;
    typedef typename std::vector<list_t> table_t;
    table_t &parent;
    int num;

  public:
    hset_iter(table_t &table, int n) : parent(table), num(n) { }

    bool operator!=(const hset_iter &rhs) const {
	return num != rhs.num;
    }

    // Return a pointer to the num'th element,
    // where num==0 is the first element.

    T operator*() const {
	unsigned int remaining = num;
	for (int i=0; ; i++) {
	    if (parent[i].size() <= remaining)
		remaining -= parent[i].size();
	    else {
		typename list_t::iterator it = parent[i].begin();
		for ( ; remaining >0; --remaining)
		    ++it;
		return *it;
	    }
	}

	return T();		// Can't happen.  :-)
    }

    // Pre-increment
    void operator++() {
	++num;
    }
};
