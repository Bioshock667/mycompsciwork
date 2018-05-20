#include <vector>
#include<string>
#include<iostream>

using namespace std;

template<class T>
class Mlist
{
 public:
  Mlist();//creates mlist
  T front()//returns front of list
 {return mlist[0];}
  T back()//returns end of list
  {return mlist[mlist.size()-1];}
  bool in(T x);//determines if "x" is in the list
  bool empty();// determines if the list is empty
  void addfront(T entry)//adds entry to front of list
  {mlist.insert(mlist.begin(),entry);}
  void addend(T entry)//adds entry to back of list
  {mlist.push_back(entry);}
  void addorder(T entry)// add entry to list
  {addorder(mlist.begin(),entry);}
  void removefront()//removes front entry in list
  {mlist.erase(mlist.begin());}
  void removeend()//removes end entry in list
  {mlist.pop_back();}
  void remove(T n)//searches list and removes entry with value n
  {remove(mlist.begin(),n);}
  void display()
  {for (int i=0; i<mlist.size(); i++) cout << mlist[i] << endl;}
 private:
  vector<T> mlist;
  void remove(class vector<T>::iterator ix, T n);//uses iterator and recursion to remove n
  void addorder(class vector<T>::iterator ix, T n);//uses iterator and rerecursion to add value n
 };

template<class T>
Mlist<T>::Mlist()
{}

template<class T>
bool Mlist<T>::in(T x)
{
  for (int i=0; i<mlist.size(); i++)
  {
	if(mlist[i]==x)
	   return true;
  }
  return false;
}

template<class T>
bool Mlist<T>::empty()
{
   if(mlist.size()==0)
	return false;
  else 
   return true;
}

template<class T>
void Mlist<T>::remove(class vector<T>::iterator ix, T n)
{
   if(ix==mlist.end())
	return;
   if(*ix == n)
	ix=mlist.erase(ix);
   else
	remove(++ix,n);
}

template<class T>
void Mlist<T>::addorder(class vector<T>::iterator ix, T n)
{
   if(ix==mlist.end())
   {
	mlist.push_back(n);
	return;
   }
   if(*ix>n)
   {
	addorder(++ix,n);
   }
   else
	ix=mlist.insert(ix,n);
}

int main()
{
 Mlist<int> test1 = Mlist<int>() ;
 test1.addorder(5);
 test1.addorder(7);
 test1.addorder(4);
 //cout << test1.front() << test1.back() << endl;
 test1.display();
 test1.remove(7);
 test1.display();
 cout << test1.front()<< endl;
 cout << test1.back()<< endl;
 Mlist<string> test2 = Mlist<string>() ;
 test2.addorder("John");
 test2.addorder("Paul");
 test2.addorder("Mary");
 test2.addorder("Kate");
 test2.remove("Paul");
 cout << test2.front()<< endl;
 cout << test2.back()<< endl;
}

