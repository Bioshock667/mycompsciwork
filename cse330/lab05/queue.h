#ifndef QUEUE_H
#define QUEUE_H

#include<list>
using namespace std;

template <class T, template <class T, class = allocator<T> > class Container = list>
class queue {
 public:

    //operations
   bool 	empty () { return c.empty(); }
   unsigned int	size  () { return c.size(); }
   T & 		front () { return c.front(); }
   T &		back  () { return c.back(); }
   void		push  (T x) { c.push_back(x); }
   void		pop   () { c.pop_front(); }

 protected:
	Container<T> c;
};
#endif