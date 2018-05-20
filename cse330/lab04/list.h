//
//
//	simplified List class
//
//	Described in Chapter 9 of
//	Data Structures in C++ using the STL
//	Published by Addison-Wesley, 1997
//	Written by Tim Budd, budd@cs.orst.edu
//	Oregon State University
//
//
#ifndef LIST_H_
#define LIST_H_

template <class T> class Link;
template <class T> class List;

template <class T> class ListIterator {
	typedef ListIterator<T> iterator;
public:
		// constructor
	ListIterator (List<T> * tl, Link<T> * cl)
		: theList(tl), currentLink(cl) { }

		// iterator protocol
	T & operator * ()
		{ return currentLink->value; }
	void operator = (iterator rhs)
		{ theList = rhs.theList; currentLink = rhs.currentLink; }
	bool operator == (const iterator rhs) const
		{ return currentLink == rhs.currentLink; }
	bool operator != (const iterator rhs) const
		{ return currentLink != rhs.currentLink; }
	iterator & operator ++ ()
		{ currentLink = currentLink->nextLink; return * this; }
	iterator operator ++ (int);
	iterator & operator -- ()
		{ currentLink = currentLink->prevLink; return * this; }
	iterator operator -- (int);

protected:
	List <T> * theList;
	Link <T> * currentLink;
	friend class List<T>;
};

template <class T>
class List {
public:
		// type definitions
	typedef T value_type;
	typedef ListIterator<T> iterator;

		// constructor and destructor
	List () : firstLink(0), lastLink(0) { }
	List (List<T> * x) : firstLink(0), lastLink(0) { }
	~ List ();

		// operations
	bool empty () { return firstLink == 0; }
	int size();
	T back () { return lastLink->value; }
	T front () { return firstLink->value; }
	void push_front(T);
	void push_back(T);
	void pop_front ();
	void pop_back ();
	iterator begin () { return iterator (this, firstLink); }
	iterator end () { return iterator (this, 0); }
	void sort ();
	void insert (iterator, T);
	void erase (iterator itr) { erase (itr, itr); }
	void erase (iterator, iterator);
	void operator =(const List<T> & l);

protected:
	Link <T> * firstLink;
	Link <T> * lastLink;
};

template <class T> class Link {
private:
	Link (T v) : value(v), nextLink(0), prevLink(0) { }
	T value;
	Link<T> * nextLink;
	Link<T> * prevLink;
		// allow Lists to see element values
	friend class List<T>;
	friend class ListIterator<T>;
};

template <class T> int List<T>::size ()
	// count number of elements in collection
{
	int counter = 0;
	for (Link<T> * ptr = firstLink; ptr != 0; ptr = ptr->nextLink)
		counter++;
	return counter;
}

template <class T> void List<T>::push_front (T newValue)
	// add a new value to the front of a List
{
	Link<T> * newLink = new Link<T> (newValue);
	if (empty())
		firstLink = lastLink = newLink;
	else {
		firstLink->prevLink = newLink;
		newLink->nextLink = firstLink;
		firstLink = newLink;
		}
}

template <class T> void List<T>::push_back (T newValue)
	// add a new value to the end of a List
{
	Link<T> * newLink = new Link<T> (newValue);
	if (empty())
		firstLink = lastLink = newLink;
	else {
		lastLink->nextLink = newLink;
		newLink->prevLink = lastLink;
		lastLink = newLink;
	}
}

template <class T> void List<T>::pop_front()
	// remove first element from Linked List
{
	Link <T> * save = firstLink;
	firstLink = firstLink->nextLink;
	if (firstLink != 0)
		firstLink->prevLink = 0;
	else
		lastLink = 0;
	delete save;
}

template <class T> void List<T>::pop_back()
	// remove last element from Linked List
{
	Link <T> * save = lastLink;
	lastLink = save->prevLink;
	if (lastLink != 0)
		lastLink->nextLink = 0;
	delete save;
}

template <class T> List<T>::~List ()
	// remove each element from the List
{
	Link <T> * first = firstLink;
	while (first != 0) {
		Link <T> * next  = first->nextLink;
		delete first;
		first = next;
		}
}

template <class T>
void List<T>::operator=(const List<T> & l)
{
    firstLink = 0;
    lastLink = 0;
    for (Link<T> * current = l.firstLink; current != 0; current = current->nextLink)
        push_back(current->value);
}



template <class T> ListIterator<T> ListIterator<T>::operator ++ (int)
	// postfix form of increment
{
		// clone, then increment, return clone
	ListIterator<T> clone (theList, currentLink);
	currentLink = currentLink->nextLink;
	return clone;
}
template <class T> ListIterator<T> ListIterator<T>::operator -- (int)
	// postfix form of decrement
{

		// clone, then increment, return clone
	ListIterator<T> clone (theList, currentLink);
	currentLink = currentLink->prevLink;
	return clone;
}

template <class T> void List<T>::insert (ListIterator<T> itr, T value)
	// insert a new element into the middle of a Linked List
{
	Link<T> * newLink = new Link<T>(value);
	Link<T> * current = itr.currentLink;

	newLink->nextLink = current;
	newLink->prevLink = current->prevLink;
	current->prevLink = newLink;
	current = newLink->prevLink;
	if (current != 0)
		current->nextLink = newLink;
	else
		firstLink = newLink;
}

template <class T>
void List<T>::erase (ListIterator<T> start, ListIterator<T> stop)
	// remove values from the range of elements
{
	Link<T> * first = start.currentLink;
	Link<T> * prev = first->prevLink;
	Link<T> * last = stop.currentLink;
	Link<T> * next = last->nextLink;

	if (prev == 0) {
		firstLink = next;
	}
	else if (next == 0) {
		lastLink = prev;
		lastLink->nextLink = 0;
	}
	else {
		prev->nextLink = next;
		next->prevLink = prev;
	}
	while (start != stop) {
		ListIterator<T> next = start;
		delete start.currentLink;
		++next;
		start = next;
		}
}
#endif
