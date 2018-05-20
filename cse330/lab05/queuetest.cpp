#include <iostream>
#include <cassert>
#include "queue.h"
#include <list>
#include <string>


using namespace std;



int main()
{
  queue<int> q1;
  assert(q1.size() == 0);
  assert(q1.empty());

  q1.push(0);
  q1.push(4);
  q1.push(5);
  q1.push(1);
  assert(q1.size() == 4);
  assert(q1.front() == 0);
  assert(q1.back() == 1);

  q1.push(2);
  assert(q1.size() == 5);
  assert(q1.back() == 2);

  q1.pop();
  assert(q1.front() == 4);
  assert(q1.back() == 2);


  queue<string> q2;
  q2.push("Would");
  q2.push("you");
  q2.push("kindly?");
  assert(q2.front() == "Would");
  assert(q2.back() == "kindly?");

  cout << "All tests passed";

}
