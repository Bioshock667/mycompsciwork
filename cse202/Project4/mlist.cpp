/*Programmer: Seth Lemanek
  Version: 1.1 beta
  Date completed: 3/12/2014
  This program creates a class Mlist using a template for multiple data types with a main program that test its
  multiple use on many data types and its functions.
*/
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
  {for (int i=0; i<mlist.size(); i++) cout << mlist[i] << " "; cout << endl;}
 private:
  vector<T> mlist;
  void remove(class vector<T>::iterator ix, T n);//uses iterator and recursion to remove n
  void addorder(class vector<T>::iterator ix, T n);//uses iterator and rerecursion to add value n
 }; //Mlist

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
	return true;
  else 
   return false;
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
   if(*ix<n)
   {
	addorder(++ix,n);
   }
   else
	ix=mlist.insert(ix,n);
}

int main()
{
 Mlist<int> numbers = Mlist<int>() ;
 numbers.addorder(5);
 numbers.addorder(10);
 numbers.addorder(3);
 numbers.addorder(12);
 numbers.display();
 numbers.remove(10);
 cout << "Remove 10 ...\n";
 numbers.display();
 cout << "New List from loop!" << endl;
 for (int i = 11; i > 5; i--)
  numbers.addorder(i);
 numbers.display();
 cout << "Is 9 in the list? ";
if(numbers.in(9)==true)
	cout << "true" << endl;
 else
	cout <<"false" << endl;
 cout << numbers.front()<< "<- front" << endl;
 cout << numbers.back()<< "<- back" << endl;
 Mlist<string> namelist = Mlist<string>() ;
 namelist.addorder("John");
 namelist.addorder("Paul");
 namelist.addorder("Mary");
 namelist.addorder("Kate");
 namelist.display();
 namelist.remove("Paul");
 namelist.addfront("Abigail");
 namelist.addend("Zohan");
 namelist.display();
 cout << "list goes from " << namelist.front() << " to " << namelist.back() << endl;

 namelist.remove("John");
 namelist.remove("Mary");
 namelist.remove("Kate");
 namelist.remove("Abigail");
 namelist.remove("Zohan");
 cout << "Now, is the list empty? ";
 if(namelist.empty()==true)
	cout << "true" << endl;
 else
	cout <<"false" << endl;
 Mlist<char> alphabet = Mlist<char>();
 alphabet.addorder('a');
 alphabet.addorder('c');
 alphabet.addorder('d');
 alphabet.addorder('z');
 alphabet.addorder('b');
 alphabet.display();
 alphabet.removefront();
 alphabet.removeend();
 alphabet.display();
}
