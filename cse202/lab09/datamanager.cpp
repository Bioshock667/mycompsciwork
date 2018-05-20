#include<vector>
#include<iostream>

using namespace std;

class Data
{
 public:
 Data()
{cout << "building ...\n";}
 void addData(int x) // adds x to the data vector
 {data.push_back(x);}
 bool operator ==(Data other) const; //compares two Data objects for equality
 static void changebenchmark(int newbenchmark); // changes the static benchmark variable
 vector<int> getData() const // returns the data vector
 {return data;}
 int getbenchmark() const // returns the static benchmark
 {return benchmark;}
 void deleteData(int x);
 private:
 vector<int> data;
 static int benchmark;
};

int Data::benchmark = 10;

void Data::changebenchmark(int newbenchmark)
{ benchmark=newbenchmark;
}

bool Data::operator ==(Data other) const
{
  if(data.size() != other.getData().size())
	return false;
  else
  {
     for(int i = 0; i<data.size();i++)
     {
	if(data[i] != other.getData()[i])
	     return false;
     }
   return true;
  }
}
void Data::deleteData(int x)
{

  for(vector<int>::iterator it = data.begin();it != data.end();++it)
  {
     if(*it == x)
 	data.erase(it);
  }
}
	
int main()
{
  Data d1, d2, d3;
  d1.addData(10);
  d1.addData(20);
  d1.addData(30);
  d2.addData(10);
  d2.addData(20);
  d2.addData(30);
  d3.addData(10);
  d3.addData(25);
  d3.addData(30);
  if (d1 == d2) cout << "d1=d2" << endl;
  if (d2 == d3) cout << "d2=d3" << endl;
  else cout << "d2 != d3" << endl;
  cout << "d1 benchmark " << d1.getbenchmark() <<endl;
  cout << "d2 benchmark " << d2.getbenchmark() <<endl;
  cout << "d3 benchmark " << d3.getbenchmark() <<endl;
  d1.changebenchmark(100);
  cout << "new d1 benchmark " << d1.getbenchmark() <<endl;
  cout << "new d2 benchmark " << d2.getbenchmark() <<endl;
  cout << "new d3 benchmark " << d3.getbenchmark() <<endl;
  d1.deleteData(10);
  cout << "New d1 data: " << endl;
  for(int i = 0; i < d1.getData().size(); i++)
  cout << d1.getData()[i] << endl;

}


