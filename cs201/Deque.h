#ifndef DEQUE_H
#define DEQUE_H

// deque.h - an implementation of double-ended queue

#include <vector>

using namespace std;

template <class T> class dequeIterator;

template <class T>
class deque {
public:
	typedef dequeIterator<T> iterator;
	
	deque(): vecOne(), vecTwo() { }
	deque(const unsigned int size, const T& initial): vecOne(size/2, initial), vecTwo(size-(size/2), initial) { }
	deque(const deque<T> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) { }
        ~deque() { } // destructors for vecOne and vecTwo are automatically called
                     // never call a destructor explicitly
        deque & operator=(const deque<T> & d);

	T & operator[](unsigned int);
	T & front();
	T & back();
	bool empty();
	iterator begin();
	iterator end();
	void erase(const iterator &);
	void erase(const iterator &, const iterator &);
	void insert(const iterator &, const T &);
	int size();
	void push_front(const T & value);
	void push_back(const T & value);
	void pop_front();
	void pop_back();
protected:
	vector<T> vecOne;
	vector<T> vecTwo;
};

// Your code goes here ...
template <class T> T deque<T>::front ()
{
  if (vecOne.empty())
  {
    return vecTwo.front();
  }
  else
  {
    vecOne.back();
  }
}
template <class T> void deque<T>::pop_front()
{
  if (vecOne.empty())
  {
    vecTwo.erase(vecTwo.begin());
  }
  else
  {
    vecOne.pop_back();
  }
}
template <class T> T deque<T>::back ()
{
  if (vecOne.empty())
  {
    return vecTwo.back();
  }
  else
  {
    vecOne.front();
  }
}
template <class T> void deque<T>::pop_back()
{
  if (vecOne.empty())
  {
    vecTwo.erase(vecTwo.end());
  }
  else
  {
    vecOne.pop_front();
  }
}
template < class T > T & deque < T > :: operator [ ] ( unsigned int index )
{
  int n = vecOne.size();
  if (index <= n)
  {
    return vecOne [ (n-1) - index ];
  }
  else
  {
    return vecTwo [ index - n];
  }
}
template <class T> dequeIterator <T> dequeIterator<T> ::operator ++ (int)
{
  deque<T>::iterator clone(thedeque, index);
  index++;
  return clone
}
template <class T> void deque<T>::erase ( dequeIterator <T> itr)
{
  int index = itr.index;
  int n = vecOne.size();
  if (index < n)
  {
    vecOne.erase(vecOne.begin() + ((n - 1) - index));
  }
  else
  {
    vecTwo.erase(vecTwo.begin() + (n - index));
  }
}
template <class T>
class dequeIterator {
	friend class deque<T>;
	typedef dequeIterator<T> iterator;
public:
	dequeIterator(): thedeque(0), index(0) { }
	dequeIterator(deque<T> * d, int i): thedeque(d), index(i) { }
	dequeIterator(const iterator & d): thedeque(d.thedeque), index(d.index) { }

	T & operator*();
	iterator & operator++();
	iterator operator++(int);
	iterator & operator--();
	iterator operator--(int);
	bool operator==(const iterator & r);
	bool operator!=(const iterator & r);
	bool operator<(const iterator & r);
	T & operator[](unsigned int i);
	iterator operator=(const iterator & r);
	iterator operator+(int i);
	iterator operator-(int i);
protected:
	deque<T> * thedeque;
	int index;
};
#endif
