// PriorityQueue.h
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>

using namespace std;

template <class T>
void print_vector(const vector<T>&);

template <class R>
void swap1 (R& x, R& y)
{
	R temp = x;
	x = y;
	y = temp;
}

template <class T>
class PriorityQueue
{
 public:

  bool empty() {return heap.empty();}
  int  size()  {return heap.size();}
  T&   top()   {return heap[0];}

  void push(T& newElement)
  {
    heap.push_back(newElement);
    push_heap();
  }
  void pop()   {pop_heap();}
  void print_tree_aux(int pos, int level) const;
  void print_tree() {print_tree_aux(0,0);}

 private:

  void push_heap();
  void pop_heap();
  void adjust_heap();

  vector<T> heap;
};


template <class T>
void PriorityQueue<T>::push_heap()
{ // push a value onto the priority queue
  int position = heap.size() - 1;
  int parent = (position - 1) / 2; // integer division

  while (position > 0 && heap[position] > heap[parent])
    { // bubble up value as far as is necessary
      swap1(heap[position], heap[parent]);
      position = parent;
      parent = (position - 1) / 2;
    }
}

template <class T>
void PriorityQueue<T>::pop_heap()
{ // remove root and adjust heap
  int lastpos = heap.size() - 1;
  swap1(heap[0],heap[lastpos]); //swap root with last position
  heap.pop_back(); // remove last position
  adjust_heap(); // call adjust_heap
}

template <class T>
void PriorityQueue<T>::adjust_heap()
{ // restructures heap as necessary
  int position = 0; // position of root
  int heapSize = heap.size();
  while (position < heap.size())
	{
	  // position is within heap to adjust ..
	  // get pos of left chld;
	  int childpos = position * 2 + 1; // index of left child

	  if (childpos < heapSize)
	    {
	      // there is a left child within heap to adjust;
	      // is this the larger child? if there exists a right
	      // child within the heap to adjust, and this right
	      // child is larger, set childpos to the index of the
	      // larger child; (otherwise, just keep index of left
	      // child;
	      if ((childpos + 1 < heapSize) &&
            heap[childpos + 1] > heap[childpos])
		  childpos++;

	      // if value at position is larger than the
	      // larger child, then the value is in its
	      // proper place; done;
	      if (heap[position] > heap[childpos])
            return;
	      else
            swap(heap[position],heap[childpos]); // swap value with larger child;
	    }
	  position = childpos;
	}
}


template <class T>
void PriorityQueue<T>::print_tree_aux(int pos, int level) const
{ // prints tree using dots to indicate level of value in the tree
  if (heap.empty())
    {
      cout << "empty" << endl;
      return;
    }

  // print level many dots followed by value at index pos;
  for (int i = 1; i <= level; i++)
    cout << ".";
  cout << heap[pos] << endl;;

  if (2 * pos + 1 >= heap.size())
    return; // value at pos is a leaf;

  print_tree_aux(2 * pos+ 1, level + 1); // print left subtree;

  if (2 * pos + 2 < heap.size())
    print_tree_aux(2 * pos + 2, level + 1); // print right subtree;
}

template <class T>
void print_vector(const vector<T>& vec)
{   // print contents of a vector
	cout << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl << endl;
}
#endif
