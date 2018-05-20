#ifndef STACK_H
#define STACK_H
// Stack.h -- a stack implemented as an adapter (of vector or list or ...)
#include <list>
using namespace std;
//Use the following line for STL containers.
template <class T, template <class T, class = allocator<T> > class Container = list>
//template <class T, template <class T> class Container = list>
class Stack
{
public:
//We don't need a constructor or destructor because the Container has/should have one
//Stack(): container() { }
//~Stack() { ~container(); }
bool empty() const { return c.empty(); }
unsigned int size() const { return c.size(); }
void push(const T & x) { c.push_back(x); }
void pop() { c.pop_back(); }
T & top() { return c.back(); }
private:
Container<T> c;
};
#endif
