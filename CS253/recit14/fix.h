// This class is certainly inadequate.  It has no include guards,
// inadequate const-correctness, is missing several ctors,
// no assignment operator, etc.
#include <stdlib.h>
#include <ostream>
template <typename T, int N>
class fix {
  public:
    typedef unsigned int size_type;
    typedef T *iterator;
    size_type size() const {
	return N;
    }
    T &operator[] (size_type index) {
        if(data==NULL){
            cout<<"cannot the thing";
            exit(1);
        }
            
        return data[index];
    }
    iterator begin() {
	return &data[0];
    }
    iterator end() {
	return &data[N];
    }
  private:
    T data[N];
};
