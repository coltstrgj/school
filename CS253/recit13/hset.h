#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include "hasher.h"
#include "hset_iter.h"
#include "hasher2.h"
template <class T, class H = Hasher>
class hset {
  private:
    typedef typename std::list<T> list_t;
    typedef typename std::vector<list_t> table_t;
    static const unsigned table_size=8;
    table_t table;

  public:
    typedef hset_iter<T> iterator;
    typedef T value_type;
    typedef size_t size_type;

    hset() : table(table_size) { }
    // Default copy ctor, op=, dtor are fine
    
    void insert(T datum) {
	unsigned hashval = H()(datum) % table.size();
	list_t &lr = table[hashval];
	if (find(lr.begin(), lr.end(), datum) == lr.end())
	    lr.push_back(datum);
    }

    size_type size() const {
	size_type total = 0;
	for (unsigned i=0; i<table.size(); i++)
	    total += table[i].size();
	return total;
    }

    iterator begin() {
	return iterator(table, 0);
    }

    iterator end() {
	return iterator(table, size());
    }

    void dump() const {
	for (unsigned i=0; i<table.size(); i++) {
	    std::cout << "table[" << i << "]";
	    for (typename list_t::const_iterator iter=table[i].begin();
		iter!=table[i].end(); iter++)
		    std::cout << ' ' << *iter;
	    std::cout << '\n';
	}
    }
///////////////////////////////////////////////////////////////////////////////
    bool empty() const {
        for (unsigned int i=0; i<table_size; i++)
	        if(!table[i].empty())
                return false;
    	return true;
    }






////////////////////////////////////////////////////////////////////////////////////
};
